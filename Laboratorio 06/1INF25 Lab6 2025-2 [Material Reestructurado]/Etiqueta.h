#ifndef CODIGO_DEV_ETIQUETA_H
#define CODIGO_DEV_ETIQUETA_H
#include <iostream>

using namespace std;

class Etiqueta {
private:
    char codigo[7];
    char *nombre;
public:
    friend bool operator>>(istream &archivo_de_etiquetas, Etiqueta &etiqueta);
    friend ostream & operator<<(ostream &out, Etiqueta &etiqueta);
};


#endif //CODIGO_DEV_ETIQUETA_H