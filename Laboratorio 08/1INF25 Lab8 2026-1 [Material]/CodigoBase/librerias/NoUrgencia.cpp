//
// Created by erasm on 11/06/2026.
//

#include "../../include/model/NoUrgencia.hpp"

void NoUrgencia::get_especialidad(char* especialidad) const {
    if (this->especialidad == nullptr) especialidad[0] = '\0';
    else strcpy(especialidad, this->especialidad);
}

void NoUrgencia::set_especialidad(const char *especialidad) {
    if (this->especialidad != nullptr) delete [] this->especialidad;
    this->especialidad = new char[strlen(especialidad) + 1];
    strcpy(this->especialidad, especialidad);
}

bool NoUrgencia::is_es_consulta_programada() const {
    return es_consulta_programada;
}

void NoUrgencia::set_es_consulta_programada(bool es_consulta_programada) {
    this->es_consulta_programada = es_consulta_programada;
}

void NoUrgencia::leer(ifstream &input,int hh) {
    //3,1005,Luis Torres,Dermatitis,Dermatologia,0
    Atencion::leer(input,hh);
    char buffer[100];
    input.getline(buffer,100, ',');
    set_especialidad(buffer);
    input>>es_consulta_programada;
    input.ignore();
}

void NoUrgencia::imprimir(ofstream &output) const {
    Atencion::imprimir(output);
    output << setw(20)<< especialidad;
    output << setw(20)<< (es_consulta_programada ? "SI" : "NO") << "\n";
}

int NoUrgencia::obtenerPrioridad() const {
    return 3;
}
