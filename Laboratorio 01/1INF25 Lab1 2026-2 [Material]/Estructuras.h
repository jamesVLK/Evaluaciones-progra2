//
// Created by cueva on 2/09/2025.
//

#ifndef SOBRECARGACURSOS_ESTRUCTURAS_H
#define SOBRECARGACURSOS_ESTRUCTURAS_H

    struct Producto {
        int codigo;
        char *nombre;
        char *unidad;
    };
    struct Empaque {
        int  codigo;
        char *nombre;
        int cantidad;
    };

    struct ProductoStock {
        int codigo;
        char *nombre;
        int stock;
        int empacado;
        int picking;
    };

    struct Almacen {
        char *codigo;
        int numeroProdutos;
        struct ProductoStock producto_stock[200];
    };


#endif //SOBRECARGACURSOS_ESTRUCTURAS_H