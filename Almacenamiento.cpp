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


Almacenamiento::Almacenamiento() {}

void Almacenamiento::cargarDatos() {
  ifstream file("DatosPeliculas.csv");
  string line;

  int linea = 0;

  while (getline(file, line)) {
    if (linea == 0) {
      linea++;
      continue;
    }

    int count = contarValoresCSV(line);
    string id, nombre, duracion, calificacion, fechaEstreno, idEpisodio,
        nombreEpisodio, temporada, numeroEpisodio, generos;

    stringstream ss(line);

    getline(ss, id, ',');
    getline(ss, nombre, ',');
    getline(ss, duracion, ',');
    getline(ss, generos, ',');
    getline(ss, calificacion, ',');
    getline(ss, fechaEstreno, ',');

    if (count == 10) {
      getline(ss, idEpisodio, ',');
      getline(ss, nombreEpisodio, ',');
      getline(ss, temporada, ',');
      getline(ss, numeroEpisodio, ',');

      Episodio *episodio =
          new Episodio(id, nombre, stof(duracion), splitString(generos, '&'),
                       stof(calificacion), fechaEstreno, idEpisodio,
                       nombreEpisodio, stoi(numeroEpisodio), stoi(temporada));

      this->episodios.push_back(episodio);
    } else if (count == 6) {
      Video *video =
          new Video(id, nombre, stof(duracion), splitString(generos, '&'),
                    stof(calificacion), fechaEstreno);
      
      this->videos.push_back(video);
    }
  }

  cout << "Datos cargados correctamente" << endl;
  file.close();
}

void Almacenamiento::mostrarVideos() {
  for (const auto &video : this->videos) {
    video->imprimirInformacion();
    cout << endl;
  }

  for (const auto &episodio : this->episodios) {
    episodio->imprimirInformacion();
    cout << endl;
  }
}

void Almacenamiento::mostrarEpisodios() {
  string nombreSerie;
  cout << "Ingrese el nombre de la serie: ";
  cin.ignore();
  getline(cin, nombreSerie);

  for (const auto &episodio : this->episodios) {
    if (episodio->obtenerNombre() == nombreSerie) {
      episodio->imprimirInformacion();
      cout << endl;
    }
  }
}

void Almacenamiento::mostrarVideosCalificacion() {
  float calificacion;
  cout << "Ingrese la calificación: ";
  cin >> calificacion;

  for (const auto &video : this->videos) {
    if (video->obtenerCalificacion() >= calificacion) {
      video->imprimirInformacion();
      cout << endl;
    }
  }
}

void Almacenamiento::mostrarVideosPorCalificacion() {
  float calificacion;
  cout << "Ingrese la calificación: ";
  cin >> calificacion;

  cout << "Peliculas con calificación mayor o igual a " << calificacion
       << endl;
  for (const auto &video : this->videos) {
    if (video->obtenerCalificacion() >= calificacion) {
      video->imprimirInformacion();
      cout << endl;
    }
  }

  cout << "Episodios con calificación mayor o igual a " << calificacion
       << endl;
  for (const auto &episodio : this->episodios) {
    if (episodio->obtenerCalificacion() >= calificacion) {
      episodio->imprimirInformacion();
      cout << endl;
    }
  }
}

void Almacenamiento::mostrarVideosPorGenero() {
  string genero;
  cout << "Ingrese el género: ";
  cin >> genero;

  cout << "Peliculas con género " << genero << endl;
  for (const auto &video : this->videos) {
    if (video->tieneGenero(genero)) {
      video->imprimirInformacion();
      cout << endl;
    }
  }

  cout << "Episodios con género " << genero << endl;
  for (const auto &episodio : this->episodios) {
    if (episodio->tieneGenero(genero)) {
      episodio->imprimirInformacion();
      cout << endl;
    }
  }
}

void Almacenamiento::calcularPromedioSerie() {
  string nombreSerie;
  cout << "Ingrese el nombre de la serie: ";
  cin.ignore();
  getline(cin, nombreSerie);

  float promedio = 0;
  int count = 0;

  for (const auto &episodio : this->episodios) {
    if (episodio->obtenerNombre() == nombreSerie) {
      promedio += episodio->obtenerCalificacion();

      episodio->imprimirInformacion();
      cout << endl;

      count++;
    }
  }

  if (count == 0) {
    cout << "No se encontró la serie" << endl;
    return;
  }

  cout << "El promedio de la serie " << nombreSerie << " es "
       << promedio / count << endl;
}

void Almacenamiento::calificarVideo() {
  string nombreVideo;
  cout << "Ingrese el nombre de la pelicula/serie: ";
  cin.ignore();
  getline(cin, nombreVideo);

  bool encontrado = false;

  for (const auto &video : this->videos) {
    if (video->obtenerNombre() == nombreVideo) {
      cout << "Calificacion actual: " << video->obtenerCalificacion() << endl;
      float calificacion;
      cout << "Ingrese la calificación: ";
      cin >> calificacion;
      video->setCalificacion(calificacion);
      cout << "Calificación actualizada: " << video->obtenerCalificacion()
           << endl;
      encontrado = true;
    }
  }

  if (!encontrado) {
    for (const auto &episodio : this->episodios) {
      if (episodio->obtenerNombreEpisodio() == nombreVideo) {
        cout << "Calificacion actual: " << episodio->obtenerCalificacion()
             << endl;
        float calificacion;
        cout << "Ingrese la calificación: ";
        cin >> calificacion;
        episodio->setCalificacion(calificacion);
        cout << "Calificación actualizada: "
             << episodio->obtenerCalificacion() << endl;
        encontrado = true;
      }
    }
  }

  if (!encontrado) {
    cout << "No se encontró el video" << endl;
    return;
  }

  ofstream file;
  file.open("DatosPeliculas.csv");

  file << "ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha "
          "Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio"
       << endl;

  for (const auto &video : this->videos) {
    file << video->obtenerId() << "," << video->obtenerNombre() << ","
         << video->obtenerDuracion() << ",";
    for (const auto &genero : video->obtenerGeneros()) {
      if (genero != video->obtenerGeneros().back()) {
        file << genero;
        continue;
      }
      file << genero << "&";
    }
    file << "," << video->obtenerCalificacion() << ","
         << video->obtenerFechaEstreno() << endl;
  }

  for (const auto &episodio : this->episodios) {
    file << episodio->obtenerId() << "," << episodio->obtenerNombre() << ","
         << episodio->obtenerDuracion() << ",";
    for (const auto &genero : episodio->obtenerGeneros()) {
      if (genero != episodio->obtenerGeneros().back()) {
        file << genero;
        continue;
      }
      file << genero << "&";
    }
    file << "," << episodio->obtenerCalificacion() << ","
         << episodio->obtenerFechaEstreno() << ","
         << episodio->obtenerIdEpisodio() << ","
         << episodio->obtenerNombreEpisodio() << ","
         << episodio->obtenerNumeroTemporada() << ","
         << episodio->obtenerNumeroEpisodio() << endl;
  }
}
