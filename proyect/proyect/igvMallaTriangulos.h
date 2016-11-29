#ifndef __IGVMALLATRIANGULOS
#define __IGVMALLATRIANGULOS

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
class igvMallaTriangulos {
	protected:
		// Atributos

		long int num_vertices; // número de vértices de la malla de triángulos
		float *vertices; // array con las (num_vertices * 3) coordenadas de los vértices
		float *normales; // array con las (num_vertices * 3) coordenadas de la normal a cada vértice (sólo para la generación de la esfera)

		float *coor_tex; // array con las (num_vertices * 2) coordenadas de textura para cada vértice (sólo para la generación de la esfera)

		long int num_triangulos; // número de triángulos de la malla de triángulos
		unsigned int *triangulos; // array con los (num_triangulos * 3) índices a los vértices de cada triángulo

		// Apartado G: Añadir aquí los atributos con los ángulos de rotación en X, Y y Z.

	public:
		// Constructor y destructor

		// genera una esfera centrada en el origen de radio r y con div_u divisiones en u y div_v divisiones en v
		igvMallaTriangulos(float r, int div_u, int div_v);                                                  

		~igvMallaTriangulos();

		// Métodos
		// método con las llamadas OpenGL para visualizar la malla de triángulos
    void visualizar();

};

#endif
