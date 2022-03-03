#ifndef FOOD_H
#define FOOD_H

#include "../Headers.h"

class Food
{
  private:
    float x;
    float y;
    sf::RectangleShape shape;

    // Initializers
    void initShape();

  public:
    // Constructor and Destructor
    Food(const float x, const float y);
    virtual ~Food();

    // Accessors
    const sf::Vector2f getPos() const;

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // FOOD_H
