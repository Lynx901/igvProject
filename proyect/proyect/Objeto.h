//
//  Objeto.h
//  proyect
//
//  Created by Daniel Moya on 29/11/16.
//  Copyright © 2016 Daniel Moya. All rights reserved.
//

#include <iostream>
#include "vector3.h"
#include "matrix.h"


#ifndef Objeto_h
#define Objeto_h

class Objeto {
private:
  
  std::string  nombre;                                                                    // Nombre del objeto.
  Vector3      posicion;                                                                  // Posición en el espacio mundo.
  float        velocidad;                                                                 // Velocidad a la que se mueve el objeto.
  Matrix       matrizLocal;                                                               // Transformación del espacio local al mundo.
  
public:

  Objeto();                                                                               // Constructor
  Objeto(const Objeto &other);                                                            // Constructor de copia
  virtual ~Objeto();                                                                      // Destructor

  void setNombre(std::string name);                                                       // Establece el nombre
  void setPosicion(Vector3 vPosicion);                                                    // Establece la posición
  void setSpeed(float valor)	{ velocidad = valor; }                                      // Establece la velocidad
  void setOrientacion(Vector3 vMirar, Vector3 vArriba);                                   // Establece la orientación
  
  std::string   getNombre()   { return nombre; }                                          // Devuelve el nombre del objeto
  Vector3       getPosicion() { return posicion; }                                        // Devuelve la posición del objeto
  float         getSpeed()    { return velocidad; }                                       // Devuelve la velocidad del objeto
  Vector3       getVectorOrientacion();                                                   // Devuelve hacia donde mira el objeto

  Matrix getLocalMatrix()       { return matrizLocal; }                                   // Devuelve la matriz local del objeto
  Matrix & getRefLocalMatrix()  { return matrizLocal; }                                   // Devuelve una referencia a la matriz local
  Matrix getWorldMatrix();                                                                // Devuelve la matriz de mundo
  
  int   actualiza(long msElapsed);                                                        // Actualiza el estado el objeto
  void  actualizaEjes();                                                                  // Recalcula el sistema de ejes (ortonormales)

  void avanzar(float distancia);                                                          // Ir en el sentido en el que mira el objeto
  void strafe(float distancia);                                                           // Desplazamiento lateral del objeto
  void pitch(float angulo);                                                               // Giro en eje X
  void yaw(float angulo);                                                                 // Giro en eje Y
  void roll(float angulo);                                                                // Giro en eje Z
  
};

#endif /* Objeto_h */
