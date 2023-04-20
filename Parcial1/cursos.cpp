#include "cursos.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ifstream fin;
ofstream fout;

void concatenar(char *cadena1, char *cadena2){
    int i = 0, j = 0;
    while (cadena1[i] != '\0') {
        i++;
    }
    while (cadena2[j] != '\0') {
        cadena1[i] = cadena2[j];
        i++;
        j++;
    }
    cadena1[i] = '\0';
}

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
    separador[0] = '\n';
    concatenar(data,separador);

    return data;
}

void regCurso(char *cursoData){  //agrega el nuevo curso al archivo que contiene la informacion de los cursos
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


