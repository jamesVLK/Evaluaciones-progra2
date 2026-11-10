//
// Created by erasm on 11/06/2026.
//

#include "Emergencia.hpp"

Emergencia::Emergencia() {
    requiere_rcp = false;
    minutos_sin_pulso = 0;
}


void Emergencia::leer(ifstream &input,int hh) {
    //1,1001,Juan Perez,Paro Cardiaco,1,3
    Atencion::leer(input, hh);
    input >> requiere_rcp;
    input.ignore();
    input >> minutos_sin_pulso;
    input.ignore();
}

void Emergencia::imprimir(ofstream &output) const {
    Atencion::imprimir(output);
    // atributos propios
    output << setw(10) << (requiere_rcp ? "SI" : "NO") ;
    output << setw(10) << minutos_sin_pulso;
    output << setw(30) <<"Nivel: CRITICO (0 min)\n";
}

int Emergencia::obtenerPrioridad() const {
    return 1;
}

