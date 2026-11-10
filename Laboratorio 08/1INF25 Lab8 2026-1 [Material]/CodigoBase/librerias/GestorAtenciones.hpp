//
// Created by erasm on 11/06/2026.
//

#ifndef L7261_GESTOREMERGENCIAS_HPP
#define L7261_GESTOREMERGENCIAS_HPP
#include "../model/Emergencia.hpp"
#include "../model/Urgencia.hpp"
#include "../model/NoUrgencia.hpp"
#include "../model/ListaDoble.hpp"

class  GestorAtenciones {
private:
    Atencion **atenciones;

    int cantidad_atenciones;

    int capacidad;

    ListaDoble atenciones_prioridad;

public:
    GestorAtenciones();

    ~GestorAtenciones();

    void cargar_atenciones(const char *nombreArchivo, int);

    void agregar_atencion(Atencion *);

    void procesar_dia(const char *fecha);

    void generar_reporte_diario(const char *nombre_reporte);

    Atencion *reservar_memoria_atencion(char);

    void reservar_memoria();

};


#endif //L7261_GESTOREMERGENCIAS_HPP
