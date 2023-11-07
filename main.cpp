#include <iostream>
#include <string>
#include "espacio.h"
using namespace std;

void opcionesjuego(Espacio **, char, char, string *, int *);
string movusuario(string *);
void imprimirjuego(Espacio **);
void reiniciaropciones(string *, int *);

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
    string mov;
    string *opciones = new string[15];
    int *copciones = new int[15];
    while(juego){
        imprimirjuego(matriz);
        if(turno){
            cout<<"Turno de O"<<endl;
            opcionesjuego(matriz,signo1, signo2,opciones,copciones);
            mov=movusuario(opciones);
        }
        else{
            opcionesjuego(matriz,signo2, signo1,opciones,copciones);
            mov=movusuario(opciones);
        }
        reiniciaropciones(opciones,copciones);
    }

    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    delete[] opciones;
    delete[] copciones;

    return 0;
}

void opcionesjuego(Espacio **matriz, char sj, char sc, string *array, int *carray)
{
    char posicionf, posicionc;
    string posicion;
    int fila=0, columna=0, cont=0, auxi, auxj;
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
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
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
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
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
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
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
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
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
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
                        }
                    }
                }
                if(i-1>=0 && j-1>=0){
                    if(matriz[i-1][j-1].getSigno()==sc){
                        fila=i-1;
                        columna=j-1;
                        while(matriz[fila][columna].getSigno()==sc && fila>=0 && columna>=0){
                            fila-=1;
                            columna-=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
                        }
                    }
                }
                if(i-1>=0 && j+1<columnas){
                    if(matriz[i-1][j+1].getSigno()==sc){
                        fila=i-1;
                        columna=j+1;
                        while(matriz[fila][columna].getSigno()==sc && fila>=0 && columna<columnas){
                            fila-=1;
                            columna+=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
                        }
                    }
                }
                if(i+1<filas && j-1>=0){
                    if(matriz[i+1][j-1].getSigno()==sc){
                        fila=i+1;
                        columna=j-1;
                        while(matriz[fila][columna].getSigno()==sc && fila<filas && columna>=0){
                            fila+=1;
                            columna-=1;
                        }
                        if(matriz[fila][columna].getSigno()=='N'){
                            posicionf=fila;
                            posicionc=columna;
                            posicionf+=48;
                            posicionc+=48;
                            posicion+=posicionf;
                            posicion+=posicionc;
                            array[cont]=posicion;
                            auxi=i+1;
                            auxj=j+1;
                            auxi=(auxi*10)+auxj;
                            carray[cont]=auxi;
                            cont+=1;
                            posicion="";
                        }
                    }
                }
            }
        }
    }
}

string movusuario(string *moves)
{
    string mov;
    char columna, fila;
    int filanum;
    bool valido=true;
    cout<<"Ingrese el movimiento: ";
    cin>>mov;
    columna=mov[0];
    fila=mov[1];
    if(columna>90){
        columna-=32;
    }
    fila-=1;
    columna-=17;
    mov[0]=fila;
    mov[1]=columna;
    for(int i=0; moves[i]!="";i++){
        if(mov==moves[i]){
            valido=false;
            break;
        }
    }
    while(valido){
        cout<<"Ingrese un movimiento valido: ";
        cin>>mov;
        columna=mov[0];
        fila=mov[1];
        if(columna>90){
            columna-=32;
        }
        fila-=1;
        columna-=17;
        mov[0]=fila;
        mov[1]=columna;
        for(int i=0; moves[i]!="";i++){
            if(mov==moves[i]){
                valido=false;
                break;
            }
        }
    }
    return mov;
}

void imprimirjuego(Espacio **matriz)
{
    for(int i=0; i<filas;i++){
        cout<<"|";
        for(int j=0;j<columnas;j++){
            if(matriz[i][j].getSigno()=='N'){
                cout<<"   |";
            }
            else if(matriz[i][j].getSigno()=='O'){
                cout<<" O |";
            }
            else if(matriz[i][j].getSigno()=='X'){
                cout<<" X |";
            }
        }
        cout<<endl;
        cout<<"---------------------------------"<<endl;
    }
}

void reiniciaropciones(string *opc, int* copc)
{
    for(int i=0; i<15;i++){
        opc[i]="";
        copc[i]=0;
    }
}
