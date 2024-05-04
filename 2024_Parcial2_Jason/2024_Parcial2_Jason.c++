#include <iostream>
#include <filesystem>
#include <windows.h>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

// Prototipos de las funciones
void init();
void impar_par(int numArchivos);
void Crear_Archivos(int numArchivos);

int main(){
    init();
    return 0;
}

// Solicita al usuario el número de archivos a crear
void init(){
    int numArchivos;
    cout << "Ingrese el número de archivos a crear: ";
    cin >> numArchivos;
    Crear_Archivos(numArchivos);
}

// Separa los archivos en dos carpetas en el escritorio que sean pares e impares
void impar_par(int numArchivos){
    // Aqui se crean los dos directorios en el escritorio
    fs::create_directory("C:/Users/jasso/Desktop/Par");
    fs::create_directory("C:/Users/jasso/Desktop/Impar");

    for (int i = 1; i <= numArchivos; ++i) {
        string nombreArchivo = "File" + to_string(i) + ".txt";
      
        if (i % 2 == 0) {
            // Mueve el archivo al directorio de par
            fs::rename(nombreArchivo, "C:/Users/jasso/Desktop/Par/" + nombreArchivo);
        } 
        
        else {
            // Mueve el archivo al directorio de impar
            fs::rename(nombreArchivo, "C:/Users/jasso/Desktop/Impar/" + nombreArchivo);
        }
    }
}

// Crea los archivos y los separan en dos diferentes directorios
void Crear_Archivos(int numArchivos){
    for (int i = 1; i <= numArchivos; ++i) {
        ofstream archivo("File" + to_string(i) + ".txt");
        // Agrega texto al archivo
        for (int j = 0; j < i; ++j) {
                archivo << "linea de texto" << endl;
            }
            archivo.close();
    }
    impar_par(numArchivos);
}

