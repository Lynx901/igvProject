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
  GLfloat rojo[]  ={1, 0, 0, 1.0};
  GLfloat verde[] ={0, 1, 0, 1.0};
  GLfloat azul[]  ={0, 0, 1, 1.0};
  
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

int randomNumber() {
  return rand()%69 + 1;
}

void igvEscena3D::visualizar(Camara camara, bool start) {
  glPushMatrix();
  
  if (ejes)
    pintarEjes();
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                                 Focos                                              */
  /*                                                                                    */
  /**************************************************************************************/
  
  posFoco1    = posFoco2    = camara.mPos;                                                // Crea los focos en la posición de la cámara
  posFoco1.x  = camara.mPos.x + 3;                                                        // Pone el foco 1 un poco a la derecha
  posFoco2.x  = camara.mPos.x - 3;                                                        // Pone el foco 2 un poco a la izquierda
  
  igvColor cAmbF(0.0, 0.0, 0.0, 1.0);
  igvColor cDifF(1.0, 1.0, 1.0, 1.0);
  igvColor cEspF(1.0, 1.0, 1.0, 1.0);
  
  igvFuenteLuz foco1(GL_LIGHT1, posFoco1, cAmbF, cDifF, cEspF, 1.0, 0.0, 0.0, dirFoco, 15, 20);
  foco1.aplicar();
  
  igvFuenteLuz foco2(GL_LIGHT2, posFoco2, cAmbF, cDifF, cEspF, 1.0, 0.0, 0.0, dirFoco, 15, 20);
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
  igvTextura textSB("/Users/dani/Desktop/texturas/sbSphere.bmp");
  textSB.aplicar();
  gluSphere(qobj,100,50,50);
  gluDeleteQuadric(qobj);
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
  
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Dibujo de planetas                                         */
  /*                                                                                    */
  /**************************************************************************************/
  
  tVector3 pSol(1, 1, 1), pMer(5, 25, 5),   pVen(10, 10, 10), pTie(15, 15, 15),      // Posiciones de los planetas
  pMar(20, 20, 20), pJup(25, 25, 25), pSat(30, 30, 30), pUra(35, 35, 35),
  pNep(40, 40, 40), pPlu(45, 45, 45);
  
  
  Planeta sol(      "sol",      pSol);                                                  // Creación de los planetas
  if(seleccion != 1 && !sol.explotado) {
    sol.explotado = false;
    glPushName(SOL);                                                                      // Dibujo y control del espacio de nombres
    sol.dibujar();
    glPopName();
  } else if(!start) {
    sol.explotar();
    sol.explotado = true;
  }
  
  Planeta mercurio( "mercurio", pMer);
  if(seleccion != 2 && !mercurio.explotado) {
    mercurio.explotado = false;
    glPushName(MERCURIO);                                                                      // Dibujo y control del espacio de nombres
    mercurio.dibujar();
    glPopName();
  } else if(!start) {
    mercurio.explotar();
    mercurio.explotado = true;
  }
  
  Planeta venus(    "venus",    pVen);
  if(seleccion != 3 && !venus.explotado) {
    venus.explotado = false;
    glPushName(VENUS);                                                                      // Dibujo y control del espacio de nombres
    venus.dibujar();
    glPopName();
  } else if(!start) {
    venus.explotar();
    venus.explotado = true;
  }
  
  Planeta tierra(   "tierra",   pTie);
  if(seleccion != 4 && !tierra.explotado) {
    tierra.explotado = false;
    glPushName(TIERRA);                                                                      // Dibujo y control del espacio de nombres
    tierra.dibujar();
    glPopName();
  } else if(!start) {
    tierra.explotar();
    tierra.explotado = true;
  }
  
  Planeta marte(    "marte",    pMar);
  if(seleccion != 5 && !marte.explotado) {
    marte.explotado = false;
    glPushName(MARTE);                                                                      // Dibujo y control del espacio de nombres
    marte.dibujar();
    glPopName();
  } else if(!start) {
    marte.explotar();
    marte.explotado = true;
  }
  
  Planeta jupiter(  "jupiter",  pJup);
  if(seleccion != 6 && !jupiter.explotado) {
    jupiter.explotado = false;
    glPushName(JUPITER);                                                                      // Dibujo y control del espacio de nombres
    jupiter.dibujar();
    glPopName();
  } else if(!start) {
    jupiter.explotar();
    jupiter.explotado = true;
  }
  
  Planeta saturno(  "saturno",  pSat);
  if(seleccion != 7 && !saturno.explotado) {
    saturno.explotado = false;
    glPushName(SATURNO);                                                                      // Dibujo y control del espacio de nombres
    saturno.dibujar();
    glPopName();
  } else if(!start) {
    saturno.explotar();
    saturno.explotado = true;
  }
  
  Planeta urano(    "urano",    pUra);
  if(seleccion != 8 && !urano.explotado) {
    urano.explotado = false;
    glPushName(URANO);                                                                      // Dibujo y control del espacio de nombres
    urano.dibujar();
    glPopName();
  } else if(!start) {
    urano.explotar();
    urano.explotado = true;
  }
  
  Planeta neptuno(  "neptuno",  pNep);
  if(seleccion != 9 && !neptuno.explotado) {
    neptuno.explotado = false;
    glPushName(NEPTUNO);                                                                      // Dibujo y control del espacio de nombres
    neptuno.dibujar();
    glPopName();
  } else if(!start) {
    neptuno.explotar();
    neptuno.explotado = true;
  }
  
  Planeta pluton(   "pluton",   pPlu);
  if(seleccion != 10 && !pluton.explotado) {
    pluton.explotado = false;
    glPushName(PLUTON);                                                                      // Dibujo y control del espacio de nombres
    pluton.dibujar();
    glPopName();
  } else if(!start) {
    pluton.explotar();
    pluton.explotado = true;
  }
  
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Dibujo de naves y satélites                                */
  /*                                                                                    */
  /**************************************************************************************/
  
  std::vector<Nave> satelites;
  for (int i = 0; i < 5; i++) {
    satelites.push_back(Nave("satelite", tVector3(randomNumber(), randomNumber(), randomNumber())));
    satelites.at(i).dibujar();
  }
  
  std::vector<Nave> cohetes;
  for (int i = 0; i < 5; i++) {
    cohetes.push_back(Nave("cohete", tVector3(randomNumber(), randomNumber(), randomNumber())));
    cohetes.at(i).dibujar();
  }

  glPopMatrix (); // restaura la matriz de modelado
}










