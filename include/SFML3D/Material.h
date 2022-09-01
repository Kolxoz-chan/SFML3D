#ifndef MATERIAL_H
#define MATERIAL_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

namespace sf3d
{
    class Material
    {
    private:
        sf::Color _ambient_color;
        sf::Color _diffuse_color;
        sf::Color _specular_color;
        sf::Color _emission_color;
        float _shininess;

    public:
        Material(sf::Color ambient = sf::Color::White, sf::Color diffuse = sf::Color::White, sf::Color specular = sf::Color::White, sf::Color emission = sf::Color::White, float shininess = 0.0);

        void apply() const;
    };
}

#endif // MATERIAL_H
