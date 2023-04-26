#include <iostream>
#include "cursos.h"
#include "horario.h"
#include "jornada.h"

using namespace std;

int select(int no){                     //pide un numero al usuario para navegar a travez de menus (numero de opciones)
    int selUser = 0;
    while(selUser < 1 || selUser > no){
        cin>>selUser;
    }
    return selUser;
}

int main()
{
    char* datosCurso = new char[110];     //contiene informacion del curso pedido al usuario
    char*** horario;           //contiene el horario
    char*** cursos;            //contiene informacion de todos los cursos
    int nCursos = 0;           //numero de cursos registrados
    int eleccion = 0;        //eleccion del usuario en el menú

    while(true){
        cout<<"Agenda"<<endl<<"1. Crear nueva agenda"<<endl<<"2. Ver agenda"<<endl<<"3. Salir"<<endl;
        eleccion = select(3);

        if(eleccion==1){
            cout<<"Se eliminara la agenda anterior"<<endl<<"1. Continuar"<<endl<<"2. Volver"<<endl;
            eleccion = select(2);
            if(eleccion==1){
                horario = crearHorario();
                actualizarHorario(horario);
                delCursos();      //elimina el horario y cursos anteriores

                cout<<"Cuantos cursos desea registrar?"<<endl;
                cin>>nCursos;
                for(int i = 1; i <= nCursos; i++){        //registra los cursos
                    cout<<"Curso "<<i<<endl;
                    datosCurso = pedirDatos();
                    regCurso(datosCurso);
                    delete[] datosCurso;
                }
                cursos = leerCursos();
                regHTD(horario, cursos, nCursos);   //registra las HTD en el horario
                actualizarHorario(horario);
                regHTI(horario, cursos, nCursos);   //registra las HTI en el horario

                cout<<"HORARIO"<<endl;
                imprimirHorario(horario, cursos, nCursos);  //imprime el horario en consola

                actualizarHorario(horario);

                cout<<"1. Salir"<<endl;
                select(1);
            }
        }
        else if(eleccion==2){       //imprime el horario en consola
            horario = leerHorario();
            cursos = leerCursos();
            nCursos = cantCursos();

            cout<<"HORARIO"<<endl;
            imprimirHorario(horario, cursos, nCursos);

            cout<<"1. Salir"<<endl;
            select(1);
        }
        else if(eleccion==3){
            break;
        }
    }
    return 0;
}
