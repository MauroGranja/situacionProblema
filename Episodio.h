#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <string>
#include <vector>

#include "Video.h"

using namespace std;

class Episodio : public Video {
  string idEpisodio;
  string nombreEpisodio;
  int numeroEpisodio;
  int numeroTemporada;

public:
  Episodio(string id, string nombre, float duracion, vector<string> generos, float calificacion, string fechaEstreno, string idEpisodio, string nombreEpisodio, int numeroEpisodio, int numeroTemporada);
  string obtenerIdEpisodio();
  string obtenerNombreEpisodio();
  int obtenerNumeroEpisodio();
  int obtenerNumeroTemporada();
  void imprimirInformacion() override;
};

#endif // !EPISODIO_H
