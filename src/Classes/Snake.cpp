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

// Update Functions

void Snake::updateDirection()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && (this->direction.y != 1 || this->body.size() == 1))
  {
    this->direction.y = -1;
    this->direction.x = 0;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && (this->direction.y != -1 || this->body.size() == 1))
  {
    this->direction.y = 1;
    this->direction.x = 0;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && (this->direction.x != 1 || this->body.size() == 1))
  {
    this->direction.x = -1;
    this->direction.y = 0;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && (this->direction.x != -1 || this->body.size() == 1))
  {
    this->direction.x = 1;
    this->direction.y = 0;
  }

  // Testing Grow Functions
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
  {
    this->grow();
  }
}

void Snake::update()
{
  this->updateDirection();
  if (this->moveClock.getElapsedTime().asSeconds() > 1.f / this->speed) {
    this->lastPart = this->body[0];

    if (this->body.size() > 1)
    {
      this->body.push_back(sf::Vector2f(this->body[this->body.size() - 1] + this->direction));

      // Wrapping snake if it exits the window bounds
      if (this->body[this->body.size() - 1].x > 800 / TILE_SIZE - 1) this->body[this->body.size() - 1].x = 0;
      else if (this->body[this->body.size() - 1].x < 0) this->body[this->body.size() - 1].x = 800 / TILE_SIZE - 1;
      if (this->body[this->body.size() - 1].y > 600 / TILE_SIZE - 1) this->body[this->body.size() - 1].y = 0;
      else if (this->body[this->body.size() - 1].y < 0) this->body[this->body.size() - 1].y = 600 / TILE_SIZE - 1;

      this->body.pop_front();
    }
    else
    {
      this->body[0] += this->direction;
    }

    this->moveClock.restart();
  }
}

// Functions

void Snake::grow()
{
  this->body.push_front(this->lastPart);
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
