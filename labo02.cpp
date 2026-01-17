#include <iostream>
#include <string>
using namespace std;

class Estudiante {
public:
    string nombre;
    float notaFinal;

    Estudiante(string n, float nota) {
        nombre = n;
        notaFinal = nota;
    }

    void imprimir() {
        cout << "Nombre: " << nombre
             << " | Nota final: " << notaFinal << endl;
    }
};
int main() {

    return 0;
}