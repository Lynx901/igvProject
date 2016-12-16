#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>

#include "igvEscena3D.h"


// Metodos constructores

igvEscena3D::igvEscena3D () {
	ejes = true;
}

igvEscena3D::~igvEscena3D() {
}


// Metodos publicos 

void pintarEjes(void) {
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

void pintarQuadPlanoXZbot(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;
  
  for (float i = 0.0; i < tam_x; i += divisionX){
    for (float j = 0.0; j < tam_z; j += divisionZ){
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
    }
  }
}

void pintarQuadPlanoYZleft(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;
  
  for (float i = 0.0; i < tam_x; i += divisionX){
    for (float j = 0.0; j < tam_z; j += divisionZ){
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
    }
  }
}

void pintarQuadPlanoXYback(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;
  
  for (float i = 0.0; i < tam_x; i += divisionX){
    for (float j = 0.0; j < tam_z; j += divisionZ){
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
    }
  }
}

void pintarQuadPlanoXZtop(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;
  
  for (float i = 0.0; i < tam_x; i += divisionX){
    for (float j = 0.0; j < tam_z; j += divisionZ){
      glNormal3f(0, 1, 0);
      glBegin(GL_QUADS);
      
      glTexCoord2f(0, 1);
      glVertex3f(i, fin, j);
      
      glTexCoord2f(0, 0);
      glVertex3f(i, fin, j + divisionZ);
      
      glTexCoord2f(1, 1);
      glVertex3f(i + divisionX, fin, j + divisionZ);
      
      glTexCoord2f(1, 0);
      glVertex3f(i + divisionX, fin, j);
      
      glEnd();
    }
  }
}

void pintarQuadPlanoXYfront(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;

  for (float i = 0.0; i < tam_x; i += divisionX){
    for (float j = 0.0; j < tam_z; j += divisionZ){
      glNormal3f(0, 1, 0);
      glBegin(GL_QUADS);
      
      glTexCoord2f(0, 1);
      glVertex3f(i, j, fin);
      
      glTexCoord2f(0, 0);
      glVertex3f(i, j + divisionZ, fin);
      
      glTexCoord2f(1, 1);
      glVertex3f(i + divisionX, j + divisionZ, fin);
      
      glTexCoord2f(1, 0);
      glVertex3f(i + divisionX, j, fin);
      
      glEnd();
    }
  }
}

void pintarQuadPlanoYZright(float div_x, float div_z, float inicio, float fin) {
  float tam_x = fin;
  float tam_z = fin;
  
  float divisionX = tam_x / div_x;
  float divisionZ = tam_z / div_z;
  
  for (float i = 0.0; i < tam_x; i += divisionX){
    for (float j = 0.0; j < tam_z; j += divisionZ){
      glNormal3f(0, 1, 0);
      glBegin(GL_QUADS);
      
      glTexCoord2f(0, 1);
      glVertex3f(fin, i, j);
      
      glTexCoord2f(0, 0);
      glVertex3f(fin, i, j + divisionZ);
      
      glTexCoord2f(1, 1);
      glVertex3f(fin, i + divisionX, j + divisionZ);
      
      glTexCoord2f(1, 0);
      glVertex3f(fin, i + divisionX, j);
      
      glEnd();
    }
  }
}

tVector3 random1(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random2(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random3(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random4(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random5(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random6(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random7(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random8(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);


void igvEscena3D::visualizar(tVector3 camara) {
	glPushMatrix();
	  if (ejes)
      pintarEjes();

                                                                                          // Las luces se aplican antes de las  transformaciones a la escena para que permanezcan fijas

  
    GLfloat luz0[4]={5,5,5,2}; // luz puntual
    glShadeModel(GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_POSITION, luz0); // la luz se coloca aquí si permanece fija y no se mueve con la escena
    glEnable(GL_LIGHT0);
  
    /*
     * ESTO ES EL SKYBOX HECHO CON QUADS.
     * Ha sido reemplazado porque las texturas no se ve’an nada realistas
     *
    igvTextura textSB1("/Users/dani/Desktop/texturas/skybox/sb1.bmp");
    textSB1.aplicar();
    pintarQuadPlanoXZbot(1, 1, 0, 50);
    igvTextura textSB2("/Users/dani/Desktop/texturas/skybox/sb2.bmp");
    textSB2.aplicar();
    pintarQuadPlanoYZleft(1, 1, 0, 50);
    igvTextura textSB3("/Users/dani/Desktop/texturas/skybox/sb3.bmp");
    textSB3.aplicar();
    pintarQuadPlanoXYback(1, 1, 0, 50);
    igvTextura textSB4("/Users/dani/Desktop/texturas/skybox/sb4.bmp");
    textSB4.aplicar();
    pintarQuadPlanoXYfront(1, 1, 0, 50);
    igvTextura textSB5("/Users/dani/Desktop/texturas/skybox/sb5.bmp");
    textSB5.aplicar();
    pintarQuadPlanoYZright(1, 1, 0, 50);
    igvTextura textSB6("/Users/dani/Desktop/texturas/skybox/sb6.bmp");
    textSB6.aplicar();
    pintarQuadPlanoXZtop(1, 1, 0, 50);
     */
  
    // Dibuja el skybox
    GLfloat azul[]={0,0,1,1.0};
    glMaterialfv(GL_FRONT,GL_EMISSION, azul);
    glPushMatrix();
      glTranslatef(25, 25, 25);
      GLuint id;
      glGenTextures(1, &id);
      GLUquadric *qobj = gluNewQuadric();
      gluQuadricTexture(qobj,GL_TRUE);
      glBindTexture(GL_TEXTURE_2D, id);
      glEnable(GL_TEXTURE_2D);
      igvTextura textSB("/Users/dani/Desktop/texturas/skybox/sbSphere.bmp");
      textSB.aplicar();
      gluSphere(qobj,50,50,50);
      gluDeleteQuadric(qobj);
      glDisable(GL_TEXTURE_2D);
    glPopMatrix();
  
  
    // Dibuja los planetas
    tVector3 pSol(0, 0, 0);
    tVector3 pMer(5, 5, 5);
    tVector3 pVen(10, 10, 10);
    tVector3 pTie(15, 15, 15);
    tVector3 pMar(20, 20, 20);
    tVector3 pJup(25, 25, 25);
    tVector3 pSat(30, 30, 30);
    tVector3 pUra(35, 35, 35);
    tVector3 pNep(40, 40, 40);
    tVector3 pPlu(45, 45, 45);
  
  
    Planeta sol(      "sol",      pSol);
    Planeta mercurio( "mercurio", pMer);
    Planeta venus(    "venus",    pVen);
    Planeta tierra(   "tierra",   pTie);
    Planeta marte(    "marte",    pMar);
    Planeta jupiter(  "jupiter",  pJup);
    Planeta saturno(  "saturno",  pSat);
    Planeta urano(    "urano",    pUra);
    Planeta neptuno(  "neptuno",  pNep);
    Planeta pluton(   "pluton",   pPlu);

    sol.dibujar();
    mercurio.dibujar();
    venus.dibujar();
    tierra.dibujar();
    marte.dibujar();
    jupiter.dibujar();
    saturno.dibujar();
    urano.dibujar();
    neptuno.dibujar();
    pluton.dibujar();
  
  /*std::cout << "\t\t" << tVector3::distancia(pSol, camara) << std::endl;
  std::cout << "\tYo "   << camara.x << " - " << camara.y << " - "  << camara.z << std::endl;
  std::cout << "\tSol "   << pSol.x << " - " << pSol.y << " - "  << pSol.z << std::endl;
   */
    if(tVector3::distancia(pSol, camara) > 10) {
    }
  
    // Dibuja las naves
    Nave nave1("satelite", tVector3(5, 10, 5));
    Nave nave2("satelite", tVector3(random2.x, random2.y, random2.z));
    Nave nave3("satelite", tVector3(random3.x, random3.y, random3.z));
    Nave nave4("satelite", tVector3(random4.x, random4.y, random4.z));
  
    Nave nave5("cohete", tVector3(random5.x, random5.y, random5.z));
    Nave nave6("cohete", tVector3(random6.x, random6.y, random6.z));
    Nave nave7("cohete", tVector3(random7.x, random7.y, random7.z));
    Nave nave8("cohete", tVector3(random8.x, random8.y, random8.z));
  
    nave1.dibujar();
    nave2.dibujar();
    nave3.dibujar();
    nave4.dibujar();
  
    nave5.dibujar();
    nave6.dibujar();
    nave7.dibujar();
    nave8.dibujar();
  
  glPopMatrix (); // restaura la matriz de modelado
}















