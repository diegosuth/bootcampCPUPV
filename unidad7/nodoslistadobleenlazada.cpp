#include <bits/stdc++.h>
using namespace std;
struct Node {
    string data;
    Node* next;
    Node* prev;
    bool genesis;
};
unordered_map<string,Node*> mapanodos;
// Funcion para crear nodos iniciales incluyendo cabeza
Node* crearLista(long long tamanolista){
    //creacion cabeza
    Node* cabeza = new Node();
    cabeza -> data = "1";
    cabeza -> next = nullptr;
    cabeza -> prev = nullptr;
    cabeza ->genesis = true;
    mapanodos[cabeza ->data] = cabeza;
    Node* actual = cabeza; //puntero para indicar el nodo actual
    //creacion de lista inicial
    for(long long i = 2; i <= tamanolista; i++){
        Node* nuevonodo = new Node();
        nuevonodo->data = to_string(i);
        nuevonodo -> genesis = true;
        mapanodos[nuevonodo->data] = nuevonodo;
        actual->next = nuevonodo;//para conectar el recien creado con el anterior
        nuevonodo->prev = actual; 
        actual = nuevonodo; // ahora es es el actual con el que el siguiente se va a conectar
        if(i == tamanolista){
            actual->next = nullptr;   
        }
    }
    return cabeza; //solo con la cabeza puedo acceder a toda la lista enlazada
}
void insertarEntreNodos(string nombreabuscar, string datoainsertar){
    Node* actual = mapanodos[nombreabuscar];
    Node* nuevonodo = new Node();
    nuevonodo->data = datoainsertar;
    nuevonodo->prev = actual;
    nuevonodo->genesis = false;
    nuevonodo->next = actual->next; //digo al nodo nuevo que enchufe al mismo nodo que el n-1(ambos apuntan a n)
    actual->next = nuevonodo;//le digo al n-1 que apunte al nodo nuevo(y mantiene la cadena ya que el n-2 sigue apuntando a n-1)
    if(nuevonodo->next != nullptr){
        nuevonodo->next->prev = nuevonodo; 
    }
    
}
Node* eliminarHasta(Node* cabeza, string nombreaborrar){
    Node* actual = mapanodos[nombreaborrar];
    Node* anterior = mapanodos[nombreaborrar]->prev;
    if(anterior != nullptr){
        Node* nodoaeliminar = actual;
        Node* nodoareconectar = anterior;
        actual = actual->next;
        mapanodos.erase(nodoaeliminar->data);
        delete nodoaeliminar;
        while((actual != nullptr) && (!actual -> genesis)){
            nodoaeliminar = actual;
            actual = actual->next;
            mapanodos.erase(nodoaeliminar->data);
            delete nodoaeliminar;
        }
        nodoareconectar->next = actual;
        if(actual != nullptr){
            actual->prev = nodoareconectar;
            }
        }
    else{
        Node* nodoaeliminar = actual;
        if(actual == cabeza){
            cabeza = actual->next;
        }
        actual = actual->next;
        mapanodos.erase(nodoaeliminar->data);
        delete nodoaeliminar;
        while((actual != nullptr) && (!actual -> genesis)){
            if(actual == cabeza){
                nodoaeliminar = actual;
                actual = actual->next;
                cabeza = actual;
                mapanodos.erase(nodoaeliminar->data);
                delete nodoaeliminar; 
                continue;
            }
            nodoaeliminar = actual;
            actual = actual->next;
            mapanodos.erase(nodoaeliminar->data);
            delete nodoaeliminar;
        }
    }
    return cabeza;
}
int main() {
    long cantidadoperaciones;
    cin >> cantidadoperaciones;
    string linea;
    cin.ignore();
    Node* cabeza = crearLista(1000000);
    for(long i = 0; i < cantidadoperaciones; i++){
        getline(cin,linea);
        istringstream iss(linea);
        char operacion;
        string nombrenodo;
        string palabra;
        iss >> operacion;
        if(operacion == '+'){
            iss >> nombrenodo >> palabra;
            insertarEntreNodos(nombrenodo, palabra);
        }
        else if(operacion == '-'){
            iss >> nombrenodo;
            cabeza = eliminarHasta(cabeza,nombrenodo);
        }
    }
    Node* actual = cabeza;
    while(actual != nullptr){
        cout << actual->data << "\n";
        actual = actual->next;
    }



    return 0;
}
