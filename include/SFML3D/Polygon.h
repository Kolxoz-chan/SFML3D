#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <SFML3D/Material.h>

#include <vector>

namespace sf3d
{
    class Polygon : public sf::Drawable
    {
    private:
        std::vector<sf::Vector3f> _vertexes, _normals;
        std::vector<sf::Vector2f> _tex_coords;
        Material* _material;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        Polygon() = default;
        Polygon(const std::vector<sf::Vector3f>& vertexes, const std::vector<sf::Vector3f>& normals, const std::vector<sf::Vector2f>& tex_coords);

        void addPoint(sf::Vector3f vertex, sf::Vector3f normal = {0.f, 0.f, 0.f}, sf::Vector2f tex_coord = {0.f, 0.f});
    };
}

#endif // POLYGON_H
