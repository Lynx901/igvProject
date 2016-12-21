/**
 * @file    Camara.h
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#ifndef Camara_h
#define Camara_h

#include <math.h>

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Clase tVector3                                                                          **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

class tVector3 {
public:
  tVector3() {}
  tVector3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
  
  tVector3 operator+(tVector3 vVector)  { return tVector3(x + vVector.x, y + vVector.y, z + vVector.z); }
  tVector3 operator+(float number)      { return tVector3(x + number,    y + number,    z + number); }
  tVector3 operator-(tVector3 vVector)  { return tVector3(x - vVector.x, y - vVector.y, z - vVector.z); }
  tVector3 operator-(float number)      { return tVector3(x - number,    y - number,    z - number); }
  tVector3 operator=(tVector3 vVector)  { return tVector3(x = vVector.x, y = vVector.y, z = vVector.z); }
  tVector3 operator*(float number)      { return tVector3(x * number,    y * number,    z * number); }
  tVector3 operator/(float number)      { return tVector3(x / number,    y / number,    z / number); }
  
  static float distancia(tVector3 v1, tVector3 v2)  { return sqrt(pow(v1.x - v2.x, 2) +
                                                                  pow(v1.y - v2.y, 2) +
                                                                  pow(v1.z - v2.z, 2)); }
  
  float x, y, z;
};

/**************************************************************************************************************************************/
/**                                                                                                                                  **/
/**                                          Clase Camara                                                                            **/
/**                                                                                                                                  **/
/**************************************************************************************************************************************/

class Camara {
public:
  
  tVector3 mPos;
  tVector3 mView;
  tVector3 mUp;
  
  bool  modoSelect;
  float anchoSeleccion;
  float altoSeleccion;
  
  Camara(bool modo) {modoSelect = false;};                                                 // Crea la cámara en el modo "visualizar"
  
  void moverCamara(float velocidad);                                                      // Modifica la posición de la cámara
  
  void rotarVista(float velocidad);                                                       // Modifica la vista de la cámara
  
  void posicionarCamara(float pos_x,   float pos_y,  float pos_z,
                        float view_x,  float view_y, float view_z,
                        float up_x,    float up_y,   float up_z);                         // Establece la posición de la cámara
  
  void establecerSeleccion(int ancho, int alto, int cX, int cY);
  
};

#endif /* Camara_h */
