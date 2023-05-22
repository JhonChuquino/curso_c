#include <iostream>
#include <string>
#include "biblioteca.cpp"
#include "persona.cpp"
#include "libro.cpp"
using namespace std;
class Bibliotecario:Persona{
    private:
    string codigo_bibliotecario;
    string libro_prestado[5];
    Biblioteca biblioteca;
    public:
    Bibliotecario(string _codigo_bibliotecario="", string _nombre="", string _apellido="", string _dni="", string _correo="", string _telefono="", string _direccion=""):Persona(_nombre, _apellido, _dni, _correo, _telefono, _direccion){
        codigo_bibliotecario=_codigo_bibliotecario;
    }
    string getCodigo_B(){
        return codigo_bibliotecario;
    }
    void setCodigo_B(string _codigo_bibliotecario){
        codigo_bibliotecario=_codigo_bibliotecario;
    }
    string getLibro_prestado(int num_libro){
        return libro_prestado[num_libro];
    }
    void setLibro_prestado(string _libro,int num_libro){
        libro_prestado[num_libro]=_libro;
    }
    void setDatos_biblio(){
        biblioteca.setDatos("147","huanito","Av. Pepe","987445624");
    }
    string getDatos_biblio(){
        return biblioteca.getDatos();
    }
};
class Usuario:Persona{
    private:
    string codigo_user;
    Libro libro[5];
    public:
    Usuario(string _codigo_user= "",string _nombre="", string _apellido="", string _dni="", string _correo="", string _telefono="", string _direccion=""):Persona(_nombre, _apellido, _dni, _correo, _telefono, _direccion){
        codigo_user = _codigo_user;
    }
    string getCodigo_user(){
        return codigo_user;
    }
    void setCodigo_user(string _codigo_user){
        codigo_user = _codigo_user;
    }
    string getData_User(){
        return "nombre : "+nombre+"\tapellido : "+apellido+"\tdni : "+dni+"\tcorreo : "+correo+"\ttelefono : "+telefono;
    }
    string getData_Lib(int num_lib){
        return libro[num_lib].getData();
    }
    void rellenar_lib(){
        libro[0] = { "0484758", "La Llorona", " Terror ", "Lalangi Acharte"};
        libro[1] = { "954734738", "La Leyenda de Acharte", " comedia "};
        libro[2] = { "46283858", "Los 3 Mosqueteros", " Accion", "Ls hermanos Grimm"};
        libro[3] = {"48729437", "Padre rico, Padre joven", " Psicologia ", " Anonimo"};
        libro[4] = {"3734849", "48 leyes del Poder", " Automotivacion ", " Robert Greene "};
    }
};