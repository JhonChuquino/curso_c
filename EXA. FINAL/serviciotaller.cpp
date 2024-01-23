#include <iostream>
#include <string>
#include <vector>

using namespace std;
#ifndef SERVICIOTALLER_H
#define SERVICIOTALLER_H

class ServicioTaller {
    private:
    string nombre;
    string descripcion;
    int tiempoEstimado;
    string fecha;

    public:  // constructor y parametros
    ServicioTaller(const string& nombre, const string& descripcion, int tiempoEstimado, string fecha)
        : nombre(nombre), descripcion(descripcion), tiempoEstimado(tiempoEstimado), fecha(fecha) {}
    //getter and setter
    string getNombre() const {
        return nombre;
    }

    string getDescripcion() const {
        return descripcion;
    }

    int getTiempoEstimado() const {
        return tiempoEstimado;
    }

    string getFecha() const {
        return fecha;
    }
};
#endif
//para evitar la redefinicion de la clase
#ifndef EMPLEADO_H
#define EMPLEADO_H

class Empleado {
    private:
    string nombre;
    string apellidos;
    string especialidad;
    int anosExperiencia;
    vector<ServicioTaller> serviciosAsignados;

    public:  // constructor y parametros, usamos el cosnt para evitar que se modifiquen
    Empleado(const string& nombre, const string& apellidos, const string& especialidad, int anosExperiencia)
        : nombre(nombre), apellidos(apellidos), especialidad(especialidad), anosExperiencia(anosExperiencia) {}
    //metodos getter and setter
    string getNombre() const {
        return nombre;
    }

    string getApellidos() const {
        return apellidos;
    }

    string getEspecialidad() const {
        return especialidad;
    }

    int getAnosExperiencia() const {
        return anosExperiencia;
    }
    
   //metodo para asignar servicios, usando el almacenamiento
    void asignarServicio(const ServicioTaller& servicio) {
        serviciosAsignados.push_back(servicio);
    }
    // Método para mostrar los servicios asignados al empleado y todos los detalles del parametro
    void mostrarServiciosAsignados() const {
        cout << "Servicios asignados a " << nombre << " " << apellidos << ":" << endl;
        for (const ServicioTaller& servicio : serviciosAsignados) {
            cout << "Nombre: " << servicio.getNombre() << endl;
            cout << "Descripción: " << servicio.getDescripcion() << endl;
            cout << "Tiempo estimado: " << servicio.getTiempoEstimado() << " horas" << endl;
            cout << "fecha en el que se realizo el servicio: "  << servicio.getFecha() << endl;
            cout << "----------------------------------" << endl;
        }
    }
    // Método para calcular el tiempo total de los servicios asignados al empleado
    int calcularTiempoTotal() const {
        int tiempoTotal = 0;
        for (const ServicioTaller& servicio : serviciosAsignados) {
            tiempoTotal += servicio.getTiempoEstimado();
        }
        return tiempoTotal;
    }

};
#endif

