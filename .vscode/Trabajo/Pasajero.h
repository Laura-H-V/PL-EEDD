    #ifndef PASAJERO_H
    #define PASAJERO_H
    #include <iostream>
    using namespace std;

    class Pasajero {
    private:
        int ID;
        int minLlegada; //Minuto de llegada al aeropuerto.
        int duracionControl; //Duración del control de aduanas.
        string pais;
        int prioridad;
        int IDBox;
        int tiempoTotal; //Minuto en el que sale del box, una vez atendido


    public:
        Pasajero(); // Declaración del constructor por defecto
        Pasajero(int ID, int minLlegada, int duracionControl, string pais, int prioridad); // Constructor con parámetros

        // Métodos de acceso
        int getID() const; // Agrega `const` al final de la declaración
        int getMinLlegada();
        int getDuracionControl();
        string getPais() const;
        int getPrioridad();
        int getTiempoTotal();
        int calcularTiempoEstancia() const;



        // Métodos de modificación
        void setID(int id);
        void setMinLlegada(int min);
        void setDuracionControl(int duracion);
        void setPais(string pais);
        void setPrioridad(int prioridad);
        void setSalidaBox(int salida);
        void setIDBox(int IDBox);
        void setTiempoTotal(int tiempo);

        ~Pasajero(); // Destructor
    };

    #endif // PASAJERO_H
