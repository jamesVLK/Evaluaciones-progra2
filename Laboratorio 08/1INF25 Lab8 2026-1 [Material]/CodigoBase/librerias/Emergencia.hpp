//
// Created by erasm on 11/06/2026.
//

#ifndef L7261_EMERGENCIA_HPP
#define L7261_EMERGENCIA_HPP
#include "Atencion.hpp"


class Emergencia : public Atencion {
private:
    bool requiere_rcp;
    int minutos_sin_pulso;
public:
    Emergencia();
    void leer(ifstream &,int);
    void imprimir(ofstream &) const;
    int obtenerPrioridad() const;
};


#endif //L7261_EMERGENCIA_HPP
