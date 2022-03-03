#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML");
  this->window->setFramerateLimit(60);
}

void Game::initFoods()
{
  this->foods.push_back(Food(1, 1));
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
      isInside = newFoodX == part.x && newFoodY == part.y ? true : false;
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
