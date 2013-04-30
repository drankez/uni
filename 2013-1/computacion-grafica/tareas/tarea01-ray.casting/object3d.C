/********************************************************************
 * FILE : object3D.C
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
 
#include "object3d.h"
#include "supporting-files/vectors.h"

// Constructor
Object3D::Object3D() {
    color = Vec3f(1, 1, 1); // Color por default: blanco
}

// Destructor
Object3D::~Object3D() {}

// Getter
Vec3f Object3D::getColor() {
    return color;
}

// Setter
void Object3D::setColor(float r, float g, float b) {
    color = Vec3f(r, g, b);
}