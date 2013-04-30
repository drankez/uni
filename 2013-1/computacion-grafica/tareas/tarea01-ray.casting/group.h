/*******************************************************************
 * FILE : group.h
 *
 * A Group is a special subclass of Object3D that gathers multiple 3D 
 * primitives. For example, it will be used to store the entire 3D 
 * scene. It stores an array of pointers to Object3D instances. The 
 * intersect method of Group loops through all these instances, 
 * calling their intersection methods. The Group constructor should 
 * take as input the number of objects under the group. The group 
 * should include a method to add the objects:
 *
 *          void addObject(int index, Object3D *obj)
 *******************************************************************/

#ifndef GROUP_H_
#define GROUP_H_

#include <vector>
#include "object3d.h"
#include "supporting-files/ray.h"
#include "supporting-files/hit.h"

using std::vector;

class Group : public Object3D {

public:

    // Constructor y Destructor
    Group(int _n);
    ~Group();
    
    // Getters and Setters
    int getN() { return n; }
    
    // Methods
    void addObject(int index, Object3D *obj)
    virtual bool intersect(const Ray &r, Hit &h, float tmin);
    
    // Public members
    vector< *Object3D > arr;
    
private:
    int n;
};

#endif GROUP_H_