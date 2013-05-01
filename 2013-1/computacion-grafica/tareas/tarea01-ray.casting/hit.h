#ifndef _HIT_H
#define _HIT_H

#include "vectors.h"
#include "ray.h"

class Material;

// ====================================================================
// ====================================================================

class Hit {
  
public:

  // CONSTRUCTOR & DESTRUCTOR
  Hit() { material = NULL; }
  Hit(float _t, Material *m, Vec3f n) { 
    t = _t; material = m; normal = n; }
  Hit(const Hit &h) { 
    t = h.t; 
    material = h.material; 
    normal = h.normal; 
    intersectionPoint = h.intersectionPoint; }
  ~Hit() {}

  // ACCESSORS
  Vec3f getColor() { return color; };
  void setColor( Vec3f co ) { color = co; };
  float getT() const { return t; }
  void setT(float _t) { t = _t; }
  Material* getMaterial() const { return material; }
  Vec3f getNormal() const { return normal; }
  Vec3f getIntersectionPoint() const { return intersectionPoint; }
  
  // MODIFIER
  void set(float _t, Material *m, Vec3f n, const Ray &ray) {
    t = _t; material = m; normal = n; 
    intersectionPoint = ray.pointAtParameter(t); }

private: 

  // REPRESENTATION
  float t;
  Material *material;
  Vec3f normal;
  Vec3f intersectionPoint;
  Vec3f color;

};

inline ostream &operator<<(ostream &os, const Hit &h) {
  os << "Hit <" <<h.getT()<<", "<<h.getNormal()<<">";
  return os;
}
// ====================================================================
// ====================================================================

#endif
