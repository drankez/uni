/********************************************************************
 * FILE : object3D.h
 * 
 * This class is pure virtual. It only provides the specification for
 * 3D primitives, and in particular the ability to be intersected with
 * a ray via the virtual method:
 * 
 *    virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;
 * 
 * Since this method is pure virtual for the Object3D class, the 
 * prototype in the header includes '= 0;'. Subclasses derived from 
 * Object3D must implement this routine (see description below). For 
 * this assignment, an Object3D will store its color as a Vec3f. Later
 * in the semester, we will instead store a pointer to more complex 
 * materials. For now, your Object3D class must have:
 * 
 * - a default costructor and destructor
 * - a color field, and
 * - a pure virtual intersection method
 ********************************************************************/

#ifndef OBJECT3D_H_
#define OBJECT3D_H_
 
#include "supporting-files/ray.h"
#include "supporting-files/hit.h"
 
class Object3D {

public:

    // Constructor y destructor
    Object3D();
    ~Object3D();
    
    // Getters and Setters
    Vec3f getColor();
    void setColor(float r, float g, float b);
    
    // Metodos
    virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;

private:

    // Propiedades
    Vec3f color;
};

#endif