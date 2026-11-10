//
// Created by erasm on 11/06/2026.
//

#include "Atencion.hpp"

int Atencion::get_codigo() const {
    return codigo;
}

void Atencion::set_codigo(int codigo) {
    this->codigo = codigo;
}

int Atencion::get_hora_ingreso() const {
    return hora_ingreso;
}

void Atencion::set_hora_ingreso(int hora_ingreso) {
    this->hora_ingreso = hora_ingreso;
}

string Atencion::get_paciente() const {
    return paciente;
}

void Atencion::set_paciente(const string &paciente) {
    this->paciente = paciente;
}

string Atencion::get_descripcion() const {
    return descripcion;
}

void Atencion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

Atencion::Atencion() {
    codigo = 0;
    hora_ingreso = 0;
    paciente = "";
    descripcion = "";
}

void Atencion::leer(ifstream & input, int hh) {
    /*
    * 1,1001,Juan Perez,Paro Cardiaco,1,3
    * 2,1002,Ana Ruiz,Dificultad Respiratoria,88,1
    * 3,1003,Carlos Diaz,Fractura Brazo,Brazo Derecho,1
     */

    int _codigo;
    char buffer[100];
    input >> _codigo;
    if (input.eof()) return;
    input.ignore();
    input.getline(buffer,100, ',');
    set_codigo(_codigo);
    set_paciente(buffer);
    input.getline(buffer,100, ',');
    set_descripcion(buffer);
    set_hora_ingreso(hh);
}

void Atencion::imprimir(ofstream & output) const {
    output << setw(10)  << codigo ;
    output << setw(20)  << paciente ;
    output << setw(60)  << descripcion ;
}

Atencion &Atencion::operator=(const Atencion &other) {
    if (this == &other)
        return *this;

    codigo = other.codigo;
    hora_ingreso = other.hora_ingreso;
    paciente = other.paciente;
    descripcion = other.descripcion;

    return *this;
}
