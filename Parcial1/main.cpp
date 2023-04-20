#include <iostream>
#include "cursos.h"
#include "horario.h"
#include "jornada.h"

using namespace std;

int main()
{
    char* datosCurso = new char[110];
    char*** horario;

    //datosCurso = pedirDatos();
    //cout<<datosCurso<<endl;
    //regCurso(datosCurso);

    horario = crearHorario();
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 16; ++j) {
            for(int k = 0; k < 8; ++k) {
                cout<<horario[i][j][k];
            }
        }
    }

    actualizarHorario(horario);

    return 0;
}
