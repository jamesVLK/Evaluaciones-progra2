#include <iostream>
#include "Canal.h"

#include <complex.h>
#include <cstring>


using namespace std;


ostream &operator<<(ostream &out, Canal &canal) {
    out << canal.nombre;
    out << ": ";
    out << canal.seguidores;
    out << " - ";
    out << canal.categoria;
    out << "[";
    for (int i = 0; i < canal.cantidad_etiquetas; i++) {
        out << canal.vector_etiquetas[i];
        if (i > 0 and i != canal.cantidad_etiquetas - 1)
            out << ", ";
    }
    out << "]";
    return out;
}
