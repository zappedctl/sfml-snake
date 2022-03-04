#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  std::ifstream windowConfig("src/Config/Window.ini");

  std::string windowTitle = "SFML";
  sf::VideoMode windowVideoMode(800, 600);
  unsigned int windowFPSLimit = 60;
  bool windowVSyncEnabled = false;

  if (windowConfig.is_open())
  {
    std::getline(windowConfig, windowTitle); 
    windowConfig >> windowVideoMode.width >> windowVideoMode.height;
    windowConfig >> windowFPSLimit;
    windowConfig >> windowVSyncEnabled;
  }
  else {
    std::cout << "ERROR::GAME::CANT_OPEN_WINDOW_CONFIG_FILE" << std::endl;
  }

  this->window = new sf::RenderWindow(windowVideoMode, windowTitle);
  this->window->setFramerateLimit(windowFPSLimit);
  this->window->setVerticalSyncEnabled(windowVSyncEnabled);
}

void Game::initFoods()
{
  this->spawnFood();
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initFoods();
  this->grid = new Background(800, 600, "src/Assets/Textures/grid.png");
}

Game::~Game()
{
  delete this->window;
  delete this->grid;
}

// Update Functions

void Game::updateSFMLEvents()
{
  while (this->window->pollEvent(this->sfEvent))
  {
    switch (this->sfEvent.type)
    {
      case sf::Event::Closed:
        this->window->close();
        break;

      default:
        break;
    }
  }
}

void Game::updateSnake()
{
  this->snake.update();
  for (Food food : this->foods)
  {
    if (this->snake.getHead() == food.getPos())
    {
      snake.grow();
      this->foods.pop_back();
      this->spawnFood();
    }
  }
}

void Game::updateCollisions()
{
  // Checking for collision between the snake's head and the tail
  for (int i = 0; i < this->snake.getBody().size() - 2; i++)
  {
    if (this->snake.getBody()[i] == this->snake.getHead()) this->window->close();
  }
}

void Game::update()
{
  this->updateSFMLEvents();
  this->updateSnake();
  this->updateCollisions();
}

// Render Functions

void Game::renderGrid()
{
  this->grid->render(*this->window);
}

void Game::renderSnake()
{
  this->snake.render(*this->window);
}

void Game::renderFoods()
{
  for (int i = 0; i < this->foods.size(); i++)
  {
    this->foods[i].render(*this->window);
  }
}

void Game::render()
{
  this->window->clear();
  this->renderGrid();
  this->renderSnake();
  this->renderFoods();
  this->window->display();
}

// Functions

void Game::spawnFood()
{
  int newFoodX = 0; 
  int newFoodY = 0;

  bool isInside = true;
  while (isInside)
  {
    newFoodX = rand() % 800 / TILE_SIZE;
    newFoodY = rand() % 600 / TILE_SIZE;

    for (sf::Vector2f part : this->snake.getBody())
    {
      isInside = newFoodX == part.x && newFoodY == part.y;
    } 
  }

  this->foods.push_back(Food(newFoodX, newFoodY));
}

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
