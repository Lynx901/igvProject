#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include <math.h>
#include <iostream>

#include "igvCamara.h"

// Metodos constructores

igvCamara::igvCamara () {}

igvCamara::~igvCamara () {}

igvCamara::igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
  P0 = _P0;
  r = _r;
  V = _V;
  
  tipo = _tipo;
}


// Metodos publicos
void igvCamara::set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
  P0 = _P0;
  r = _r;
  V = _V;
}
void igvCamara::set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
                    double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar) {
  tipo = _tipo;
  
  P0 = _P0;
  r = _r;
  V = _V;
  
  xwmin = _xwmin;
  xwmax = _xwmax;
  ywmin = _ywmin;
  ywmax = _ywmax;
  znear = _znear;
  zfar = _zfar;
}

void igvCamara::set(tipoCamara _tipo,
                    igvPunto3D _P0,
                    igvPunto3D _r,
                    igvPunto3D _V,
                    double _angulo,
                    double _raspecto,
                    double _znear,
                    double _zfar) {
  tipo = _tipo;
  
  P0 = _P0;
  r = _r;
  V = _V;
  
  angulo = _angulo;
  raspecto = _raspecto;
  znear = _znear;
  zfar = _zfar;
}

void igvCamara::aplicar(void) {
  
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  
  if (tipo==IGV_PARALELA) {
    glOrtho(xwmin, xwmax, ywmin, ywmax, znear, zfar);
  }
  if (tipo==IGV_FRUSTUM) {
    glFrustum(xwmin, xwmax, ywmin, ywmax, znear, zfar);
  }
  if (tipo==IGV_PERSPECTIVA) {
    gluPerspective(angulo,raspecto,znear,zfar);
  }

  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(P0[X],P0[Y],P0[Z],
            r[X],r[Y],r[Z],
            V[X],V[Y],V[Z]);
  
}

void igvCamara::zoom(double factor) {
  if(tipo == IGV_PERSPECTIVA){
    angulo += factor * 20;
    if(angulo > 180) {
      angulo = 180;
    }
  }else if (tipo==IGV_PARALELA) {
		  xwmin += xwmin * factor;
		  xwmax += xwmax * factor;
		  ywmin += ywmin * factor;
		  ywmax += ywmax * factor;
  }
}

void igvCamara::miraIzq(double valor) {
  anguloCamaraX += valor;
}

void igvCamara::miraDer(double valor) {
  anguloCamaraX -= valor;
}

void igvCamara::miraArriba(double valor) {
  anguloCamaraY += valor;
}

void igvCamara::miraAbajo(double valor) {
  anguloCamaraY -= valor;
}








