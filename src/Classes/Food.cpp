#include "../Headers/Food.h"
#include "../Constants.h"

// Initializers

void Food::initShape()
{
  this->shape.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
  this->shape.setFillColor(sf::Color::Red);
}

// Constructor and Destructor

Food::Food()
{
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
