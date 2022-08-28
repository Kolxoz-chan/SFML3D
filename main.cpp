#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include <SFML3D/Mesh3d.h>
#include <SFML3D/View3d.h>

using namespace sf;
using namespace std;

int main(int argc, char *argv[])
{
    RenderWindow window(VideoMode(1280, 720), "SFML3D", sf::Style::Default, sf::ContextSettings(24, 8, 3, 3, 3));
    window.setMouseCursorVisible(false);

    View3D view(window.getSize());

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);

    Vector2i pos = window.getPosition();
    Vector2u size = window.getSize();
    Vector2f center = {pos.x + size.x/2.f, pos.y + size.y/2.f};

    PlaneMesh floor({5, 5});
    floor.setColor(sf::Color(0, 255, 0));
    floor.setPosition({-2.5, -1, 0});

    BoxMesh box2({0.2, 0.2, 0.2});
    box2.setColor(sf::Color::Red);
    box2.setPosition({0, -0.8, -5});

    CylinderMesh obj(6, 0.3, 0.3);
    obj.setPosition({0, -0.8, -1});
    //obj.setRotation({30.f, 0.f, 0.f});
    obj.setColor(sf::Color(255, 165, 0));

    SphereMesh sphere(0.5, 16, 10);
    sphere.setPosition({0.f, 0.f, 2.f});
    sphere.setColor(Color::Red);

    Mesh3D mesh;
    cout << mesh.load("test.obj");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                view.setSize({event.size.width, event.size.height});
            }
        }

        // Mouse
        Vector2i center(window.getSize().x / 2, window.getSize().y / 2);
        Vector2i delta = Mouse::getPosition(window) - center;
        Mouse::setPosition(center, window);
        view.rotate({0.f, delta.x * 0.1f, 0.f});

        // Keyboard
        sf::Vector3f rotation = view.getRotation();
        float angle = rotation.y * (M_PI/180);

        float dz = cos(angle) * 0.002;
        float dx = sin(angle) * 0.002;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            view.move({-dx, 0, dz});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            view.move({dx, 0, -dz});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            view.move({dz, 0, dx});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            view.move({-dz, 0, -dx});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        box2.rotate({0, 0.1, 0});
        obj.rotate({0, -0.1, 0});
        sphere.rotate({0.1, 0, 0});

        glClearColor(150/255.f, 200/255.f, 216/255.f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        view.update();

        window.draw(box2);
        window.draw(floor);
        window.draw(sphere);
        window.draw(obj);

        window.display();
    }
    return 0;
}
