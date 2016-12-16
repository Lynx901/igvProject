#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Nave.h"
#include "Planeta.h"
#include "igvTextura.h"

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Clase igvEscena3D                                                                       **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

class igvEscena3D {
protected:
  bool ejes;                                                                              // Ejes X, Y, Z en la escena
  
public:
  igvEscena3D();                                                                          // Constructor
  ~igvEscena3D();                                                                         // Destructor
  
  void visualizar(tVector3 pos);                                                         // M�todo donde se dibuja la escena
  
  void setEjes(bool _ejes)   { ejes = _ejes; } ;                                          // Pinta los ejes
  bool getEjes()             { return ejes; } ;                                           // Devuelve si los ejes est�n pintados o no

};

#endif
