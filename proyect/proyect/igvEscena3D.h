#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "igvFuenteLuz.h"
#include "igvMallaTriangulos.h"
#include "Objeto.h"

class igvEscena3D {
protected:
  // Atributos
  
  bool ejes;
  
public:
  // atributos p�blicos
  igvMallaTriangulos *malla; // malla de tri�ngulos asociada a la escena
  Objeto nosotros;
  
  
  // Constructores por defecto y destructor
  igvEscena3D();
  ~igvEscena3D();
  
  // Metodos est�ticos
  
  // M�todos
  // m�todo con las llamadas OpenGL para visualizar la escena
  void visualizar();
  
  void set_ejes(bool _ejes)   { ejes = _ejes; } ;
  bool get_ejes()             { return ejes; } ;

};

#endif
