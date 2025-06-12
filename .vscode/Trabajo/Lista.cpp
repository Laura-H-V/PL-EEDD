#include "Lista.h"

Lista::Lista() : cabeza(nullptr), cola(nullptr) {}

Lista::~Lista() {
    while (!esVacia()) {
        pNodoLista temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cola = nullptr;
}

//Insertar izquierda
void Lista::insertarInicio(Box v) {
    pNodoLista nuevo = new NodoLista(v, cabeza, nullptr);
    if (esVacia()) {
        cabeza = cola = nuevo;
    } else {
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
}

//Insertar derecha
void Lista::insertarFinal(Box v) {
    pNodoLista nuevo = new NodoLista(v, nullptr, cola);
    if (esVacia()) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
}

void Lista::insertarEnPosicion(Box v, int pos) {
    if (pos <= 0) {
        insertarInicio(v);
    } else if (pos >= longitud()) {
        insertarFinal(v);
    } else {
        pNodoLista actual = cabeza;
        for (int i = 0; i < pos - 1 && actual->siguiente != nullptr; i++) {
            actual = actual->siguiente;
        }
        pNodoLista nuevo = new NodoLista(v, actual->siguiente, actual);
        actual->siguiente->anterior = nuevo;
        actual->siguiente = nuevo;
    }
}

void Lista::eliminar(Box v) {
    if (esVacia()) return;

    pNodoLista actual = cabeza;
    while (actual != nullptr && actual->valor.getId() != v.getId()) {
        actual = actual->siguiente;
    }
    if (actual == nullptr) return;

    if (actual == cabeza) {
        cabeza = cabeza->siguiente;
        if (cabeza != nullptr) cabeza->anterior = nullptr;
    } else if (actual == cola) {
        cola = cola->anterior;
        if (cola != nullptr) cola->siguiente = nullptr;
    } else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }
    delete actual;
}

bool Lista::esVacia() {
    return cabeza == nullptr;
}

Box* Lista::buscar(int id) {
    pNodoLista actual = cabeza;  // Comienza desde el primer nodo de la lista
    while (actual != nullptr) {  // Recorre la lista hasta el final
        if (actual->valor.getId() == id) {  // Compara el ID del núcleo con el ID que estamos buscando
            return &actual->valor;  // Si encuentra el núcleo, retorna su dirección
        }
        actual = actual->siguiente;  // Avanza al siguiente nodo
    }
    return nullptr;  // Si no encuentra el núcleo, retorna nullptr
}

void Lista::mostrar() {
    pNodoLista actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->valor.getId() << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

int Lista::longitud() {
    int contador = 0;
    pNodoLista actual = cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// Devuelve el núcleo basado en el proceso del nodo cabeza
Box Lista::inicio() {
    if (!esVacia() && cabeza != nullptr) {
        Box box = cabeza->valor; // Obtén el núcleo desde el nodo cabeza

        if (box.estaLibre() && !box.colaEsperaBox.es_vacia()) { 
            // Si el núcleo está libre y la cola no está vacía
            Persona persona = box.colaEsperaBox.inicio(); // Obtén el primer proceso de la cola
            box.asignarProceso(&persona); // Asigna el proceso al núcleo
        }
        
        return nucleo;
    }
    return Box();  // Devuelve un núcleo vacío si la lista está vacía
}

// Devuelve el núcleo basado en el proceso del nodo cola
Box Lista::fin() {
    if (!esVacia() && cola != nullptr) {
        Box box = cola->valor; // Obtén el núcleo desde el nodo cola

        if (box.estaLibre() && !nucleo.colaEsperaBox.es_vacia()) { 
            // Si el núcleo está libre y la cola no está vacía
            Persona persona = nucleo.colaEsperaBox.fin(); // Obtén el último proceso de la cola
            nucleo.asignarProceso(&persona); // Asigna el proceso al núcleo
        }
        
        return box;
    }
    return Box();  // Devuelve un núcleo vacío si la lista está vacía
}

pNodoLista Lista::obtenerCabeza() const {
    return cabeza;
}