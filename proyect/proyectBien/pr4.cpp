#include <cstdlib>
#include <math.h>
#include <mach/mach_time.h>

#include "igvInterfaz.h"

// Objetos globales
// objeto que contiene la configuración y la interacción con la ventana de visualización
igvInterfaz interfaz;




int main (int argc, char** argv) {
  // inicializa la ventana de visualización
  interfaz.configurarEntorno(argc,argv,
                             500, 500,
                             100,
                             100,
                             "El Sistema Solar" // título de la ventana
                             );
  
  // establece las funciones callbacks para la gestión de los eventos
  interfaz.inicializa_callbacks();
  
  // inicia el bucle de visualización de OpenGL
  glutMainLoop();
  
  return(0);
}


