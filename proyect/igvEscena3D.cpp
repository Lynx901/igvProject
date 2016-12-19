#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>

#include "igvEscena3D.h"
#include "igvFuenteLuz.h"


// Metodos constructores

igvEscena3D::igvEscena3D () {
	ejes = false;
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

/*
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
*/

tVector3 random1(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random2(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random3(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random4(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random5(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random6(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random7(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);
tVector3 random8(rand() % 49 + 1, rand() % 49 + 1, rand() % 49 + 1);

int const SOL       = 1;
int const MERCURIO  = 2;
int const VENUS     = 3;
int const TIERRA    = 4;
int const MARTE     = 5;
int const JUPITER   = 6;
int const SATURNO   = 7;
int const URANO     = 8;
int const NEPTUNO   = 9;
int const PLUTON    = 10;



void igvEscena3D::visualizar(Camara camara) {

  /**************************************************************************************/
  /*                                                                                    */
  /*                         Instrucciones                                              */
  /*                                                                                    */
  /**************************************************************************************/
  
  GLfloat blanco[]={1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT,GL_EMISSION, blanco);
  
  igvTextura instrucciones("/Users/dani/Desktop/texturas/instrucciones.bmp");
  instrucciones.aplicar();
  
  glNormal3f(0, 1, 0);
  glBegin(GL_QUADS);
  
    glTexCoord2f(0, 0);
    glVertex3f(25, 25, 25);
    
    glTexCoord2f(1, 0);
    glVertex3f(35, 25, 25);
    
    glTexCoord2f(1, 1);
    glVertex3f(35, 35, 25);
    
    glTexCoord2f(0, 1);
    glVertex3f(25, 35, 25);
  
  glEnd();
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                                 Focos                                              */
  /*                                                                                    */
  /**************************************************************************************/
  
  posFoco1    = posFoco2    = camara.mPos;
  posFoco1.x  = camara.mPos.x + 3;
  posFoco2.x  = camara.mPos.x - 3;
  
	glPushMatrix();
	  if (ejes)
      pintarEjes();
  
  igvColor cAmbF(0.0, 0.0, 0.0, 1.0);
  igvColor cDifF(1.0, 1.0, 1.0, 1.0);
  igvColor cEspF(1.0, 1.0, 1.0, 1.0);
  
  igvFuenteLuz foco1(GL_LIGHT1, posFoco1, cAmbF, cDifF, cEspF, 1.0, 0.0, 0.0, dirFoco, 30, 10);
  foco1.aplicar();

  igvFuenteLuz foco2(GL_LIGHT2, posFoco2, cAmbF, cDifF, cEspF, 1.0, 0.0, 0.0, dirFoco, 30, 10);
  foco2.aplicar();

  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Dibujo de skybox                                           */
  /*                                                                                    */
  /**************************************************************************************/
  
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
  
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Dibujo de planetas                                         */
  /*                                                                                    */
  /**************************************************************************************/
  
  tVector3 pSol(0, 0, 0),    pMer(5, 5, 5),    pVen(10, 10, 10), pTie(15, 15, 15),
             pMar(20, 20, 20), pJup(25, 25, 25), pSat(30, 30, 30), pUra(35, 35, 35),
             pNep(40, 40, 40), pPlu(45, 45, 45);
  
  
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
  
    glPushName(SOL);
      sol.dibujar();
    glPopName();
  
    glPushName(MERCURIO);
      mercurio.dibujar();
    glPopName();
    
    glPushName(VENUS);
      venus.dibujar();
    glPopName();

    glPushName(TIERRA);
      tierra.dibujar();
    glPopName();
    
    glPushName(MARTE);
      marte.dibujar();
    glPopName();
    
    glPushName(JUPITER);
      jupiter.dibujar();
    glPopName();
    
    glPushName(SATURNO);
      saturno.dibujar();
    glPopName();
    
    glPushName(URANO);
      urano.dibujar();
    glPopName();
    
    glPushName(NEPTUNO);
      neptuno.dibujar();
    glPopName();
    
    glPushName(PLUTON);
      pluton.dibujar();
    glPopName();

  
  
  /*std::cout << "\t\t" << tVector3::distancia(pSol, camara) << std::endl;
  std::cout << "\tYo "   << camara.x << " - " << camara.y << " - "  << camara.z << std::endl;
  std::cout << "\tSol "   << pSol.x << " - " << pSol.y << " - "  << pSol.z << std::endl;
   */
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Control de impactos                                        */
  /*                                                                                    */
  /**************************************************************************************/
  
    switch (seleccion) {
      case 1: // Sol
        sol.explotar();
        break;
      case 2: // Mercurio
        mercurio.explotar();
        break;
      case 3: // Venus
        venus.explotar();
        break;
      case 4: // Tierra
        tierra.explotar();
        break;
      case 5: // Marte
        marte.explotar();
        break;
      case 6: // Jupiter
        jupiter.explotar();
        break;
      case 7: // Saturno
        saturno.explotar();
        break;
      case 8: // Urano
        urano.explotar();
        break;
      case 9: // Neptuno
        neptuno.explotar();
        break;
      case 10: // Pluton
        pluton.explotar();
        break;
        
    }
    
    if(tVector3::distancia(pSol, camara.mPos) < 3) {
      
    }
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Dibujo de naves y satŽlites                                */
  /*                                                                                    */
  /**************************************************************************************/
  
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










