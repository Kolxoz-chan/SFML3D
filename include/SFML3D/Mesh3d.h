#ifndef MESH3D_H
#define MESH3D_H

#define _USE_MATH_DEFINES


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <SFML3D/Polygon.h>

#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>

namespace sf3d
{
    // Base mode ----------------------------------------------------------------- //
    class Mesh3D : public sf::Drawable
    {
    protected:
        sf::Vector3f _position, _rotation, _scale = sf::Vector3f(1, 1, 1);
        std::vector<sf3d::Polygon> _polygons;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        Mesh3D();

        void setPosition(sf::Vector3f value);
        void setRotation(sf::Vector3f value);
        void setScale(sf::Vector3f value);

        void move(sf::Vector3f value);
        void rotate(sf::Vector3f value);
        void scale(sf::Vector3f value);

        void addPolygon(const Polygon& obj);

        bool load(const std::string& path);
    };

    // Plane -------------------------------------------------------------------- //
    class PlaneMesh : public Mesh3D
    {
    public:
        PlaneMesh(float width = 1.0, float height = 1.0);
    };

    // Box ---------------------------------------------------------------------- //
    class BoxMesh : public Mesh3D
    {
    public:
        BoxMesh(float width = 1.0, float height = 1.0, float depth = 1.0);
    };

    // Cylinder ----------------------------------------------------------------- //
    class CylinderMesh : public Mesh3D
    {
    public:
        CylinderMesh(int angles_count = 5, float radius = 0.5, float height = 1.0);
    };

    // Sphere ------------------------------------------------------------------- //
    class SphereMesh : public Mesh3D
    {
    public:
        SphereMesh(float radius = 0.5, int segments = 10, int rings = 10);


    };
}

#endif // MESH3D_H
