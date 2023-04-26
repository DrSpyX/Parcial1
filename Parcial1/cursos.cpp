#include "cursos.h"
#include "cadenas.h"
#include <limits>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ifstream fin;
ofstream fout;

char* pedirDatos(){                   //pide los datos de un curso al usuario y los devuelve en una cadena con el formato codigo;nombreCurso;creditos;HTD;HTI
    char* data = new char[110];
    char entrada[50];
    int creditos;
    int HTD;
    int HTI;
    char separador[2] = {';', '\0'};    //separa la informacion en el archivo

    data[0] = '\0';

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"ingrese el codigo del curso"<<endl;
    cin.getline(entrada,50,'\n');
    concatenar(data,entrada);
    concatenar(data,separador);
    cout<<"ingrese el nombre del curso"<<endl;
    cin.getline(entrada,50,'\n');
    concatenar(data,entrada);
    concatenar(data,separador);
    cout<<"ingrese el numero de creditos del curso"<<endl;
    cin>>creditos;
    cout<<"ingrese las horas de trabajo con el docente"<<endl;
    cin>>HTD;

    if(creditos == 1 && HTD == 4){     //casos de cursos con un credito
        HTI = 8;
    }
    else if(creditos == 1 && HTD == 2){
        HTI = 0;
    }
    else{
        HTI = ((creditos * 48)/16)-HTD;     //calcula HTI
    }

    char temp[2];
    temp[0] = static_cast<char>(creditos+48);       //convierte los numeros almacenados en int a char para almacenarlos en la variable con el resto de información
    concatenar(data,temp);
    concatenar(data,separador);
    temp[0] = static_cast<char>(HTD+48);
    concatenar(data,temp);
    concatenar(data,separador);
    temp[0] = static_cast<char>(HTI+48);
    concatenar(data,temp);
    concatenar(data,separador);
    separador[0] = '\n';            //agrega un salto de linea para indicar que se acaba la información de un curso
    concatenar(data,separador);

    return data;
}

void regCurso(char *cursoData){  //agrega el nuevo curso al archivo que contiene la información de los cursos(todos los datos del curso organizados)
    try{

        fout.open("cursosData.txt", ios::app);                      //abre el archivo modo append
        if(!fout.is_open()){
            throw '1';
        }
        fout<<cursoData;                     //escribe los datos en el archivo
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

int cantCursos(){
    int numLineas = 0;
    try{
        fin.open("cursosData.txt");                   //abre el archivo para lectura
        if(!fin.is_open()){
            throw '1';
        }

        char c;

        while (fin.get(c)) {         //obtiene la cantidad de lineas que hay en el archivo para saber la cantidad de cursos registrados
            if (c == '\n') {
                numLineas++;
            }
        }

        fin.close();
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

    return numLineas;
}

char*** leerCursos(){                   //lee la información de los cursos registrados en el archivo "cursosData.txt"
    char*** cursos = new char**[8];
    int k=0;
    int numLineas = cantCursos();

    try{
        fin.open("cursosData.txt");                   //abre el archivo para lectura
        if(!fin.is_open()){
            throw '1';
        }

        for(int i = 0; i < numLineas; ++i) {        //crea los arreglos de las diferentes dimensiones
            cursos[i] = new char*[5];
            for(int j = 0; j < 5; ++j) {
                cursos[i][j] = new char[50];
                k = 0;
                while(fin.peek() != ';'){
                    cursos[i][j][k] = fin.get();        //agrega un carácter del archivo al arreglo
                    k++;
                }
                cursos[i][j][k] = '\0';
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
    return cursos;
}

void delCursos(){  //elimina todos los cursos registrados
    try{

        fout.open("cursosData.txt", ios::trunc);                      //abre el archivo modo trunc para eliminar la información
        if(!fout.is_open()){
            throw '1';
        }
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
