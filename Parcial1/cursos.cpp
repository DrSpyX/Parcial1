#include "cursos.h"
#include "cadenas.h"
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
    char separador[2] = {';', '\0'};

    data[0] = '\0';

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
    temp[0] = static_cast<char>(creditos+48);
    concatenar(data,temp);
    concatenar(data,separador);
    temp[0] = static_cast<char>(HTD+48);
    concatenar(data,temp);
    concatenar(data,separador);
    temp[0] = static_cast<char>(HTI+48);
    concatenar(data,temp);
    concatenar(data,separador);
    separador[0] = '\n';
    concatenar(data,separador);

    return data;
}

void regCurso(char *cursoData){  //agrega el nuevo curso al archivo que contiene la informacion de los cursos(todos los datos del curso organizados)
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

char*** leerCursos(){
    char*** cursos = new char**[8];
    int k=0;

    try{
        fin.open("cursosData.txt");                   //abre el archivo para lectura
        if(!fin.is_open()){
            throw '1';
        }

        char c;
        int numLineas = 0;

        while (fin.get(c)) {
            if (c == '\n') {
                numLineas++;
            }
        }

        fin.close();
        fin.open("cursosData.txt");

        for(int i = 0; i < numLineas; ++i) {
            cursos[i] = new char*[5];
            for(int j = 0; j < 5; ++j) {
                cursos[i][j] = new char[50];
                k = 0;
                while(fin.peek() != ';'){
                    cursos[i][j][k] = fin.get();
                    k++;
                }
                cursos[i][j][k] = '\0';
                fin.ignore();
            }
            fin.ignore();
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
