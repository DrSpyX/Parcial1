#include "cadenas.h"

void concatenar(char* cadena1, char* cadena2){          //concatena dos cadenas(cadena principal, cadena para concatenar)
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

void copiar(char* copia, char* original) {  //crea una copia de una cadena
    int i = 0;
    while (original[i] != '\0') {
        copia[i] = original[i];
        i++;
    }
    copia[i] = '\0';
}

bool comparar(const char* cadena1, const char* cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
        i++;
    }
    if (cadena1[i] != cadena2[i]) {
        return false;
    }
    return true;
}
