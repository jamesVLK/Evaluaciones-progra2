//
// Created by erasm on 11/06/2026.
//

#ifndef L7261_URGENCIA_HPP
#define L7261_URGENCIA_HPP
#include "Atencion.hpp"


class Urgencia : public Atencion {
private:
    char *zona_lesion;
    bool necesita_rx;

public:

    void get_zona_lesion(char *) const;

    void set_zona_lesion(const char *);

    bool is_necesita_rx() const;

    void set_necesita_rx(const bool necesita_rx);

    void leer(ifstream &, int);

    void imprimir(ofstream &) const;

    int obtenerPrioridad() const;

};


#endif //L7261_URGENCIA_HPP
