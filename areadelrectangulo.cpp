//    07/03/2023
//HALLAR EL AREA DE UN RECTANGULO HACIENDO EL USO DE FUNCIONES

#include<iostream>
using namespace std;
//declaramos una funcion y sus parametros
int area_rectangulo(int base, int altura)
{       
	//inicializamos las variables
	float area = 0;
	//realizamos las variables
	area = (base*altura);
	//mostramos por pantalla
	cout << "el area del triangulo es : " ; cout << area << "m^2" ;
	return area;
}
int main()
{
	system("cls");
	//declaramos la variable
	int area, base, altura;
	//pedimos datos al usuario y las capturamos en las variables
	cout << "ingrese la base y la altura " << endl;
	cin >> base; cin >> altura;
	
	//llamamos la funcion
	
	area_rectangulo(base,altura);
	return 0;

}
