#include <cstdio>
#include <cstdlib>

// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

bool PointSphereCollision(glm::vec4 point, glm::vec4 sphere_center, float radius)
{
    float eq = pow((point.x - sphere_center.x), 2) + pow((point.y - sphere_center.y), 2) + pow((point.z - sphere_center.z), 2);
    return eq <= pow(radius, 2);
}

bool PointPlaneCollision(glm::vec4 point, glm::vec3 plane) {
    if (plane.x == -100) {
        if(plane.y == -100) {
            return point.z == plane.z;
        } else {
            return point.y == plane.y;
        }
    }
    if (plane.y == -100 && plane.z == -100) {
        return point.x == plane.x;
    }
    return true;
}

bool SphereSphereCollision(glm::vec4 sphere_center_1, float radius_1, glm::vec4 sphere_center_2, float radius_2) {
    if (sphere_center_1.x + sphere_center_2.x <= radius_1 + radius_2) {
        return false;
    }
    if (sphere_center_1.y + sphere_center_2.y <= radius_1 + radius_2) {
        return false;
    }
    if (sphere_center_1.z + sphere_center_2.z <= radius_1 + radius_2) {
        return false;
    }
    return true;
}
