#include <iostream>
using namespace std;

int main() {
    int filas, columnas;

    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> columnas;
    int ids[100][100]; //tamaño maximo por seguridad

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            //Formula "mas random"
            ids[i][j] = ((i + 3) * (j + 5) + i * i + j * 3 + 7) % 90 + 10;
        }
    }
    cout << "\nMatriz de IDs más variados:\n\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << ids[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}