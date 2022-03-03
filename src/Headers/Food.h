#ifndef FOOD_H
#define FOOD_H

#include "../Headers.h"

class Food
{
  private:
    sf::RectangleShape shape;

    // Initializers
    void initShape();

  public:
    // Constructor and Destructor
    Food();
    virtual ~Food();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // FOOD_H
