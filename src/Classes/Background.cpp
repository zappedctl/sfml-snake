#include "../Headers/Background.h"

// Initializers

void Background::initTexture()
{
  this->texture = new sf::Texture();
  if (!this->texture->loadFromFile(this->texturePath))
  {
    std::cout << "ERROR::BACKGROUND::CANT_LOAD_TEXTURE_FILE" << std::endl;
  }

  this->texture->setRepeated(true);
}

void Background::initShape(const float w, const float h)
{
  this->shape.setTexture(this->texture);
  this->shape.setSize(sf::Vector2f(w, h));
  this->shape.setTextureRect(sf::IntRect(0, 0, w, h));
}

// Constructor and Destructor

Background::Background(const float w, const float h, const std::string path)
{
  this->texturePath = path;
  this->initTexture();
  this->initShape(w, h);
}

Background::~Background()
{

}

// Functions

void Background::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
