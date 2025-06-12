#ifndef PASAJERO_H
#define PASAJERO_H
#include <iostream>

class Pasajero {
private:
    int ID;
    int minLlegada; //Minuto de llegada al aeropuerto.
    int minAtendido; //Minuto en el que comienza a ser atendido en el box.
    int duracionControl; //Duración del control de aduanas.
    int pais;
    int prioridad;
    int IDBox;
    int salidaBox; //Minuto en el que sale del box, una vez atendido


public:
    Pasajero(); // Declaración del constructor por defecto
    Pasajero(int ID, int minLlegada, int minAtendido, int duracionControl, int pais, int prioridad, int IDBox, int salidaBox); // Constructor con parámetros

    // Métodos de acceso
    int getID() const;
    int getMinLlegada() const;
    int getMinAtendido() const;
    int getDuracionControl() const;
    int getPais() const;
    int getPrioridad() const;
    int getIDBox() const;
    int getSalidaBox() const;


    // Métodos de modificación
    void setMinAtendido(int min);
    void setDuracionControl(int duracion);
    void setIDBox(int idBox);
    void setSalidaBox(int salida);
    void setPrioridad(int prioridad);

    ~Pasajero(); // Destructor
};

#endif // PASAJERO_H
