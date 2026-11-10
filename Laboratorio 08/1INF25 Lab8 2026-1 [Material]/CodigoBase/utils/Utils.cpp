//
// Created by erasm on 11/06/2026.
//

#include "../../include/utils/Utils.hpp"

void Utils::apertura_archivo_lectura(ifstream &input, string nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "El archivo : " << setw(20) << nombre_archivo << "No se puede abrir" << endl;
        exit(1);
    }
}

void Utils::apertura_archivo_escritura(ofstream &output, string nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "El archivo : " << setw(20) << nombre_archivo << "No se puede abrir" << endl;
    }
}

char *Utils::fecha_a_path(const char *fecha) {
    char *path;
    path = new char[strlen(fecha) + 3];
    strcpy(path, fecha);
    for (int i = 0; path[i]; i++)
        if (path[i] == '-') path[i] = '/';
    return path;
}

char *Utils::int_a_char(int n) {
    char *buffer = new char[20];
    int i = 0;

    if (n == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return buffer;
    }

    int temp = n;
    int pot = 1;

    while (temp >= 10) {
        temp /= 10;
        pot *= 10;
    }

    while (pot > 0) {
        int dig = n / pot;
        buffer[i++] = dig + '0';
        n %= pot;
        pot /= 10;
    }

    buffer[i] = '\0';
    return buffer;
}

void Utils::construir_nombre_archivo(char *destino, const char *base, int hh) {
    strcpy(destino, base);

    char buffer_hh[10];
    sprintf(buffer_hh, "%02d", hh);

    strcat(destino, buffer_hh);
    strcat(destino, ".csv");
}

void Utils::construir_path_dia(char *destino, const char *fecha) {
    char *path_fecha = Utils::fecha_a_path(fecha);

    strcpy(destino, "ArchivosDeDatos/");
    strcat(destino, path_fecha);
    strcat(destino, "/");

    delete[] path_fecha;
}

