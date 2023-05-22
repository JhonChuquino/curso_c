//Elabore un programa que implemente una clase denominada vehiculo que contenga los siguientes 
//atributos cilindrada de motor
//numero de asientos, numero de ruedas, numero de puertas, certificacion de seguridad.
#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include<iostream>
#include<string>
using namespace std;

class Transporte
{
    protected:
    int cilindradaMotor;
    int numAsientos;
    int numRuedas;
    int numPuertas;
    bool certificacionSeguridad;
    
    public:
    Transporte(int _cilindrada = 0, int _asientos = 0, int _ruedas = 0, int _puertas = 0, bool _seguridad = "") {
        cilindradaMotor = _cilindrada;
        numAsientos = _asientos;
        numRuedas = _ruedas;
        numPuertas = _puertas;
        certificacionSeguridad = _seguridad;
    }

    // Métodos para obtener los valores de los atributos
    int getCilindradaMotor(){
        return cilindradaMotor;
    }
    void setCilindradaMotor(int _cilindrada){
        cilindradaMotor = _cilindrada;
    }

    int getNumAsientos(){
        return numAsientos;
    }
    void setNumAsientos(int _asientos){
        numAsientos = _asientos;
    }

    int getNumRuedas(){
        return numRuedas;
    }
    void setNumRuedas(int _ruedas){
        numRuedas = _ruedas;
    }

    int getNumPuertas(){
        return numPuertas;
    }
    void setNumPuertas(int _puertas){
        numPuertas = _puertas;
    }

    bool tieneCertificacionSeguridad(){
        return certificacionSeguridad;
    }
};
#endif // TRANSPORTE_H
