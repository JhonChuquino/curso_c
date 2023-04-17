//  05/03/2023    
//HACER UN PROGRAMA QUE CALCULE TU EDAD SEGUN TU FECHA DE NACIMIENTO Y TE DIGA SI ERES MAYOR DE EDAD O NO

#include<iostream>
using namespace std; // nos permite usar el cin y cout.
int calcular_edad(int anio_nacimiento)//llamamos a esta funcion para que se ejecuta dentro de esta funcion
{
	int edad = 0; // inicializamos la edad
	int anio;
	edad = 2023 - anio_nacimiento; // realizamos la operacion
	if(anio>=18){ //la primera condiición.
		cout <<  "tienes " << edad << "años " << " Eres mayor de edad" ;
	}else{
		cout << "tienes " << edad << "años " <<  " Eres menor de edad";
	}
	
	return edad; //nos devuelve la edad.
}
int main(){
	system("cls");
	int anio_nacimiento; //declarando la variable.
	cout << "ingresa el año de tu nacimiento" << endl;
	cin >> anio_nacimiento; // capturando el dato
	int edad = calcular_edad(anio_nacimiento);
	return 0;
	
}
