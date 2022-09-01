#include "Mesh3d.h"

namespace sf3d
{
    Mesh3D::Mesh3D()
    {

    }

    void Mesh3D::setPosition(sf::Vector3f value)
    {
        _position = value;
    }

    void Mesh3D::setRotation(sf::Vector3f value)
    {
        _rotation = value;
    }

    void Mesh3D::setScale(sf::Vector3f value)
    {
        _scale = value;
    }

    void Mesh3D::move(sf::Vector3f value)
    {
        _position += value;
    }

    void Mesh3D::rotate(sf::Vector3f value)
    {
        _rotation += value;
    }

    void Mesh3D::scale(sf::Vector3f value)
    {
        _scale += value;
    }

    void Mesh3D::addPolygon(const Polygon& obj)
    {
        _polygons.push_back(obj);
    }

    bool Mesh3D::load(const std::string& path)
    {
        std::ifstream file;
        file.open(path);

        if(file.is_open())
        {
            auto tokenize = [](std::string const &str, const char* delim, std::vector<std::string> &out)
            {
              out.clear();
              char *token = std::strtok(const_cast<char*>(str.c_str()), delim);
              while (token != nullptr)
              {
                  out.push_back(token);
                  token = std::strtok(nullptr, delim);
              }
            };

            // Arrays
            std::vector<sf::Vector3f> v;
            std::vector<sf::Vector2f> vt;
            std::vector<sf::Vector3f> vn;

            std::vector<std::string> info;
            std::vector<std::string> parts;
            std::string line;

            while(!file.eof())
            {
                std::getline(file, line);

                tokenize(line, " ", parts);

                if(!parts.empty())
                {
                    std::string token = parts[0];

                    if(token == "v")
                    {
                        v.push_back({std::stof(parts[1]), std::stof(parts[2]), std::stof(parts[3])});
                    }
                    else if(token == "vt")
                    {
                        vt.push_back({std::stof(parts[1]), std::stof(parts[2])});
                    }
                    else if(token == "vn")
                    {
                        vn.push_back({std::stof(parts[1]), std::stof(parts[2]), std::stof(parts[3])});
                    }
                    else if(token == "f")
                    {
                        for(int i=1; i<parts.size(); i++)
                        {
                            tokenize(parts[i], "/", info);
    /*
                            sf::Vector3f vertex = v[stoi(info[0]) - 1];
                            _buffer.push_back(vertex.x);
                            _buffer.push_back(vertex.y);
                            _buffer.push_back(vertex.z);

                            sf::Vector2f tex = vt[stoi(info[1]) - 1];
                            _tex_coords.push_back(tex.x);
                            _tex_coords.push_back(tex.y);

                            sf::Vector3f normal = vn[stoi(info[2]) - 1];
                            _normals.push_back(normal.x);
                            _normals.push_back(normal.y);
                            _normals.push_back(normal.z);
                            */
                        }
                    }
                }
            }
            file.close();

            return true;
        }

        return false;
    }

    void Mesh3D::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.setActive(true);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(_position.x, _position.y, _position.z);
        glRotatef(_rotation.x, 1, 0, 0);
        glRotatef(_rotation.y, 0, 1, 0);
        glRotatef(_rotation.z, 0, 0, 1);

        for(int i=0; i<_polygons.size(); i++)
        {
            target.draw(_polygons[i], states);
        }

        target.setActive(false);
    }

    PlaneMesh::PlaneMesh(float width, float height)
    {
        _buffer =
        {
            -width, 0, -height,
            width, 0, -height,
            width, 0, height,
            width, 0, height,
            -width, 0, height,
            -width, 0, -height
        };

        _normals =
        {
            0, 1, 0,
            0, 1, 0,
            0, 1, 0,
            0, 1, 0,
            0, 1, 0,
            0, 1, 0
        };
    }


    BoxMesh::BoxMesh(float w, float h, float d)
    {
        // Vertexes
        sf::Vector3f p1(-w, -h, -d);
        sf::Vector3f p2(w, -h, -d);
        sf::Vector3f p3(w, h, -d);
        sf::Vector3f p4(-w, h, -d);

        // Normals
        sf::Vector3f n_back(0.f, 0.f, -1.f);
        sf::Vector3f n_front(0.f, 0.f, 1.f);
        sf::Vector3f n_up(0.f, 1.f, 0.f);
        sf::Vector3f n_bottom(0.f, -1.f, 0.f);
        sf::Vector3f n_left(-1.f, 0.f, 0.f);
        sf::Vector3f n_right(1.f, 0.f, 0.f);

        // Tex coords
        sf::Vector2f t1(-w, -h);
        sf::Vector2f t2(w, -h);
        sf::Vector2f t3(w, h);
        sf::Vector2f t4(-w, h);


        addPolygon(Polygon({p1, p2, p3, p4}, {n_back, n_back, n_back, n_back}, ));

    }

    CylinderMesh::CylinderMesh(int angles_count, float radius, float height)
    {
        float len = 360 / angles_count;

        for(float i=0; i<360; i+=len)
        {
            float rad_1 = i * (M_PI/180);
            float rad_2 = (i + len) * (M_PI/180);

            sf::Vector2f p1 = {cos(rad_1) * radius, sin(rad_1) * radius};
            sf::Vector2f p2 = {cos(rad_2) * radius, sin(rad_2) * radius};

            auto points =
            {
                p1.x, -height/2, p1.y,
                p2.x, - height/2, p2.y,
                p2.x, height/2, p2.y,
                p2.x, height/2, p2.y,
                p1.x, height/2, p1.y,
                p1.x, -height/2, p1.y
            };

            _buffer.insert(_buffer.end(), points);

            sf::Vector3f normal = {p1.x/radius + p2.x/radius, 0.f, p1.y/radius + p2.y/radius};
            _normals.insert(_normals.end(),
            {
               normal.x, normal.y, normal.z,
               normal.x, normal.y, normal.z,
               normal.x, normal.y, normal.z,
               normal.x, normal.y, normal.z,
               normal.x, normal.y, normal.z,
               normal.x, normal.y, normal.z
            });

            // Bottom
            _buffer.insert(_buffer.end(),
            {
               p1.x, -height/2, p1.y,
               p2.x, -height/2, p2.y,
               0.f, -height/2, 0.f,
            });

            _normals.insert(_normals.end(),
            {
               0.f, -1.f, 0.f,
               0.f, -1.f, 0.f,
               0.f, -1.f, 0.f,
            });

            // Up
            _buffer.insert(_buffer.end(),
            {
               p1.x, height/2, p1.y,
               p2.x, height/2, p2.y,
               0.f, height/2, 0.f,
            });

            _normals.insert(_normals.end(),
            {
               0.f, 1.f, 0.f,
               0.f, 1.f, 0.f,
               0.f, 1.f, 0.f,
            });
        }
    }

    SphereMesh::SphereMesh(float radius, int segments, int rings)
    {
        float radians = (M_PI/180.f);
        float coef_v = (180.f / rings) * radians;
        float coef_h = (360.f / segments) * radians;

        for(int i=0; i<rings; i++)
        {
            float angle_v = i * coef_v;
            float y_axis = cos(angle_v) * radius;
            float cur_radius = sin(angle_v) * radius;

            float next_angle_v = (i+1) * coef_v;
            float next_y_axis = cos(next_angle_v) * radius;
            float next_radius = sin(next_angle_v) * radius;

            for(int j=0; j<segments; j++)
            {
                float angle_h = j * coef_h;
                float next_angle_h = (j+1) * coef_h;

                sf::Vector3f p1 = {sin(angle_h) * cur_radius, y_axis, cos(angle_h) * cur_radius};
                sf::Vector3f p2 = {sin(next_angle_h) * cur_radius, y_axis, cos(next_angle_h) * cur_radius};
                sf::Vector3f p3 = {sin(next_angle_h) * next_radius, next_y_axis, cos(next_angle_h) * next_radius};
                sf::Vector3f p4 = {sin(angle_h) * next_radius, next_y_axis, cos(angle_h) * next_radius};

                _buffer.insert(_buffer.end(),
                {
                   p1.x, p1.y, p1.z,
                   p2.x, p2.y, p2.z,
                   p3.x, p3.y, p3.z,
                   p3.x, p3.y, p3.z,
                   p4.x, p4.y, p4.z,
                   p1.x, p1.y, p1.z,
                });

                sf::Vector3f normal = p1 + p2 + p3 + p4;
                float sum = abs(normal.x + normal.y + normal.z);
                for(int i=0; i<6; i++)
                {
                    _normals.push_back(normal.x/sum);
                    _normals.push_back(normal.y/sum);
                    _normals.push_back(normal.z/sum);
                }
            }
        }
    }
}

