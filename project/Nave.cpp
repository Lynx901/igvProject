/**
 * @file    Nave.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <iostream>
#include "Nave.h"

#ifndef Nave_cpp
#define	Nave_cpp

/****************************************************************************************/
/**                                                                                    **/
/**                      Implementación Nave.cpp                                       **/
/**                                                                                    **/
/****************************************************************************************/

Nave::Nave(std::string tipo, tVector3 posicion)
: tipo(tipo)
, posicion(posicion) {

};

Nave::Nave(const Nave &orig) {
  tipo = orig.tipo;
  posicion = orig.posicion;
};

Nave::~Nave() {};

GLfloat angulo = 0;
void Nave::dibujar() {
  GLfloat gris[]       = {0.5, 0.5,   0.5};
  GLfloat negro[]      = {0.0, 0.0,   0.0};
  GLfloat azul[]       = {0.0, 0.15,  0.61};
  GLfloat azulClaro[]  = {0.0, 0.55,  1.0};
  GLfloat rojo[]       = {0.8, 0.15,  0.15};
  
  angulo += 0.005;

  if(tipo == "satelite") {
    glPushMatrix();
      glRotatef(angulo, 0, 1, 0);
      glTranslatef(posicion.x, posicion.y, posicion.z);
      glScalef(0.05, 0.05, 0.05);
      glMaterialfv(GL_FRONT, GL_EMISSION, gris);
      // Cuerpo
      glTranslatef(0, 0, -2);
      GLUquadricObj *cuerpo;
      cuerpo = gluNewQuadric();
      gluQuadricDrawStyle(cuerpo, GLU_FILL);
      gluCylinder(cuerpo, 2, 2, 4, 20, 20);
      // Parte trasera
      glPushMatrix();
        glTranslatef(0, 0, 4);
        glutSolidSphere(2, 50, 50);
      glPopMatrix();
      // Parte delantera
      glPushMatrix();
        // Cabeza
        glTranslatef(0, 0, -4);
        GLUquadricObj *cabeza;
        cabeza = gluNewQuadric();
        gluQuadricDrawStyle(cabeza, GLU_FILL);
        gluCylinder(cabeza, 0.25, 2, 4, 20, 20);
        // Antena
        glTranslatef(0, 0, -2);
        GLUquadricObj *antena;
        antena = gluNewQuadric();
        glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
        gluQuadricDrawStyle(antena, GLU_FILL);
        gluCylinder(antena, 0.25, 0.25, 2, 20, 20);
        glutSolidSphere(0.5, 50, 50);
      glPopMatrix();
      // Brazo Izquierdo
      glMaterialfv(GL_FRONT, GL_EMISSION, negro);
      glPushMatrix();
        // Brazo
        glTranslatef(-6, 0, 2);
        glRotatef(90, 0, 1, 0);
        GLUquadricObj *brazoizq;
        brazoizq = gluNewQuadric();
        gluQuadricDrawStyle(brazoizq, GLU_FILL);
        gluCylinder(brazoizq, 0.5, 0.5, 4, 20, 20);
        // Panel
        glMaterialfv(GL_FRONT, GL_EMISSION, azul);
        glScalef(2, 2, 0.1);
        glutSolidCube(5);
      glPopMatrix();
      // Brazo Derecho
      glMaterialfv(GL_FRONT, GL_EMISSION, negro);
      glPushMatrix();
    glMaterialf(GL_FRONT, GL_SHININESS, 0.25 * 128.0);
        // Brazo
        glTranslatef(6, 0, 2);
        glRotatef(-90, 0, 1, 0);
        GLUquadricObj *brazoder;
        brazoder = gluNewQuadric();
        gluQuadricDrawStyle(brazoder, GLU_FILL);
        gluCylinder(brazoder, 0.5, 0.5, 4, 20, 20);
        // Panel
        glMaterialfv(GL_FRONT, GL_EMISSION, azul);
        glScalef(2, 2, 0.1);
        glutSolidCube(5);
      glPopMatrix();
    glPopMatrix();
  }
  
  
  
  if(tipo == "cohete") {
    glPushMatrix();
      glRotatef(angulo, 0, 1, 0);
      glTranslatef(posicion.x, posicion.y, posicion.z);
      glScalef(0.05, 0.05, 0.05);
      glRotatef(90, 0.5, 0.5, 0);
      // Cuerpo
      glMaterialfv(GL_FRONT, GL_EMISSION, gris);
      glTranslatef(0, 0, -4);
      GLUquadricObj *cuerpo;
      cuerpo = gluNewQuadric();
      gluQuadricDrawStyle(cuerpo, GLU_FILL);
      gluCylinder(cuerpo, 3, 3, 8, 20, 20);
      // Tapadera
      glPushMatrix();
        glTranslatef(0, 0, 8);
        GLUquadricObj *tapadera;
        tapadera = gluNewQuadric();
        gluQuadricDrawStyle(tapadera, GLU_FILL);
        gluDisk(tapadera, 0, 3, 50, 50);
      glPopMatrix();
      // Rallas rojas del cuerpo
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, azul);
        gluCylinder(cuerpo, 3.01, 3.01, 2, 20, 20);
        glTranslatef(0, 0, 6);
        gluCylinder(cuerpo, 3.01, 3.01, 2, 20, 20);
      glPopMatrix();
      // Alas
      glPushMatrix();
        // Laterales
        glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
        glRotatef(90, 1, 0, 0);
        for (int i = -4; i <= 4; i+=8) {
          glPushMatrix();
            glTranslatef(i, 8, 0);
            glScalef(0.5, 1.5, 0.1);
            glutSolidCube(5);
          glPopMatrix();
        }
        // Frontales
        glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
        glRotatef(90, 0, 1, 0);
        for (int i = 4; i >= -4; i-=8) {
          glPushMatrix();
            glTranslatef(i, 8, 0);
            glScalef(0.5, 1.5, 0.1);
            glutSolidCube(5);
          glPopMatrix();
        }
      glPopMatrix();
      // Cabeza
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, gris);
        glTranslatef(0, 0, -3);
        GLUquadricObj *cabeza;
        cabeza = gluNewQuadric();
        gluQuadricDrawStyle(cabeza, GLU_FILL);
        gluCylinder(cabeza, 1, 3, 3, 20, 20);
        // Escotilla
        glPushMatrix();
          glMaterialfv(GL_FRONT, GL_EMISSION, azul);
          glRotatef(-125, 1, 0, 0);
          glTranslatef(0, -2, 0);
          GLUquadricObj *escotilla;
          escotilla = gluNewQuadric();
          gluQuadricDrawStyle(escotilla, GLU_FILL);
          gluCylinder(escotilla, 1, 1, 1, 20, 20);
          // Ventana
          glMaterialfv(GL_FRONT, GL_EMISSION, azulClaro);
          glTranslatef(0, 0, 1);
          GLUquadricObj *ventana;
          ventana = gluNewQuadric();
          gluQuadricDrawStyle(ventana, GLU_FILL);
          gluDisk(ventana, 0, 1, 50, 50);
        glPopMatrix();
        // Antena
        glPushMatrix();
          glMaterialfv(GL_FRONT, GL_EMISSION, gris);
          // Base de la antena
          glutSolidSphere(1, 50, 50);
          // Palo de la antena
          glTranslatef(0, 0, -3);
          glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
          GLUquadricObj *antena;
          antena = gluNewQuadric();
          gluQuadricDrawStyle(antena, GLU_FILL);
          gluCylinder(antena, 0.25, 0.25, 2, 20, 20);
          // Cabeza de la antena
          glutSolidSphere(0.5, 50, 50);
        glPopMatrix();
      glPopMatrix();
    glPopMatrix();
  }
}


#endif	/* Nave_cpp */
