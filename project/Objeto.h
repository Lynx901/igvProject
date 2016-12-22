/**
 * @file    Objeto.h
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include <iostream>
#include "Camara.h"

#ifndef Objeto_h
#define Objeto_h

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Clase Objeto                                                                            **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

class Objeto {
private:
  
  std::string  nombre;                                                                    // Nombre del objeto.
  tVector3     posicion;                                                                  // Posición en el espacio mundo.
  
public:

  Objeto();                                                                               // Constructor
  Objeto(const Objeto &other);                                                            // Constructor de copia
  virtual ~Objeto();                                                                      // Destructor

  void setNombre(std::string name);                                                       // Establece el nombre
  void setPosicion(tVector3 vPosicion);                                                   // Establece la posición
  
  std::string   getNombre()    { return nombre; }                                         // Devuelve el nombre del objeto
  tVector3      getPosicion()  { return posicion; }                                       // Devuelve la posición del objeto

  
  void  dibujar();                                                                        // Dibuja el elemento
};

#endif /* Objeto_h */
