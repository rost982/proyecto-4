#include <iostream>
using namespace std;

// usar por ahora un solo estudiante, problemas al mostrar informacion de los prestamos con mas estudiantes//

int x;

struct recurso
{
    int idrecurso;
    string nombre;
    bool disponibilidad = 1;

    void registraridrecurso();
    void consultardisponibilidad();
};

void recurso::registraridrecurso()
{
    cout << "registrar el codigo del recurso\n";
    cin >> idrecurso;
};

void recurso::consultardisponibilidad()
{
    if (disponibilidad == 1)
    {
        cout << "disponible";
    }
    else if (disponibilidad == 0)
    {
        cout << "No disponible";
    }
};

struct estudiante
{
    int idestudiante;
    string nombrer;

    void registraridestudiante();
};

void estudiante::registraridestudiante()
{
    cout << "registra codigo de estudiante\n";
    cin >> idestudiante;
}

struct prestamo
{
    int idrecurso, idprestamo;
    string nombre;
    estudiante prestatario;
    recurso recursoprestado;
    bool estado;

    void consultarprestamoestudiante();
    void consultarprestamo();
    void devolverrecurso();
};

void prestamo::consultarprestamoestudiante()
{
    cout << "El prestámo del estudiante es: " << nombre << " y " << idrecurso;
};

void prestamo::consultarprestamo()
{
    cout << "ID del préstamo: " << idprestamo << endl;
    cout << "Estudiante: " << nombre << " (ID: " << prestatario.idestudiante << ")" << endl;
    cout << "Recurso: " << recursoprestado.nombre << " (ID: " << recursoprestado.idrecurso << ")" << endl;
    cout << "Estado: " << (estado ? "Activo" : "Devuelto") << endl;
}

void prestamo::devolverrecurso()
{
    estado = 0;
    recursoprestado.disponibilidad = 1;
    cout << "Recurso devuelto correctamente.\n";
}

int main()
{
    // Definimos listas que se usarán después
    prestamo listaPrestamos[100];
    int cantidadPrestamos = 0;

    // CONSULTA INICIAL
    char consultar;
    cout << "\n¿Deseas consultar el estado de algún préstamo? (s/n): ";
    cin >> consultar;

    while (consultar == 's')
    {
        int idbuscado;
        cout << "Ingresa el ID del préstamo a consultar: ";
        cin >> idbuscado;

        bool encontrado = false;
        for (int k = 0; k < cantidadPrestamos; k++)
        {
            if (listaPrestamos[k].idprestamo == idbuscado)
            {
                listaPrestamos[k].consultarprestamo();
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Préstamo no encontrado.\n";
        }

        cout << "\n¿Deseas consultar otro préstamo? (s/n): ";
        cin >> consultar;
    }

    // ESTUDIANTES
    cout << "cuantos estudiantes hay: ";
    cin >> x;
    estudiante listaestudiantes[x];

    int i;
    for (i = 0; i < x; i++)
    {
        cout << "ingresa el nombre del estudiante: ";
        cin >> listaestudiantes[i].nombrer;
        cout << "ingresa id del estudiante: ";
        cin >> listaestudiantes[i].idestudiante;
    }

    cout << "Se muestra la información de estudiantes:\n";
    for (i = 0; i < x; i++)
    {
        cout << listaestudiantes[i].nombrer;
        cout << listaestudiantes[i].idestudiante << "\n";
    }

    // RECURSOS
    int y;
    cout << "cuantos recursos hay: ";
    cin >> y;
    recurso listarecurso[y];

    int o;
    for (o = 0; o < y; o++)
    {
        cout << "ingresa el nombre del recurso: ";
        cin >> listarecurso[o].nombre;
        cout << "\n";
        cout << "ingresa id del recurso: ";
        cin >> listarecurso[o].idrecurso;
        cout << "\n";
    }

    cout << "Se muestra la información del recurso:\n";
    for (i = 0; i < y; i++)
    {
        cout << listarecurso[i].nombre;
        cout << listarecurso[i].idrecurso << "\n";
    }

    // PRÉSTAMOS
    cout << "¿Cuántos préstamos quieres registrar?: ";
    cin >> cantidadPrestamos;

    int n;
    for (n = 0; n < cantidadPrestamos; n++)
    {
        cout << "\nREGISTRANDO PRÉSTAMO #" << n + 1 << endl;

        cout << "Ingrese ID del préstamo: ";
        cin >> listaPrestamos[n].idprestamo;

        cout << "Ingrese nombre del estudiante: ";
        cin >> listaPrestamos[n].nombre;

        cout << "Ingrese ID del estudiante: ";
        cin >> listaPrestamos[n].prestatario.idestudiante;

        cout << "Ingrese nombre del recurso: ";
        cin >> listaPrestamos[n].recursoprestado.nombre;

        cout << "Ingrese ID del recurso: ";
        cin >> listaPrestamos[n].idrecurso;
        listaPrestamos[n].recursoprestado.idrecurso = listaPrestamos[n].idrecurso;

        // VALIDACIÓN DE DISPONIBILIDAD
        bool disponible = false;
        for (int j = 0; j < y; j++)
        {
            if (listarecurso[j].idrecurso == listaPrestamos[n].idrecurso)
            {
                if (listarecurso[j].disponibilidad == 1)
                {
                    disponible = true;
                    listarecurso[j].disponibilidad = 0;
                    listaPrestamos[n].recursoprestado.disponibilidad = 0;
                    break;
                }
            }
        }

        if (!disponible)
        {
            cout << "El recurso no está disponible. No se puede registrar el préstamo.\n";
            n--;
            continue;
        }

        listaPrestamos[n].estado = 1;
    }

    // MOSTRAR PRÉSTAMOS
    cout << "\nInformación de préstamos registrados:\n";
    for (n = 0; n < cantidadPrestamos; n++)
    {
        cout << "------------------------\n";
        cout << "ID Préstamo: " << listaPrestamos[n].idprestamo << endl;
        cout << "Estudiante: " << listaPrestamos[n].nombre << " (ID: " << listaPrestamos[n].prestatario.idestudiante << ")" << endl;
        cout << "Recurso: " << listaPrestamos[n].recursoprestado.nombre << " (ID: " << listaPrestamos[n].recursoprestado.idrecurso << ")" << endl;
        cout << "Estado: " << (listaPrestamos[n].estado ? "Activo" : "Devuelto") << endl;
    }

    // OPCIÓN DE DEVOLVER RECURSO
    char devolver;
    cout << "\n¿Deseas devolver algún recurso? (s/n): ";
    cin >> devolver;

    while (devolver == 's')
    {
        int id;
        cout << "Ingresa el ID del préstamo a devolver: ";
        cin >> id;

        bool encontrado = false;
        for (n = 0; n < cantidadPrestamos; n++)
        {
            if (listaPrestamos[n].idprestamo == id && listaPrestamos[n].estado == 1)
            {
                listaPrestamos[n].devolverrecurso();

                for (int j = 0; j < y; j++)
                {
                    if (listarecurso[j].idrecurso == listaPrestamos[n].idrecurso)
                    {
                        listarecurso[j].disponibilidad = 1;
                        break;
                    }
                }

                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Préstamo no encontrado o ya devuelto.\n";
        }

        cout << "\n¿Deseas devolver otro recurso? (s/n): ";
        cin >> devolver;
    }

    // CONSULTA FINAL
    cout << "\n¿Deseas consultar el estado de algún préstamo? (s/n): ";
    cin >> consultar;

    while (consultar == 's')
    {
        int idbuscado;
        cout << "Ingresa el ID del préstamo a consultar: ";
        cin >> idbuscado;

        bool encontrado = false;
        for (n = 0; n < cantidadPrestamos; n++)
        {
            if (listaPrestamos[n].idprestamo == idbuscado)
            {
                listaPrestamos[n].consultarprestamo();
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Préstamo no encontrado.\n";
        }

        cout << "\n¿Deseas consultar otro préstamo? (s/n): ";
        cin >> consultar;
    }

    return 0;
    system("clear");
}