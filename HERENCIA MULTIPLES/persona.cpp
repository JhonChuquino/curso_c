#include <iostream>
#include <string>

using namespace std;

class Persona{
    private:
    string nombre;
    string apellidos;
    int edad;
    public:
    Persona( string _nombre="", string _apellido ="", int _edad=0){
        nombre = _nombre;
        apellidos = _apellido;
        edad = _edad;
    }

    void setDatosPersona(string _nombre, string _apellido, int _edad){
        nombre = _nombre;
        apellidos = _apellido;
        edad = _edad;
    }

    string getDataPersona(){
        return "apellidos y nombre : " + apellidos + " ," + nombre + ", edad : " + to_string(edad);
    }
};