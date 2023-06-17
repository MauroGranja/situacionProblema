
#include <iostream>
#include <string>
#include <vector>

#include "Video.h"
#include "Episodio.h"

using namespace std;

Episodio::Episodio(string id, string nombre, float duracion, vector<string> generos, float calificacion, string fechaEstreno, string idEpisodio, string nombreEpisodio, int numeroEpisodio, int numeroTemporada) : Video(id, nombre, duracion, generos, calificacion, fechaEstreno) {
  this->idEpisodio = idEpisodio;
  this->nombreEpisodio = nombreEpisodio;
  this->numeroEpisodio = numeroEpisodio;
  this->numeroTemporada = numeroTemporada;
}

string Episodio::obtenerIdEpisodio() {
  return idEpisodio;
}

string Episodio::obtenerNombreEpisodio() {
  return nombreEpisodio;
}

int Episodio::obtenerNumeroEpisodio() {
  return numeroEpisodio;
}

int Episodio::obtenerNumeroTemporada() {
  return numeroTemporada;
}


void Episodio::imprimirInformacion() {
  Video::imprimirInformacion();
  cout << "ID Episodio: " << this->idEpisodio << endl;
  cout << "Nombre Episodio: " << this->nombreEpisodio << endl;
  cout << "Número Episodio: " << this->numeroEpisodio << endl;
  cout << "Número Temporada: " << this->numeroTemporada << endl;
}
