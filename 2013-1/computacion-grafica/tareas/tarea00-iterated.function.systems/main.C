#include <cstring>
#include <fstream>
#include "ifs.h"
#include "supporting-files/matrix.h"
#include "supporting-files/image.h"

void leer_matriz(ifstream &source, float *v);

int main(int argc, char **argv) {

    /*************************************************************************
     * Código para parsear los datos ingresados por linea de comandos.
     *************************************************************************/
    char *input_file;
    int   width;
    int   height;
    char *output_file;
    float depth_min;
    float depth_max;
    char *depth_file;
    int   points;
    int iters;

    // Ejemplos de comandos de invocación:
    // raycast -input input.txt -size 100 100 -output output.tga
    // raycast -input input.txt -size 100 100 -depth 5.5 8.8 output.tga
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i],"-input")) {
            i++; assert (i < argc); 
            input_file = argv[i];
        } else if (!strcmp(argv[i],"-points")) {
            i++; assert (i<argc);
            points = atoi(argv[i]);
        } else if (!strcmp(argv[i],"-iters")) {
            i++; assert (i<argc);
            iters = atoi(argv[i]);
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
            printf ("Hay un error en la invocacion %d: '%s'\n",i,argv[i]);
            assert(0);
        }
    }

    /*************************************************************************
     * El siguiente código tiene como objetivo llenar las matrices m[i], 
     * ademas de llenar el arreglo 'probs' de probabilidades y transformar las
     * probabilidades absolutas a probabilidades acumuladas.
     *************************************************************************/
    int n;                          // Numero de transformaciones afines.
    float *v = new float[16];       // Vector temporal para crear la matriz.
    float *probs = new float[n];    // Probabilidad de hacer una transformacion
    ifstream source;

    source.open(input_file, ios_base::in);  // Lee el archivo dado en "-input".
    source >> n;                            // Lee el primer numero del archivo
    Matrix *m = new Matrix[n];              // Crea un array de 'n' matrices.

    float acum = 0;                 // La probabilidad acumulada.
    for (int i = 0; i < n; ++i) {
        source >> probs[i];         // Lee la probabilidad de transformacion.
        acum += probs[i];           // Acumula
        probs[i] = acum;            // Cambia la prob. absoluta por acumulada.
        leer_matriz(source, v);     // Lee y guarda la matriz linealmente en v
        m[i] = *(new Matrix(v));    // Crea la matriz basado en 'v'.
    }

    /*************************************************************************
     * MAIN
     *************************************************************************/
    IFS *ifs = new IFS();
    Image *img = new Image(width, height);
    ifs->inicializarIFS(n, m);
    ifs->render(img, points, iters, output_file, probs);
}

/*****************************************************************************
 * lee numeros de un archivo de entrada y los guarda en el arreglo lineal 'v'
 *****************************************************************************/
void leer_matriz(ifstream &source, float *v) {
    for (int j = 0; j < 16; ++j) {      // las matrices son de 4x4.
        if( (j+1)%4 == 0 || j >= 12 ) { // la cuarta columna y cuarta fila ...
            v[j] = 0;                   // de la matriz se igualan a cero.
        } else {
            source >> v[j];             // se lee un numero y se guarda en 'v'.
        }
    }
}