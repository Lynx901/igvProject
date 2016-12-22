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
#include "Camara.h"

#ifndef Planeta_h
#define	Planeta_h

/****************************************************************************************/
/**                                                                                    **/
/**                           Clase Planeta.h                                          **/
/**                                                                                    **/
/****************************************************************************************/

class Planeta {
public:
  std::string nombre;                                                                     // Nombre del planeta
  tVector3    posicion;                                                                   // Posición del planeta
  bool        explotado;                                                                  // Indica si el planeta ha sido explotado
  
  Planeta(std::string nombre, tVector3 posicion);                                         // Constructor
  Planeta(const Planeta &orig);                                                           // Constructor de copia
  virtual ~Planeta();                                                                     // Destructor
  
  void dibujar();                                                                         // Dibuja el planeta
  void explotar();                                                                        // Explota el planeta
  
};

#endif	/* Planeta_h */
