#include "jornada.h"
#include "cadenas.h"
#include <iostream>
#include <random>

using namespace std;

void regHTD(char*** horario, char*** iCursos, int cantCursos){       //registra las HTD en el horario (el horario, informacion de los cursos, cantidad de cursos registrados)
    int HTD = 0;   //cantidad de clases de cada curso
    int dia = 0;
    int hora = 0;
    char libre[8] = {'0','0','0','0','0','0','0','\0'};

    cout<<"Registre las clases una por una"<<endl;

    for(int i = 0; i < cantCursos; i++){
        HTD = static_cast<int>(iCursos[i][3][0]-48);     //convierte las HTD en int
        cout<<iCursos[i][1]<<endl;
        for(int j = 0; j < HTD; j++){        //registra la hora y el dia de cada clase
            while (true){
                cout<<"Clase "<<j+1<<endl<<"Dia"<<endl<<"1. Lunes"<<endl<<"2. Martes"<<endl<<"3. Miercoles"<<endl<<"4. Jueves"<<endl<<"5. Viernes"<<endl<<"6. Sabado"<<endl;
                dia = 0;
                hora = 0;
                while(dia < 1 || dia > 6){
                    cin>>dia;
                }
                dia--;
                cout<<"Hora"<<endl;
                while(hora < 6 || hora > 21){
                    cin>>hora;
                }
                hora -= 6;
                if(comparar(horario[dia][hora],libre)){
                    copiar(horario[dia][hora],iCursos[i][0]);       //si el espacio está libre se asigna el curso al horario y detiene el ciclo
                    break;
                }
                else{                                               //si está ocupado el espacio no se asigna y se vuelve a pedir la información
                    cout<<"Espacio no disponible"<<endl;
                }
            }
        }
    }
}

void regHTI(char*** horario, char*** iCursos, int cantCursos){
    int HTI = 0;
    int dia = 0;
    int hora = 0;
    char libre[8] = {'0','0','0','0','0','0','0','\0'};
    char dias[6][10] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado"};
    int eleccion = 0;

    random_device rd;
    mt19937 gen(rd());

    cout<<"Registre las horas de estudio independiente"<<endl;

    for(int i = 0; i < cantCursos; i++){
        HTI = static_cast<int>(iCursos[i][4][0]-48);     //convierte las HTI en int
        if(HTI != 0){
            cout<<iCursos[i][1]<<endl;
            for(int j = 0; j < HTI; j++){        //registra la hora y el dia de cada clase
                while(true){
                    uniform_int_distribution<> dis1(0, 5);      //genera los numeros aleatorios
                    dia = dis1(gen);
                    uniform_int_distribution<> dis2(0, 15);
                    hora = dis2(gen);
                    if(comparar(horario[dia][hora],libre)){
                        cout<<"Hora "<<j+1<<endl<<"El "<<dias[dia]<<" a las "<<hora+6<<" esta disponible"<<endl<<"1. Usar espacio"<<endl<<"2. Sugerir otro espacio"<<endl<<"3. Asignar espacio manualmente"<<endl;
                        eleccion = 0;
                        while(eleccion < 1 || eleccion > 3){
                            cin>>eleccion;
                        }
                        if(eleccion==1){
                            copiar(horario[dia][hora],iCursos[i][0]);       //si el usuario lo desea se asigna el curso a el espacio aleatorio
                            break;
                        }
                        else if(eleccion==3){
                            while(true){
                                cout<<"Hora "<<j+1<<endl<<"Dia"<<endl<<"1. Lunes"<<endl<<"2. Martes"<<endl<<"3. Miercoles"<<endl<<"4. Jueves"<<endl<<"5. Viernes"<<endl<<"6. Sabado"<<endl;
                                dia = 0;
                                hora = 0;
                                while(dia < 1 || dia > 6){
                                    cin>>dia;
                                }
                                dia--;
                                cout<<"Hora"<<endl;
                                while(hora < 6 || hora > 21){
                                    cin>>hora;
                                }
                                hora -= 6;
                                if(comparar(horario[dia][hora],libre)){
                                    copiar(horario[dia][hora],iCursos[i][0]);       //si el espacio está libre se asigna el curso al horario y detiene el ciclo
                                    break;
                                }
                                else{                                               //si está ocupado el espacio no se asigna y se vuelve a pedir la información
                                    cout<<"Espacio no disponible"<<endl;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
