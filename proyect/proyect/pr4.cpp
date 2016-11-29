#include <cstdlib>
#include <math.h>
#include <mach/mach_time.h>

#include "igvInterfaz.h"

// Objetos globales
// objeto que contiene la configuración y la interacción con la ventana de visualización
igvInterfaz interfaz;




int main (int argc, char** argv) {
  // inicializa la ventana de visualización
  interfaz.configura_entorno(argc,argv,
                             500, 500,
                             (glutGet(GLUT_SCREEN_WIDTH))/2,
                             (glutGet(GLUT_SCREEN_HEIGHT))/2,
                             "El Sistema Solar" // título de la ventana
                             );
  
  // establece las funciones callbacks para la gestión de los eventos
  interfaz.inicializa_callbacks();
  
  // inicia el bucle de visualización de OpenGL
  interfaz.inicia_bucle_visualizacion();
  
  return(0);
}


