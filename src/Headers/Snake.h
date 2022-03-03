#ifndef SNAKE_H
#define SNAKE_H

#include "../Headers.h"
#include "../Constants.h"

class Snake
{
  private:
    std::vector<sf::Vector2f> body;

  public:
    // Constructor and Destructor
    Snake();
    virtual ~Snake();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // SNAKE_H
