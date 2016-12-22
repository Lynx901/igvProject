/**
 * @file    igvFuenteLuz.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#ifndef __IGVFUENTELUZ
#define __IGVFUENTELUZ

#include <GLUT/glut.h>

#include "Camara.h"
#include "igvColor.h"

class igvFuenteLuz {
protected:
  unsigned int  idLuz;                                                                    // De GL_LIGHT0 a GL_LIGHT7
  
  tVector3      posicion;                                                                 // Indica la posici—n de la luz
  bool          on;                                                                       // Indica si la luz est‡ encendida o no
  
  igvColor colorAmbiente;
  igvColor colorDifuso;
  igvColor colorEspecular;
  
  double aten_a0;
  double aten_a1;
  double aten_a2;
  
  tVector3  direccion_foco;
  double    angulo_foco;
  double    exponente_foco;
  
  
public:
  igvFuenteLuz();
  
  igvFuenteLuz(const unsigned int _idLuz,
               const tVector3&    _posicion,
               const igvColor&    cAmb, const igvColor& cDif, const igvColor& cEsp,
               const double       a0,   const double    a1,   const double     a2);       // Constructor de luz puntual
  
  
  igvFuenteLuz(const unsigned int _idLuz,
               const tVector3&  _posicion,
               const igvColor&  cAmb,     const igvColor& cDif,   const igvColor& cEsp,
               const double     a0,       const double    a1,     const double a2,
               const tVector3&  dir_foco, const double ang_foco,  const double exp_foco); // Constructor de un foco
  
  
  
  void set(const igvColor& cAmb, const igvColor& cDif, const igvColor& cEsp);
  void setAmbiental(const igvColor& cAmb);
  void setDifuso(const igvColor& cDif);
  void setEspecular(const igvColor& cEsp);
  void setPosicion(tVector3 pos);
  void setAtenuacion(double a0, double a1, double a2);
  
  
  igvColor&   getAmbiental();
  igvColor&   getDifuso();
  igvColor&   getEspecular();
  tVector3 &  getPosicion();
  void        getAtenuacion(double & a0, double & a1, double & a2);
  
  unsigned int isOn();
  
  void setOn();
  void setOff();
  
  void aplicar();
};

#endif

