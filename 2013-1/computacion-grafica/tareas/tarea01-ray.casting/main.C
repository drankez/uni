#include <cstring>
#include <iostream>

#include "scene_parser.h"
#include "image.h"
#include "ray.h"
#include "hit.h"
#include "vectors.h"
#include "orthocamera.h"

using namespace std;

int main(int argc, char **argv) {
    // ========================================================
    // ========================================================
    // Some sample code you might like to use for parsing 
    // command line arguments 

    char *input_file = NULL;
    int width = 100;
    int height = 100;
    char *output_file = NULL;
    float depth_min = 0;
    float depth_max = 1;
    char *depth_file = NULL;

    // sample command lines:
    // raycast -input input.txt -size 100 100 -output output.tga
    // raycast -input input.txt -size 100 100 -depth 5.5 8.8 output.tga

    for (int i = 1; i < argc; i++) {
      if (!strcmp(argv[i],"-input")) {
        i++; assert (i < argc); 
        input_file = argv[i];
      } else if (!strcmp(argv[i],"-size")) {
        i++; assert (i < argc); 
        width = atoi(argv[i]);
        i++; assert (i < argc); 
        height = atoi(argv[i]);
      } else if (!strcmp(argv[i],"-output")) {
        i++; assert (i < argc); 
        output_file = argv[i];
      } else if (!strcmp(argv[i],"-depth")) {
        i++; assert (i < argc); 
        depth_min = atof(argv[i]);
        i++; assert (i < argc); 
        depth_max = atof(argv[i]);
        i++; assert (i < argc); 
        depth_file = argv[i];
      } else {
        printf ("whoops error with command line argument %d: '%s'\n",i,argv[i]);
        assert(0);
      }
    }

    // ========================================================
    // ========================================================
    
    SceneParser parseador = SceneParser(input_file);
    Ray r;
    float tmin = -1000;
    
    Image img(width, height);
    Vec3f co(1, 1, 1);
    
    float sz = ((OrthographicCamera *)(parseador.getCamera()))->getSize();
    
    for (float i=-sz/2; i<sz/2; i+=0.05) {
        for (float j=-sz/2; j<sz/2; j+=0.05) {
            r = (parseador.getCamera())->generateRay(Vec2f(i,j));
            Hit h;
            h.setT(1000000);
            if ( (parseador.getGroup())->intersect(r, h, tmin) ) {
                img.SetPixel(((i+sz/2)/sz)*width,
                             ((j+sz/2)/sz)*height,
                             h.getColor());
            }
            img.SaveTGA(output_file);
        }
    }
}