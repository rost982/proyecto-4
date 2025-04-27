#include <iostream>
using namespace std;




// usar por ahora un solo estudiante, problemas al mostrar informacion de los prestamos con mas estudiantes//


int x;
struct recurso
{
    //atributos
    int idrecurso;
    string nombre;
    bool disponibilidad=1;
    //métodos o funciones
    void registraridrecurso();
    void consultardisponibilidad();
};

void recurso::registraridrecurso()
{
    cout<<"registrar el codigo del recurso\n";
    cin>>idrecurso;
};

void recurso::consultardisponibilidad()
{
    if(disponibilidad==1)
    {
        cout<<"disponible";
    }
    
    else if(disponibilidad==0)
    {
        cout<<"No disponible";
    }
};

struct estudiante
{
    //atributos
    int idestudiante;
    string nombrer;
    //métodos o funciones
    void registraridestudiante();
};

void estudiante::registraridestudiante()
{
    cout<<"registra codigo de estudiante\n" ;
    cin>>idestudiante;
}

 struct prestamo 
 {
        // Atributos
    int idrecurso,idprestamo; string nombre;               // Id único del préstamo
    estudiante prestatario;        // El estudiante que realiza el préstamo
    recurso recursoprestado;      // El recurso que se presta
    bool estado;                   
    // Métodos
    void consultarprestamoestudiante();      // Registrar un nuevo préstamo
    void consultarprestamo();      // Consultar el estado de un préstamo
    void devolverrecurso();
};
void prestamo::consultarprestamoestudiante()
{
    cout<<"El prestámo del estudiante es: "<<nombre<<" y "<<idrecurso;
    
    
};

/*void prestamo::consultarprestamo()
{
    
}
*/

main()
{
    int x;
    cout<<"cuantos estudiantes hay: ";
    cin>>x;
    //ESTUDIANTE
    estudiante listaestudiantes[x];
    int i;
    for(i=0; i<x; i++)
    {
       cout<<"ingresa el nombre del estudiante: ";
        cin>>listaestudiantes[i].nombrer;
        cout<<"ingresa id del estudiante: ";
        cin>>listaestudiantes[i].idestudiante;
    }
    cout<<"Se muestra la información de estudiantes:\n";
    for(i=0; i<x; i++)
    {
        cout<<listaestudiantes[i].nombrer;
        cout<<listaestudiantes[i].idestudiante<<"\n";
    }
    
    
    //mateo.registraridestudiante();
    //system("clear");
    
    //RECURSOS
   int y;
   cout<<"cuantos recursos hay: ";
   cin>>y;
   recurso listarecurso[x];
   int o;
   for(o=0; o<y; o++)
   { 
       cout<<"ingresa el nombre del recurso: ";
        cin>>listarecurso[o].nombre;cout<<"\n";
        cout<<"ingresa id del recurso: ";
        cin>>listarecurso[o].idrecurso;cout<<"\n";
    }
 cout<<"Se muestra la información del recurso:\n";
    for(i=0; i<y; i++)
    {
        cout<<listarecurso[o].nombre;
        cout<<listarecurso[o].idrecurso<<"\n";
    }
    
    //recurso1.registraridrecurso();
    //system("clear");
    
    //PRESTAMOS
   int cantidadPrestamos;
    cout << "¿Cuántos préstamos quieres registrar?: ";
    cin >> cantidadPrestamos;

    prestamo listaPrestamos[cantidadPrestamos];

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

        listaPrestamos[n].estado = 1; // al registrar, el préstamo está activo
    }

    cout << "\nInformación de préstamos registrados:\n";
    for (n = 0; n < cantidadPrestamos; n++)
    {
        cout << "------------------------\n";
        cout << "ID Préstamo: " << listaPrestamos[n].idprestamo << endl;
        cout << "Estudiante: " << listaPrestamos[n].nombre << " (ID: " << listaPrestamos[n].prestatario.idestudiante << ")" << endl;
        cout << "Recurso: " << listaPrestamos[n].recursoprestado.nombre << " (ID: " << listaPrestamos[n].recursoprestado.idrecurso << ")" << endl;
        cout << "Estado: " << (listaPrestamos[n].estado ? "Activo" : "Devuelto") << endl;
    }

    return 0;
    system("clear");
    
    
}