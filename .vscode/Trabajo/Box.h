#ifndef BOX_H
#define BOX_H

#include "Cola.h"
#include "Pasajero.h"

class Box {
private:
    int IDBox;
    Pasajero* pasajeroActual; // Pasajero que está siendo atendido
    Cola colaEsperaBox; // Cola de espera de pasajeros
    int tiempoRestante; // Tiempo restante de atención del pasajero actual

public:
    // Constructores
    Box();
    Box(int id);

    // Métodos de acceso
    int getIDBox() const;
    Pasajero* getPasajeroActual() const;
    int getTiempoRestante() const;
    bool colaEsperaVacia() const;
    Cola& getColaEsperaBox();
    const Cola& getColaEsperaBox() const; // Método público para acceder a la cola

    // Métodos de modificación
    void asignarPasajero(Pasajero* p);
    void liberarBox();
    void actualizarTiempo(int minutos);
    bool estaLibre() const;

    // Gestión de cola de espera
    void agregarPasajeroAEspera(Pasajero p);
    Pasajero obtenerPrimerPasajeroEnEspera();

    // Métodos adicionales
    void mostrarInfo() const;

    ~Box();
};

#endif // BOX_H
