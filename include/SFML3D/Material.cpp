#include "Material.h"

namespace sf3d
{
    Material::Material(sf::Color ambient, sf::Color diffuse, sf::Color specular, sf::Color emission, float shininess)
    {
        _ambient_color = ambient;
        _diffuse_color = diffuse;
        _specular_color = specular;
        _emission_color = emission;
        _shininess = shininess;
    }

    void Material::apply() const
    {
        GLfloat ambient[] = {_ambient_color.r / 255.f, _ambient_color.g / 255.f, _ambient_color.b / 255.f, _ambient_color.a / 255.f};
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);

        GLfloat diffuse[] = {_diffuse_color.r / 255.f, _diffuse_color.g / 255.f, _diffuse_color.b / 255.f, _diffuse_color.a / 255.f};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

        GLfloat specular[] = {_specular_color.r / 255.f, _specular_color.g / 255.f, _specular_color.b / 255.f, _specular_color.a / 255.f};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, specular);

        GLfloat emission[] = {_emission_color.r / 255.f, _emission_color.g / 255.f, _emission_color.b / 255.f, _emission_color.a / 255.f};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, emission);

        glMaterialf(GL_FRONT, GL_SHININESS, 128/_shininess);
    }
}
