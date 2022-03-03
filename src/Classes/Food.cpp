#include "../Headers/Food.h"
#include "../Constants.h"

// Initializers

void Food::initShape()
{
  this->shape.setPosition(sf::Vector2f(this->x, this->y));
  this->shape.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
  this->shape.setFillColor(sf::Color::Red);
}

// Constructor and Destructor

Food::Food(const float x, const float y)
{
  this->x = x;
  this->y = y;

  this->initShape();
}

Food::~Food()
{

}

// Functions

void Food::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
