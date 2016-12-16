#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "igvInterfaz.h"
#include "Camara.h"

Camara camara;                                                                            // Se crea una c‡mara.

extern igvInterfaz interfaz;                                                              /* Los callbacks deben ser est‡ticos y se
                                                                                           * requiere este objeto para acceder desde ellos 
                                                                                           * a las variables de la clase
                                                                                           */
bool fullScreen = false;
int antiguoW;
int antiguoH;

/******************************* Metodos constructores **********************************************************************************/

igvInterfaz::igvInterfaz () {}

igvInterfaz::~igvInterfaz () {}

/******************************* Metodos publicos ***************************************************************************************/

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
  
  camara.posicionarCamara(40, 40, 1,                                                       // Posici—n de la c‡mara
                          25, 25, 25,                                                        // Hacia d—nde mira
                          0, 1, 0);                                                       // Vector arriba
}

void Camera() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  gluPerspective(45.0,
                 static_cast<GLfloat>(interfaz.getAncho()) / static_cast<GLfloat>(interfaz.getAlto()),
                 0.1,
                 100.0);
  
  glMatrixMode(GL_MODELVIEW);
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
  glutSetCursor(GLUT_CURSOR_NONE);                                                        // Esconde el cursor en la aplicaci—n
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                                     // Borra la ventana y el z-buffer
  glLoadIdentity();
  
  Camera();                                                                               // Llama al set-up de la c‡mara
  Enables();                                                                              // Hace los glEnables correspondientes
  interfaz.escena.visualizar(camara.mPos);                                                // Dibuja la escena
  
  glutSwapBuffers();                                                                      // Refresca la ventana sin parpadeos
}

int contador;
void igvInterfaz::setReshape(int w, int h) {
  
  glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));                     // Dimensiona el viewport al nuevo ancho y alto
  
  interfaz.setAncho(w);                                                                   // Guarda los valores nuevos de la ventana
  interfaz.setAlto(h);
  
  glutPostRedisplay();                                                                    // Renueva el contenido de la ventana de visi—n
}

void igvInterfaz::setTeclas(unsigned char key, int x, int y) {
  switch (key) {
    case 'w':
      camara.moverCamara(0.03);                                                           // Mueve la c‡mara hacia delante
      break;
    case 's':
      camara.moverCamara(-0.03);                                                          // Mueve la c‡mara hacia detr‡s
      break;
    case 'd':
      camara.rotarVista(0.03);                                                            // Mueve la c‡mara hacia la derecha
      break;
    case 'a':
      camara.rotarVista(-0.03);                                                           // Mueve la c‡mara hacia la izquierda
      break;
    case 'f':                                                                             // Pone la app en pantalla completa
      if(!fullScreen){
        antiguoH = interfaz.getAlto();
        antiguoW = interfaz.getAncho();
        glutFullScreen();
        fullScreen = true;
      } else {
        glutReshapeWindow(antiguoH, antiguoW);
        fullScreen = false;
      }
      break;
    case 'e':
      interfaz.escena.setEjes(interfaz.escena.getEjes() ? false : true);                  // Activa/Desactiva los ejes
      break;
    case 27:
      exit(1);                                                                            // Tecla de escape para salir
      break;
  }
}

void igvInterfaz::movimientoRaton(int x, int y) {
  float angY  = 0.0;
  float angZ  = 0.0;
  
  float midX = interfaz.getAlto()/2;
  float midY = interfaz.getAncho()/2;
  
  //std::cout << "\nX: " << x << " Y: " << y;                                             // Muestra la posici—n del rat—n
  
  if(!fullScreen){
    if(x < 0 || x > interfaz.getAlto()) return;                                             // Evita que se actualice fuera de la ventana
    if(y < 0 || y > interfaz.getAncho()) return;
  }
  
  //glutWarpPointer(midX, midY);
  
  angY = static_cast<GLfloat>( (midX - x) ) / 10000;                                       // Movimiento del rat—n y su velocidad
  angZ = static_cast<GLfloat>( (midY - y) ) / 500;
  
  //std::cout << "\n\t ang Y: " << angY << " ang >: " <<  angZ;
  
  camara.mView.y += angZ * 2;
  
  if((camara.mView.y - camara.mPos.y) >  80)
    camara.mView.y = camara.mPos.y + 80;                                                   // Limita el movimiento en el eje Y
  if((camara.mView.y - camara.mPos.y) < -80)
    camara.mView.y = camara.mPos.y - 80;
  
  camara.rotarVista(-angY);                                                               // Rota la c‡mara
}



void igvInterfaz::initCallbacks() {
  glutDisplayFunc(setDisplay);                                                            // Se visualiza la escena
  glutReshapeFunc(setReshape);                                                            // Establece el viewport para redimensionar
  glutKeyboardFunc(setTeclas);                                                            // Permite el control por teclas NO especiales
  glutPassiveMotionFunc(movimientoRaton);
  
  glutPostRedisplay();                                                                    // Renueva el contenido de la ventana de vision
}










