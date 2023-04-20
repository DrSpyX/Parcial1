#include "cursos.h"
#include "horario.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;

char*** crearHorario(){                //crea el horario vacio
    char*** horario = new char**[6];
    for(int i = 0; i < 6; ++i) {
        horario[i] = new char*[16];
        for(int j = 0; j < 16; ++j) {
            horario[i][j] = new char[8];
            for(int k = 0; k < 7; ++k) {
                horario[i][j][k] = '0';
            }
            horario[i][j][7] = '\0';
        }
    }

    return horario;
}

void actualizarHorario(char*** horario){        //actualiza el horario en el archivo "horario"
    char* data = new char[800];
    char separador[2] = {';', '\0'};
    data[0] = '\0';
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 16; ++j) {
            concatenar(data,horario[i][j]);
            concatenar(data,separador);
        }
    }

    cout<<data<<endl;
    try{
        fout.open("horario.txt");                      //abre el archivo para escritura
        if(!fout.is_open()){
            throw '1';
        }
        fout<<data;                //actualiza el archivo con el horario
        fout.close();                            //cierra el archivo
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
}

char*** leerHorario(){
    char*** horario = new char**[6];
    streampos pos;

    try{
        fin.open("horario.txt");                   //abre el archivo para lectura
        if(!fin.is_open()){
            throw '1';
        }

        for(int i = 0; i < 6; ++i) {
            horario[i] = new char*[16];
            for(int j = 0; j < 16; ++j) {
                horario[i][j] = new char[8];
                for(int k = 0; k < 7; ++k) {
                    horario[i][j][k] = fin.get();
                }
                horario[i][j][7] = '\0';
            }
        }
        fin.close();                        //Cierra el archivo
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para lectura."<<endl;
        }
    }
    catch (...){
        cout<<"Error no definido"<<endl;
    }
    return horario;
}

//void imprimirHorario(char*** horario){

//}
