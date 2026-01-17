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

    float sumaNotasRecursiva(Nodo *nodo)
    {
        if (nodo == nullptr)
            return 0;
        return nodo->estudiante->notaFinal +
               sumaNotasRecursiva(nodo->siguiente);
    }

    int contarEstudiantesRecursivo(Nodo *nodo)
    {
        if (nodo == nullptr)
            return 0;
        return 1 + contarEstudiantesRecursivo(nodo->siguiente);
    }

public:
    ListaEnlazada()
    {
        head = nullptr;
    }

    void agregarEstudiante(string nombre, float nota)
    {
        Estudiante *nuevo = new Estudiante(nombre, nota);
        Nodo *nuevoNodo = new Nodo(nuevo);

        if (head == nullptr)
        {
            head = nuevoNodo;
        }
        else
        {
            Nodo *temp = head;
            while (temp->siguiente != nullptr)
            {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void imprimirLista()
    {
        Nodo *temp = head;
        while (temp != nullptr)
        {
            temp->estudiante->imprimir();
            temp = temp->siguiente;
        }
    }

    float calcularPromedioRecursivo()
    {
        if (head == nullptr)
            return 0;

        float suma = sumaNotasRecursiva(head);
        int total = contarEstudiantesRecursivo(head);

        return suma / total;
    }
};

int main()
{

ListaEnlazada lista;

    lista.agregarEstudiante("Juan", 8.5);
    lista.agregarEstudiante("Maria", 9.0);
    lista.agregarEstudiante("Carlos", 7.2);
    lista.agregarEstudiante("Ana", 10.0);

    lista.imprimirLista();
    cout << "Promedio: " << lista.calcularPromedioRecursivo() << endl;
    
    return 0;
}