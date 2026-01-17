#include <iostream>
#include <string>
using namespace std;

class Estudiante
{
public:
    string nombre;
    float notaFinal;

    Estudiante(string n, float nota)
    {
        nombre = n;
        notaFinal = nota;
    }

    void imprimir()
    {
        cout << "Nombre: " << nombre
             << " | Nota final: " << notaFinal << endl;
    }
};

class ListaEnlazada
{
private:
    struct Nodo
    {
        Estudiante *estudiante;
        Nodo *siguiente;

        Nodo(Estudiante *e)
        {
            estudiante = e;
            siguiente = nullptr;
        }
    };

    Nodo *head;

public:
    ListaEnlazada()
    {
        head = nullptr;
    }

void agregarEstudiante(string nombre, float nota) {
        Estudiante* nuevo = new Estudiante(nombre, nota);
        Nodo* nuevoNodo = new Nodo(nuevo);

        if (head == nullptr) {
            head = nuevoNodo;
        } else {
            Nodo* temp = head;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }
    
void imprimirLista() {
        Nodo* temp = head;
        while (temp != nullptr) {
            temp->estudiante->imprimir();
            temp = temp->siguiente;
        }
    }
};

int main()
{

    return 0;
}