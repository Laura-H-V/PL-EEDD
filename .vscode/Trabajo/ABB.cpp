#include "ABB.h"
#include "NodoABB.h"

ABB::ABB() //crea árbol vacío
{
    //ctor
    raiz=NULL;
}
ABB::ABB(NodoABB *r)
{
    raiz=r;

}
ABB::ABB(string nom, NodoABB *hIz, NodoABB *hDer)//constructor que crea árbolBin con dato y dos subárboles
{
    raiz= new NodoABB(nom, hIz, hDer);//llamamos al constructor del Nodo y raiz es un puntero al Nodo creado

}

ABB::~ABB()
{
    //dtor
}


void ABB::verInOrden() { verInOrden(raiz);}
void ABB::verInOrden(NodoABB *arb)// Método para ver Arbol empezando por su izquirda, después pasamos por la raiz y por ultimo por la rama derecha
{
    if (arb) {
       verInOrden(arb->hi);//Recursion para la rama izquierda
       cout<< arb->nombre<<endl;//Mostrar nombre
        verInOrden(arb->hd);// Recursion para la rama derecha
    }
}
/*void ABB::verInOrdenABB()// Método para ver Arbol en inorden sin tener que pasar puntero, resulta farragoso crear objetos cada vez...
{
    if (raiz) {
            ABB hijoIz(raiz->hi);hijoIz.verInOrden();//Recursion para la rama izquierda
        raiz->cliente.verDatos();//Mostrar datos del cliente
        ABB hijoDer(raiz->hd);hijoDer.verInOrden();// Recursion para la rama derecha
    }
}*/


void ABB::insertar(string nombre)
{
    insertar(nombre, raiz);
}
void ABB::insertar(string nombre, NodoABB *nodo)//En este método insertamos un nombre en el ABB para que siga ordenado
{


    if ((nodo->nombre>nombre) || (nodo->nombre ==nombre))
        //((nombre.compare(nodo->nombre)==0) ||  (nombre.compare(nodo->nombre)<0)) usando funcion de string


         { //Si el nombre del cliente es menor o igual al del nodo  raíz entoces comprobamos...


        if (nodo->hi == NULL)//Si el nodo izquierdo está vacio entoces
        {
            //creo un objeto NodoABB para insertarlo en el ABB
        NodoABB *nuevo=new NodoABB(nombre);
        nodo->hi= nuevo;
        }
            //Creamos un nuevo nodo e incluimos el cliente y el pedido en la lista (se crea vscía)

        else//En caso de que el nodo no estuviera vacio
        {
            insertar(nombre, nodo->hi);//insertamos al pasajero en el nodo izquierdo
        }
    }
    else// Si el nombre es > que el nodo
    {
        cout<<"es menor "<<nodo->nombre<<"que  "<< nombre<<endl;
        if (nodo->hd == NULL)//Comprobamos si el derecho no existe
        {

            //creo un objeto NodoABB para insertarlo en el ABB
        NodoABB *nuevo=new NodoABB(nombre);
            nodo->hd=nuevo;
            }// Creamos un nuevo nodo en la rama derecha

        else//si existe
        {
            insertar(nombre, nodo->hd);// insertamos el pasajero al nodo derecho
        }
    }
}


