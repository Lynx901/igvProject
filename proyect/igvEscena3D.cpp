/**
 * @file    igvEscena3D.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

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
  GLfloat rojo[]  = {1, 0, 0, 1.0};
  GLfloat verde[] = {0, 1, 0, 1.0};
  GLfloat azul[]  = {0, 0, 1, 1.0};
  
  glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
  glBegin(GL_LINES);
		glVertex3f(1000, 0, 0);
		glVertex3f(-1000, 0, 0);
  glEnd();
  
  glMaterialfv(GL_FRONT, GL_EMISSION, verde);
  glBegin(GL_LINES);
		glVertex3f(0, 1000, 0);
		glVertex3f(0, -1000, 0);
  glEnd();
  
  glMaterialfv(GL_FRONT, GL_EMISSION, azul);
  glBegin(GL_LINES);
		glVertex3f(0, 0, 1000);
		glVertex3f(0, 0, -1000);
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

tVector3 random1(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random2(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random3(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random4(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random5(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random6(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random7(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random8(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random9(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random10(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random11(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random12(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random13(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random14(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random15(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random16(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random17(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random18(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random19(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);
tVector3 random20(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50);

void igvEscena3D::visualizar(Camara camara, bool start) {
  glPushMatrix();
  
    if (ejes)
      pintarEjes();
    
    /************************************************************************************/
    /*                                                                                  */
    /*                                 Focos                                            */
    /*                                                                                  */
    /************************************************************************************/
    
    posFoco1    = posFoco2    = camara.mPos;                                              // Crea los focos en la posici—n de la c‡mara
    posFoco1.x  = camara.mPos.x + 3;                                                      // Pone el foco 1 un poco a la derecha
    posFoco2.x  = camara.mPos.x - 3;                                                      // Pone el foco 2 un poco a la izquierda
    
    igvColor cAmbF(0.0, 0.0, 0.0, 1.0);
    igvColor cDifF(1.0, 1.0, 1.0, 1.0);
    igvColor cEspF(1.0, 1.0, 1.0, 1.0);
    
    igvFuenteLuz foco1(GL_LIGHT1, posFoco1, cAmbF, cDifF, cEspF, 1.0, 0.0, 0.0, dirFoco, 5, 5);
    foco1.aplicar();
    
    igvFuenteLuz foco2(GL_LIGHT2, posFoco2, cAmbF, cDifF, cEspF, 1.0, 0.0, 0.0, dirFoco, 5, 5);
    foco2.aplicar();
    
    
    /************************************************************************************/
    /*                                                                                  */
    /*                                    Skybox                                        */
    /*                                                                                  */
    /************************************************************************************/
    
    GLfloat azul[] = {0, 0, 1, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, azul);
    glPushMatrix();
      GLuint id;
      glGenTextures(1, &id);
      GLUquadric *qobj = gluNewQuadric();
      gluQuadricTexture(qobj, GL_TRUE);
      glBindTexture(GL_TEXTURE_2D, id);
      glEnable(GL_TEXTURE_2D);
        igvTextura textSB("/Users/dani/Desktop/texturas/sbSphere.bmp");
        textSB.aplicar();
        gluSphere(qobj, 100, 50, 50);
        gluDeleteQuadric(qobj);
      glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    
    /************************************************************************************/
    /*                                                                                  */
    /*                                    Planetas                                      */
    /*                                                                                  */
    /************************************************************************************/
    
    tVector3  pSol(0, 0, 0),
              pMer(10, 2, 10),
              pVen(17, -10, 17),
              pTie(24, 21, 24),
              pMar(31, 14, 31),
              pJup(38, -32, 38),
              pSat(45, 52, 45),
              pUra(52, -26, 52),
              pNep(59, 40, 59),
              pPlu(65, 0, 65);
    
    
    Planeta sol(      "sol",      pSol);                                                  // Creaci—n de los planetas
    if(seleccion != 1) {
      glPushName(SOL);
        sol.dibujar();
      glPopName();
    } else if(!start) {
      sol.explotar();
    }
    
    Planeta mercurio( "mercurio", pMer);
    if(seleccion != 2) {
      glPushName(MERCURIO);
        mercurio.dibujar();
      glPopName();
    } else if(!start) {
      mercurio.explotar();
    }
    
    Planeta venus(    "venus",    pVen);
    if(seleccion != 3) {
      glPushName(VENUS);
        venus.dibujar();
      glPopName();
    } else if(!start) {
      venus.explotar();
    }
    
    Planeta tierra(   "tierra",   pTie);
    if(seleccion != 4) {
      glPushName(TIERRA);
        tierra.dibujar();
      glPopName();
    } else if(!start) {
      tierra.explotar();
    }
    
    Planeta marte(    "marte",    pMar);
    if(seleccion != 5) {
      glPushName(MARTE);
        marte.dibujar();
      glPopName();
    } else if(!start) {
      marte.explotar();
    }
    
    Planeta jupiter(  "jupiter",  pJup);
    if(seleccion != 6) {
      glPushName(JUPITER);
        jupiter.dibujar();
      glPopName();
    } else if(!start) {
      jupiter.explotar();
    }
    
    Planeta saturno(  "saturno",  pSat);
    if(seleccion != 7) {
      glPushName(SATURNO);
        saturno.dibujar();
      glPopName();
    } else if(!start) {
      saturno.explotar();
    }
    
    Planeta urano(    "urano",    pUra);
    if(seleccion != 8) {
      glPushName(URANO);
        urano.dibujar();
      glPopName();
    } else if(!start) {
      urano.explotar();
    }
    
    Planeta neptuno(  "neptuno",  pNep);
    if(seleccion != 9) {
      glPushName(NEPTUNO);
        neptuno.dibujar();
      glPopName();
    } else if(!start) {
      neptuno.explotar();
    }
    
    Planeta pluton(   "pluton",   pPlu);
    if(seleccion != 10) {
      glPushName(PLUTON);
        pluton.dibujar();
      glPopName();
    } else if(!start) {
      pluton.explotar();
    }
  
    /************************************************************************************/
    /*                                                                                  */
    /*                                     Naves                                        */
    /*                                                                                  */
    /************************************************************************************/
  
    Nave satelite1("satelite", random1);
    satelite1.dibujar();
    Nave satelite2("satelite", random2);
    satelite2.dibujar();
    Nave satelite3("satelite", random3);
    satelite3.dibujar();
    Nave satelite4("satelite", random4);
    satelite4.dibujar();
    Nave satelite5("satelite", random5);
    satelite5.dibujar();
    Nave satelite6("satelite", random6);
    satelite6.dibujar();
    Nave satelite7("satelite", random7);
    satelite7.dibujar();
    Nave satelite8("satelite", random8);
    satelite8.dibujar();
    Nave satelite9("satelite", random9);
    satelite9.dibujar();
    Nave satelite10("satelite", random10);
    satelite10.dibujar();
    Nave satelite11("cohete", random11);
    satelite11.dibujar();
    Nave satelite12("cohete", random12);
    satelite12.dibujar();
    Nave satelite13("cohete", random13);
    satelite13.dibujar();
    Nave satelite14("cohete", random14);
    satelite14.dibujar();
    Nave satelite15("cohete", random15);
    satelite15.dibujar();
    Nave satelite16("cohete", random16);
    satelite16.dibujar();
    Nave satelite17("cohete", random17);
    satelite17.dibujar();
    Nave satelite18("cohete", random18);
    satelite18.dibujar();
    Nave satelite19("cohete", random19);
    satelite19.dibujar();
    Nave satelite20("cohete", random20);
    satelite10.dibujar();
  
  
  glPopMatrix (); // restaura la matriz de modelado
}










