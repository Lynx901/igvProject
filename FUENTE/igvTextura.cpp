/**
 * @file    igvTextura.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include "igvTextura.h"

igvTextura::igvTextura(char *fichero) {
  GLubyte *imagen;

	imagen = loadBMPRaw(fichero, alto, ancho);
  
  glGenTextures(1, &idTextura);
  
  glBindTexture(GL_TEXTURE_2D, idTextura);
  
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ancho, alto, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen);
  
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	delete imagen;
}

void igvTextura::aplicar(void) {
  glBindTexture(GL_TEXTURE_2D, idTextura);
}

igvTextura::~igvTextura() {
  glDeleteTextures(1, &idTextura); 
}
