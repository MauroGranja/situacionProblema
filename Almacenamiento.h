#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "Video.h"
#include "Episodio.h"

using namespace std;

class Almacenamiento
{
  vector<Video*> videos;
  vector<Episodio*> episodios;
public:
  Almacenamiento();
  void cargarDatos();
  void mostrarVideos();
  void mostrarEpisodios();
  void mostrarVideosCalificacion();
  void mostrarVideosPorCalificacion();
  void mostrarVideosPorGenero();
  void calcularPromedioSerie();
  void calificarVideo();
};

#endif // !ALMACENAMIENTO_H
