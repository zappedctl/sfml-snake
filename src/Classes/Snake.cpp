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
  this->speed = 16;
  this->initBody();
}

Snake::~Snake()
{

}

// Accessors

const sf::Vector2f Snake::getHead() const
{
  return this->body[this->body.size() - 1];
}

const std::deque<sf::Vector2f> Snake::getBody() const
{
  return this->body;
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

void Snake::update(sf::Vector2u windowSize)
{
  this->updateDirection();

  // Snake Movement:
  //
  // 1. The head moves based on the current direction (sf::Vector2f)
  // 2. The new position is pushed to the snake's body end
  // 3. The first element from the snake's body (the tail) is removed

  if (this->moveClock.getElapsedTime().asSeconds() > 1.f / this->speed) {
    this->lastPart = this->body[0];

    if (this->body.size() > 1)
    {
      this->body.push_back(sf::Vector2f(this->body[this->body.size() - 1] + this->direction));

      // Wrapping snake if it exits the window bounds
      if (this->body[this->body.size() - 1].x > windowSize.x / TILE_SIZE - 1)
        this->body[this->body.size() - 1].x = 0;
      else if (this->body[this->body.size() - 1].x < 0)
        this->body[this->body.size() - 1].x = windowSize.x / TILE_SIZE - 1;

      if (this->body[this->body.size() - 1].y > windowSize.y / TILE_SIZE - 1)
        this->body[this->body.size() - 1].y = 0;
      else if (this->body[this->body.size() - 1].y < 0)
        this->body[this->body.size() - 1].y = windowSize.y / TILE_SIZE - 1;

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

  for (sf::Vector2f part : this->body)
  {
    snakePart.setPosition(part * TILE_SIZE);
    target.draw(snakePart);
  }
}
