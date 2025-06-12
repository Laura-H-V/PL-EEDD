#include "Pasajero.h"

// Constructor por defecto
Pasajero::Pasajero() 
    : ID(0), minLlegada(0), minAtendido(0), duracionControl(0), pais(0), prioridad(0), IDBox(-1), salidaBox(0) {}

// Constructor con parámetros
Pasajero::Pasajero(int ID, int minLlegada, int minAtendido, int duracionControl, int pais, int prioridad, int IDBox, int salidaBox) 
    : ID(ID), minLlegada(minLlegada), minAtendido(minAtendido), duracionControl(duracionControl), pais(pais), prioridad(prioridad), IDBox(IDBox), salidaBox(salidaBox) {}

// Métodos de acceso
int Pasajero::getID() const { return ID; }
int Pasajero::getMinLlegada() const { return minLlegada; }
int Pasajero::getMinAtendido() const { return minAtendido; }
int Pasajero::getDuracionControl() const { return duracionControl; }
int Pasajero::getPais() const { return pais; }
int Pasajero::getPrioridad() const { return prioridad; }
int Pasajero::getIDBox() const { return IDBox; }
int Pasajero::getSalidaBox() const { return salidaBox; }

// Métodos de modificación
void Pasajero::setMinAtendido(int min) { minAtendido = min; }
void Pasajero::setDuracionControl(int duracion) { duracionControl = duracion; }
void Pasajero::setIDBox(int idBox) { IDBox = idBox; }
void Pasajero::setSalidaBox(int salida) { salidaBox = salida; }
void Pasajero::setPrioridad(int p) { prioridad = p; }

// Destructor
Pasajero::~Pasajero() {}