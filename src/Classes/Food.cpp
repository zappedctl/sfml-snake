#include "../Headers/Food.h"
#include "../Constants.h"

// Initializers

void Food::initShape()
{
  this->shape.setPosition(sf::Vector2f(this->x * TILE_SIZE, this->y * TILE_SIZE));
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

// Accessors

const sf::Vector2f Food::getPos() const
{
  return sf::Vector2f(this->x, this->y);
}

// Functions

void Food::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
