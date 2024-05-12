#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Diccionario para las traducciones
map<string, string> translations = {
    {"if", "si"},
    {"}else{", "si_no"},
    {"for", "para"},
    {"while", "mientras"},
    {"asm", "ensamble"},
    {"auto", "automatico"},
    {"bool", "booleano"},
    {"break", "romper"},
    {"case", "caso"},
    {"catch", "atrapar"},
    {"char", "variable_global"},
    {"class", "clase"},
    {"const", "constante"},
    {"const_cast", "reparto_constante"},
    {"continue", "continuar"},
    {"default", "por_defecto"},
    {"delete", "borrar"},
    {"do", "hacer"},
    {"double", "doble"},
    {"dynamic_cast", "transmision_dinamica"},
    {"enum", "enumeracion"},
    {"explicit", "explicito"},
    {"extern", "externo"},
    {"false", "falso"},
    {"float", "flotante"},
    {"fried", "frito"},
    {"goto", "ir_a"},
    {"inline", "en_linea"},
    {"int", "entero"},
    {"long", "largo"},
    {"mutable", "mudable"},
    {"namespace", "espacio_de_nombres"},
    {"new", "nuevo"},
    {"operator", "operador"},
    {"private", "privado"},
    {"protected", "protegido"},
    {"public", "publico"},
    {"register", "resgistro"},
    {"reinterpret_cast", "generador_de_valor"},
    {"return", "devolver"},
    {"short", "corto"},
    {"signed", "firmado"},
    {"sizeof", "tamaño_de"},
    {"static", "estatico"},
    {"static_cast", "transmision_estatica"},
    {"struct", "estructura"},
    {"switch", "cambiar"},
    {"template", "plantilla"},
    {"this", "esto"},
    {"throw","esto"},
    {"true", "verdadero"},
    {"try", "intentar"},
    {"typedef", "definicion_de_tipo"},
    {"typedi", "mecanografiado"},
    {"typename", "escribe_un_nombre"},
    {"union", "union"},
    {"unsigned", "no firmado"},
    {"using", "usado"},
    {"virtual", "virtual"},
    {"void", "vacio"},
    {"voltatile", "volatil"},
    {"main()", "principal"},
    {"string", "cadena"},
    // Puedes agregar más palabras según lo definido en la Fase I
};

// Función para traducir una línea de código
string translateLine(const string& line) {
    istringstream iss(line);
    string word;
    string translatedLine;
    bool isFunctionOrMethod = false;

    // Verificar si la línea contiene una función o método
    if (line.find("()") != string::npos) {
        isFunctionOrMethod = true;
    }

    while (iss >> word) {
        // Verificar si la palabra es una llave
        if (word == "{") {
            if (!isFunctionOrMethod) {
                translatedLine += " inicio_estructura_control ";
            } else {
                translatedLine += " { ";
            }
        } else if (word == "}") {
            if (!isFunctionOrMethod) {
                translatedLine += " fin_estructura_control ";
            } else {
                translatedLine += " } ";
            }
        } else {
            // Traducir la palabra si está en el diccionario, de lo contrario, mantenerla igual
            auto it = translations.find(word);
            if (it != translations.end()) {
                translatedLine += it->second + " ";
            } else {
                translatedLine += word + " ";
            }
        }
    }
    return translatedLine;
}

int main() {
    string input;
    cout << "Ingresa el codigo C++ (termina con una linea vacia):\n";
    // Leer el texto multilínea
    string line;
    while (getline(cin, line) && !line.empty()) {
        input += line + "\n";
    }
    // Separar el texto en líneas y traducirlas
    istringstream iss(input);
    string translatedCode;
    while (getline(iss, line)) {
        translatedCode += translateLine(line) + "\n";
    }
    // Mostrar el código traducido
    cout << "Codigo traducido:\n";
    cout << translatedCode;
    return 0;
}

