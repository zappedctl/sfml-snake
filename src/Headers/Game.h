#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "../Constants.h"
#include "Background.h"
#include "Snake.h"
#include "Food.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    Background* grid;
    Snake snake;
    std::vector<Food> foods;
    sf::SoundBuffer pickupBuffer;
    sf::Sound pickupSound;

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
    void updateCollisions();
    void update();

    // Render Functions
    void renderGrid();
    void renderSnake();
    void renderFoods();
    void render();

    // Functions
    void spawnFood();
    void run();
};

#endif // GAME_H
