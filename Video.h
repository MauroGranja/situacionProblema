#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video
{
  string id;
  string nombre;
  float duracion;
  vector<string> generos;
  float calificacion;
  string fechaEstreno;
public:
  Video (string id, string nombre, float duracion, vector<string> generos, float calificacion, string fechaEstreno);
  void setCalificacion(float calificacion);
  string obtenerId();
  string obtenerNombre();
  float obtenerDuracion();
  vector<string> obtenerGeneros();
  float obtenerCalificacion();
  string obtenerFechaEstreno();
  bool tieneGenero(string genero);
  virtual void imprimirInformacion();
  void imprimirGeneros();
};

#endif // !VIDEO_H
