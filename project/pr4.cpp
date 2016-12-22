/**
 * @file    pr4.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include <cstdlib>

#include "igvInterfaz.h"

// Objeto que contiene la configuraci—n y la interacci—n con la ventana de visualizaci—n
igvInterfaz interfaz;

int main (int argc, char** argv) {
  
  // Inicializamos la ventana de visualizaci—n
  interfaz.configurarEntorno(argc,argv,         // Par‡metros del main
                             700, 700,          // Tama–o de la ventana
                             300, 100,          // Posici—n de la ventana
                             "El Sistema Solar" // T’tulo de la ventana
                             );
  
  // Establece los callbacks para la gesti—n de los eventos
  interfaz.initCallbacks();
  
  // Inicia el bucle de visualizaci—n de OpenGL
  glutMainLoop();
  
  return(0);
}


