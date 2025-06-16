#ifndef LISTAPASAJEROS_H
#define LISTAPASAJEROS_H


class ListaPasajeros {
private:
    Pasajero* listaPasajeros; // Arreglo dinámico de pasajeros
    int capacidad;  // Capacidad actual del arreglo
    int cantidad;   // Número de pasajeros almacenados
    ABB arbolDestinos; // Árbol binario para clasificación por destino

    void redimensionar(int nuevaCapacidad); // Expande o reduce el tamaño del arreglo

public:
    // Constructor y destructor
    ListaPasajeros(int capacidadInicial = 10);
    ~ListaPasajeros();

    // Métodos de gestión
    void insertarPasajero(const Pasajero& p);
    void eliminarPasajero(int id);
    Pasajero* buscarPasajero(int id);
    Pasajero* buscarPasajeroPorIndice(int index);
    bool esVacia() const;
    int contarPasajeros() const;
    Pasajero* buscarPasajeroPorID(int id);


    // Métodos relacionados con ABB
    void agregarAlABB(const Pasajero& p);
    void mostrarPorPais(const std::string& pais);
    void calcularTiempoMedioPorPais();

    // Métodos auxiliares
    void mostrarLista();
};

#endif // LISTAPASAJEROS_H
