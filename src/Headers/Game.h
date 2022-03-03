#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "Food.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    std::vector<Food> foods;

    // Initializers
    void initWindow();
    void initFoods();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Update Functions
    void updateSFMLEvents();
    void update();

    // Render Functions
    void renderFoods();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
