#include "Pasajero.h"
using namespace std;

// Constructor por defecto
Pasajero::Pasajero() 
    : ID(0), minLlegada(0), duracionControl(0), pais(""), prioridad(0), IDBox(-1), tiempoTotal(0) {}

// Constructor con parámetros
Pasajero::Pasajero(int ID, int minLlegada, int duracionControl, string pais, int prioridad) 
    : ID(ID), minLlegada(minLlegada), duracionControl(duracionControl), pais(pais), prioridad(prioridad), IDBox(-1), tiempoTotal(0) {}

// Métodos de acceso
int Pasajero::getID() const { return ID; }
int Pasajero::getMinLlegada() { return minLlegada; }
int Pasajero::getDuracionControl() { return duracionControl; }
string Pasajero::getPais() const{ return pais; }
int Pasajero::getPrioridad()  { return prioridad; }
int Pasajero::getTiempoTotal()  { return tiempoTotal; }

// Métodos de modificación
void Pasajero::setDuracionControl(int duracion) { duracionControl = duracion; }
void Pasajero::setID(int id) { ID = id; }
void Pasajero::setMinLlegada(int min) { minLlegada = min; }
void Pasajero::setPais(string p) { pais = p; }
void Pasajero::setPrioridad(int p) { prioridad = p; }
void Pasajero::setIDBox(int idBox) { IDBox = idBox; }
void Pasajero::setTiempoTotal(int tiempo) { tiempoTotal = tiempo; }
void Pasajero::setSalidaBox(int salida) { tiempoTotal = salida; }
 
// Calcula la duración de estancia en el aeropuerto
int Pasajero::calcularTiempoEstancia() const {return tiempoTotal - minLlegada;}

// Destructor
Pasajero::~Pasajero() {}

