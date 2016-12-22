/**
 * @file    igvInterfaz.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

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
} modoInterfaz;                                                                           // Enum necesario para el atributo

class igvInterfaz {
protected:
  igvEscena3D escena;                                                                     // Escena que se visualiza en la ventana
  
  modoInterfaz  modo;                                                                     // Indica si se est‡ seleccionando algo o no
  bool          pulsado;                                                                  // Indica si se ha pulsado algo
  int           objetoSeleccionado;                                                       // Indica el objeto que se ha seleccionado
  
  bool          start;                                                                    // Indica si la ejecuci—n est‡ en modo "start"
  
public:
  float cursorX;
  float cursorY;
  int anchoVentana;                                                                       // Ancho inicial de la ventana de visualizaci—n
  int altoVentana;                                                                        // Alto inicial de la ventana de visualizaci—n
  int contador;                                                                           // Sirve para saber el estado del juego
  
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
  
  void initSeleccion(int TAMANO_LISTA_IMPACTOS, GLuint *impactos);                        // Inicia la selecci—n de objetos
  void endSeleccion(int TAMANO_LISTA_IMPACTOS, GLuint *impactos);                         // Termina la selecci—n de objetos
  
};

#endif











