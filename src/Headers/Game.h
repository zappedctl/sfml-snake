#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "../Constants.h"
#include "Snake.h"
#include "Food.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    Snake snake;
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
    void updateSnake();
    void update();

    // Render Functions
    void renderSnake();
    void renderFoods();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
