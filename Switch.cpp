#include <iostream>
using namespace std;
int main()
{
    int x;
    
    cout<<" Bienvenido, en qué podemos ayudarte?\n Tenemos los siguientes servicios: \n";
    cout<<" 1. Agregar un recurso \n 2. Agregar un estudiante \n 3. Prestar un recurso "<< 
    "disponible \n 4. Consultar los préstamos de un estudiante \n"<<
    " 5. Consultar la información de un préstamo \n 6. Devolver un recurso prestado \n";
    cin>>x;
    
    switch (x)
    {
        case 1: cout<<"Ha agregado un recurso!";
        break;
        case 2: cout<<"Ha agregado un estudiante!";
        break;
        case 3: cout<<"Se ha prestado un recurso disponible!";
        break;
        case 4: cout<<"Se ha consultado los datos de un estudiante";
        break;
        case 5: cout<<"Ha consultado la información de un préstamo";
        break;
        case 6: cout<<"Ha devuelto un recurso prestado";
        break;
        default: cout<<"Su opción no está disponible";
    }
    
}
