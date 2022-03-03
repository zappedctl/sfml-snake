#include "../Headers/Snake.h"

// Initializers

void Snake::initBody()
{
  this->body.push_back(sf::Vector2f(1, 3));
  this->body.push_back(sf::Vector2f(2, 3));
  this->body.push_back(sf::Vector2f(3, 3));
}

// Constructor and Destructor

Snake::Snake()
{
  this->direction.x = 1;
  this->speed = 8;
  this->initBody();
}

Snake::~Snake()
{

}

// Functions

void Snake::updateDirection()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
  {
    this->direction.y = -1;
    this->direction.x = 0;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
  {
    this->direction.y = 1;
    this->direction.x = 0;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
  {
    this->direction.x = -1;
    this->direction.y = 0;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
  {
    this->direction.x = 1;
    this->direction.y = 0;
  }
}

void Snake::update()
{
  this->updateDirection();
  if (this->moveClock.getElapsedTime().asSeconds() > 1.f / this->speed) {
    for (int i = 0; i < this->body.size(); i++)
    {
      this->body[i].x += this->direction.x;
      this->body[i].y += this->direction.y;
    }
    this->moveClock.restart();
  }
}

void Snake::render(sf::RenderTarget& target)
{
  sf::RectangleShape snakePart(sf::Vector2f(TILE_SIZE, TILE_SIZE));
  snakePart.setFillColor(sf::Color::Green);

  for (int i = 0; i < this->body.size(); i++)
  {
    snakePart.setPosition(this->body[i] * TILE_SIZE);
    target.draw(snakePart);
  }
}
