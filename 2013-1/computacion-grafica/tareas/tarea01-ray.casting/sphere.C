/********************************************************************
 * FILE : sphere.C
 * 
 * Sphere is a subclass of Object3D that additionally stores a center 
 * point and a radius. For this assignment, the Sphere constructor 
 * will be given the center, radius, and color. The Sphere class 
 * implements the virtual intersect method mentioned above (but 
 * without the '=0;'):
 * 
 *      virtual bool intersect(const Ray &r, Hit &h, float tmin);
 * 
 * With the intersect routine, we are looking for the closest 
 * intersection along a Ray, parameterized by t. tmin is used to 
 * restrict the range of intersection.
 * 
 * If an intersection is found such that t >= tmin and t is less than 
 * the value of the intersection currenly stored in the Hit data
 * structure, Hit is updated as necessary. Note that if the new 
 * intersection is closer than the previous one, both t and color must
 * be modified.
 * 
 * For an orthographic camera, rays always start at infinity, so tmin 
 * will just be set to a large negative value. However, in the next 
 * assignment you will implement a perspective camera and it will be 
 * important that yout intersection routine verifies that t >= tmin.
 * tmin is not modified by the intersection routine.
 ********************************************************************/

#include <cmath>
#include <iostream>

#include "sphere.h"
#include "vectors.h"
#include "hit.h"
#include "ray.h"

using namespace std;

// Constructor
Sphere::Sphere(Vec3f &c, float r, Vec3f &co) {
    setColor(co.r(), co.g(), co.b());
    center = c;
    radius = r;
}

// Destructor
Sphere::~Sphere() {}

// Getters and Setters
Vec3f Sphere::getCenter() const { return center; }
void Sphere::setCenter(const Vec3f &c) { center = c; }
float Sphere::getRadius() const { return radius; }
void Sphere::setRadius(float r) { radius = r; }


/********************************************************************
 * MEMBER METHOD : intersect
 *
 * Verifica si el rayo 'r' intersecta (true) o no (false) a esta
 * esfera. La determinacion de si hay interseccion se basa en el 
 * enfoque geometrico.
 ********************************************************************/
bool Sphere::intersect(const Ray &r, Hit &h, float tmin) {
    bool ans = false;
    bool inside = false;
    float t = -1;
    
    const Vec3f orig = r.getOrigin();
    Vec3f or_c = center - orig;
    float tp = or_c.Dot3(r.getDirection());
    if (tp < 0) {
        return false;
    }
    float d2 = or_c.Dot3(or_c) - tp*tp;
    if (d2 > radius*radius) {
        return false;
    }
    float t1 = (float) sqrt(radius*radius - d2);
    if ( or_c.Length() < radius ) {
        inside = true;
    }
    if (inside) {
        t = tp + t1;
    } else {
        t = tp - t1;
    }
    if (t < tmin || t > h.getT()) {
        return false;
    }
    Vec3f normal = r.pointAtParameter(t) - center;
    normal.Normalize();
    h.set(t, NULL, normal, r);
    h.setColor(getColor());
    return true;
}