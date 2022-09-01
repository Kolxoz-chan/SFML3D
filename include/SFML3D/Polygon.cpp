#include "Polygon.h"

namespace sf3d
{
    Polygon::Polygon(const std::vector<sf::Vector3f>& vertexes, const std::vector<sf::Vector3f>& normals, const std::vector<sf::Vector2f>& tex_coords)
    {
        _vertexes = vertexes;
        _normals = normals;
        _tex_coords = tex_coords;
    }

    void Polygon::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        glBegin(GL_POLYGON);

        if(_material)
        {
            _material->apply();
        }

        for(int i=0; i<_vertexes.size(); i++)
        {
            sf::Vector3f point = _vertexes[i];
            sf::Vector3f normal = _normals[i];
            sf::Vector2f coord = _tex_coords[i];

            glNormal3f(normal.x, normal.y, normal.z);
            glTexCoord2f(coord.x, coord.y);
            glVertex3f(point.x, point.y, point.z);
        }

        glEnd();
    }

    void Polygon::addPoint(sf::Vector3f vertex, sf::Vector3f normal, sf::Vector2f tex_coord)
    {
        _vertexes.push_back(vertex);
        _normals.push_back(normal);
        _tex_coords.push_back(tex_coord);
    }
}
