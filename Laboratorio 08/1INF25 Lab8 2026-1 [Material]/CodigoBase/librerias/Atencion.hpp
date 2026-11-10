//
// Created by erasm on 11/06/2026.
//

#ifndef L8261_ATENCION_HPP
#define L8261_ATENCION_HPP
#include "../utils/Utils.hpp"


class Atencion {
private:
    int codigo;
    string paciente;
    string descripcion;
    int hora_ingreso;

public:
    string get_paciente() const;

    void set_paciente(const string &paciente);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);

    Atencion();

    virtual ~Atencion() = default;

    virtual void leer(ifstream &, int);

    virtual void imprimir(ofstream &) const;

    virtual int obtenerPrioridad() const =0;

    Atencion &operator=(const Atencion &);

    int get_codigo() const;

    void set_codigo(int codigo);

    int get_hora_ingreso() const;

    void set_hora_ingreso(int hora_ingreso);

};

#endif //L8261_ATAtencion *ION_HPP
