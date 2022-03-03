#ifndef SNAKE_H
#define SNAKE_H

#include "../Headers.h"
#include "../Constants.h"

class Snake
{
  private:
    std::vector<sf::Vector2f> body;
    sf::Vector2f direction;
    int speed;

    // Move Clock
    sf::Clock moveClock;

    // Initializers
    void initBody();

  public:
    // Constructor and Destructor
    Snake();
    virtual ~Snake();

    // Update Functions
    void updateDirection();
    void update();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // SNAKE_H
