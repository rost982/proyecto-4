#include <iostream>
using namespace std;

const int MAX_ESTUDIANTES = 100;
const int MAX_RECURSOS = 100;
const int MAX_PRESTAMOS = 100;
//Estructuras
struct recurso {
    int idrecurso;
    string nombre;
    bool disponibilidad = true;
};

struct estudiante {
    int idestudiante;
    string nombre;
};

struct prestamo {
    int idprestamo;
    int idestudiante;
    int idrecurso;
    bool estado = true; // Fin del registro de préstamo
};

// Arreglo para guardar todos los estudiantes registrados
estudiante listaEstudiantes[MAX_ESTUDIANTES];
int cantidadEstudiantes = 0; //Contador de estudiantes registrados

recurso listaRecursos[MAX_RECURSOS];
int cantidadRecursos = 0; //Contador de recursos registrados

prestamo listaPrestamos[MAX_PRESTAMOS];
int cantidadPrestamos = 0; //Contador de prestamos registrados

// FUNCION DE PAUSA
void pausa() {
    cout << "\nPresiona ENTER para volver al menú...";
    cin.ignore();
    cin.get();
}

// FUNCIONES 

// Función para registrar un nuevo estudiante
void registrarEstudiante() {
    if (cantidadEstudiantes >= MAX_ESTUDIANTES) {
        cout << "No se pueden registrar más estudiantes.\n";
        return;
    }
    estudiante e;
    cout << "Ingrese ID del estudiante: ";
    cin >> e.idestudiante;
    cout << "Ingrese nombre del estudiante: ";
    cin >> e.nombre;
    listaEstudiantes[cantidadEstudiantes++] = e;
}
// Función para registrar un nuevo recurso
void registrarRecurso() {
    if (cantidadRecursos >= MAX_RECURSOS) {
        cout << "No se pueden registrar más recursos.\n";
        return;
    }
    recurso r;
    cout << "Ingrese ID del recurso: ";
    cin >> r.idrecurso;
    cout << "Ingrese nombre del recurso: ";
    cin >> r.nombre;
    listaRecursos[cantidadRecursos++] = r;
}
// Función para mostrar un recurso
void mostrarRecursos() {
    cout << "\n--- Lista de Recursos ---\n";
    for (int i = 0; i < cantidadRecursos; i++) {
        cout << listaRecursos[i].nombre << " (ID: " << listaRecursos[i].idrecurso << ") - "
             << (listaRecursos[i].disponibilidad ? "Disponible" : "No disponible") << "\n";
    }
    pausa();
}
// Devuelve la posición del estudiante +1. Si no se encuentra, devuelve 0
int buscarEstudiantePorID(int id) {
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (listaEstudiantes[i].idestudiante == id) return i + 1;
    }
    return 0;
}
// Devuelve la posición del recurso +1. Si no se encuentra, devuelve 0
int buscarRecursoPorID(int id) {
    for (int i = 0; i < cantidadRecursos; i++) {
        if (listaRecursos[i].idrecurso == id) return i + 1;
    }
    return 0;
}
// Función para realizar un prestamo
void realizarPrestamo() {
    if (cantidadPrestamos >= MAX_PRESTAMOS) {
        cout << "No se pueden registrar más préstamos.\n";
        return;
    }

    prestamo p;
    cout << "Ingrese ID del préstamo: ";
    cin >> p.idprestamo;
    cout << "Ingrese ID del estudiante: ";
    cin >> p.idestudiante;

    int idxEstAux = buscarEstudiantePorID(p.idestudiante);
    if (idxEstAux == 0) {
        cout << "Estudiante no encontrado.\n";
        return;
    }
    int idxEst = idxEstAux - 1;

    cout << "Ingrese ID del recurso: ";
    cin >> p.idrecurso;

    int idxRecAux = buscarRecursoPorID(p.idrecurso);
    if (idxRecAux == 0) {
        cout << "Recurso no encontrado.\n";
        return;
    }
    int idxRec = idxRecAux - 1;

    if (!listaRecursos[idxRec].disponibilidad) { // Verifica que el recurso esté disponible antes de prestarlo
        cout << "El recurso no está disponible.\n";
        return;
    }

    listaRecursos[idxRec].disponibilidad = false;
    p.estado = true;
    listaPrestamos[cantidadPrestamos++] = p;
    cout << "Préstamo registrado exitosamente.\n";
// Fin del registro de préstamo
    pausa();
}

void consultarPrestamos() {
    cout << "\n--- Lista de Préstamos ---\n";
    for (int i = 0; i < cantidadPrestamos; i++) {
        int idxEstAux = buscarEstudiantePorID(listaPrestamos[i].idestudiante);
        int idxRecAux = buscarRecursoPorID(listaPrestamos[i].idrecurso);
        int idxEst = idxEstAux > 0 ? idxEstAux - 1 : -1;
        int idxRec = idxRecAux > 0 ? idxRecAux - 1 : -1;

        cout << "ID Préstamo: " << listaPrestamos[i].idprestamo << endl;
        cout << "Estudiante: " << (idxEst >= 0 ? listaEstudiantes[idxEst].nombre : "Desconocido")
             << " (ID: " << listaPrestamos[i].idestudiante << ")" << endl;
        cout << "Recurso: " << (idxRec >= 0 ? listaRecursos[idxRec].nombre : "Desconocido")
             << " (ID: " << listaPrestamos[i].idrecurso << ")" << endl;
        cout << "Estado: " << (listaPrestamos[i].estado ? "Activo" : "Devuelto") << endl;
        cout << "--------------------------\n";
    }
    pausa();
}
// Cambia el estado del préstamo a 'devuelto' y marca el recurso como disponible
void devolverRecurso() {
    int id;
    cout << "Ingrese ID del préstamo a devolver: ";
    cin >> id;

    for (int i = 0; i < cantidadPrestamos; i++) {
        if (listaPrestamos[i].idprestamo == id && listaPrestamos[i].estado) {
            listaPrestamos[i].estado = false;
            int idxRecAux = buscarRecursoPorID(listaPrestamos[i].idrecurso);
            if (idxRecAux != 0) {
                int idxRec = idxRecAux - 1;
                listaRecursos[idxRec].disponibilidad = true;
            }
            cout << "Recurso devuelto exitosamente.\n";
            pausa();
            return;
        }
    }
    cout << "Préstamo no encontrado o ya devuelto.\n";
    pausa();
}
// Muestra los préstamos realizados por un estudiante
void mostrarPrestamosDeEstudiante() {
    int id;
    cout << "Ingrese el ID del estudiante: ";
    cin >> id;

    int idxEstAux = buscarEstudiantePorID(id);
    if (idxEstAux == 0) {
        cout << "Estudiante no encontrado.\n";
        pausa();
        return;
    }
    int idxEst = idxEstAux - 1;

    cout << "\n--- Préstamos del Estudiante: " << listaEstudiantes[idxEst].nombre << " ---\n";

    bool tienePrestamos = false;
    for (int i = 0; i < cantidadPrestamos; i++) {
        if (listaPrestamos[i].idestudiante == id) {
            tienePrestamos = true;
            int idxRecAux = buscarRecursoPorID(listaPrestamos[i].idrecurso);
            if (idxRecAux == 0) continue;
            int idxRec = idxRecAux - 1;

            cout << "ID Préstamo: " << listaPrestamos[i].idprestamo << endl;
            cout << "Recurso: " << listaRecursos[idxRec].nombre << " (ID: " << listaRecursos[idxRec].idrecurso << ")\n";
            cout << "Estado: " << (listaPrestamos[i].estado ? "Activo" : "Devuelto") << endl;
            cout << "--------------------------\n";
        }
    }

    if (!tienePrestamos) {
        cout << "Este estudiante no tiene préstamos registrados.\n";
    }
    pausa();
}
// Muestra el menú y permite al usuario elegir una opción
void menu() {
    int opcion;
    do {
        cout << "\n========= MENÚ =========\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Registrar recurso\n";
        cout << "3. Realizar préstamo\n";
        cout << "4. Consultar préstamos\n";
        cout << "5. Devolver recurso\n";
        cout << "6. Mostrar préstamos de un estudiante\n";
        cout << "7. Mostrar recursos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarEstudiante(); break;
            case 2: registrarRecurso(); break;
            case 3: realizarPrestamo(); break;
            case 4: consultarPrestamos(); break;
            case 5: devolverRecurso(); break;
            case 6: mostrarPrestamosDeEstudiante(); break;
            case 7: mostrarRecursos(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}
// Inicia el programa mostrando el menú principal
int main() {
    menu();
    return 0;
}