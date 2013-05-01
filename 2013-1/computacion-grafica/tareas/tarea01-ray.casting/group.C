/*******************************************************************
 * FILE : group.C
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

#include "group.h"
#include "object3d.h"
#include "ray.h"
#include "hit.h"
 
// Constructor
Group::Group(int _n) {
    n = _n;
    arr = new Object3D*[n];
}

//Destructor
Group::~Group() {
    delete[] arr;
}

// Getters and Setters
int Group::getN() { return n; }

//Methods

/********************************************************************
 * FUNCTION : addObject
 ********************************************************************/
void Group::addObject(int index, Object3D *obj) {
    arr[index] = obj;
}

/********************************************************************
 * FUNCTION : intersect
 ********************************************************************/
bool Group::intersect(const Ray &r, Hit &h, float tmin) {
    bool ans = false;
    for (int i=0; i<n; i++) {
        ans = ans || arr[i]->intersect(r, h, tmin);
    }
    return ans;
}