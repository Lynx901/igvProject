#ifndef __IGVINTERFAZ
#define __IGVINTERFAZ

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <string>

#include "igvEscena3D.h"

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Clase igvInterfaz                                                                       **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

typedef enum {
  IGV_VISUALIZAR,
  IGV_SELECCIONAR
} modoInterfaz;

class igvInterfaz {
protected:
  igvEscena3D escena;                                                                     // Escena que se visualiza en la ventana
  
  modoInterfaz modo;
  bool pulsado;
  int objetoSeleccionado;
  
  
public:
  float cursorX;
  float cursorY;
  int anchoVentana;                                                                       // Ancho inicial de la ventana de visualizaci—n
  int altoVentana;                                                                        // Alto inicial de la ventana de visualizaci—n
  
  
  igvInterfaz();                                                                          // Constructor
  ~igvInterfaz();                                                                         // Destructor
  
  // Callbacks de eventos
  static void setTeclas(unsigned char key, int x, int y);                                 // Controla los eventos del teclado
  static void setTeclasUp(unsigned char key, int x, int y);                               // Controla los eventos del teclado
  static void setTeclasEspeciales(int key, int x, int y);                                 // Controla los eventos del teclado (especiales)
  
  static void setReshape(int w, int h);                                                   // Define el viewport
  static void setDisplay();                                                               // Define la c‡mara y visualiza la escena
  
  static void movimientoRaton(int x, int yes);                                            // Controla el desplazamiento del rat—n
  static void pulsacionRaton(GLint boton,GLint estado,GLint x,GLint y);                   // Controla los botones del rat—n
  
  
  // MŽtodos
  void configurarEntorno(int argc, char** argv,                                           // Par‡metros del main
                         int ancho, int alto,                                             // Ancho y alto de la ventana de visualizaci—n
                         int _pos_X, int _pos_Y,                                          // Posicion inicial de la ventana
                         std::string _titulo);                                            // T’tulo de la ventana de visualizaci—n
  
  void initCallbacks();                                                                   // Inicializa todos los callbacks
  
  void initSeleccion(int TAMANO_LISTA_IMPACTOS, GLuint *impactos);
  void endSeleccion(int TAMANO_LISTA_IMPACTOS, GLuint *impactos);
  
};

#endif











