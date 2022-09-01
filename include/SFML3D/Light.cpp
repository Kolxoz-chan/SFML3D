#include "Light.h"

namespace sf3d
{
    Light::Light(GLint index, sf::Color ambient, sf::Color diffuse, sf::Color specular)
    {
        glEnable(index);
        _index = index;

        setAmbientColor(ambient);
        setDiffuseColor(diffuse);
        setSpecularColor(specular);
    }

    void Light::setAmbientColor(sf::Color ambient)
    {
        _ambient_color = ambient;

        GLfloat value[] = {ambient.r/255.f, ambient.g/255.f, ambient.b/255.f, ambient.a/255.f};
        glLightfv(_index, GL_AMBIENT, value);
    }

    void Light::setDiffuseColor(sf::Color diffuse)
    {
        _diffuse_color = diffuse;

        GLfloat value[] = {diffuse.r/255.f, diffuse.g/255.f, diffuse.b/255.f, diffuse.a/255.f};
        glLightfv(_index, GL_DIFFUSE, value);
    }

    void Light::setSpecularColor(sf::Color specular)
    {
        _specular_color = specular;

        GLfloat value[] = {specular.r/255.f, specular.g/255.f, specular.b/255.f, specular.a/255.f};
        glLightfv(_index, GL_SPECULAR, value);
    }

    // --------------------------------------------------------------------------------------------------- //

    SunLight::SunLight(GLint index, sf::Vector3f direction, sf::Color ambient, sf::Color diffuse, sf::Color specular) : Light(index, ambient, diffuse, specular)
    {
        setDirection(direction);
    }

    void SunLight::setDirection(sf::Vector3f direction)
    {
        _direction = direction;

        GLfloat value[] = {_direction.x, _direction.y, _direction.z, 0.0};
        glLightfv(_index, GL_POSITION, value);
    }

    // ---------------------------------------------------------------------------------------------------- //

    PointLight::PointLight(GLint index, sf::Vector3f position, float constant, float linear, float quadratic, sf::Color ambient, sf::Color diffuse, sf::Color specular) : Light(index, ambient, diffuse, specular)
    {
        setPosition(position);
        setAttenuation(constant, linear, quadratic);
    }

    void PointLight::setPosition(sf::Vector3f position)
    {
        _position = position;

        GLfloat value[] = {position.x, position.y, position.z, 1.0};
        glLightfv(_index, GL_POSITION, value);
    }

    void PointLight::setAttenuation(float constant, float linear, float quadratic)
    {
        _constant_attenuation = constant;
        _linear_attenuation = linear;
        _quadratic_attenuation = quadratic;

        glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, _constant_attenuation);
        glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, _linear_attenuation);
        glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, _quadratic_attenuation);
    }
}
