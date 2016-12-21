/**
 * @file    igvTextura.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

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

		void aplicar(void);                                                                   // Aplica la textura
  
protected:
		unsigned int idTextura;                                                               // Identificador de la textura
		unsigned int alto;                                                                    // Alto de la textura
    unsigned int ancho;                                                                   // Ancho de la textura
};

#endif

