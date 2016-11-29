#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"

// Metodos constructores

igvEscena3D::igvEscena3D () {
	ejes = true;
}

igvEscena3D::~igvEscena3D() {
}


// Metodos publicos 

void pintar_ejes(void) {
  GLfloat rojo[]={1,0,0,1.0};
  GLfloat verde[]={0,1,0,1.0};
  GLfloat azul[]={0,0,1,1.0};

  glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glBegin(GL_LINES);
		glVertex3f(1000,0,0);
		glVertex3f(-1000,0,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glBegin(GL_LINES);
		glVertex3f(0,1000,0);
		glVertex3f(0,-1000,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glBegin(GL_LINES);
		glVertex3f(0,0,1000);
		glVertex3f(0,0,-1000);
	glEnd();
}

void pintarQuadPlanoXZ(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;
  
  
  
  float altura = 1.0 / div_z;
  float ancho  = 1.0 / div_x;
  
  float contmapx = 0.0;
  float contmapz = 1.0;
  
  
  
  for (float i = 0.0; i <= tam_x; i += divisionX){
    contmapz = 1.0;
    for (float j = 0.0; j <= tam_z; j += divisionZ){
      glNormal3f(0, 1, 0);
      glBegin(GL_QUADS);
      
        glTexCoord2f(0, 1);
        glVertex3f(i, 0.0, j);
        
        glTexCoord2f(0, 0);
        glVertex3f(i, 0.0, j + divisionZ);
        
        glTexCoord2f(1, 1);
        glVertex3f(i + divisionX, 0.0, j + divisionZ);
        
        glTexCoord2f(1, 0);
        glVertex3f(i + divisionX, 0.0, j);
      
      glEnd();
      contmapz = contmapz - altura;
    }
    contmapx = contmapx + ancho;
  }
}

void pintarQuadPlanoYZ(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;

  
  float altura = 1.0 / div_z;
  float ancho  = 1.0 / div_x;
  
  float contmapx = 0.0;
  float contmapz = 1.0;
  
  
  
  for (float i = 0.0; i <= tam_x; i += divisionX){
    contmapz = 1.0;
    for (float j = 0.0; j <= tam_z; j += divisionZ){
      glNormal3f(0, 1, 0);
      glBegin(GL_QUADS);
      
      glTexCoord2f(0, 1);
      glVertex3f(0.0, i, j);
      
      glTexCoord2f(0, 0);
      glVertex3f(0.0, i, j + divisionZ);
      
      glTexCoord2f(1, 1);
      glVertex3f(0.0, i + divisionX, j + divisionZ);
      
      glTexCoord2f(1, 0);
      glVertex3f(0.0, i + divisionX, j);
      
      glEnd();
      contmapz = contmapz - altura;
    }
    contmapx = contmapx + ancho;
  }
}

void pintarQuadPlanoXY(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;
  
  
  
  float altura = 1.0 / div_z;
  float ancho  = 1.0 / div_x;
  
  float contmapx = 0.0;
  float contmapz = 1.0;
  
  
  
  for (float i = 0.0; i <= tam_x; i += divisionX){
    contmapz = 1.0;
    for (float j = 0.0; j <= tam_z; j += divisionZ){
      glNormal3f(0, 1, 0);
      glBegin(GL_QUADS);
      
      glTexCoord2f(0, 1);
      glVertex3f(i, j, 0.0);
      
      glTexCoord2f(0, 0);
      glVertex3f(i, j + divisionZ, 0.0);
      
      glTexCoord2f(1, 1);
      glVertex3f(i + divisionX, j + divisionZ, 0.0);
      
      glTexCoord2f(1, 0);
      glVertex3f(i + divisionX, j, 0.0);
      
      glEnd();
      contmapz = contmapz - altura;
    }
    contmapx = contmapx + ancho;
  }
}

void igvEscena3D::visualizar(void) {
	glPushMatrix();
	  if (ejes) pintar_ejes();

		// luces se aplican antes de las transformaciones a la escena para que permanezcan fijas
    GLfloat luz0[4]={5,5,5,2}; // luz puntual
    glShadeModel(GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_POSITION, luz0); // la luz se coloca aquí si permanece fija y no se mueve con la escena
    glEnable(GL_LIGHT0);
  
    pintarQuadPlanoXZ(10, 10, 0, 30);
    pintarQuadPlanoYZ(10, 10, 0, 30);
    pintarQuadPlanoXY(10, 10, 0, 30);
  
    GLfloat rojo[]={1,0,0,1.0};
    GLfloat verde[]={0,1,0,1.0};
    GLfloat azul[]={0,0,1,1.0};
  
    glDisable(GL_TEXTURE_2D);
    glMaterialfv(GL_FRONT,GL_EMISSION,verde);
    glPushMatrix();
      glTranslatef(4, 2, 2);
      glutSolidSphere(1, 50, 50);
    glPopMatrix();
  
    glMaterialfv(GL_FRONT,GL_EMISSION,azul);
    glPushMatrix();
      glTranslatef(1, 4, 8);
      glutSolidSphere(1, 50, 50);
    glPopMatrix();
  
    glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
    glPushMatrix();
      glTranslatef(10, 2, 10);
      glutSolidSphere(1, 50, 50);
    glPopMatrix();
  
  
  
  glPopMatrix (); // restaura la matriz de modelado
}















