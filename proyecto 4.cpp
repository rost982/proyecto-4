#include <iostream>
using namespace std;
int main()
{
    int x, y;
    /*variables necesarias para el desarrollo proyecto*/
    int codigoRec, nomRec, codigoEst, nomEst, recGlobal, prestEst;
    bool recDisponible;
    do
    {
    cout<<"\n1. Registrarse \n2. Iniciar sesion \n ";
    cin>>y;
     switch (y)
    {
        case 1: cout<<"se ha registrado";
        break;
        case 2: cout<<"has iniciado sesion";
        break;
        default: cout<<"Seleccione una opción válida";
        break;
    }
    }while (y!=1 && y!=2);
    cout<<"\nBienvenido, en qué podemos ayudarte?\nTenemos los siguientes servicios: \n";
    do
    {
        cout<<"\n 1. Agregar un recurso \n 2. Agregar un estudiante \n 3. Prestar un recurso "<< 
    "disponible \n 4. Consultar los préstamos de un estudiante \n"<<
    " 5. Consultar la información de un préstamo \n 6. Devolver un recurso prestado \n 7. finalizar servicio \n";
    cin>>x;
    switch (x)
    {
        case 1: cout<<"Ha agregado un recurso!";
        break;
        case 2: cout<<"Ha agregado un estudiante!";
        break;
        case 3: cout<<"Se ha prtesado un recurso disponible!";
        break;
        case 4: cout<<"Se ha consultado los datos de un estudiante";
        break;
        case 5: cout<<"Ha consultado la información de un préstamo";
        break;
        case 6: cout<<"Ha devuelto un recurso prestado";
        break;
        case 7: cout<<"finalizando servicio";
        break;
        default: cout<<"ingrese una opcion valida";
    }
    }while (x!=7);
}
