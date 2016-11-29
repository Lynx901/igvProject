//
//  Objeto.cpp
//  proyect
//
//  Created by Daniel Moya on 29/11/16.
//  Copyright © 2016 Daniel Moya. All rights reserved.
//

#include <stdio.h>
#include "Objeto.h"
#include "matrix.h"
#include "vector3.h"

Objeto::Objeto(){
  matrizLocal.Identity();
  nombre[0]		= '\0';
  posicion		= Vector3( 0.0f, 0.0f, 0.0f );
  velocidad		= 0.0f;
}

Objeto::Objeto( const Objeto &other ){
  this->nombre      = other.nombre;
  this->matrizLocal	= other.matrizLocal;
  this->posicion    = other.posicion;
  this->velocidad		= other.velocidad;
}

Objeto::~Objeto(){
}

void Objeto::setNombre(std::string name){
  nombre = name;
}

int Objeto::actualiza(long msElapsed){
  return 0;
}

void Objeto::setPosicion(Vector3 vPosicion){
  posicion = vPosicion;
}

Matrix Objeto::getWorldMatrix(){
  Matrix transform;
  Matrix localToWorld;
  
  transform.Translate(posicion);
  
  localToWorld = matrizLocal * transform;
  
  return localToWorld;
}

void Objeto::actualizaEjes(){
  // Calculamos el vector lateral ( Forward * Up ).
  Vector3 vStrafe = matrizLocal.getForwardVector() * matrizLocal.getUpVector();
  vStrafe.Normalize();
  matrizLocal.setStrafeVector( vStrafe );
  
  // Calculamos el vector arriba ( Strafe * Forward ).
  Vector3 vUp = vStrafe * matrizLocal.getForwardVector();
  vUp.Normalize();
  matrizLocal.setUpVector( vUp );
}

void Objeto::setOrientacion(Vector3 vLook, Vector3 vUp){
  // Vector avance.
  Vector3 vForward= ( vLook - posicion );
  vForward.Normalize();
  matrizLocal.setForwardVector( vForward );
  
  // øDÛnde est· el techo?
  matrizLocal.setUpVector( vUp );
  
  // Hacemos los ejes perpendiculares.
  actualizaEjes();
}

void Objeto::avanzar(float distancia){
  posicion += ( matrizLocal.getForwardVector() * distancia );
}

void Objeto::strafe(float distancia){
  posicion += ( matrizLocal.getStrafeVector() * distancia );
}

void Objeto::pitch(float angulo){
  Matrix matrix;
  matrizLocal *= matrix.RotateX(angulo);
}

void Objeto::yaw(float angulo){
  Matrix matrix;
  matrizLocal *= matrix.RotateY(angulo);
}

void Objeto::roll(float angulo) {
  Matrix matrix;
  matrizLocal *= matrix.RotateZ(angulo);
}

Vector3 Objeto::getVectorOrientacion(){
  return ( posicion + matrizLocal.getForwardVector() );
}

