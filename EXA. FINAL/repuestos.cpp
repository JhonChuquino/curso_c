#include <iostream>
#include <string>
#include <vector>

using namespace std;
//para evitar que nos salga el error de redefinicion
#ifndef REPUESTO_H
#define REPUESTO_H

class Repuesto {
    //atributos
    protected:
    string nombre;
    string codigo;
    double precio;
    int cantidad;
    string fechaRegistro;
    string categoria;

    public:  //constructor y parametros
    Repuesto(string _nombre ="", string _codigo = "", double _precio = 0, int _cantidad = 0, string _fechaRegistro="",string _categoria=""){
        nombre = _nombre;
        codigo = _codigo;
        precio = _precio;
        cantidad = _cantidad;
        fechaRegistro = _fechaRegistro;
        categoria = _categoria;
    }
    //metodos getter and setter
    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& _nombre) {
        nombre = _nombre;
    }

    string getCodigo() const {
        return codigo;
    }

    void setCodigo(const string& _codigo) {
        codigo = _codigo;
    }

    double getPrecio() const {
        return precio;
    }

    void setPrecio(double _precio) {
        precio = _precio;
    }

    int getCantidad() const {
        return cantidad;
    }

    void setCantidad(int nuevaCantidad) {
        cantidad = nuevaCantidad;
    }

    string getFechaRegistro() const {
        return fechaRegistro;
    }

    void setFechaRegistro(const string& _fechaRegistro) {
        fechaRegistro = _fechaRegistro;
    }

    string getCategoria(){
        return categoria;
    }
    void setCategoria(string _categoria){
        categoria = _categoria;
    }

    
};
#endif

#ifndef TIENDAREPUESTO_H
#define TIENDAREPUESTO_H

class TiendaRepuestos {
private:
    //usamos un vector para poder almacenar los atributos de repuesto
    vector<Repuesto> repuestos;

public:
    //funcion donde estan los parametros para agregar los productos o repuestos
    void agregarRepuesto(const string& nombre, const string& codigo, double precio, int cantidad, const string& fechaRegistro, const string& categoria) {
        Repuesto nuevoRepuesto(nombre, codigo, precio, cantidad,fechaRegistro,categoria);
        //podemos manipular los atributos
        repuestos.push_back(nuevoRepuesto);
    }
    //funcion que nos permite actualizar  si hay cambios 
    void actualizarStock(const string& codigo, int cantidad) {
        for (Repuesto& repuesto : repuestos) {
            if (repuesto.getCodigo() == codigo) {
                repuesto.setCantidad(repuesto.getCantidad() + cantidad);
                cout << "Stock actualizado para el repuesto \"" << repuesto.getNombre() << "\"." << endl;
                return;
            }
        }
        cout << "No se encontró ningún repuesto con el código \"" << codigo << "\"." << endl;
    }

    //funcion que nos muestra los productos con todos sus datos

    void mostrarStockPorFecha() const {
        cout << "Stock de productos por fecha de registro:" << endl;
        for (const Repuesto& repuesto : repuestos) {
            
            cout << "Nombre: " << repuesto.getNombre() << endl;
            cout << "Código: " << repuesto.getCodigo() << endl;
            cout << "Precio: $" << repuesto.getPrecio() << endl;
            cout << "Cantidad disponible: " << repuesto.getCantidad() << endl;
            cout << "Fecha de registro: " << repuesto.getFechaRegistro() << endl;  // Mostrar "N/A" si no hay atributo de fecha de registro
            cout << "Categoría: N/A" <<endl;          // Mostrar "N/A" si no hay atributo de categoría
            cout << "----------------------------------" << endl;
        }
    }
    
    //funcion que nos mustra los productos disponibles
    void mostrarRepuestosDisponibles() const {
        cout << "Repuestos disponibles:" << endl;
        for (const Repuesto& repuesto : repuestos) {
            cout << "Nombre: " << repuesto.getNombre() << endl;
            cout << "Código: " << repuesto.getCodigo() << endl;
            cout << "Precio: $" << repuesto.getPrecio() << endl;
            cout << "Cantidad disponible: " << repuesto.getCantidad() << endl;
            cout << "----------------------------------" << endl;
        }
    }

    //nos muestra los repuestos que no se venden
    void mostrarRepuestosNoVendidos() const {
        cout << "Repuestos no vendidos:" << endl;
        bool encontrados = false;
        for (const Repuesto& repuesto : repuestos) {
            if (repuesto.getCantidad() == 0) {
                cout << "Nombre: " << repuesto.getNombre() << endl;
                cout << "Código: " << repuesto.getCodigo() << endl;
                cout << "Precio: $" << repuesto.getPrecio() << endl;
                cout << "----------------------------------" << endl;
                encontrados = true;
            }
        }
        if (!encontrados) {
            cout << "No hay repuestos no vendidos." << endl;
        }
    }
};
#endif




