#include "../Headers/Snake.h"

// Constructor and Destructor

Snake::Snake()
{
  this->body.push_back(sf::Vector2f(1, 3));
  this->body.push_back(sf::Vector2f(2, 3));
  this->body.push_back(sf::Vector2f(3, 3));
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
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
  {
    this->direction.y = 1;
  }
}

void Snake::update()
{
  this->updateDirection();
  for (int i = 0; i < this->body.size(); i++)
  {
    this->body[i].x += this->direction.x;
    this->body[i].y += this->direction.y;
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
