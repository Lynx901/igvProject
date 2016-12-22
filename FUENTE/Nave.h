/**
 * @file    Nave.h
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include <iostream>
#include "Camara.h"

#ifndef Nave_h
#define	Nave_h

/****************************************************************************************/
/**                                                                                    **/
/**                           Clase Nave.h                                             **/
/**                                                                                    **/
/****************************************************************************************/

class Nave {
public:
  Nave(std::string tipo, tVector3 posicion);                                              // Constructor
  Nave(const Nave &orig);                                                                 // Constructor de copia
  virtual ~Nave();                                                                        // Destructor
  
  void dibujar();                                                                         // Dibuja la nave
  
private:
  std::string tipo;                                                                       // Indica de qué tipo es la nave
  tVector3    posicion;                                                                   // Posición de la nave
};

#endif	/* Nave_h */
