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
#include "Objeto.h"

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
  //void establecerMovimiento(std::string nombre);                                          // Movimiento de la nave
  
  tVector3 getPosicion() { return posicion; };
  void     setPosicion(tVector3 pos) { posicion = pos; }
  
private:
  std::string tipo;
  tVector3    posicion;
  bool        rotacion;
};

#endif	/* Nave_h */
