#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include "espacio.h"
using namespace std;

void opcionesjuego(Espacio **, char, char, string *, int *);
string movusuario(string *);
void imprimirjuego(Espacio **);
void reiniciaropciones(string *, int *);
void jugada(Espacio ** , string *, int *, string, char);
bool finopciones(string *);
void finjuego(Espacio **);
void imphistorial();

int filas = 8, columnas = 8;

int main()
{
    cout<<"Bienvenido a eothello"<<endl;
    bool menu= true;
    short int mov=0;
    while(menu){
        cout<<"Ingrese:"<<endl<<"1-Para jugar"<<endl<<"2-Para ver historial"<<endl<<"3-Para salir: ";
        cin>>mov;
        while(mov<1 || mov>3){
            cout<<"Ingrese un movimiento valido: ";
            cin>>mov;
        }
        if (mov==1){
            Espacio** matriz = new Espacio*[filas];

            for (int i = 0; i < filas; i++) {
                matriz[i] = new Espacio[columnas];
            }
            char signo2='X', signo1='O';
            matriz[3][3].setSigno(signo2);
            matriz[3][4].setSigno(signo1);
            matriz[4][3].setSigno(signo1);
            matriz[4][4].setSigno(signo2);
            bool juego=true, turno=true, auxturno=true;
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
                    auxturno=finopciones(opciones);
                    if(auxturno==false){
                        turno=true;
                        reiniciaropciones(opciones,copciones);
                        opcionesjuego(matriz,signo1, signo2,opciones,copciones);
                    }
                }
                else{
                    cout<<"Turno de X"<<endl;
                    mov=movusuario(opciones);
                    jugada(matriz, opciones, copciones, mov, signo2);
                    turno=true;
                    reiniciaropciones(opciones,copciones);
                    opcionesjuego(matriz,signo1, signo2,opciones,copciones);
                    auxturno=finopciones(opciones);
                    if(auxturno==false){
                        turno=false;
                        reiniciaropciones(opciones,copciones);
                        opcionesjuego(matriz,signo2, signo1,opciones,copciones);
                    }
                }
                juego=finopciones(opciones);
            }
            finjuego(matriz);

            for (int i = 0; i < filas; i++) {
                delete[] matriz[i];
            }
            delete[] matriz;
            delete[] opciones;
            delete[] copciones;
        }
        else if(mov==2){
            imphistorial();
        }
        else{
            menu=false;
        }
    }
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

bool finopciones(string *opciones)
{
    bool juego=true;
    if(opciones[0]==""){
        juego=false;
    }
    return juego;
}

void finjuego(Espacio **matriz)
{
    string jugx, jugo, juego;
    int x=0, o=0;
    imprimirjuego(matriz);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if(matriz[i][j].getSigno()=='X'){
                x+=1;
            }
            else if(matriz[i][j].getSigno()=='O'){
                o+=1;
            }
        }
    }
    if(x<o){
        cout<<"El ganador es el jugador O"<<endl;
        juego="-pierde con-";
    }
    else if(x>o){
        cout<<"El ganador es el jugador X"<<endl;
        juego="-gana a-";
    }
    else{
        cout<<"Ha sido un empate"<<endl;
        juego="-empata con-";
    }
    auto now = chrono::system_clock::now();
    time_t tiempo_actual = chrono::system_clock::to_time_t(now);
    tm local_time = *localtime(&tiempo_actual);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_time);
    cout<<"Ingrese el nombre del jugador X: ";
    cin>>jugx;
    cout<<"Ingrese el nombre del jugador O: ";
    cin>>jugo;
    ofstream archi;
    archi.open("Partidas.txt", ios::app);
    archi<<jugx;
    archi<<'[';
    archi<<x;
    archi<<']';
    archi<<juego;
    archi<<jugo;
    archi<<'[';
    archi<<o;
    archi<<']';
    archi<<'-';
    archi<<buffer;
    archi<<'\n';
    archi.close();
}

void imphistorial()
{
    string linea;
    ifstream arch;
    arch.open("Partidas.txt");
    while(arch.good()){
        getline(arch,linea);
        cout<<linea<<endl;
    }
}
