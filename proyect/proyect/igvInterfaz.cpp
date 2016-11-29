#include <cstdlib>
#include <stdio.h>
#include <math.h>

#include "igvInterfaz.h"
#include "igvTextura.h"

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
// ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
  // crear cámaras
  interfaz.camara.set(IGV_PARALELA,
                      igvPunto3D(3.0, 4.0, 3.0),
                      igvPunto3D(0,   0,   0),
                      igvPunto3D(0,   1.0, 0),
                      -4.5, 4.5, -4.5, 4.5, -50, 200);
}

void igvInterfaz::configura_entorno(int argc, char** argv,
                                    int _ancho_ventana, int _alto_ventana,
                                    int _pos_X, int _pos_Y,
                                    string _titulo){
  // inicialización de las variables de la interfaz
  ancho_ventana = _ancho_ventana;
  alto_ventana = _alto_ventana;
  
  // inicialización de la ventana de visualización
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(_ancho_ventana,_alto_ventana);
  glutInitWindowPosition(_pos_X,_pos_Y);
  glutCreateWindow(_titulo.c_str());
  
  glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
  glClearColor(1.0,1.0,1.0,0.0); // establece el color de fondo de la ventana
  
  glEnable(GL_LIGHTING); // activa la iluminacion de la escena
  glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion
  
  glEnable(GL_TEXTURE_2D); // activa el uso de texturas
  
  interfaz.escena.nosotros.setNombre      ("Jugador");
  interfaz.escena.nosotros.setSpeed       ( 0.003f );
  interfaz.escena.nosotros.setPosicion    ( Vector3(5.0, 5.0, 12.0) );
  interfaz.escena.nosotros.setOrientacion ( Vector3(0, 1, 0), Vector3(0, 1, 0) );
  
  crear_mundo(); // crea el mundo a visualizar en la ventana
  
}

void igvInterfaz::inicia_bucle_visualizacion() {
  glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutSpecialFunc(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_RIGHT:
      interfaz.escena.nosotros.strafe(0.5f);
      break;
    case GLUT_KEY_LEFT:
      interfaz.escena.nosotros.strafe(-0.5f);
      break;
    case GLUT_KEY_UP:
      interfaz.escena.nosotros.pitch(-0.5f);
      break;
    case GLUT_KEY_DOWN:
      interfaz.escena.nosotros.pitch(0.5f);
      break;
  }
  
  igvPunto3D pos;
  pos[X] = interfaz.escena.nosotros.getPosicion().x;
  pos[Y] = interfaz.escena.nosotros.getPosicion().y;
  pos[Z] = interfaz.escena.nosotros.getPosicion().z;
  
  igvPunto3D orientacion;
  orientacion[X] = interfaz.escena.nosotros.getVectorOrientacion().x;
  orientacion[Y] = interfaz.escena.nosotros.getVectorOrientacion().y;
  orientacion[Z] = interfaz.escena.nosotros.getVectorOrientacion().z;
  
  interfaz.camara.set(IGV_PARALELA,
                      pos,
                      orientacion,
                      igvPunto3D(0, 1, 0),
                      -4.5, 4.5, -4.5, 5.5, -10, 200);
  
  interfaz.camara.aplicar();
  
  glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
  switch (key) {
    case 'p': // cambia el tipo de proyección de paralela a perspectiva y viceversa
      if(interfaz.camara.tipo == IGV_PARALELA) {
        interfaz.camara.set(IGV_PERSPECTIVA,
                            interfaz.camara.P0,
                            interfaz.camara.r,
                            interfaz.camara.V,
                            60, 1, 1, 200);
      }else{
        interfaz.camara.set(IGV_PARALELA,
                            interfaz.camara.P0,
                            interfaz.camara.r,
                            interfaz.camara.V,
                            -4.5, 4.5, -4.5, 5.5, -10, 200);
      }
      
      break;
    case '+':
      interfaz.camara.zoom(-0.05);
      interfaz.camara.aplicar();
      break;
    case '-':
      interfaz.camara.zoom(0.05);
      interfaz.camara.aplicar();
      break;
    case 'd':
    {
      interfaz.escena.nosotros.strafe(0.5f);
      igvPunto3D pos;
      pos[X] = interfaz.escena.nosotros.getPosicion().x;
      pos[Y] = interfaz.escena.nosotros.getPosicion().y;
      pos[Z] = interfaz.escena.nosotros.getPosicion().z;
      
      igvPunto3D orientacion;
      orientacion[X] = interfaz.escena.nosotros.getVectorOrientacion().x;
      orientacion[Y] = interfaz.escena.nosotros.getVectorOrientacion().y;
      orientacion[Z] = interfaz.escena.nosotros.getVectorOrientacion().z;
      
      interfaz.camara.set(IGV_PARALELA,
                          pos,
                          orientacion,
                          igvPunto3D(0, 1, 0),
                          -4.5, 4.5, -4.5, 5.5, -10, 200);
      
      interfaz.camara.aplicar();
      break;
    }
    case 'a':
    {
      interfaz.escena.nosotros.strafe(-0.5f);
      igvPunto3D pos;
      pos[X] = interfaz.escena.nosotros.getPosicion().x;
      pos[Y] = interfaz.escena.nosotros.getPosicion().y;
      pos[Z] = interfaz.escena.nosotros.getPosicion().z;
      
      igvPunto3D orientacion;
      orientacion[X] = interfaz.escena.nosotros.getVectorOrientacion().x;
      orientacion[Y] = interfaz.escena.nosotros.getVectorOrientacion().y;
      orientacion[Z] = interfaz.escena.nosotros.getVectorOrientacion().z;
      
      interfaz.camara.set(IGV_PARALELA,
                          pos,
                          orientacion,
                          igvPunto3D(0, 1, 0),
                          -4.5, 4.5, -4.5, 5.5, -10, 200);
      
      interfaz.camara.aplicar();
      break;
    }
    case 'w':
    {
      interfaz.escena.nosotros.pitch(-0.5f);
      igvPunto3D pos;
      pos[X] = interfaz.escena.nosotros.getPosicion().x;
      pos[Y] = interfaz.escena.nosotros.getPosicion().y;
      pos[Z] = interfaz.escena.nosotros.getPosicion().z;
      
      igvPunto3D orientacion;
      orientacion[X] = interfaz.escena.nosotros.getVectorOrientacion().x;
      orientacion[Y] = interfaz.escena.nosotros.getVectorOrientacion().y;
      orientacion[Z] = interfaz.escena.nosotros.getVectorOrientacion().z;
      
      interfaz.camara.set(IGV_PARALELA,
                          pos,
                          orientacion,
                          igvPunto3D(0, 1, 0),
                          -4.5, 4.5, -4.5, 5.5, -10, 200);
      
      interfaz.camara.aplicar();
      break;
    }
    case 's':
    {
      interfaz.escena.nosotros.pitch(0.5f);
      igvPunto3D pos;
      pos[X] = interfaz.escena.nosotros.getPosicion().x;
      pos[Y] = interfaz.escena.nosotros.getPosicion().y;
      pos[Z] = interfaz.escena.nosotros.getPosicion().z;
      
      igvPunto3D orientacion;
      orientacion[X] = interfaz.escena.nosotros.getVectorOrientacion().x;
      orientacion[Y] = interfaz.escena.nosotros.getVectorOrientacion().y;
      orientacion[Z] = interfaz.escena.nosotros.getVectorOrientacion().z;
      
      interfaz.camara.set(IGV_PARALELA,
                          pos,
                          orientacion,
                          igvPunto3D(0, 1, 0),
                          -4.5, 4.5, -4.5, 5.5, -10, 200);
      
      interfaz.camara.aplicar();
      break;
    }
    case 'c': // incrementar la distancia del plano cercano
      interfaz.camara.planocercano(0.2);
      break;
    case 'C': // decrementar la distancia del plano cercano
      interfaz.camara.planocercano(-0.2);
      break;
    case 'e': // activa/desactiva la visualizacion de los ejes
      interfaz.escena.set_ejes(interfaz.escena.get_ejes()?false:true);
      break;
    case 27: // tecla de escape para SALIR
      exit(1);
      break;
  }
  
  glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
  // dimensiona el viewport al nuevo ancho y alto de la ventana
  // guardamos valores nuevos de la ventana de visualizacion
  interfaz.set_ancho_ventana(w);
  interfaz.set_alto_ventana(h);
  
  // establece los parámetros de la cámara y de la proyección
  interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer
  
  // se establece el viewport
  glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());
  
  // establece los parámetros de la cámara y de la proyección
  interfaz.camara.aplicar();
  
  //visualiza la escena
  interfaz.escena.visualizar();
  
  // refresca la ventana
  glutSwapBuffers(); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}


void igvInterfaz::inicializa_callbacks() {
  glutKeyboardFunc(set_glutKeyboardFunc);
  glutReshapeFunc(set_glutReshapeFunc);
  glutDisplayFunc(set_glutDisplayFunc);
  glutSpecialFunc(set_glutSpecialFunc);
  
}










