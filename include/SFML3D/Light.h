#ifndef LIGHT_H
#define LIGHT_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

namespace sf3d
{
    // Light
    class Light
    {
    protected:
        GLint _index;
        sf::Color _ambient_color;
        sf::Color _diffuse_color;
        sf::Color _specular_color;

    public:
        Light(GLint index, sf::Color ambient = sf::Color::White, sf::Color diffuse = sf::Color::White, sf::Color specular = sf::Color::White);

        void setAmbientColor(sf::Color ambient);
        void setDiffuseColor(sf::Color diffuse);
        void setSpecularColor(sf::Color specular);
    };

    // Sun
    class SunLight : public Light
    {
    private:
        sf::Vector3f _direction;

    public:
        SunLight(GLint index, sf::Vector3f direction = {0.5, -0.5, 0.5}, sf::Color ambient = sf::Color::White, sf::Color diffuse = sf::Color::White, sf::Color specular = sf::Color::White);

        void setDirection(sf::Vector3f direction);
    };

    //
    class PointLight : public Light
    {
    private:
        sf::Vector3f _position;
        float _constant_attenuation = 1.0;
        float _linear_attenuation = 0.0;
        float _quadratic_attenuation = 0.0;

    public:
        PointLight(GLint index, sf::Vector3f position = {0.0, 0.0, 0.0}, float constant = 1.0, float linear = 0.0, float quadratic = 0.0, sf::Color ambient = sf::Color::White, sf::Color diffuse = sf::Color::White, sf::Color specular = sf::Color::White);

        void setPosition(sf::Vector3f position);
        void setAttenuation(float constant, float linear, float quadratic);

    };
}

#endif // LIGHT_H
