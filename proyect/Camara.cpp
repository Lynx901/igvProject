//
//  Camara.cpp
//  proyect
//
//  Created by Daniel Moya on 30/11/16.
//  Copyright © 2016 Daniel Moya. All rights reserved.
//

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <stdio.h>
#include "Camara.h"

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Implementación Camara                                                                   **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

void Camara::moverCamara(float velocidad) {
  tVector3 vVector = mView - mPos;
  
  if(mPos.x <= 0.5) {
    mPos.x  = 0.6;
    mView.x = mView.x;
  } else {
    mPos.x  = mPos.x  + vVector.x * velocidad;
    mView.x = mView.x + vVector.x * velocidad;
  }
  
  if(mPos.y <= 0.5) {
    mPos.y  = 0.6;
    mView.y = mView.y;
  } else {
    mPos.y  = mPos.y  + vVector.y * velocidad;
    mView.y = mView.y + vVector.y * velocidad;
  }
  
  if(mPos.z <= 0.5) {
    mPos.z  = 0.6;
    mView.z = mView.z;
  } else {
    mPos.z  = mPos.z  + vVector.z * velocidad;
    mView.z = mView.z + vVector.z * velocidad;
  }
  
}

void Camara::rotarVista(float velocidad) {
  tVector3 vVector = mView - mPos;
  
  GLfloat campoZ = mPos.z + sin(velocidad) * vVector.x + cos(velocidad) * vVector.z;
  GLfloat campoX = mPos.x + cos(velocidad) * vVector.x - sin(velocidad) * vVector.z;
  
  mView.z = campoZ;
  mView.x = campoX;
}

void Camara::posicionarCamara(float pos_x,   float pos_y,  float pos_z,
                      float view_x,  float view_y, float view_z,
                      float up_x,    float up_y,   float up_z){
  
  mPos	= tVector3(pos_x,  pos_y,  pos_z );
  mView	= tVector3(view_x, view_y, view_z);
  mUp		= tVector3(up_x,   up_y,   up_z  );
}
