#include <ostream>
#include <iostream>
#include <iomanip>
//1. Programe una clase que permita expresar un determinado momento en el tiempo en el siguiente formato: HHh, MMm, SSs p.m./a.m. Por ejemplo: “03h, 14m, 42s p.m.”.
// Para este ejercicio, puede utilizar la librería iomanip con la funcionalidad provista por setw y/o setfill.
// Deberá ser capaz de:
//     a. Poder ser inicializada sin parámetros (en cuyo caso el tiempo es 0h, 0m, 0s a.m.)
//     b. Poder ser inicializada pasándole sólo la hora (en cuyo caso el tiempo es “HHh, 0m, 0s a.m.”).
//     c. Poder ser inicializada pasándole sólo la hora y los minutos (en cuyo caso el tiempo es “HHh, MMm, 0s a.m.”)
//     d. Poder ser inicializada pasándole sólo la hora, los minutos y los segundos (en cuyo caso el tiempo es “HHh, MMm, SSs a.m.”)
//     e. Poder ser inicializada pasándole la hora, los minutos, los segundos y “p.m.”/”a.m.” (en cuyo caso el tiempo es “HHh, MMm, SSs p.m./a.m.”).
//     f. Agregar funcionalidad a los puntos 1.b-1.e de manera tal que no se introduzcan valores fuera de los rangos (por ejemplo, es incorrecto introducir MM = 74).
//     g. Permitir cambiar y leer en forma individual: la hora, los minutos, los segundos y si se trata de a.m. o p.m. También leer todo junto en el formato pedido.
//     h. Escribir un método que escriba por pantalla la hora en formato de hora 0 a 24, donde no se utiliza “p.m.”/”a.m.”, por ejemplo, 13hs p.m. no es válido.
//     i. Escriba un código que permita verificar cada una de las funcionalidades pedidas en 1.a-1.g. Para la verificación se deberá pedir que se interactúe con el
// programa ingresando los datos por teclado. Por ejemplo, en el caso de ingresar un valor erróneo, indicar esto por pantalla y permitir ingresar un nuevo valor o
// bien permitir salir del program

class tiempo
{
private:
    int horas;
    int minutos;
    int segundos;
    std::string periodo;
    // no accesibles desde fuera de la clase
public:
    //constructores
    tiempo(); // 1 a
    tiempo(int h); // 1 b
    tiempo(int h , int m); // 1 c
    tiempo(int h, int m, int s); // 1 d
    tiempo(int h, int m, int s, std::string p); // 1 e

    //validadores 1f
    bool validahora(int h) { return h >= 1 && h <= 12; } // 1 f
    bool validamin(int m) { return m >= 0 && m < 60; }
    bool validasegs(int s) { return s >= 0 && s < 60; }
    bool validaperiodo(std::string p){return p == "a.m." || p == "p.m.";}

    // para conseguir los valores desde fuera de la clase (ej main)
    int gethora(){return horas;}
    int getmin(){return minutos;}
    int getsegs(){return segundos;}
    std::string getperiodo(){return periodo;} // para acceder desde el main

    void modifica(); // 1 g
    void modifica24(); // 1 h 

    // destructores
     ~tiempo();
};

