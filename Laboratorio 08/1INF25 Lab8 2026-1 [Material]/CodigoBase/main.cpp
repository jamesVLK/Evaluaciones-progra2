#include "librerias/GestorAtenciones.hpp"

int main() {
    GestorAtenciones gestor;
    cout<<"Comienza la Carga de Atenciones por Prioridad"<<endl;
    gestor.cargar_atenciones_prioridad("ArchivosDeDatos/1992/01/23/10.csv");
    cout<<"Termina la Carga de Atenciones por Prioridad"<<endl;
    gestor.imprime_atenciones_prioridad("ArchivosDeReportes/1992/01/23/10.txt");
    cout<<"Termina la Impresion de Atenciones por Prioridad"<<endl;
    return 0;
}