//
// Created by erasm on 11/06/2026.
//

#ifndef L7261_NOURGENCIA_HPP
#define L7261_NOURGENCIA_HPP
#include "Atencion.hpp"


class NoUrgencia : public Atencion {
private:
    char *especialidad;
    bool es_consulta_programada;

public:

    void get_especialidad(char*) const;

    void set_especialidad(const char *);

    bool is_es_consulta_programada() const;

    void set_es_consulta_programada(bool es_consulta_programada);

    void leer(ifstream &,int);

    void imprimir(ofstream &) const;

    int obtenerPrioridad() const;
};


#endif //L7261_NOURGENCIA_HPP
