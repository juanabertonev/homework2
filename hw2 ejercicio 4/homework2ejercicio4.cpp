#include <ostream>
#include <iostream>
#include <string>
#include "homework2ejercicio4.h"
// 4. Se tiene una clase abstracta que representa una cuenta de banco genérica. Esta clase tiene los siguiente atributos y métodos:
// i. balance: el total de la cuenta (tipo double).
// ii. titularCuenta: nombre del dueño de la cuenta (string).
// iii. depositar(): deposita una cantidad de dinero en la cuenta.
// iv. retirar(): retira una cantidad de dinero de la cuenta (método virtual puro).
// v. mostrarInfo(): muestra la información de la cuenta (método virtual puro) que consta del balance, el tipo de cuenta y el nombre del titular.

// De esta clase se derivan dos subclases:

// CajaDeAhorro:
    // • El método retirar() impide retirar más dinero del que existe en el balance.
    // • Se realizará un descuento de $20 del balance luego de mostrar más de 2 veces la información de la cuenta.
// CuentaCorriente:
    // • El método retirar() permite retirar dinero de la caja de ahorro si no existen suficientes fondos en este tipo de cuenta.
    // • En caso de que la caja de ahorro tampoco tenga dinero, se imprimirá un aviso de que la cuenta no posee dinero. Utilizar friend para esto.

// Se pide:
// a. Establecer los especificadores de acceso (public, private y private) en los atributos y métodos de todas las clases, 
// explicando su elección en función de la seguridad y la flexibilidad para futuros requerimientos de cambio.
// b. Escriba el código para implementar todas clases.
// c. Escriba el código que permita probar los puntos mencionados para CajaDeAhorro y CuentaCorriente.

//constructor 
cajadeahorro::cajadeahorro(std::string titular, double plata): balance(plata), titularcuenta(titular),  tipodecuenta("caja de ahorro"), vecesmostrada(0) {}

// depositar esta en el .h

void cajadeahorro::retirar(float cant){
    if (cant<=balance) {
        balance-=cant;
    }
    else{
        std::cout << "no hay suficiente plata en la caja de ahorro\n";
    }
}

void cajadeahorro::mostrarinfo(){
    std::cout << "balance: " << balance << "\n";
    std::cout << "tipo de cuenta: " << tipodecuenta << "\n";
    std::cout << "titular: " << titularcuenta << "\n";
    vecesmostrada++;
    if(vecesmostrada>2){
        std::cout<< "descontamos 20$ de la caja de ahorro porq excediste el limite de mostradas(2)\n";
        balance-=20;
    }
}

//constructor
cuentacorriente::cuentacorriente(std::string titular, double plata, cajadeahorro* c): balance(plata), titularcuenta(titular),  tipodecuenta("cuenta corriente"), caja(c) {}

// depositar etsa en el .h

void cuentacorriente::retirar(float cant){
    if(cant<=balance){
        balance-=cant;
    }
    else if(cant<=caja->balance){
        int sino;
        std::cout << "no hay suficiente en la cuenta corriente, queres sacar de la caja de ahorro que si hay?(si=1,no=0) \n";
        std::cin >> sino;
        if(sino==1){
            caja->balance-=cant;
        }
        else{
            return;
        }
    }
    else{
        std::cout << "no hay suficiente plata ni en cuenta coriente ni en caja de ahorro \n";
    }
}

void cuentacorriente::mostrarinfo(){
    std::cout << "balance: " << balance << "\n";
    std::cout << "tipo de cuenta: " << tipodecuenta << "\n";
    std::cout << "titular: " << titularcuenta << "\n";
}


int main(){
    cajadeahorro caja("juana", 1000);
    cuentacorriente cuenta("juana", 90, &caja);

    std::cout << "caja de ahorro inicial: " << "\n";
    caja.mostrarinfo();
    std::cout << "cuenta corriente inicial: " << "\n";
    cuenta.mostrarinfo();

    std::cout << "depositamos 50$ en la caja de ahorro \n";
    caja.depositar(50);
    std::cout << "depositamos 100$ en la caja de ahorro \n";
    caja.depositar(100);
    std::cout << "retiramos 50$ de la caja de ahorro \n";
    caja.retirar(50);
    caja.mostrarinfo();
    std::cout << "intentamos retirar 2000$ de la caja de ahorro \n";
    caja.retirar(2000);
    caja.mostrarinfo(); // se sacan 20$

    std::cout << "depositamos 10$ en la cuenta corriente \n";
    cuenta.depositar(10);
    std::cout << "retiramos 200$ de la cuenta corriente \n";
    cuenta.retirar(200);
    std::cout << "intentamos retirar 20000$ de la cuenta corriente \n";
    cuenta.retirar(20000);
    cuenta.mostrarinfo();

    return 0;
}
