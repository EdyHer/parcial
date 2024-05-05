#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float notas[4]; // Arreglo para las 4 notas
    float promedio;
    string resultado;
};

// Función para crear un nuevo estudiante
void crearEstudiante(Estudiante* estudiantes, int& cantidadEstudiantes) {
    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiantes[cantidadEstudiantes].id;
    cout << "Ingrese nombres del estudiante: ";
    cin.ignore(); // Limpiar el buffer del teclado antes de leer la cadena
    getline(cin, estudiantes[cantidadEstudiantes].nombres);
    cout << "Ingrese apellidos del estudiante: ";
    getline(cin, estudiantes[cantidadEstudiantes].apellidos);
    cout << "Ingrese las 4 notas del estudiante: ";
    for (int i = 0; i < 4; ++i) {
        cin >> estudiantes[cantidadEstudiantes].notas[i];
    }
    // Calcular el promedio
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiantes[cantidadEstudiantes].notas[i];
    }
    estudiantes[cantidadEstudiantes].promedio = suma / 4;
    // Determinar el resultado (aprobado o reprobado)
    estudiantes[cantidadEstudiantes].resultado = (estudiantes[cantidadEstudiantes].promedio > 60) ? "Aprobado" : "Reprobado";
    cantidadEstudiantes++; // Incrementar la cantidad de estudiantes
}

// Función para guardar los datos de los estudiantes en un archivo binario
void guardarNotas(const Estudiante* estudiantes, int cantidadEstudiantes) {
    ofstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cout << "Error al abrir el archivo para escritura." << endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(estudiantes), cantidadEstudiantes * sizeof(Estudiante));
    archivo.close();
}

// Función para leer los datos de los estudiantes desde un archivo binario
void leerNotas(Estudiante* estudiantes, int& cantidadEstudiantes) {
    ifstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cout << "El archivo de notas no existe o no se puede abrir." << endl;
        return;
    }
    cantidadEstudiantes = 0; // Reiniciar la cantidad de estudiantes
    while (archivo.read(reinterpret_cast<char*>(&estudiantes[cantidadEstudiantes]), sizeof(Estudiante))) {
        cantidadEstudiantes++;
    }
    archivo.close();
}

// Función para imprimir los datos de los estudiantes
void imprimirNotas(const Estudiante* estudiantes, int cantidadEstudiantes) {
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        const Estudiante& estudiante = estudiantes[i];
        cout << "Estudiante ID: " << estudiante.id << endl;
        cout << "Nombre: " << estudiante.nombres << " " << estudiante.apellidos << endl;
        cout << "Notas: ";
        for (int j = 0; j < 4; ++j) {
            cout << estudiante.notas[j] << " ";
        }
        cout << endl;
        cout << "Promedio: " << fixed << setprecision(2) << estudiante.promedio << endl;
        cout << "Resultado: " << estudiante.resultado << endl << endl;
    }
}

int main() {
    int opcion;
    int cantidadEstudiantes = 0;
    const int maxEstudiantes = 100;
    Estudiante estudiantes[maxEstudiantes];

    do {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar notas de estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (cantidadEstudiantes < maxEstudiantes) {
                    crearEstudiante(estudiantes, cantidadEstudiantes);
                    guardarNotas(estudiantes, cantidadEstudiantes);
                    cout << "Estudiante agregado correctamente." << endl;
                } else {
                    cout << "No se pueden agregar más estudiantes. Capacidad máxima alcanzada." << endl;
                }
                break;
            case 2:
                leerNotas(estudiantes, cantidadEstudiantes);
                imprimirNotas(estudiantes, cantidadEstudiantes);
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}

