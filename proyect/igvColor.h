#ifndef __IGVCOLOR
#define __IGVCOLOR

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

typedef enum {
	R,
	G,
	B,
	A
}rgba;

class igvColor {
protected:
		double color[4]; // componentes R, G, B, A del color

public:
		igvColor();
		~igvColor();

		igvColor(const double r, const double g, const double b);
		igvColor(const double r, const double g, const double b, const double a);
		igvColor(const igvColor& p);	//de copia

		double& operator[] ( const unsigned char idx );
		double operator[] (const unsigned char idx) const;

		void aplicar(void);
};

#endif

