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
};

int main()
{

    return 0;
}