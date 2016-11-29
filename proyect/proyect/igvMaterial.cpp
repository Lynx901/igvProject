#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {

// Aplicar los valores de los atributos del objeto igvMaterial:
  GLfloat amb[] = {static_cast<GLfloat>(Ka[0]), static_cast<GLfloat>(Ka[1]), static_cast<GLfloat>(Ka[2])};
  GLfloat dif[] = {static_cast<GLfloat>(Kd[0]), static_cast<GLfloat>(Kd[1]), static_cast<GLfloat>(Kd[2])};
  GLfloat esp[] = {static_cast<GLfloat>(Ks[0]), static_cast<GLfloat>(Ks[1]), static_cast<GLfloat>(Ks[2])};
  GLfloat emi[] = {0.0, 0.0, 0.0};
  
// - coeficiente de reflexión de la luz ambiental
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);

// - coeficiente de reflexión difuso
  glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);

// - coeficiente de reflesión especular
  glMaterialfv(GL_FRONT, GL_SPECULAR, esp);

// - exponente de Phong
  glMaterialf(GL_FRONT, GL_SHININESS, Ns);

// establecer como color de emisión (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)
  glMaterialfv(GL_FRONT, GL_EMISSION, emi);

}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



