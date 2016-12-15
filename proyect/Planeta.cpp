/**
 * @file    Planeta.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    15/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <unistd.h> //Incluir <Windows.h> en Windows

#include <iostream>
#include "Planeta.h"
#include "igvTextura.h"


/****************************************************************************************/
/**                                                                                    **/
/**                    Implementación Planeta.cpp                                      **/
/**                                                                                    **/
/****************************************************************************************/


Planeta::Planeta(std::string nombre, tVector3 posicion)
:   nombre(nombre)
  , posicion(posicion)
{
  
};

Planeta::Planeta(const Planeta &orig) {
  nombre = orig.nombre;
  posicion = orig.posicion;
};

Planeta::~Planeta() {};

GLfloat diez[]   = {0.1, 0.1, 0.1};
GLfloat nueve[]  = {0.2, 0.2, 0.2};
GLfloat ocho[]   = {0.3, 0.3, 0.3};
GLfloat siete[]  = {0.4, 0.4, 0.4};
GLfloat seis[]   = {0.5, 0.5, 0.5};
GLfloat cinco[]  = {0.6, 0.6, 0.6};
GLfloat cuatro[] = {0.7, 0.7, 0.7};
GLfloat tres[]   = {0.8, 0.8, 0.8};
GLfloat dos[]    = {0.9, 0.9, 0.9};
GLfloat uno[]    = {1.0, 1.0, 1.0};
GLfloat angle = 0;

void Planeta::dibujar() {
  angle += 0.05;
  glPushMatrix();
  
    if(nombre == "sol") {
      glMaterialfv(GL_FRONT,GL_EMISSION,uno);
      glPushMatrix();
        glTranslatef(2, 2, 2);
        glRotatef(angle, 0, 1, 0);
      
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
          igvTextura textSol("/Users/dani/Desktop/texturas/sol.bmp");
          textSol.aplicar();
          gluSphere(qobj,5,50,50);
          gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);

      glPopMatrix();
    }
    
    if(nombre == "mercurio") {
      glMaterialfv(GL_FRONT,GL_EMISSION,dos);
      glPushMatrix();
        glTranslatef(7, 7, 7);
        glRotatef(angle, 0, 1, 0);

        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textMerc("/Users/dani/Desktop/texturas/mercurio.bmp");
        textMerc.aplicar();
        gluSphere(qobj,1,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      
      glPopMatrix();
    }
  
    if(nombre == "venus") {
      glMaterialfv(GL_FRONT,GL_EMISSION,tres);
      glPushMatrix();
        glTranslatef(9, 9, 9);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textVenus("/Users/dani/Desktop/texturas/venus.bmp");
        textVenus.aplicar();
        gluSphere(qobj,1.2,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
    
    if(nombre == "tierra") {
      glMaterialfv(GL_FRONT,GL_EMISSION,cuatro);
      glPushMatrix();
        glTranslatef(12, 12, 12);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textTierra("/Users/dani/Desktop/texturas/mapa2.bmp");
        textTierra.aplicar();
        gluSphere(qobj,1.4,50,50);
        gluDeleteQuadric(qobj);
      glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
    
    if(nombre == "marte") {
      glMaterialfv(GL_FRONT,GL_EMISSION,cinco);
      glPushMatrix();
        glTranslatef(15, 15, 15);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textMarte("/Users/dani/Desktop/texturas/marte.bmp");
        textMarte.aplicar();
        gluSphere(qobj,1.6,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
    
    if(nombre == "jupiter") {
      glMaterialfv(GL_FRONT,GL_EMISSION,seis);
      glPushMatrix();
        glTranslatef(18, 18, 18);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textJupiter("/Users/dani/Desktop/texturas/jupiter.bmp");
        textJupiter.aplicar();
        gluSphere(qobj,3,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
    
    if(nombre == "saturno") {
      glMaterialfv(GL_FRONT,GL_EMISSION,siete);
      glPushMatrix();
        glTranslatef(22, 22, 22);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textSaturno("/Users/dani/Desktop/texturas/saturno.bmp");
        textSaturno.aplicar();
        gluSphere(qobj,3.2,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
    
    if(nombre == "urano") {
      glMaterialfv(GL_FRONT,GL_EMISSION,ocho);
      glPushMatrix();
        glTranslatef(27, 27, 27);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textUrano("/Users/dani/Desktop/texturas/urano.bmp");
        textUrano.aplicar();
        gluSphere(qobj,3.4,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
    
    if(nombre == "neptuno") {
      glMaterialfv(GL_FRONT,GL_EMISSION,nueve);
      glPushMatrix();
        glTranslatef(31, 31, 31);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textNeptuno("/Users/dani/Desktop/texturas/neptuno.bmp");
        textNeptuno.aplicar();
        gluSphere(qobj,4,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
    
    if(nombre == "pluton") {
      glMaterialfv(GL_FRONT,GL_EMISSION,diez);
      glPushMatrix();
        glTranslatef(35, 35, 35);
        glRotatef(angle, 0, 1, 0);
        GLuint id;
        glGenTextures(1, &id);
        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj,GL_TRUE);
        glBindTexture(GL_TEXTURE_2D, id);
        glEnable(GL_TEXTURE_2D);
        igvTextura textPluton("/Users/dani/Desktop/texturas/pluton.bmp");
        textPluton.aplicar();
        gluSphere(qobj,0.5,50,50);
        gluDeleteQuadric(qobj);
        glDisable(GL_TEXTURE_2D);
      glPopMatrix();
    }
  
  glPopMatrix();
}
