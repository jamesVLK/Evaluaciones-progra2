#ifndef CODIGO_DEV_CATEGORIA_H
#define CODIGO_DEV_CATEGORIA_H
#include <iostream>

using namespace std;

class Categoria {
private:
    char codigo[7];
    char *nombre;
    char *descripcion;
public:

    friend ostream & operator<<(ostream &out, Categoria &categoria);
};



#endif //CODIGO_DEV_CATEGORIA_H
