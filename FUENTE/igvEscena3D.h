/**
 * @file    igvEscena3D.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GLUT/glut.h>
#include <vector>

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
  
  tVector3 posFoco1;                                                                      // Posici—n del foco1 dentro de la escena
  tVector3 posFoco2;                                                                      // Posici—n del foco2 dentro de la escena
  tVector3 dirFoco;                                                                       // Direcci—n de los dos focos
  
public:
  int seleccion;                                                                          // Atributo pœblico para la seleccion de objetos
  
  igvEscena3D();                                                                          // Constructor
  ~igvEscena3D();                                                                         // Destructor
  
  void visualizar(Camara pos, bool start);                                                // MŽtodo donde se dibuja la escena
  
  void setEjes(bool _ejes)   { ejes = _ejes; } ;                                          // Pinta los ejes
  bool getEjes()             { return ejes; } ;                                           // Devuelve si los ejes est‡n pintados o no
};

#endif
