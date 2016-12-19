#include "igvFuenteLuz.h"

// Metodos constructores 

igvFuenteLuz::igvFuenteLuz() {
}

igvFuenteLuz::igvFuenteLuz(const unsigned int _idLuz,
													 const tVector3  & _posicion,
													 const igvColor & cAmb, const igvColor & cDif, const igvColor & cEsp,
													 const double a0, const double a1, const double a2) {

  idLuz = _idLuz;
														 
	posicion = _posicion;
														 
	colorAmbiente = cAmb;
	colorDifuso = cDif;
	colorEspecular = cEsp;

	aten_a0 = a0;
	aten_a1 = a1;
	aten_a2 = a2;

	// valores por defecto cuando la luz no es un foco
	direccion_foco  = tVector3(0,0,0);
	angulo_foco     = 180; // de esta manera la luz se convierte en puntual
	exponente_foco  = 0;

	on = true;
}

igvFuenteLuz::igvFuenteLuz(const unsigned int _idLuz,
			                     const tVector3 & _posicion, 
			                     const igvColor& cAmb, const igvColor& cDif, const igvColor& cEsp,
								           const double a0, const double a1, const double a2,
													 const tVector3& dir_foco, const double ang_foco, const double exp_foco) {

  idLuz = _idLuz;
														 
	posicion = _posicion;
														 
	colorAmbiente = cAmb;
	colorDifuso = cDif;
	colorEspecular = cEsp;

	aten_a0 = a0;
	aten_a1 = a1;
	aten_a2 = a2;

	direccion_foco = dir_foco;
	angulo_foco = ang_foco;
	exponente_foco = exp_foco;

	on = true;
}

// Metodos publicos ----------------------------------------

tVector3& igvFuenteLuz::getPosicion(void) {
	return posicion;
}

void igvFuenteLuz::setPosicion(tVector3 pos) {
	posicion = pos;
}


void igvFuenteLuz::set(const igvColor & cAmb, const igvColor & cDif, const igvColor & cEsp) {
	colorAmbiente = cAmb;
	colorDifuso = cDif;
	colorEspecular = cEsp;
}

void igvFuenteLuz::setAmbiental(const igvColor & cAmb) {
	colorAmbiente = cAmb;
}

void igvFuenteLuz::setDifuso(const igvColor & cDif) {
	colorDifuso = cDif;
}

void igvFuenteLuz::setEspecular(const igvColor & cEsp) {
	colorEspecular = cEsp;
}

igvColor & igvFuenteLuz::getAmbiental() {
	return colorAmbiente;
}

igvColor & igvFuenteLuz::getDifuso() {
	return colorDifuso;
}

igvColor & igvFuenteLuz::getEspecular() {
	return colorEspecular;
}

void igvFuenteLuz::setAtenuacion(double a0, double a1, double a2) {
	aten_a0 = a0;
	aten_a1 = a1;
	aten_a2 = a2;
}

void igvFuenteLuz::getAtenuacion(double & a0, double & a1, double & a2) {
	a0 = aten_a0;
	a1 = aten_a1;
	a2 = aten_a2;
}

void igvFuenteLuz::setOn() {
  on = true;
}

void igvFuenteLuz::setOff() {
  on = false;
}

unsigned int igvFuenteLuz::isOn() {
  return on;
}

void igvFuenteLuz::aplicar() {
  GLfloat pos[] = { static_cast<GLfloat>(posicion.x),
                    static_cast<GLfloat>(posicion.y),
                    static_cast<GLfloat>(posicion.z),
                    1.0};
  
  GLfloat amb[] = { static_cast<GLfloat>(colorAmbiente[0]),
                    static_cast<GLfloat>(colorAmbiente[1]),
                    static_cast<GLfloat>(colorAmbiente[2])};
  
  GLfloat dif[] = { static_cast<GLfloat>(colorDifuso[0]),
                    static_cast<GLfloat>(colorDifuso[1]),
                    static_cast<GLfloat>(colorDifuso[2])};
  
  GLfloat esp[] = { static_cast<GLfloat>(colorEspecular[0]),
                    static_cast<GLfloat>(colorEspecular[1]),
                    static_cast<GLfloat>(colorEspecular[2])};
  
  GLfloat foco[] = {static_cast<GLfloat>(direccion_foco.x),
                    static_cast<GLfloat>(direccion_foco.y),
                    static_cast<GLfloat>(direccion_foco.z)};
  
  if(on) {
    glEnable(idLuz);
    glLightfv(idLuz, GL_POSITION, pos);
    
    glLightfv(idLuz, GL_AMBIENT,  amb);
    glLightfv(idLuz, GL_DIFFUSE,  dif);
    glLightfv(idLuz, GL_SPECULAR, esp);
    
    glLightf(idLuz, GL_CONSTANT_ATTENUATION,  aten_a0);
    glLightf(idLuz, GL_LINEAR_ATTENUATION,    aten_a1);
    glLightf(idLuz, GL_QUADRATIC_ATTENUATION, aten_a2);
    
    glLightfv(idLuz, GL_SPOT_DIRECTION, foco);
    glLightf(idLuz, GL_SPOT_CUTOFF,     angulo_foco);
    glLightf(idLuz, GL_SPOT_EXPONENT,   exponente_foco);
  } else {
    glDisable(idLuz);
  }
	
}






















