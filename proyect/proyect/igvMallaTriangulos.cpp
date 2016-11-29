#include <cstdlib>
#include <stdio.h>
#include <math.h>

#include "igvMallaTriangulos.h"

#define PI 3.14159

// Metodos constructores 

igvMallaTriangulos::igvMallaTriangulos(float r, int div_u, int div_v) {
  num_vertices = (div_u + 1) * (div_v + 1);
	vertices = new float[num_vertices * 3];
	normales = new float[num_vertices * 3];

	num_triangulos = (div_u * div_v) * 2;
	triangulos = new unsigned int [num_triangulos *3];

	long int cont_vert = 0;
	for (int i = 0; i < (div_u + 1); i++){
		float u = i * (1.0 / div_u);
		for (int j = 0; j < (div_v + 1); j++){
			float v = j * (1.0 / div_v);
			vertices[cont_vert]   = cos(-0.5*PI + PI*v) * sin(u*2*PI) * r;
			normales[cont_vert]   = vertices[cont_vert] / r;
			vertices[cont_vert+1] = sin(-0.5*PI + PI*v) * r;
			normales[cont_vert+1] = vertices[cont_vert+1] / r;
			vertices[cont_vert+2] = cos(-0.5*PI + PI*v) * cos(u*2*PI) * r;
			normales[cont_vert+2] = vertices[cont_vert+2] / r;
			cont_vert+=3;
		}
	}

	long int cont_tri = 0;
	for (int i = 0; i < (div_u); i++) {
		for (int j = 0; j < (div_v); j++) {
			triangulos[cont_tri] =   j       + i       * (div_v + 1);
			triangulos[cont_tri+1] = (j + 1) + i       * (div_v + 1);
			triangulos[cont_tri+2] = j       + (i + 1) * (div_v + 1);
			cont_tri+=3;

			triangulos[cont_tri] =   j       + (i + 1) * (div_v + 1);
			triangulos[cont_tri+1] = (j + 1) + i       * (div_v + 1);
			triangulos[cont_tri+2] = (j + 1) + (i + 1) * (div_v + 1);
			cont_tri+=3;
		}
	}
}

igvMallaTriangulos::~igvMallaTriangulos() {
	delete[] vertices;
	delete[] triangulos;
	if (normales) delete[] normales;
	if (coor_tex) delete[] coor_tex;
}


// Metodos publicos 

void igvMallaTriangulos::visualizar(void) {
	glShadeModel(GL_SMOOTH);

	glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,vertices);
	glEnableClientState(GL_NORMAL_ARRAY);
  glNormalPointer(GL_FLOAT,0,normales);

	// A–adir aquí la carga de las coordenadas de textura
  

	glDrawElements(GL_TRIANGLES,num_triangulos * 3,GL_UNSIGNED_INT,triangulos);
  glDisableClientState(GL_VERTEX_ARRAY);

}

