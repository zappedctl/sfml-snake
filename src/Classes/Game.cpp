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
  this->grid = new Background(this->window->getSize().x, this->window->getSize().y, "src/Assets/Textures/grid.png");
  this->isPaused = false;

  // Loading Pick-up Sound
  if (!this->pickupBuffer.loadFromFile("src/Assets/Sounds/pickup.wav"))
  {
    std::cout << "ERROR::GAME::CANT_LOAD_PICKUP_AUDIO_FILE" << std::endl;
  }

  this->pickupSound.setBuffer(this->pickupBuffer);

  // Seeding RNG
  srand(time(NULL));
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

      case sf::Event::KeyPressed:
        switch (this->sfEvent.key.code)
        {
          case sf::Keyboard::Escape:
            this->window->close();

          case sf::Keyboard::Key::P:
            this->togglePaused();

          default:
            break;
        }

      default:
        break;
    }
  }
}

void Game::updateSnake()
{
  this->snake.update(this->window->getSize());
  for (Food food : this->foods)
  {
    if (this->snake.getHead() == food.getPos())
    {
      snake.grow();
      this->pickupSound.play();
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
  if (!this->isPaused)
  {
    this->updateSnake();
    this->updateCollisions();
  }
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
  int insideCount = 0;
  std::deque<sf::Vector2f> snakeBody = this->snake.getBody();

  do
  {
    newFoodX = rand() % this->window->getSize().x / TILE_SIZE;
    newFoodY = rand() % this->window->getSize().y / TILE_SIZE;

    insideCount = 0;
    for (sf::Vector2f part : snakeBody)
      if (newFoodX == part.x && newFoodY == part.y)
        insideCount++;
  } while (insideCount > 0);

  this->foods.push_back(Food(newFoodX, newFoodY));
}

void Game::togglePaused()
{
  this->isPaused = !this->isPaused;
}

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
