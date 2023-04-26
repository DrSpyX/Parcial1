#include "horario.h"
#include "cadenas.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;

char*** crearHorario(){                //crea el horario vacio
    char*** horario = new char**[6];
    for(int i = 0; i < 6; ++i) {            //crea cada dimension del arreglo
        horario[i] = new char*[16];
        for(int j = 0; j < 16; ++j) {
            horario[i][j] = new char[8];
            for(int k = 0; k < 7; ++k) {
                horario[i][j][k] = '0';     //a cada carácter le asigna un 0 para que todos los huecos del horario estén disponibles
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
    for(int i = 0; i < 6; ++i) {            //organiza la información en el formato que se utiliza en el archivo
        for(int j = 0; j < 16; ++j) {
            concatenar(data,horario[i][j]);
            concatenar(data,separador);
        }
        separador[0] = '\n';
        concatenar(data,separador);
        separador[0] = ';';
    }

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

    try{
        fin.open("horario.txt");                   //abre el archivo para lectura
        if(!fin.is_open()){
            throw '1';
        }

        for(int i = 0; i < 6; ++i) {        //crea los arreglos de las diferentes dimensiones
            horario[i] = new char*[16];
            for(int j = 0; j < 16; ++j) {
                horario[i][j] = new char[8];
                for(int k = 0; k < 7; ++k) {
                    horario[i][j][k] = fin.get();       //agrega un carácter del archivo al arreglo
                }
                horario[i][j][7] = '\0';
                fin.ignore();       //no agrega el ';'
            }
            fin.ignore();       //no agrega el salto de linea
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

void imprimirHorario(char*** horario, char*** iCursos, int cantCursos){         //imprime el horario en consola(contiene el horario, contiene la informacion de los cursos, cantidad de cursos registrados)
    char codigoCurso[8];        //almacena una copia del codigo del curso que se va a imprimir
    char libre[8] = {'0','0','0','0','0','0','0','\0'};
    char dias[6][10] = {"LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO"};
    for(int i = 0; i < 6; ++i) {
        cout<<endl<<dias[i]<<endl;
        for(int j = 0; j < 16; ++j) {
            copiar(codigoCurso,horario[i][j]);
            cout<<6+j<<":00 ";
            if(comparar(codigoCurso,libre)==true){      //verifica si el codigo del curso actual corresponde a hora libre
                cout<<"libre"<<endl;
            }
            else{
                for(int k = 0; k < cantCursos; k++){            //si no es hora libre se pasa a buscar el nombre correspondiente al codigo actual
                    if(comparar(codigoCurso,iCursos[k][0])){
                        cout<<iCursos[k][1]<<endl;
                        break;
                    }
                }
            }
        }
    }
}
