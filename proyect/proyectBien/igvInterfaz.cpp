#include <cstdlib>
#include <stdio.h>
#include <math.h>

#include "igvInterfaz.h"
#include "Camara.h"

Camara camara;                                                                            // Se crea una c‡mara.

extern igvInterfaz interfaz;                                                              /* Los callbacks deben ser est‡ticos y se
                                                                                           * requiere este objeto para acceder desde ellos 
                                                                                           * a las variables de la clase
                                                                                           */
/******************************* Metodos constructores **********************************************************************************/

igvInterfaz::igvInterfaz () {}

igvInterfaz::~igvInterfaz () {}

/******************************* Metodos publicos ***************************************************************************************/

void igvInterfaz::configurarEntorno(int argc, char** argv,
                                    int _ancho_ventana, int _alto_ventana,
                                    int _pos_X, int _pos_Y,
                                    std::string _titulo) {
  
  ancho_ventana = _ancho_ventana;                                                         // Variables de la interfaz
  alto_ventana  = _alto_ventana;
  
  glutInit(&argc, argv);                                                                  // Inicializa la ventana de visualizaci—n
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(_ancho_ventana,_alto_ventana);                                       // Inicializa el tama–o de la ventana
  glutInitWindowPosition(_pos_X,_pos_Y);                                                  // Inicializa la posici—n de la ventana
  glutCreateWindow(_titulo.c_str());                                                      // Inicializa el nombre de la ventana
  
  camara.posicionarCamara(1, 0.5, 5,                                                      // Posici—n de la c‡mara
                          1, 0.5, 0,                                                      // Hacia d—nde mira
                          0, 1, 0);                                                       // Vector arriba
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
    case 'e':
      interfaz.escena.set_ejes(interfaz.escena.get_ejes() ? false : true);                // Activa/Desactiva los ejes
      break;
    case 27:
      exit(1);                                                                            // Tecla de escape para salir
      break;
  }
}

void igvInterfaz::movimientoRaton(int x, int y) {
  float angY  = 0.0f;
  float angZ  = 0.0f;
  
  float midX = interfaz.get_alto_ventana()/2;
  float midY = interfaz.get_ancho_ventana()/2;
  
  /*
  if(x < 0 || x > interfaz.get_alto_ventana()) return;
  if(y < 0 || y > interfaz.get_ancho_ventana()) return;
  */
  
 // glutWarpPointer(midX, midY);
  
  angY = static_cast<GLfloat>( (midX - x) ) / 100000;                                      // Movimiento del rat—n y su velocidad
  angZ = static_cast<GLfloat>( (midY - y) ) / 100000;
  
  camara.mView.y += angZ * 2;
  
  if((camara.mView.y - camara.mPos.y) > 8)
    camara.mView.y = camara.mPos.y + 8;                                                   // Limita el movimiento en el eje Y
  if((camara.mView.y - camara.mPos.y) <-8)
    camara.mView.y = camara.mPos.y - 8;
  
  camara.rotarVista(-angY);                                                               // Rota la c‡mara
}


void igvInterfaz::setReshape(int w, int h) {
  
  glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));                     // Dimensiona el viewport al nuevo ancho y alto

  interfaz.set_ancho_ventana(w);                                                          // Guarda los valores nuevos de la ventana
  interfaz.set_alto_ventana(h);

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

void Camera() {
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  
  gluPerspective(45.0,
                 static_cast<GLfloat>(interfaz.get_ancho_ventana()) / static_cast<GLfloat>(interfaz.get_alto_ventana()),
                 0.1,
                 100.0);
  
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(camara.mPos.x,  camara.mPos.y,  camara.mPos.z,                                // Establece la c‡mara
            camara.mView.x, camara.mView.y, camara.mView.z,
            camara.mUp.x,   camara.mUp.y,   camara.mUp.z);
  
  glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutDisplayFunc() {
  glutSetCursor(GLUT_CURSOR_NONE);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer
  glLoadIdentity();

  Camera();
  Enables();
  interfaz.escena.visualizar();

  // refresca la ventana
  glutSwapBuffers(); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}


void igvInterfaz::inicializa_callbacks() {
  glutDisplayFunc(set_glutDisplayFunc);
  glutReshapeFunc(setReshape);
  glutKeyboardFunc(setTeclas);
  glutPassiveMotionFunc(movimientoRaton);
  
  glutPostRedisplay(); // renueva el contenido de la ventana de vision
  
  
}










