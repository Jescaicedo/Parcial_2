#include <iostream>
#include <string>
#include "espacio.h"
using namespace std;

void opcionesjuego(Espacio **, char, char);

int filas = 8, columnas = 8;

int main()
{
    Espacio** matriz = new Espacio*[filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new Espacio[columnas];
    }
    char signo2='X', signo1='O';
    matriz[3][3].setSigno(signo2);
    matriz[3][4].setSigno(signo1);
    matriz[4][3].setSigno(signo1);
    matriz[4][4].setSigno(signo2);
    bool juego=true, turno=true;
    while(juego){
        if(turno){
            opcionesjuego(matriz,signo1, signo2);
        }
        else{
            opcionesjuego(matriz,signo2, signo1);
        }
    }

    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

void opcionesjuego(Espacio **matriz, char sj, char sc)
{
    string array[100];
    string posicion;
    int fila=0, columna=0, cont=0;
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if(matriz[i][j].getSigno()==sj){
                if(i+1<filas){
                    if(matriz[i+1][j].getSigno()==sc){
                        fila=i+1;
                        columna=j;
                        while(matriz[fila][columna].getSigno()==sc && fila<filas){
                            fila+=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            fila=(fila*10)+columna;
                            posicion=to_string(fila);
                            array[cont]=posicion;
                            cont+=1;
                        }

                    }
                }
                if(i-1>=0){
                    if(matriz[i-1][j].getSigno()==sc){
                        fila=i-1;
                        columna=j;
                        while(matriz[fila][columna].getSigno()==sc && fila>=0){
                            fila-=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            fila=(fila*10)+columna;
                            posicion=to_string(fila);
                            array[cont]=posicion;
                            cont+=1;
                        }

                    }
                }
                if(j+1<columnas){
                    if(matriz[i][j+1].getSigno()==sc){
                        fila=i;
                        columna=j+1;
                        while(matriz[fila][columna].getSigno()==sc && columna<columnas){
                            columna+=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            fila=(fila*10)+columna;
                            posicion=to_string(fila);
                            array[cont]=posicion;
                            cont+=1;
                        }

                    }
                }
                if(j-1>=0){
                    if(matriz[i][j-1].getSigno()==sc){
                        fila=i;
                        columna=j-1;
                        while(matriz[fila][columna].getSigno()==sc && columna<=columnas){
                            columna-=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            fila=(fila*10)+columna;
                            posicion=to_string(fila);
                            array[cont]=posicion;
                            cont+=1;
                        }

                    }
                }
                if(i+1<filas && j+1<columnas){
                    if(matriz[i+1][j+1].getSigno()==sc){
                        fila=i+1;
                        columna=j+1;
                        while(matriz[fila][columna].getSigno()==sc && fila<filas && columna<columnas){
                            fila+=1;
                            columna+=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            fila=(fila*10)+columna;
                            posicion=to_string(fila);
                            array[cont]=posicion;
                            cont+=1;
                        }
                    }
                }
            }
        }
    }
}
