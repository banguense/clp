#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "raycasting.h"

Vec3 subtract(Vec3 a, Vec3 b) {
    Vec3 result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

double dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int intersect_ray_sphere(Vec3 origin, Vec3 direction, Sphere sphere, double *t) {
    Vec3 oc = subtract(origin, sphere.center);
    double a = dot(direction, direction);
    double b = 2.0 * dot(oc, direction);
    double c = dot(oc, oc) - sphere.radius * sphere.radius;
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) {
        return 0;
    } else {
        *t = (-b - sqrt(discriminant)) / (2.0 * a);
        return 1;
    }
}

void generate_ray_casting(int width, int height, Sphere* sphere, int* output) {
    Vec3 origin = {0, 0, 0}; // Origem da câmera

    if (sphere == NULL || output == NULL) {
        fprintf(stderr, "generate_ray_casting: invalid arguments\n");
        return;
    }
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double u = (double)x / width;
            double v = (double)y / height;
            Vec3 direction = {u * 2 - 1, v * 2 - 1, -1}; // Direção do raio
            double t;
            if (intersect_ray_sphere(origin, direction, *sphere, &t)) {
                output[y * width + x] = 255; // Pixel branco se houver interseção
            } else {
                output[y * width + x] = 0; // Pixel preto se não houver interseção
            }
        }
    }
}
