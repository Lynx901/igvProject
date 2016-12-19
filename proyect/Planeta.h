/**
 * @file    Planeta.h
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    15/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include <iostream>
#include "Objeto.h"

#ifndef Planeta_h
#define	Planeta_h

/****************************************************************************************/
/**                                                                                    **/
/**                           Clase Planeta.h                                          **/
/**                                                                                    **/
/****************************************************************************************/

class Planeta {
public:
  std::string nombre;
  tVector3    posicion;
  bool        explotado;
  
  Planeta(std::string nombre, tVector3 posicion);                                         // Constructor
  Planeta(const Planeta &orig);                                                           // Constructor de copia
  virtual ~Planeta();                                                                     // Destructor
  
  void dibujar();
  void explotar();
  
};

#endif	/* Planeta_h */
