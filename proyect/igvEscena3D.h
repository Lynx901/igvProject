#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Nave.h"
#include "Planeta.h"
#include "igvTextura.h"
#include "Camara.h"

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Clase igvEscena3D                                                                       **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

class igvEscena3D {
protected:
  bool ejes;                                                                              // Ejes X, Y, Z en la escena
  
  tVector3 posFoco1;
  tVector3 posFoco2;
  tVector3 dirFoco;
  
public:
  int seleccion;                                                                          // Atributo pœblico para la seleccion de objetos
  
  
  igvEscena3D();                                                                          // Constructor
  ~igvEscena3D();                                                                         // Destructor
  
  void visualizar(Camara pos, bool start);                                                // MŽtodo donde se dibuja la escena
  
  void setEjes(bool _ejes)   { ejes = _ejes; } ;                                          // Pinta los ejes
  bool getEjes()             { return ejes; } ;                                           // Devuelve si los ejes est‡n pintados o no

};

#endif
