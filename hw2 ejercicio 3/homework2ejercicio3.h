#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <complex>
#include <sstream>

// 3. Escriba una interfaz llamada “Numero” que indique la implementación de las operaciones suma, resta y multiplicación 
// de números (si desea, puede también agregar la división), así como también un método denominado “toString” que muestra el número en formato string.
// a. De esta interfaz, se deben implementar las siguientes tres clases:
//     • Clase “Entero”,
//     • Clase “Real”,
//     • Clase “Complejo”
// b. Verifique el funcionamiento de cada uno de estas clases mediante la implementación de cada una de las operaciones
// con los números que desee e imprima el resultado utilizando el método “toString”.

//interfaz
class numero {
public:
    //implementacion de las operaciones con metodo virtual puro
    virtual numero* suma(numero* n) = 0;
    virtual numero* resta(numero* n) = 0;
    virtual numero* multiplicacion(numero* n) = 0;
    virtual numero* division(numero* n) = 0;
    virtual std::string tostring() = 0;
    virtual ~numero() {};
};

class entero: public numero {
private:
    int valor; ///inicializamos 1 entero

public:
    entero(int v) : valor(v) {}//constructor

    //usamos dynamicast para asegurarnos de que el puntero apunta a un entero
    numero* suma(numero* n) override {
        entero* otro = dynamic_cast<entero*>(n);
        if (otro){
            return new entero(valor + otro->valor);
        } 
        return nullptr;//por si fallo
    }
    numero* resta(numero* n) override {
        entero* otro = dynamic_cast<entero*>(n);
        if (otro){
            return new entero(valor - otro->valor);
        } 
        return nullptr;
    }
    numero* multiplicacion(numero* n) override {
        entero* otro = dynamic_cast<entero*>(n);
        if (otro){
            return new entero(valor * otro->valor);
        } 
        return nullptr;
    }
    numero* division(numero* n) override {
        entero* otro = dynamic_cast<entero*>(n);
        if (otro && otro->valor != 0){
            return new entero(valor / otro->valor);
        } 
        return nullptr; //evitar dividir por 0
    }

    std::string tostring() override {
        return std::to_string(valor);
    }

    ~entero() override {}
};

class real : public numero {
private:
    float valor;//inicializamos 1 real

public:
    real(float v) : valor(v) {}

    numero* suma(numero* n) override {
        real* otro = dynamic_cast<real*>(n); //usamos dinamic ccast para q apunte a un real
        if (otro){
            return new real(valor + otro->valor);
        }    
        return nullptr;
    }
    numero* resta(numero* n) override {
        real* otro = dynamic_cast<real*>(n);
        if (otro){
            return new real(valor - otro->valor);
        } 
        return nullptr;
    }
    numero* multiplicacion(numero* n) override {
        real* otro = dynamic_cast<real*>(n);
        if (otro){
             return new real(valor * otro->valor);
        }
        return nullptr;
    }
    numero* division(numero* n) override {
        real* otro = dynamic_cast<real*>(n);
        if (otro && otro->valor != 0){
            return new real(valor / otro->valor);
        } 
        return nullptr;//evitar dividir por 0
    }
    std::string tostring() override {
        return std::to_string(valor);
    }
    ~real() override{}
};


class complejo : public numero {
private:
    std::complex<float> valor;
public:
    complejo(float r, float i) : valor(r, i) {}

    numero* suma(numero* n) override {
        complejo* otro = dynamic_cast<complejo*>(n);
        if (otro){
            return new complejo(valor.real() + otro->valor.real(), valor.imag() + otro->valor.imag());
        } 
        return nullptr;// complex sabe separar .real() y .imag()
    }
    numero* resta(numero* n) override {
        complejo* otro = dynamic_cast<complejo*>(n);
        if (otro){
            return new complejo(valor.real() - otro->valor.real(), valor.imag() - otro->valor.imag());
        } 
        return nullptr; //restamos parte real y parte imaginaria
    }
    numero* multiplicacion(numero* n) override {
        complejo* otro = dynamic_cast<complejo*>(n);
        if (otro) {
            std::complex<float> res = valor * otro->valor; //multiplicamos
            return new complejo(res.real(), res.imag());
        }
        return nullptr;
    }
    numero* division(numero* n) override {
        complejo* otro = dynamic_cast<complejo*>(n); 
        if (otro && ((otro->valor) != std::complex<float>(0,0))) { //nos aseguramos que el valor sea distinto de 0 para poder dividir 
            std::complex<float> res = valor / otro->valor;//dividimos
            return new complejo(res.real(), res.imag());
        }
        return nullptr;
    }
    // imprimir en formato "a+bi" o "a -bi"
    std::string tostring() override {
        std::ostringstream ss;
        ss << valor.real();
        if (valor.imag() >= 0){
            ss << " + " << valor.imag() << "i";
        } 
        else{
            ss << " - " << -valor.imag() << "i";
        } 
        return ss.str();
    }

    ~complejo() override {}
};
