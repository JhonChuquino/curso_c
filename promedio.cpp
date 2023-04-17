//    05/03/2023
//HACER UN PROGRAMA QUE CALCULE EL PROMEDIO

#include<iostream>
using namespace std; // nos permite usar el cin y cout.
float calcular_prom(float not1, float not2, float not3)
{
	float prom = 0;
	prom = ( not1 + not2 + not3 )/3; // realiza la operacion
	return prom; 
}
int main(){
	system("cls"); // para limpiar la pantalla.
	float not1 = 0, not2 = 0, not3 = 0; //declarando las variables.
	float prom = 0;
	cout << "ingrese sus notas " << endl;
	cin >> not1 ; // capturando el primer dato
	cin >> not2 ; // capturando el segundo dato
	cin >> not3 ; // capturando el tercer dato
	system("cls");
	prom = calcular_prom( not1, not2, not3);
	if(prom >=10.5){ //la condicinal para saber si aprobo o desaprobo
		cout << " USTED APROBO CON :  " ; cout<< prom;
	}else { // caso que no se cumpla la condicional
		cout << "USTED DESAPROBO CON : " ; cout << prom;
	}
	return 0;
}
