#ifndef SNAKE_H
#define SNAKE_H

#include "../Headers.h"
#include "../Constants.h"

class Snake
{
  private:
    std::deque<sf::Vector2f> body;
    sf::Vector2f direction;
    int speed;
    sf::Vector2f lastPart;

    // Move Clock
    sf::Clock moveClock;

    // Initializers
    void initBody();

  public:
    // Constructor and Destructor
    Snake();
    virtual ~Snake();

    // Accessors
    const sf::Vector2f getHead() const;

    // Update Functions
    void updateDirection();
    void update();

    // Functions
    void grow();
    void render(sf::RenderTarget& target);
};

#endif // SNAKE_H
