#include "caratula.h"
#include <iostream>
#include <fstream>

void Juego::dibujarPortada(const std::string& archivoPortada) {
    std::ifstream archivo(archivoPortada);
    if (archivo.is_open()) {
        std::string linea;
        while (getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << archivoPortada << std::endl;
    }
}
