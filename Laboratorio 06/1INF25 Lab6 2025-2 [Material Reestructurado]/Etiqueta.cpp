#include <iostream>
#include <cstring>
#include "Etiqueta.h"
#include "Comunes.h"

using namespace std;


bool operator>>(istream &archivo_de_etiquetas, Etiqueta &etiqueta) {
    char codigo_buffer[7];
    char nombre_buffer[20];

    archivo_de_etiquetas.getline(codigo_buffer, 7, ',');
    if (archivo_de_etiquetas.eof())
        return false;
    archivo_de_etiquetas.getline(nombre_buffer, 20, '\n');

    Etiqueta etiqueta_local(codigo_buffer, nombre_buffer);
    etiqueta = etiqueta_local;
    return true;
}

ostream & operator<<(ostream &out, Etiqueta &etiqueta) {
    out << etiqueta.codigo;
    out << ": ";
    out << etiqueta.nombre;
    return out;
}