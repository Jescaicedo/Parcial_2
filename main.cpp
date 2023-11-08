#include <iostream>
#include <string>
#include "espacio.h"
using namespace std;

void opcionesjuego(Espacio **, char, char, string *, int *);
string movusuario(string *);
void imprimirjuego(Espacio **);
void reiniciaropciones(string *, int *);
void jugada(Espacio ** , string *, int *, string, char);
bool finjuego(Espacio **, string *);

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
    string *opciones = new string[30];
    int *copciones = new int[30];
    opcionesjuego(matriz,signo1, signo2,opciones,copciones);
    while(juego){
        imprimirjuego(matriz);
        if(turno){
            cout<<"Turno de O"<<endl;
            mov=movusuario(opciones);
            jugada(matriz, opciones, copciones, mov, signo1);
            turno=false;
            reiniciaropciones(opciones,copciones);
            opcionesjuego(matriz,signo2, signo1,opciones,copciones);
        }
        else{
            cout<<"Turno de X"<<endl;
            mov=movusuario(opciones);
            jugada(matriz, opciones, copciones, mov, signo2);
            turno=true;
            reiniciaropciones(opciones,copciones);
            opcionesjuego(matriz,signo1, signo2,opciones,copciones);
        }
        juego=finjuego(matriz,opciones);
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
                        while(matriz[fila][columna].getSigno()==sc && fila+1<filas){
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
                        while(matriz[fila][columna].getSigno()==sc && fila-1>=0){
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
                        while(matriz[fila][columna].getSigno()==sc && columna+1<columnas){
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
                        while(matriz[fila][columna].getSigno()==sc && columna-1>=0){
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
                        while(matriz[fila][columna].getSigno()==sc && fila+1<filas && columna+1<columnas){
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
                        while(matriz[fila][columna].getSigno()==sc && fila-1>=0 && columna-1>=0){
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
                        while(matriz[fila][columna].getSigno()==sc && fila-1>=0 && columna+1<columnas){
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
                        while(matriz[fila][columna].getSigno()==sc && fila+1<filas && columna-1>=0){
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

void jugada(Espacio **matriz , string *opciones, int *copciones, string mov, char s)
{
    int cont=0, fl, cl, fi, ci;
    char valor;
    while(opciones[cont]!="" && cont<15){
        if(opciones[cont]==mov){
            fl=copciones[cont];
            cl=fl%10;
            fl/=10;
            fl-=1;
            cl-=1;
            valor=mov[0];
            fi=stoi(string(1, valor));
            valor=mov[1];
            ci=stoi(string(1, valor));
            matriz[fi][ci].setSigno(s);
            while(fi!=fl || ci!=cl){
                if(fi<fl){
                    fi+=1;
                }
                else if(fi>fl){
                    fi-=1;
                }
                if(ci<cl){
                    ci+=1;
                }
                else if(ci>cl){
                    ci-=1;
                }
                matriz[fi][ci].setSigno(s);
            }
        }
        cont+=1;
    }
}

bool finjuego(Espacio **matriz, string *opciones)
{
    int X=0, O=0;
    bool juego=true;
    if(opciones[0]==""){
        imprimirjuego(matriz);
        juego=false;
        for(int i=0; i<filas;i++){
            for(int j=0; j<columnas;j++){
                if(matriz[i][j].getSigno()=='X'){
                    X+=1;
                }
                else if(matriz[i][j].getSigno()=='O'){
                    O+=1;
                }
            }
        }
        cout<<"El juego ha finalizado"<<endl;
        if(X>O){
            cout<<"El ganador es X"<<endl;
        }
        else if(X<O){
            cout<<"El ganador es O"<<endl;
        }
        else{
            cout<<"Es un empate"<<endl;
        }
    }
    return juego;
}
