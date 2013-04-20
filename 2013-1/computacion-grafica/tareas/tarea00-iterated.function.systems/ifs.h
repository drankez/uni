#ifndef IFS_H
#define IFS_H

#include "supporting-files/matrix.h"
#include "supporting-files/image.h"

class IFS {
private:
	int n;		// numero de transformaciones

public:
	IFS();
	~IFS();
	void inicializarIFS(int nro, Matrix *mat);
	void render(Image *img, int nro_ptos, int nro_its, char *output_file, float *probs);
	int getN();
	Matrix *m;
};
#endif