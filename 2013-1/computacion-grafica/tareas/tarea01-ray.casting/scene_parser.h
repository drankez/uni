#ifndef _SceneParser_H_
#define _SceneParser_H_

#include "vectors.h"
#include "object3d.h"
#include "sphere.h"
#include "group.h"
#include "camera.h"
#include "orthocamera.h"

#define MAX_PARSER_TOKEN_LENGTH 100

// ====================================================================
// ====================================================================

class SceneParser {

public:

  // CONSTRUCTORS, DESTRUCTOR & INITIALIZE
  SceneParser();
  SceneParser(const char *filename);
  ~SceneParser();

  // ACCESSORS
  Group* getGroup() { return group; }
  Camera* getCamera() { return camera; }
  Vec3f getBackgroundColor() { return background_color; }
  int readInt();
  float readFloat();
  Vec3f readVec3f();
  Object3D* parseObject(char *token);

private:

  // HELPER FUNCTIONS
  void initialize();
  int getToken(char token[MAX_PARSER_TOKEN_LENGTH]);
  void parseFile();
  Group* parseGroup();
  Camera* parseOrthographicCamera();
  void parseBackground();
  void parseMaterial();
  Sphere* parseSphere();
  
  // REPRESENTATION
  Group *group;
  Camera *camera;
  Vec3f background_color;

  Vec3f current_object_color;
  FILE *file;

};

// ====================================================================
// ====================================================================

#endif
