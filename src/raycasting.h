#ifndef RAYCASTING_H
#define RAYCASTING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double x, y, z;
} Vec3;

typedef struct {
    Vec3 center;
    double radius;
} Sphere;

Vec3 subtract(Vec3 a, Vec3 b);
double dot(Vec3 a, Vec3 b);
int intersect_ray_sphere(Vec3 origin, Vec3 direction, Sphere sphere, double *t);
void generate_ray_casting(int width, int height, Sphere* sphere, int* output);

#ifdef __cplusplus
}
#endif

#endif // RAYCASTING_H
