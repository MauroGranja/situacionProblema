#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "Video.h"
#include "Episodio.h"
#include "Almacenamiento.h"
#include "Utils.h"

using namespace std;

void menuVideos(Almacenamiento *almacenamiento) {
  while (true) {
    system("clear");

    cout << "1. Mostrar videos por calificación" << endl;
    cout << "2. Mostrar videos por género" << endl;
    cout << "3. Mostrar todos los videos" << endl;
    cout << "4. Regresar" << endl;
    cout << "Ingrese una opción: ";

    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1:
      almacenamiento->mostrarVideosPorCalificacion();
      break;
    case 2:
      almacenamiento->mostrarVideosPorGenero();
      break;
    case 3:
      almacenamiento->mostrarVideos();
    case 4:
      return;
    default:
      cout << "Opción inválida" << endl;
      break;
    }

    enterParaContinuar();
  }
}

void menu() {
  Almacenamiento *almacenamiento = new Almacenamiento();
  bool datosCargados = false;

  while (true) {
    system("clear");

    cout << "1. Cargar datos" << endl;
    cout << "2. Mostrar videos" << endl;
    cout << "3. Mostrar episodios de serie" << endl;
    cout << "4. Mostrar peliculas por calificación" << endl;
    cout << "5. Calificar video" << endl;
    cout << "6. Calcular promedio de una serie" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese una opción: ";

    int opcion;
    cin >> opcion;

    if (!datosCargados && !(opcion == 1 || opcion == 7)) {
      cout << "Debe cargar los datos primero" << endl;
      enterParaContinuar();
      continue;
    }

    switch (opcion) {
    case 1:
      if (datosCargados) {
        cout << "Los datos ya fueron cargados" << endl;
        break;
      }
      almacenamiento->cargarDatos();
      datosCargados = true;
      break;
    case 2:
      menuVideos(almacenamiento);
      break;
    case 3:
      almacenamiento->mostrarEpisodios();
      break;
    case 4:
      almacenamiento->mostrarVideosCalificacion();
      break;
    case 5:
      almacenamiento->calificarVideo();
      break;
    case 6:
      almacenamiento->calcularPromedioSerie();
      break;
    case 7:
      return;
    }

    enterParaContinuar();
  }
}

int main() {
  menu();
  return 0;
}
