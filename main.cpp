#include <iostream>
#include "espacio.h"
using namespace std;


int main()
{
    int filas = 8, columnas = 8;
    Espacio** matriz = new Espacio*[filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new Espacio[columnas];
    }
    char signo='X';
    Espacio esp;
    esp=matriz[0][0];
    esp.setSigno(signo);
    cout<<matriz[0][0].getSigno()<<endl;

    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
