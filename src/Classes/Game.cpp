#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML");
}

void Game::initFoods()
{
  this->foods.push_back(Food(TILE_SIZE, TILE_SIZE));
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initFoods();
}

Game::~Game()
{
  delete this->window;
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

void Game::update()
{
  this->updateSFMLEvents();
}

// Render Functions

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
  this->renderSnake();
  this->renderFoods();
  this->window->display();
}

// Functions

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
