#include "View3d.h"

namespace sf3d
{
    View3D::View3D(sf::Vector2u size)
    {
        _window_size = size;
    }

    void View3D::setPosition(sf::Vector3f value)
    {
        _position = value;
    }

    void View3D::setRotation(sf::Vector3f value)
    {
        _rotation = value;
    }

    void View3D::setScale(sf::Vector3f value)
    {
        _scale = value;
    }

    void View3D::setSize(sf::Vector2u size)
    {
        _window_size = size;
    }

    sf::Vector3f View3D::getPosition()
    {
        return _position;
    }

    sf::Vector3f View3D::getRotation()
    {
        return _rotation;
    }

    sf::Vector3f View3D::getScale()
    {
        return _scale;
    }

    sf::Vector2u View3D::getSize()
    {
        return _window_size;
    }

    void View3D::move(sf::Vector3f value)
    {
        _position += value;
    }

    void View3D::rotate(sf::Vector3f value)
    {
        _rotation += value;
    }

    void View3D::scale(sf::Vector3f value)
    {
        _scale += value;
    }

    void View3D::update()
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat ratio = float(_window_size.y) / float(_window_size.x);
        glFrustum(-1, 1, -ratio, ratio, 1.f, 100.f);

        glRotatef(_rotation.x, 1, 0, 0);
        glRotatef(_rotation.y, 0, 1, 0);
        glRotatef(_rotation.z, 0, 0, 1);
        glTranslatef(_position.x, _position.y, _position.z);
    }
}
