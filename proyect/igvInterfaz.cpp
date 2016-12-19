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
bool fullScreen = false;
int antiguoW;
int antiguoH;

/******************************* Metodos constructores **********************************************************************************/

igvInterfaz::igvInterfaz () {
  modo                = IGV_VISUALIZAR;
  objetoSeleccionado  = -1;
  pulsado             = false;
}

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
  
  camara.posicionarCamara(40, 40, 1,                                                      // Posici—n de la c‡mara
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
  
  gluPerspective(90.0,
                 static_cast<GLfloat>(interfaz.anchoVentana) / static_cast<GLfloat>(interfaz.altoVentana),
                 0.1,
                 100.0);
  
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
  //glEnable(GL_LIGHT0);
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
  interfaz.escena.visualizar(camara);                                                     // Dibuja la escena
  
  
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
      camara.moverCamara(0.03);                                                           // Mueve la c‡mara hacia delante
      break;
    case 'S':
    case 's':
      camara.moverCamara(-0.03);                                                          // Mueve la c‡mara hacia detr‡s
      break;
    case 'D':
    case 'd':
      camara.rotarVista(0.03);                                                            // Mueve la c‡mara hacia la derecha
      break;
    case 'A':
    case 'a':
      camara.rotarVista(-0.03);                                                           // Mueve la c‡mara hacia la izquierda
      break;
    case 'F':
    case 'f':                                                                             // Pone la app en pantalla completa
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
      interfaz.escena.setEjes(interfaz.escena.getEjes() ? false : true);                  // Activa/Desactiva los ejes
      break;
    case 27:
      exit(1);                                                                            // Tecla de escape para salir
      break;
  }
}

void igvInterfaz::setTeclasEspeciales(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_UP:
      camara.moverCamara(0.03);                                                           // Mueve la c‡mara hacia delante
      break;
    case GLUT_KEY_DOWN:
      camara.moverCamara(-0.03);                                                          // Mueve la c‡mara hacia detr‡s
      break;
    case GLUT_KEY_RIGHT:
      camara.rotarVista(0.03);                                                            // Mueve la c‡mara hacia la derecha
      break;
    case GLUT_KEY_LEFT:
      camara.rotarVista(-0.03);                                                           // Mueve la c‡mara hacia la izquierda
      break;
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
  
  //std::cout << "\nX: " << x << " Y: " << y;                                             // Muestra la posici—n del rat—n
  
  if(!fullScreen){
    if(x < 0 || x > interfaz.altoVentana) return;                                         // Evita que se actualice fuera de la ventana
    if(y < 0 || y > interfaz.anchoVentana) return;
  }
  
  //glutWarpPointer(midX, midY);
  
  angY = static_cast<GLfloat>( (midX - x) ) / 10000;                                      // Movimiento del rat—n y su velocidad
  angZ = static_cast<GLfloat>( (midY - y) ) / 500;
  
  //std::cout << "\n\t ang Y: " << angY << " ang >: " <<  angZ;
  
  camara.mView.y += angZ * 2;
  
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
   * Esta función debe devolver el c—digo del objeto seleccionado, que no tiene por quŽ
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
  
  if(numImpactos > 0)
    objetoSeleccionado = procesar(numImpactos, impactos);                                 // Si hay impactos, se pasa a procesarlos
  else
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










