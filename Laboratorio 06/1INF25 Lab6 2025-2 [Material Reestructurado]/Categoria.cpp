#include <iostream>
#include <cstring>
#include "Categoria.h"
#include "Comunes.h"

using namespace std;

ostream & operator<<(ostream &out, Categoria &categoria) {
    out << categoria.codigo;
    out << ": ";
    out << categoria.nombre;
    out << " - ";
    out << categoria.descripcion;
    return out;
}
