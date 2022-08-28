#ifndef VIEW3D_H
#define VIEW3D_H

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

class View3D
{
private:
    sf::Vector3f _position;
    sf::Vector3f _scale;
    sf::Vector3f _rotation;
    sf::Vector2u _window_size;

public:
    View3D(sf::Vector2u size);

    void setPosition(sf::Vector3f value);
    void setRotation(sf::Vector3f value);
    void setScale(sf::Vector3f value);
    void setSize(sf::Vector2u size);

    sf::Vector3f getPosition();
    sf::Vector3f getRotation();
    sf::Vector3f getScale();
    sf::Vector2u getSize();

    void move(sf::Vector3f value);
    void rotate(sf::Vector3f value);
    void scale(sf::Vector3f value);

    void update();
};

#endif // VIEW3D_H
