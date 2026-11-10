//
// Created by erasm on 11/06/2026.
//

#include "GestorAtenciones.hpp"

GestorAtenciones::GestorAtenciones() {
    cantidad_atenciones = 0;
    atenciones = nullptr;
    capacidad = 0;
}

GestorAtenciones::~GestorAtenciones() {
    delete [] atenciones;
}

void GestorAtenciones::cargar_atenciones(const char *nombreArchivo, int hh) {
    ifstream input;
    Utils::apertura_archivo_lectura(input, nombreArchivo);
    while (true) {
        int tipo;
        input >> tipo;

        if (input.eof()) break;

        input.ignore(); // coma

        Atencion *atencion = reservar_memoria_atencion(tipo);

        atencion->leer(input, hh);

        agregar_atencion(atencion);
    }

    input.close();
}

void GestorAtenciones::agregar_atencion(Atencion *atencion) {
    if (cantidad_atenciones == capacidad)
        reservar_memoria();
    atenciones[cantidad_atenciones] = atencion;
    cantidad_atenciones++;
}

void GestorAtenciones::procesar_dia(const char *fecha) {
    char path_dia[200];

    Utils::construir_path_dia(path_dia, fecha);

    for (int hh = 0; hh < 1; hh++) {
        char archivo[300];
        Utils::construir_nombre_archivo(archivo, path_dia, hh);

        cout << archivo << endl;

        cargar_atenciones(archivo, hh);
    }
}

void GestorAtenciones::generar_reporte_diario(const char *nombre_reporte) {
    ofstream output;
    Utils::apertura_archivo_escritura(output, nombre_reporte);
    cout<<cantidad_atenciones<<endl;
    for (int h = 0; h < 1; h++) {
        output << "============================\n";
        output << "HORA: " << h << "\n";
        output << "============================\n";

        output << "============================\n";
        output << "EMERGENCIAS: " << "\n";
        output << "============================\n";
        for (int i = 0; i < cantidad_atenciones; i++) {
            if (atenciones[i]->get_hora_ingreso() == h and atenciones[i]->obtenerPrioridad() == 1) {
                atenciones[i]->imprimir(output); // POLIMORFISMO
            }
        }
        output << "============================\n";
        output << "URGENCIAS: " << "\n";
        output << "============================\n";
        for (int i = 0; i < cantidad_atenciones; i++) {
            if (atenciones[i]->get_hora_ingreso() == h and atenciones[i]->obtenerPrioridad() == 2) {
                atenciones[i]->imprimir(output); // POLIMORFISMO
            }
        }
        output << "============================\n";
        output << "NO URGENCIAS: " << "\n";
        output << "============================\n";
        for (int i = 0; i < cantidad_atenciones; i++) {
            if (atenciones[i]->get_hora_ingreso() == h and atenciones[i]->obtenerPrioridad() == 3) {
                atenciones[i]->imprimir(output); // POLIMORFISMO
            }
        }

        output << "\n";
    }

    output.close();
}

Atencion *GestorAtenciones::reservar_memoria_atencion(char tipo) {
    switch (tipo) {
        case 1:
            return new Emergencia();

        case 2:
            return new Urgencia();

        case 3:
            return new NoUrgencia();

        default:
            return nullptr;
    }
}

void GestorAtenciones::reservar_memoria() {
    capacidad += 5;
    if (atenciones == nullptr) {
        atenciones = new Atencion *[capacidad]{};
    } else {
        Atencion **aux = new Atencion *[capacidad]{};
        for (int i = 0; i < cantidad_atenciones; i++) {
            aux[i] = atenciones[i];
        }
        delete[] atenciones;
        atenciones = aux;
    }
}


