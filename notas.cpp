#include <iostream>
using namespace std;

const int MAX_ESTUDIANTES = 100; // Puedes ajustar este valor según tus necesidades

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4];
};

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante estudiantes[MAX_ESTUDIANTES];

    for (int i = 0; i < n; ++i) {
        cout << "Estudiante #" << i + 1 << endl;
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

    cout << "\nResultados:\n";
    for (int i = 0; i < n; ++i) {
        double promedio = 0;
        for (int j = 0; j < 4; ++j) {
            promedio += estudiantes[i].notas[j];
        }
        promedio /= 4.0;

        cout << "Estudiante #" << i + 1 << ": " << estudiantes[i].nombres << " " << estudiantes[i].apellidos;
        cout << " (ID: " << estudiantes[i].id << ")" << endl;
        cout << "Promedio: " << promedio << endl;

        if (promedio > 60) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
    }

    return 0;
}

