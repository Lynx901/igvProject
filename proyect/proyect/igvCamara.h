#ifndef __IGVCAMARA
#define __IGVCAMARA

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "igvPunto3D.h"

typedef enum {
	IGV_PARALELA,
	IGV_FRUSTUM,
	IGV_PERSPECTIVA
} tipoCamara;

typedef enum {
  primera,
  alzado,
  planta,
  perfil,
} posicion;

class igvCamara {

	public:
		// atributos
    posicion p;
    float anguloCamaraX;
    float anguloCamaraY;
  
		tipoCamara tipo;	// paralela o perspectiva

		// ventana de visión: parametros proyección paralela y frustum
		GLdouble xwmin, xwmax, ywmin, ywmax;

		// ventana de visión: parametros proyección perspectiva
		GLdouble 	angulo, raspecto;

		// distancias de planos cercano y lejano
		GLdouble znear, zfar;

		// punto de visión	
		igvPunto3D P0;

		// punto de referencia de visión	
		igvPunto3D r;

		// vector arriba	
		igvPunto3D V;

		// Metodos

	public:
		// Constructores por defecto y destructor
		igvCamara();
		~igvCamara();

		// Otros constructores
		igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

		// Metodos
		// define la posición de la cámara
		void set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

		// define una cámara de tipo paralela o frustum
		void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                         double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar);

		// define una cámara de tipo perspectiva
		void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                         double _angulo, double _raspecto, double _znear, double _zfar);

		void aplicar(void); // aplica a los objetos de la escena la transformación de visión y la transformación de proyección
		                    // asociadas a los parámetros de la cámara
		void zoom(double factor); // realiza un zoom sobre la cámara
  
    void planocercano(double factor) { znear += factor; }
    void miraIzq(double valor);
    void miraDer(double valor);
    void miraArriba(double valor);
    void miraAbajo(double valor);

};

#endif

