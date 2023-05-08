#include <iostream>
#include <string>
#include "profesor.cpp"
#include "investigador.cpp"

using namespace std;

class Profesorinvestigador : public  Profesor , public  Investigador
{
    private:
    //string codigo_e;

    public:
    Profesorinvestigador( string _nombre = "", string _dni = 0, string _facultad = "", string _codigo = "", string _especialidad = "", string _libros_pub = "") : Profesor(_nombre, _dni, _facultad) , Investigador(_codigo, _especialidad, _libros_pub)
    {
        //codigo_e = _codigo_e;
    }

};
