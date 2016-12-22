# igvProject
Proyecto de prácticas de la asignatura Informática Gráfica y Visualización
Instalación.


macOS con Xcode (RECOMENDADO)
-----------------------------
+ Crea un nuevo proyecto de línea de comandos.
+ Elimina el archivo main.cpp que crea automáticamente.
+ Añade los archivos y directorios de la carpeta /FUENTE
+ Haz click sobre el nombre de tu proyecto y pulsa en el apartado “Build Phases”
+ Haz click sobre “Link Binary With Libreries"
+ Haz click en el + y añade GLUT.framework y OpenGL.framework
+ Haz click sobre “Build Settings” y busca “deprecated”
+ En “Apple LLVM 8.0 - Warnings - All Lenguajes” pon a “No” el apartado “Deprecated Functions”
+ Cambia #include \<GLUT/glut.h>  en camara.cpp, igvColor.h, igvEscena3D.h, igvFuenteLuz.h, igvTextura.h, igvInterfaz.h, Nave.cpp y Planeta.cpp por:

\#include \<OpenGL/gl.h>
\#include \<OpenGL/glu.h>
\#include \<GLUT/glut.h>

+ Ejecuta.
+ Si al ejecutar no carga las texturas, es porque en Xcode hay que meter la ruta completa del archivo, así que si pulsas shift+cmd+f y buscas “texturas” podrás localizar todos los sitios donde cambiar la ruta /texturas/algo por la ruta completa del archivo (algo como /Users/dani/Desktop/FUENTE/texturas/algo).

Windows con Visual Studio
-------------------------
+ Pulsa en “Nuevo” y luego en “Proyecto a partir de código existente…”
+ Agrega la carpeta /FUENTE y ponle un nombre al proyecto
+ En “Tipo de proyecto” selecciona “Proyecto de aplicación de consola”
+ En la siguiente ventana déjalo todo en blanco y dale a “Siguiente”
+ Ejecuta.
+ Si al ejecutar no carga las texturas, posiblemente sea por la ruta, ya que depende de dónde esté situada la carpeta /texturas. Todas están en los archivos igvEscena3D.cpp, igvInterfaz.cpp, o Planeta.cpp, por lo que cambiar las rutas es una operación trivial.
