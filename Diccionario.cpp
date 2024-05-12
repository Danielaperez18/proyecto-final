#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const char* ARCHIVO_DICCIONARIO = "diccionario.dat";

struct Palabra {
    char palabra[50];
    char traduccion[50];
};

void inicializarDiccionario();

void cargarDiccionario() {
    FILE* archivo = fopen(ARCHIVO_DICCIONARIO, "rb");
    if (archivo != NULL) {
        Palabra palabra;
        while (fread(&palabra, sizeof(Palabra), 1, archivo)) {
            cout << palabra.palabra << ": " << palabra.traduccion << endl;
        }
        fclose(archivo);
        cout << "Diccionario cargado correctamente." << endl;
    } else {
        cout << "El archivo del diccionario no existe. Inicializando con palabras predeterminadas." << endl;
        inicializarDiccionario();
        cargarDiccionario();
    }
}

void inicializarDiccionario() {
    Palabra palabrasPredeterminadas[] = {
        {"if", "Si"},
        {"asm", "Ensamblador"},
        {"auto", "Automatico"},
        {"bool", "Booleano"},
        {"break", "Interrumpir"},
        {"case", "Caso"},
        {"catch", "Captura"},
        {"char", "Caracter"},
        {"class", "Clase"},
        {"const", "Constante"},
        {"const_cast", "Moldear_Constante"},
        {"continue", "Continuar"},
        {"default", "Predeterminado"},
        {"delete", "Eliminar"},
        {"do", "Hacer"},
        {"double", "Doble"},
        {"dynamic_cast", "Convercion_Dinamica"},
        {"else", "Si no"},
        {"enum", "Enumeracion"},
        {"explicit", "Explicito"},
        {"extern", "Externo"},
        {"false", "Falso"},
        {"float", "Flotante"},
        {"for", "Para"},
        {"friend", "Amigo"},
        {"goto", "Ir a"},
        {"inline", "En linea"},
        {"int", "Entero"},
        {"long", "Largo"},
        {"mutable", "Mutable"},
        {"namespace", "Espacio de Nombre"},
        {"new", "Nuevo"},
        {"operator", "Operador"},
        {"private", "Privado"},
        {"protected", "Protegido"},
        {"public", "Publico"},
        {"register", "Registrado"},
        {"reinterpret_cast", "Reinterpretar Lanzamiento"},
        {"return", "Retornar"},
        {"short", "Corto"},
        {"signed", "Con signo"},
        {"sizeof", "Tamaño de"},
        {"static", "Estatico"},
        {"static_cast", "Lanzamiento Estatico"},
        {"struct", "Estructura"},
        {"switch", "Interruptor"},
        {"template", "Plantilla"},
        {"this", "this"},
        {"throw", "Lanzar"},
        {"true", "Verdadero"},
        {"try", "Intentar"},
        {"typedef", "Definicion de Tipo"},
        {"typeid", "typeid"},
        {"typename", "Nombre de Tipo"},
        {"union", "Union"},
        {"unsigned", "No Asignado"},
        {"using", "Asignado"},
        {"virtual", "Virtual"},
        {"void", "Vacio"},
        {"volatile", "Volatil"},
        {"while", "Mientras"}
    };

    FILE* archivo = fopen(ARCHIVO_DICCIONARIO, "ab");
    if (archivo != NULL) {
        fwrite(palabrasPredeterminadas, sizeof(Palabra), sizeof(palabrasPredeterminadas) / sizeof(Palabra), archivo);
        fclose(archivo);
        cout << "Diccionario inicializado con palabras predeterminadas." << endl;
    } else {
        cout << "No se pudo inicializar el diccionario con palabras predeterminadas." << endl;
    }
}

void guardarPalabra(const char* palabra, const char* traduccion) {
}

void actualizarPalabra(const char* palabra, const char* traduccion) {
}

void eliminarPalabra(const char* palabra) {
}

void verDiccionario() {
    cargarDiccionario();
}

int main() {
    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Ver Diccionario\n";
        cout << "2. Agregar Palabra\n";
        cout << "3. Actualizar Palabra\n";
        cout << "4. Eliminar Palabra\n";
        cout << "5. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        char palabra[50];
        char traduccion[50];

        switch (opcion) {
            case 1:
                cout << "\nDiccionario:\n";
                verDiccionario();
                break;
            case 2:
                cout << "Ingrese Palabra: ";
                cin >> palabra;
                cout << "Ingrese Traducción: ";
                cin >> traduccion;
                guardarPalabra(palabra, traduccion);
                break;
            case 3:
                cout << "Ingrese Palabra a actualizar: ";
                cin >> palabra;
                cout << "Ingrese nueva Traducción: ";
                cin >> traduccion;
                actualizarPalabra(palabra, traduccion);
                break;
            case 4:
                cout << "Ingrese Palabra a eliminar: ";
                cin >> palabra;
                eliminarPalabra(palabra);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese un número del 1 al 5." << endl;
        }
    } while (opcion != 5);

    return 0;
}

