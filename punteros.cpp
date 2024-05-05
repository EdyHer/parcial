#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura para almacenar los datos de los estudiantes
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4];
};

// Función para calcular el promedio de las notas
double calcularPromedio(const double* notas) {
    double suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += notas[i];
    }
    return suma / 4;
}

// Función para determinar si el estudiante aprobó o reprobó
string obtenerResultado(double promedio) {
    return (promedio > 60) ? "Aprobado" : "Reprobado";
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // Crear un arreglo de estructuras para almacenar los datos de los estudiantes
    Estudiante* estudiantes = new Estudiante[n];

    for (int i = 0; i < n; ++i) {
        cout << "Estudiante " << i + 1 << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        cout << "Notas (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }
    }

    // Calcular promedio y mostrar resultados
    for (int i = 0; i < n; ++i) {
        double promedio = calcularPromedio(estudiantes[i].notas);
        string resultado = obtenerResultado(promedio);

        cout << "Estudiante " << estudiantes[i].id << ": " << estudiantes[i].nombres << " " << estudiantes[i].apellidos << endl;
        cout << "Promedio: " << promedio << " (" << resultado << ")" << endl;
    }

    // Liberar memoria
    delete[] estudiantes;

    return 0;
}

