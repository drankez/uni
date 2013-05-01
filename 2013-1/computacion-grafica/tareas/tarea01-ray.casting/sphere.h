/********************************************************************
 * FILE : sphere.h
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
 * the value of the intersection currenly stored in the Hit data s
 * tructure, Hit is updated as necessary. Note that if the new 
 * intersection is closer than the previous one, both t and color must
 * be modified.
 * 
 * For an orthographic camera, rays always start at infinity, so tmin 
 * will just be set to a large negative value. However, in the next 
 * assignment you will implement a perspective camera and it will be 
 * important that yout intersection routine verifies that t >= tmin.
 * tmin is not modified by the intersection routine.
 ********************************************************************/

#ifndef SPHERE_H_
#define SPHERE_H_

#include "object3d.h"
#include "vectors.h"
#include "hit.h"
#include "ray.h"

class Sphere : public Object3D {

public:

    // Constructores y Destructor
    Sphere(Vec3f &c, float r, Vec3f &co);
    ~Sphere();
    
    // Getters and Setters
    Vec3f getCenter() const;
    void setCenter(const Vec3f &c);
    float getRadius() const;
    void setRadius(float r);
    
    // Methods
    virtual bool intersect(const Ray &r, Hit &h, float tmin);

private:
    
    // Propiedades
    Vec3f center;
    float radius;
};

#endif