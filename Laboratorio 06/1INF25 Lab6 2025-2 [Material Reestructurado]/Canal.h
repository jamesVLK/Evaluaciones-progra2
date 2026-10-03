#ifndef CODIGO_DEV_CANAL_H
#define CODIGO_DEV_CANAL_H
#include <iostream>
#define CANAL_NO_LEIDO -1
#define MAX_VECTOR_ETIQUETAS 5

using namespace std;

class Canal {
private:
    char *nombre;
    char *categoria;
    char *etiquetas;
    int cantidad_etiquetas;
    char *vector_etiquetas[MAX_VECTOR_ETIQUETAS];
    int seguidores;
public:

    friend ostream & operator<<(ostream &out, Canal &canal);
};


#endif //CODIGO_DEV_CANAL_H
