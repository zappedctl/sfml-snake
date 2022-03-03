#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../Headers.h"

class Background
{
  private:
    std::string texturePath;
    sf::Texture* texture;
    sf::RectangleShape shape;

    // Initializers
    void initTexture();
    void initShape(const float w, const float h);

  public:
    // Constructor and Destructor
    Background(const float w, const float h, const std::string path);
    virtual ~Background();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BACKGROUND_H
