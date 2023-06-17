#include <iostream>
#include <string>
#include <vector>

#include "Video.h"

using namespace std;

Video::Video(string id, string nombre, float duracion, vector<string> generos, float calificacion, string fechaEstreno)
{
  this->id = id;
  this->nombre = nombre;
  this->duracion = duracion;
  this->generos = generos;
  this->calificacion = calificacion;
  this->fechaEstreno = fechaEstreno;
}

void Video::setCalificacion(float calificacion) {
  this->calificacion = calificacion;
}

string Video::obtenerId() {
  return id;
}

string Video::obtenerNombre() {
  return nombre;
}

float Video::obtenerDuracion() {
  return duracion;
}

vector<string> Video::obtenerGeneros() {
  return generos;
}

float Video::obtenerCalificacion() {
  return calificacion;
}

string Video::obtenerFechaEstreno() {
  return fechaEstreno;
}

bool Video::tieneGenero(string genero) {
  for (int i = 0; i < generos.size(); i++) {
    if (generos[i] == genero) {
      return true;
    }
  }
  return false;
}

void Video::imprimirInformacion() {
  cout << "Id: " << id << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Duracion: " << duracion << endl;
  cout << "Generos: ";
  imprimirGeneros();
  cout << "Calificacion: " << calificacion << endl;
  cout << "Fecha de estreno: " << fechaEstreno << endl;
}

void Video::imprimirGeneros() {
  for (int i = 0; i < generos.size(); i++) {
    cout << generos[i] << " ";
  }
  cout << endl;
}
