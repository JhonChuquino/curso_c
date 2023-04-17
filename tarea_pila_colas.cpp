//25/03/2023
//HACER UN PROGRAMA QUE TOME EL VALORES DE LA PILA Y LAS MUESTRE EN LA COLA

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    system("cls");
   stack<int> mi_pila; // Definir la pila
   queue<int> mi_cola; // Definir la cola
   
   mi_pila.push(1); // Añadir elementos a la pila
   mi_pila.push(2);
   mi_pila.push(3);
   mi_pila.push(4);
   mi_pila.push(5);
   
   cout << "Los valores de la pila son: ";
   
   while(!mi_pila.empty()) { // Iterar hasta que la pila esté vacía
      cout << mi_pila.top() << " "; // Obtener el valor en la parte superior de la pila
      mi_cola.push(mi_pila.top()); // Añadir el valor en la cola
      mi_pila.pop(); // Eliminar el valor de la pila
   }
   
   cout << "\nLos valores de la cola son: ";
   while(!mi_cola.empty()) { // Iterar hasta que la cola esté vacía
      cout << mi_cola.front() << " "; // Obtener el valor en el frente de la cola
      mi_cola.pop(); // Eliminar el valor de la cola
   }
   
   return 0;
}