#include <iostream>
#include "cursos.h"
#include "horario.h"
#include "jornada.h"

using namespace std;

int select(int no){                     //pide un numero al usuario para navegar a travez de menus (numero de opciones)
    int selUser = 0;
    while(selUser < 1 || selUser > no){
        cin >> selUser;
    }
    return selUser;
}

int main()
{
    char* datosCurso = new char[110];     //contiene informacion del curso pedido al usuario
    char*** horario;           //contiene el horario
    char*** cursos;            //contiene informacion de todos los cursos

    int eleccionMP = 0;

    while(true){
        cout<<"Agenda"<<endl<<"1. Crear nueva agenda"<<endl<<"2. Ver agenda"<<endl<<"3. Salir"<<endl;
        eleccionMP = select(3);

        if(eleccionMP==1){
            horario = crearHorario();
        }
        else if(eleccionMP==2){
            horario = leerHorario();
            cursos = leerCursos();
            cout<<"Horario"<<endl;
            imprimirHorario(horario, cursos);
            int eleccionVa = 0;
            while(true){
                cout<<"1. Salir"<<endl;
                eleccionVa = select(1);
                if(eleccionVa==1){
                    break;
                }
            }
        }
        else if(eleccionMP==3){
            break;
        }
    }
    return 0;
}
