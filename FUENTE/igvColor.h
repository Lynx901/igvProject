/**
 * @file    igvColor.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#ifndef __IGVCOLOR
#define __IGVCOLOR

#include <GLUT/glut.h>

typedef enum {
	R,
	G,
	B,
	A
}rgba;

class igvColor {
protected:
		double color[4];                                                                      // Componentes R, G, B, A del color

public:
		igvColor();
		~igvColor();

		igvColor(const double r, const double g, const double b);                             // Crea un color RGB
		igvColor(const double r, const double g, const double b, const double a);             // Crea un color RGBA
		igvColor(const igvColor& p);

		double& operator[] ( const unsigned char idx );
		double operator[] (const unsigned char idx) const;

		void aplicar(void);
};

#endif

