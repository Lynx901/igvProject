/**
 * @file    igvInterfaz.cpp
 * @brief   Archivo del proyecto: proyect
 * @author  Daniel Moya Leiva
 * @version 1.0
 * @date    14/12/16
 *
 *   Copyright © 2016 Daniel Moya. All rights reserved.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "igvInterfaz.h"
#include "Camara.h"

Camara camara(false);                                                                     // Se crea una c‡mara.

extern igvInterfaz interfaz;                                                              /* Los callbacks deben ser est‡ticos y se
                                                                                           * requiere este objeto para acceder desde ellos 
                                                                                           * a las variables de la clase
                                                                                           */

int const BOTON = 11;

bool fullScreen = false;
int antiguoW;
int antiguoH;

igvInterfaz::igvInterfaz () {
  modo                = IGV_VISUALIZAR;
  objetoSeleccionado  = -1;
  pulsado             = false;
  start               = true;
  contador            = 10;
}

igvInterfaz::~igvInterfaz () {}

void igvInterfaz::configurarEntorno(int argc, char** argv,
                                    int ancho, int alto,
                                    int _pos_X, int _pos_Y,
                                    std::string _titulo) {
  
  anchoVentana = ancho;                                                                   // Variables de la interfaz
  altoVentana  = alto;
  
  glutInit(&argc, argv);                                                                  // Inicializa la ventana de visualizaci—n
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(anchoVentana,altoVentana);                                           // Inicializa el tama–o de la ventana
  glutInitWindowPosition(_pos_X,_pos_Y);                                                  // Inicializa la posici—n de la ventana
  glutCreateWindow(_titulo.c_str());                                                      // Inicializa el nombre de la ventana
  
  camara.posicionarCamara(25, 25, 1,                                                      // Posici—n de la c‡mara
                          25, 25, 25,                                                     // Hacia d—nde mira
                          0, 1, 0);                                                       // Vector arriba
}

void Camera() {
  if(!camara.modoSelect) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


  } else {
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    GLint viewport[4];                                                                    // Obtiene el tama–o actual del viewport
    glGetIntegerv(GL_VIEWPORT, viewport);
    
    gluPickMatrix(interfaz.cursorX,                                                       // Carga la matriz de proyecci—n
                  viewport[3] - interfaz.cursorY,                                         // y genera el volumen de visi—n
                  camara.anchoSeleccion,                                                  // para la selecci—n alrededor del pixel
                  camara.altoSeleccion,                                                   // pulsado
                  viewport);
  }
  
  gluPerspective(45,
                 static_cast<GLfloat>(interfaz.anchoVentana) / static_cast<GLfloat>(interfaz.altoVentana),
                 0.1,
                 200.0);
  
  glMatrixMode (GL_MODELVIEW);                                                            // Carga la matriz de modelado
  glLoadIdentity();
  gluLookAt(camara.mPos.x,  camara.mPos.y,  camara.mPos.z,                                // Establece la c‡mara
            camara.mView.x, camara.mView.y, camara.mView.z,
            camara.mUp.x,   camara.mUp.y,   camara.mUp.z);
  

  
  glutPostRedisplay();                                                                    // Renueva el contenido de la ventana de visi—n
}

void Enables(void){
  
  glEnable(GL_DEPTH_TEST);                                                                // Activa el ocultamiento de caras ocultas
  glEnable(GL_LIGHTING);                                                                  // Activa la luz
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);                                                                 // Normaliza para la luz
  glEnable(GL_TEXTURE_2D);                                                                // Activa las texturas
  
  glShadeModel(GL_SMOOTH);                                                                // Establece las luces "smooth"
  
  glClearColor(1.0, 1.0, 1.0, 1.0);                                                       // Establece el color de fondo de la ventana
}

void igvInterfaz::setDisplay() {
  GLuint impactos[1024];                                                                  // Lista impactos cuando modo = IGV_SELECCIONAR
  
  glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);                                              // Cambia el cursor en la aplicaci—n
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                                     // Borra la ventana y el z-buffer
  glLoadIdentity();
  
  
  if(interfaz.modo == IGV_SELECCIONAR)
    interfaz.initSeleccion(1024, impactos);                                               // Se pasa a modo selecci—n
  
  Camera();                                                                               // Llama al set-up de la c‡mara
  Enables();                                                                              // Hace los glEnables correspondientes
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Instrucciones                                              */
  /*                                                                                    */
  /**************************************************************************************/
  if((interfaz.objetoSeleccionado >= 1 && interfaz.objetoSeleccionado <= 10) &&
     interfaz.contador > 0){
    
    interfaz.contador--;
    interfaz.objetoSeleccionado = -1;
    std::cout << "Contador: " << interfaz.contador << std::endl;
    
  }
  
  if(interfaz.start) {
    camara.posicionarCamara(25, 25, 1,                                                    // Posici—n de la c‡mara
                            25, 25, 25,                                                   // Hacia d—nde mira
                            0, 1, 0);                                                     // Vector arriba
    
    GLfloat blanco[]={1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, blanco);
    
    igvTextura instrucciones("/Users/dani/Desktop/texturas/instrucciones.bmp");
    instrucciones.aplicar();
    
    glNormal3f(0, 1, 0);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 0);
      glVertex3f(29, 20, 15);    //abajo izq
      
      glTexCoord2f(1, 0);
      glVertex3f(21.5, 20, 15);  //abajo der
      
      glTexCoord2f(1, 1);
      glVertex3f(21.5, 30, 15);  //arriba der
      
      glTexCoord2f(0, 1);
      glVertex3f(29, 30, 15);    //arriba izq
    glEnd();
    
    GLfloat verde[] = {0.0, 1.0, 0.0, 0.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, verde);
    
    glPushName(BOTON);
      glPushMatrix();
        glTranslatef(25, 21, 15);
        glScalef(2, 0.7, 0.1);

        glutSolidCube(1);
      glPopMatrix();
    glPopName();
    
    if(interfaz.objetoSeleccionado == BOTON)
      interfaz.start = false;
  }
  
  /**************************************************************************************/
  /*                                                                                    */
  /*                         Fin                                                        */
  /*                                                                                    */
  /**************************************************************************************/
  
  
  if(interfaz.contador == 0) {
    camara.posicionarCamara(25, 25, 1,                                                      // Posici—n de la c‡mara
                            25, 25, 25,                                                     // Hacia d—nde mira
                            0, 1, 0);                                                       // Vector arriba
 
    GLfloat blanco[]={1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, blanco);
    
    igvTextura instrucciones("/Users/dani/Desktop/texturas/fin.bmp");
    instrucciones.aplicar();
    
    glNormal3f(0, 1, 0);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 0);
      glVertex3f(29, 20, 15);    //abajo izq
      
      glTexCoord2f(1, 0);
      glVertex3f(21.5, 20, 15);  //abajo der
      
      glTexCoord2f(1, 1);
      glVertex3f(21.5, 30, 15);  //arriba der
      
      glTexCoord2f(0, 1);
      glVertex3f(29, 30, 15);    //arriba izq
    glEnd();
      
    GLfloat verde[] = {0.0, 1.0, 0.0, 0.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, verde);
    
    glPushName(BOTON);
      glPushMatrix();
        glTranslatef(25, 21, 15);
        glScalef(2, 0.7, 0.1);
        
        glutSolidCube(1);
      glPopMatrix();
    glPopName();
      
    if(interfaz.objetoSeleccionado == BOTON) {
      interfaz.contador = 10;
    }
  }
  
  interfaz.escena.visualizar(camara, interfaz.start);                                     // Dibuja la escena
  
  
  if(interfaz.modo == IGV_SELECCIONAR)
    interfaz.endSeleccion(1024, impactos);                                                // Salir del modo selecci—n y procesar impactos
  else
    glutSwapBuffers();                                                                    // Refresca la ventana sin parpadeos
}

void igvInterfaz::setReshape(int w, int h) {
  glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));                     // Dimensiona el viewport al nuevo ancho y alto
  
  interfaz.anchoVentana = w;                                                              // Guarda los valores nuevos de la ventana
  interfaz.anchoVentana = h;
  
  glutPostRedisplay();                                                                    // Renueva el contenido de la ventana de visi—n
}

/**************************************************************************************/
/*                                                                                    */
/*                         Control de las teclas                                      */
/*                                                                                    */
/**************************************************************************************/

void igvInterfaz::setTeclas(unsigned char key, int x, int y) {
    switch (key) {
      case 'W':
      case 'w':
        if(!interfaz.start)
        camara.moverCamara(0.03);                                                         // Mueve la c‡mara hacia delante
        break;
      case 'S':
      case 's':
        if(!interfaz.start)
        camara.moverCamara(-0.03);                                                        // Mueve la c‡mara hacia detr‡s
        break;
      case 'D':
      case 'd':
        if(!interfaz.start)
        camara.rotarVista(0.03);                                                          // Mueve la c‡mara hacia la derecha
        break;
      case 'A':
      case 'a':
        if(!interfaz.start)
          
        camara.rotarVista(-0.03);                                                         // Mueve la c‡mara hacia la izquierda
        break;
      case 'F':
      case 'f':                                                                           // Pone la app en pantalla completa
        if(!fullScreen){
          antiguoH = interfaz.altoVentana;
          antiguoW = interfaz.anchoVentana;
          glutFullScreen();
          fullScreen = true;
        } else {
          glutReshapeWindow(antiguoH, antiguoW);
          fullScreen = false;
        }
        break;
      case 'E':
      case 'e':
        interfaz.escena.setEjes(interfaz.escena.getEjes() ? false : true);                // Activa/Desactiva los ejes
        break;
      case 27:
        exit(1);                                                                          // Tecla de escape para salir
        break;
  }
}

void igvInterfaz::setTeclasEspeciales(int key, int x, int y) {
  if(!interfaz.start) {
    switch (key) {
      case GLUT_KEY_UP:
        camara.moverCamara(0.03);                                                         // Mueve la c‡mara hacia delante
        break;
      case GLUT_KEY_DOWN:
        camara.moverCamara(-0.03);                                                        // Mueve la c‡mara hacia detr‡s
        break;
      case GLUT_KEY_RIGHT:
        camara.rotarVista(0.03);                                                          // Mueve la c‡mara hacia la derecha
        break;
      case GLUT_KEY_LEFT:
        camara.rotarVista(-0.03);                                                         // Mueve la c‡mara hacia la izquierda
        break;
    }
  }
}

/**************************************************************************************/
/*                                                                                    */
/*                         Control de la c‡mara                                       */
/*                                                                                    */
/**************************************************************************************/

void igvInterfaz::movimientoRaton(int x, int y) {

  float angY  = 0.0;                                                                      // Necesarias para el c‡lculo del movimiento
  float angZ  = 0.0;
  
  float midX = interfaz.altoVentana/2;                                                    // Guarda los centros de la pantalla
  float midY = interfaz.anchoVentana/2;
  
  if(!fullScreen){
    if(x < 0 || x > interfaz.altoVentana) return;                                         // Evita que se actualice fuera de la ventana
    if(y < 0 || y > interfaz.anchoVentana) return;
  }
  
  angY = static_cast<GLfloat>( (midX - x) ) / 10000;                                      // Movimiento del rat—n y su velocidad
  angZ = static_cast<GLfloat>( (midY - y) ) / 500;
  
  camara.mView.y += angZ;
  
  if((camara.mView.y - camara.mPos.y) >  80)
    camara.mView.y = camara.mPos.y + 80;                                                  // Limita el movimiento en el eje Y
  if((camara.mView.y - camara.mPos.y) < -80)
    camara.mView.y = camara.mPos.y - 80;
  
  camara.rotarVista(-angY);                                                               // Rota la c‡mara
  
  glutPostRedisplay();
}

void igvInterfaz::pulsacionRaton(GLint boton, GLint estado, GLint x, GLint y) {
  if(boton == 0) {                                                                        // Si el bot—n pulsado es el izquierdo
    if(estado == GLUT_DOWN) {                                                             // Si est‡ pulsado
      interfaz.pulsado = true;                                                            // Activa la pulsaci—n
      interfaz.modo    = IGV_SELECCIONAR;                                                 // Cambia el modo de la interfaz
      
      interfaz.cursorX = x;                                                               // Guarda la posici—n de la pulsaci—n
      interfaz.cursorY = y;
    } else
      interfaz.pulsado = false;
    
    glutPostRedisplay();
    
    if(estado == GLUT_UP) {                                                               // Si no est‡ pulsado
      interfaz.pulsado = false;                                                           // No activa la pulsaci—n
    }
  }
}

/**************************************************************************************/
/*                                                                                    */
/*                         Control de impactos                                        */
/*                                                                                    */
/**************************************************************************************/

void igvInterfaz::initSeleccion(int TAMANO_LISTA_IMPACTOS, GLuint *impactos) {
  glSelectBuffer(TAMANO_LISTA_IMPACTOS, impactos);                                        // Establece d—nde se almacenan los impactos
  
  glRenderMode(GL_SELECT);                                                                // Pasa al modo "GL_SELECT"
  
  camara.establecerSeleccion(1, 1, cursorX, cursorY);
}

int procesar(int numImpactos, GLuint *impactos) {
  /*
   * Esta funci—n debe devolver el c—digo del objeto seleccionado, que no tiene por quŽ
   * coincidir con el nombre asignado con la pila de nombres. Si se han utilizado nombres
   * jer‡rquicos hay que tener en cuenta que esta funci—n s—lo devuevle un œnico c—digo
   *
   */
  
  GLuint minZ = 0xffffffff;                                                               // M’nima Z seleccionada (m‡xima al principio)
  GLuint nombres = 0;
  int recorre = 0;
  int aux     = 0;
  
  for(int i = 0; i < numImpactos; i++) {                                                  // Recorre el vector de impactos
    aux = impactos[recorre];
    if(impactos[recorre + 1] < minZ) {
      minZ    = impactos[recorre + 1];
      nombres = impactos[recorre + 3];
    }
    recorre += 3 + aux;
  }
  
  if(nombres > 0)
    return nombres;                                                                       // Devuelve el c—digo del objeto seleccionado
  
  return(-1);                                                                             // Si no se ha seleccionado ninguno, devuelve -1
}

void igvInterfaz::endSeleccion(int TAMANO_LISTA_IMPACTOS, GLuint *impactos) {
  int numImpactos = glRenderMode(GL_RENDER);                                              // Vuelve a "GL_RENDER" y obtiene n¼ impactos
  
  if(numImpactos > 0) {
    objetoSeleccionado = procesar(numImpactos, impactos);                                 // Si hay impactos, se pasa a procesarlos
  }else
    objetoSeleccionado = 0;
  

  escena.seleccion = objetoSeleccionado;                                                  // Se pasa el resultado a la escena

  interfaz.modo = IGV_VISUALIZAR;                                                         // Pasamos al modo IGV_VISUALIZAR para terminar
  camara.modoSelect = false;
}


/**************************************************************************************/
/*                                                                                    */
/*                         Callbacks                                                  */
/*                                                                                    */
/**************************************************************************************/

void igvInterfaz::initCallbacks() {
  glutDisplayFunc(setDisplay);                                                            // Se visualiza la escena
  glutReshapeFunc(setReshape);                                                            // Establece el viewport para redimensionar
  glutKeyboardFunc(setTeclas);                                                            // Permite el control por teclas NO especiales
  glutSpecialFunc(setTeclasEspeciales);                                                   // Permite el control por teclas NO especiales
  glutPassiveMotionFunc(movimientoRaton);                                                 // Controla movimiento del rat—n sin pulsaci—n
  glutMouseFunc(pulsacionRaton);                                                          // Controla las pulsaciones del rat—n
  
  
  
  glutPostRedisplay();                                                                    // Renueva el contenido de la ventana de vision
}










