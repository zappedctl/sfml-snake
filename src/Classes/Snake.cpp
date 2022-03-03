#include "../Headers/Snake.h"

// Constructor and Destructor

Snake::Snake()
{
  this->body.push_back(sf::Vector2f(64, 64));
}

Snake::~Snake()
{

}

// Functions

void Snake::render(sf::RenderTarget& target)
{
  sf::RectangleShape snakePart(sf::Vector2f(TILE_SIZE, TILE_SIZE));
  snakePart.setFillColor(sf::Color::Green);

  for (int i = 0; i < this->body.size(); i++)
  {
    snakePart.setPosition(this->body[i]);
    target.draw(snakePart);
  }
}
