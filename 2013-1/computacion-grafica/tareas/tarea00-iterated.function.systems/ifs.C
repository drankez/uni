#include "ifs.h"
#include "supporting-files/image.h"
#include "supporting-files/vectors.h"
#include "supporting-files/matrix.h"

inline float aleat() { return (float)rand()/(float)RAND_MAX; }

IFS::IFS() {
	this->n = 0;
	this->m = NULL;
}

IFS::~IFS() {
	delete this->m;
}

void IFS::inicializarIFS(int nro, Matrix *mat) {
	this->n = nro;
	this->m = mat;
}

void IFS::render(Image *img, int nro_ptos, int nro_its, char *output_file, float *probs) {
    for (int j = 0; j < nro_ptos; ++j) {
        // 'p' representa un punto aleatorio dentro del cuadrado de dimensiones
        // "width x height". Las dos primeras coordenadas son del plano del
        // cuadrado, mientras que el tercer parametro se establece a 'width/2' 
        // para que la traslacion sea consistente.
        Vec4f p(img->Width()*aleat(), img->Height()*aleat(), img->Width()/2, 1);
        int i = 0;
        for (int k = 0; k < nro_its; ++k) {
            // El siguiente 'for' tiene por finalidad generar un numero 
            // aleatorio no uniforme sino de acuerdo a las probabilidades dadas
            // en el arreglo 'probs'.
            float r = aleat();              // Aleatorio entre 0 y 1.
            for (int s = 0; s < n; ++s) {   // ¿Donde cae el r?
                if( r < probs[s] ){
                    i = s; break;
                }
            }
            // El algoritmo correria mas rapido si a cada transformacion se le
            // asigna la misma probabilidad. En ese caso eliminamos el 'for'
            // anterior y lo reemplazamos con una sola sentencia:
            // i = rand() % n   //genera un numero entero entre 0 y n-1.
            this->m[i].Transform(p);	// Transforma el punto 'p' de acuerdo a
            							// la matriz de transformacion m[i].
        }
        float x, y, z, w;       // Las cordenadas de 'p' luego de n ...  
        p.Get(x, y, z, w);      // transformaciones (solo importan x e y).
        Vec3f blanco(1, 1, 1);  // Color del punto a dibujarse en la imagen.
        
        // Guarda el punto en el buffer 'img'. Se hace una traslacion extra al
        // punto a dibujar "(x+width/4, y+height/4)" para evitar los problemas 
        // de desborde de la imagen.
        img->SetPixel(x+img->Width()/4, y+img->Height()/4, blanco);
    }
    img->SaveTGA(output_file);   //Guarda la imagen con formato TGA.
}

int IFS::getN() {
	return this->n;
}