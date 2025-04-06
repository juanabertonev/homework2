#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "homework2ejercicio3.h"
// 3. Escriba una interfaz llamada “Numero” que indique la implementación de las operaciones suma, resta y multiplicación 
// de números (si desea, puede también agregar la división), así como también un método denominado “toString” que muestra el número en formato string.
// a. De esta interfaz, se deben implementar las siguientes tres clases:
//     • Clase “Entero”,
//     • Clase “Real”,
//     • Clase “Complejo”
// b. Verifique el funcionamiento de cada uno de estas clases mediante la implementación de cada una de las operaciones
// con los números que desee e imprima el resultado utilizando el método “toString”.



int main() {
    numero* e1 = new entero(10);
    numero* e2 = new entero(3);
    numero* r1 = new real(4.2);
    numero* r2 = new real(-1);
    numero* c1 = new complejo(4, -1);
    numero* c2 = new complejo(1, 5);

    // enteros
    std::cout << "Suma enteros: " << e1->suma(e2)->tostring() << "\n";
    std::cout << "Resta enteros: " << e1->resta(e2)->tostring() << "\n";
    std::cout << "Multiplicación enteros: " << e1->multiplicacion(e2)->tostring() << "\n";
    std::cout << "División enteros: " << e1->division(e2)->tostring() << "\n\n";

    // reales
    std::cout << "Suma reales: " << r1->suma(r2)->tostring() << "\n";
    std::cout << "Resta reales: " << r1->resta(r2)->tostring() << "\n";
    std::cout << "Multiplicación reales: " << r1->multiplicacion(r2)->tostring() << "\n";
    std::cout << "División reales: " << r1->division(r2)->tostring() << "\n\n";

    // complejos
    std::cout << "Suma complejos: " << c1->suma(c2)->tostring() << "\n";
    std::cout << "Resta complejos: " << c1->resta(c2)->tostring() << "\n";
    std::cout << "Multiplicación complejos: " << c1->multiplicacion(c2)->tostring() << "\n";
    std::cout << "División complejos: " << c1->division(c2)->tostring() << "\n";

    // liberar memoria
    delete e1;
    delete e2;
    delete r1; 
    delete r2;
    delete c1; 
    delete c2;

    return 0;
}
