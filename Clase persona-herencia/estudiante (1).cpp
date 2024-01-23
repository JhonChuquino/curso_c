#include <iostream>
#include <string>
#include"persona.cpp"

using namespace std;

class Estudiante : Persona
{
private:
    string codigo_estudiante;
    string facultad;
    string correo_institucional;

public:
    Estudiante(string _codigo_estudiante, string _facultad, string _correo_institucional, string _nombres, string _apellido, string _dni) :Persona(_nombres, _apellido, _dni)
    {
        codigo_estudiante = _codigo_estudiante;
        facultad = _facultad;
        correo_institucional = _correo_institucional;
    }

    string getCodigo_estudiante()
    {
        return codigo_estudiante;
    }
    void setCodigo_estudiante(string _codigo_estudiante)
    {
        codigo_estudiante = _codigo_estudiante;
    }

    string getFacultad()
    {
        return facultad;
    }
    void setFacultad(string _facultad)
    {
        facultad = _facultad;
    }

    string getCorreo_institucional()
    {
        return correo_institucional;
    }
    void setCorreo_institucional(string _correo_institucional)
    {
        correo_institucional = _correo_institucional;
    }
    void getDatos()
    {
        cout << "los datos del estudiante es: " << getNombres() << ", " << getApellido() << " " << getDni();
    }
};




