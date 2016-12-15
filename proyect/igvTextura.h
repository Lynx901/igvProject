#ifndef __IGVTEXTURA
#define __IGVTEXTURA

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>

#include "bmp.h"

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Clase igvEscena3D                                                                       **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

class igvTextura {
public:
		igvTextura();                                                                         // Textura ajedrez de 64 x 64 texeles
		igvTextura(char *fichero);                                                            // Textura cargada desde un fichero BMP
		~igvTextura();                                                                        // Destructor

		void aplicar(void);
  
protected:
		unsigned int idTextura;                                                               // identificador de la textura
		unsigned int alto;                                                                    // alto de la textura
    unsigned int ancho;                                                                   // ancho de la textura
};

#endif

