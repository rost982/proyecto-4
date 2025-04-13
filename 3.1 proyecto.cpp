#include <iostream>
using namespace std;


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
    //ESTUDIANTE
    estudiante mateo,felipe,sebastian;
    cout<<"ingresa el nombre del estudiante \n";
    cin>>mateo.nombrer;
    mateo.registraridestudiante();
    system("clear");
    
    //RECURSOS
    recurso recurso1, recurso2, recurso3;
    cout<<"ingresa el nombre del recurso \n";
    cin>>recurso1.nombre;
    recurso1.registraridrecurso();
    system("clear");
    
    //PRESTAMOS
    
    cout<<"\n1.Registrar prestamo.\n2.Consultar prestamo.";
    cin>>x;
    switch (x)
    {
        case 1: 
    prestamo prestamo1, prestamo2, prestamo3;
    cout<<"ingresa el id del prestamo \n";
    cin>>prestamo1.idprestamo;
    prestamo1.consultarprestamoestudiante();
    system("clear");
    break;
    
    case 2:
    }
    
    
    
    
    prestamo prestamo1, prestamo2, prestamo3;
    cout<<"ingresa el id del prestamo \n";
    cin>>prestamo1.idprestamo;
    prestamo1.consultarprestamoestudiante();
    system("clear");
    
    
}