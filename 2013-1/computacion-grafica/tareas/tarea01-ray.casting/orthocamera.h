/********************************************************************
 * FILE : orthocamera.h
 * 
 * Write both a pure virtual generic Camera class and an 
 * OrtographicCamera subclass. A camera must be able to generate a ray
 * for each screen-space coordinate, described as a Vec2f:
 *
 *      Ray generateRay(Vec2f point)
 *
 * The direction of the rays generated by an ortographic camera is 
 * always the same, but the origin varies.
 *
 * An ortographic camera is described by an orthonormal basis (one
 * point and three vectors) and an image size (one floating point).
 * The constructor takes as input the center of the image, the 
 * projection direction, an up vector, and the image size. The input 
 * projection direction might not be a unit vector and must be 
 * normalized. The input vector might not be a unit vector or 
 * perpendicular to the direction. It must be modified to be 
 * orthonormal to the direction. The third basis vector, the 
 * horizontal vector of the image plane, is deduced from the direction
 * and the up vector (hint: remember vector algebra and cross 
 * products). The origin of the rays generated by the camera for the 
 * screen coordinates, which vary from (0,0) -> (0,1), should bary 
 * from:
 *
 *          center - (size/2)up - (size/2)horizontal 
 *      to
 *          center + (size/2)up + (size/2)horizontal
 *
 * The camera does not know about screen resolution. Image resolution 
 * should be handled in your main loop. For non-square image ratios, 
 * just crop the screen coordinates accordingly.
 ********************************************************************/

#ifndef ORTO_H_
#define ORTO_H_

#include "camera.h"

class OrthographicCamera : public Camera {

public:

    // Constructor y Destructor
    OrthographicCamera(Vec3f &c, Vec3f &p, Vec3f &u, float sz);
    ~OrthographicCamera();
    
    // Getters and Setters
    Vec3f getCenter();
    void setCenter(Vec3f &c);
    Vec3f getProjection();
    void setProjection(Vec3f &p);
    Vec3f getUp();
    void setUp(Vec3f &u);
    Vec3f getHorizontal();
    void setHorizontal(Vec3f &h);
    float getSize();
    void setSize(float sz);
    
    // Methods
    virtual Ray generateRay(Vec2f point);

private:

    Vec3f center;
    Vec3f projection;
    Vec3f up;
    Vec3f horizontal;
    float size;
};

#endif