#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include "homework2ejercicio1.h"
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

// inicializmaos el constructor
tiempo::tiempo() : horas(0), minutos(0), segundos(0), periodo("a.m.") {} // 1 a

tiempo::tiempo(int h) : tiempo() { // 1 b
    if (validahora(h)) horas = h;
}

tiempo::tiempo(int h, int m) : tiempo(h) { // 1 c
    if (validamin(m)) minutos = m;
}

tiempo::tiempo(int h, int m, int s) : tiempo(h, m) { // 1d 
    if (validasegs(s)) segundos = s;
}

tiempo::tiempo(int h, int m, int s, std::string p) : tiempo(h, m, s) { // 1 e
    if (validaperiodo(p)) periodo = p;
}

tiempo::~tiempo() {} // destructor

void tiempo::modifica(){ 
    int sino;
    int comando = -1; // inicializamos
    std::cout << "queres leer o modificar algo? (si=1/no=0) ";
    std::cin >> sino;
    while (comando!= 0){ // puede cambiar y leer las veces uqe quiera hasta que decida salir (0)
        if(sino==1){
            std::cout << "Que queres hacer?:\n";
            std::cout << "1. modificar hora\n";
            std::cout << "2. modificar minutos\n";
            std::cout << "3. modificar segundos\n";
            std::cout << "4. modificar a.m./p.m.\n";
            std::cout << "5. ver la hora\n";
            std::cout << "6. ver los minutos\n";
            std::cout << "7. ver los segundos\n";
            std::cout << "8. ver a.m./p.m.\n";
            std::cout << "9. ver todo en formato 12hrs\n";
            std::cout << "10. ver todo en formato 24hrs\n";
            std::cout << "0. salir\n";
            std::cout << "Ingrese opción(el numero): ";
            std::cin >> comando;
            if(comando==1){
                int h;
                std::cout << "ingrese hora: ";
                std::cin >> h;
                if (validahora(h)) { // si no es valido no se va a poder cambiar
                    horas = h;
                } else {
                    std::cout << "intente nuevamente.\n";
                }
            }
            else if(comando==2){
                int m;
                std::cout << "ingrese minutos: ";
                std::cin >> m;
                if(validamin(m)){
                    minutos = m;
                }
                else {
                    std::cout << "intente nuevamente.\n";
                }
            }
            else if(comando==3){
                int s;
                std::cout << "ingrese segundos: ";
                std::cin >> s;
                if (validasegs(s)){
                    segundos = s;
                }
                else {
                    std::cout << "intente nuevamente.\n";
                }
            }
            else if(comando==4){
                std::string p;
                std::cout << "ingrese periodo(a.m./p.m.): ";
                std::cin >> p;
                if(validaperiodo(p)){
                    periodo = p;
                }
                else {
                    std::cout << "intente nuevamente.\n";
                }
            }
            else if(comando == 5){ // leer (5-8)
                std::cout << "Hora: " << horas << "\n";
            }
            else if(comando == 6){
                std::cout << "Minutos: " << minutos << "\n";
            }
            else if(comando == 7){
                std::cout << "Segundos: " << segundos << "\n";
            }
            else if(comando == 8){
                std::cout << "Periodo: " << periodo << "\n";
            }
            else if(comando==9){ // no hace falta usar gethoras() xq esta funcion esta adentro de la clase, sabe acceder direectament con horas
                std::cout << std::setfill('0') << std::setw(2) << horas << ":" << std::setw(2) << minutos << ":" << std::setw(2) << segundos << std::setw(4) << periodo; 
            } 
            else if(comando ==10){
                modifica24(); // llamamos a la funcion
            }
            else if(comando==0){
                return;
            }
            else{
                std::cout << "opcion invalida";
            }
        }
    }
    return;
}

// setw pone un ancho de tamano n con espacios
// setfill rellena con x caracter
void tiempo::modifica24(){
    if(periodo == "a.m."){
        if(horas == 12){ // caso de 12am, que pasa a ser 00.00 (medianoche)
            std::cout << std::setfill('0') << std::setw(2) << 0 << ":" << std::setw(2) << minutos << ":" << std::setw(2) << segundos << " hs\n";
        }
        else{
            std::cout << std::setfill('0') << std::setw(2) << horas << ":" << std::setw(2) << minutos << ":" << std::setw(2) << segundos << " hs\n";
        }
    }
    else if(periodo == "p.m."){
        if(horas == 12){ // caso de 12pm, que sigue siendo 12 (del mediodia)
            std::cout << std::setfill('0') << std::setw(2) << horas << ":" << std::setw(2) << minutos << ":" << std::setw(2) << segundos << " hs\n";
        }
        else{
            std::cout << std::setfill('0') << std::setw(2) << horas + 12 << ":"  << std::setw(2) << minutos << ":"  << std::setw(2) << segundos << " hs\n";
        }
    }
}

// i. Escriba un código que permita verificar cada una de las funcionalidades pedidas en 1.a-1.g. Para la verificación se deberá pedir que se interactúe con el
// programa ingresando los datos por teclado. Por ejemplo, en el caso de ingresar un valor erróneo, indicar esto por pantalla y permitir ingresar un nuevo valor o
// bien permitir salir del programa
int main(){
    int h,m,s;
    std::string p;
    tiempo t; // objeto tiempo
    // 1 a
    t = tiempo(); //constructor
    std::cout << "tiempo sin inicializar: " << "Hora: " << t.gethora() << " minutos: " << t.getmin() << " segundos: " << t.getsegs() << " periodo: " << t.getperiodo() << std::endl;

    // 1 b
    std::cout << "ingrese hora ";
    std::cin >> h;
    while(!t.validahora(h)){ // 1 f
        std::cout << "hora invalida. volver a ingresar o presionar -1 para salir del programa ";
        std::cin >> h;
        if(h==-1){
            return 0;
        }
    }
    t = tiempo(h);
    std::cout << "inicializacion con hora " << h << "\n";
    std::cout << std::setfill('0') << std::setw(2) << t.gethora() << ":" << std::setw(2) << t.getmin() << ":" << std::setw(2) << t.getsegs() << std::setw(4) << t.getperiodo() << std::endl;

    // 1 c 
    std::cout << "ingrese minutos ";
    std::cin >> m;
    while(!t.validamin(m)){// 1 f
        std::cout << "minutos invalidos. volver a ingresar o presionar -1 para salir ";
        std::cin >> m;
        if(m==-1){
            return 0;
        }
    }
    t = tiempo(h,m);
    std::cout << "inicializacion con minutos " << m << "\n";
    std::cout << std::setfill('0') << std::setw(2) << t.gethora() << ":" << std::setw(2) << t.getmin() << ":" << std::setw(2) << t.getsegs() << std::setw(4) << t.getperiodo() << std::endl;
    
    // 1 d 
    std::cout << "ingrese segundos ";
    std::cin >> s;
    while(!t.validasegs(s)){
        std::cout << "segundos invalidos. volver a ingresar o presionar -1 para salir ";
        std::cin >> s;
        if(s==-1){
            return 0;
        }
    }
    t = tiempo(h,m,s);
    std::cout << "inicializacion con segundos " << s << "\n";
    std::cout << std::setfill('0') << std::setw(2) << t.gethora() << ":" << std::setw(2) << t.getmin() << ":" << std::setw(2) << t.getsegs() << std::setw(4) << t.getperiodo() << std::endl;
    
    // 1 e 
    std::cout << "ingrese periodo(a.m./p.m.) ";
    std::cin >> p;
    while(!t.validaperiodo(p)){
        std::cout << "periodo invalido. volver a ingresar o presionar s para salir ";
        std::cin >> p;
        if(p == "s"){
            return 0;
        }
    }
    t = tiempo(h,m,s,p);
    std::cout << "inicializacion con periodo " << p << "\n";
    std::cout << std::setfill('0') << std::setw(2) << t.gethora() << ":" << std::setw(2) << t.getmin() << ":" << std::setw(2) << t.getsegs() << std::setw(4) << t.getperiodo() << std::endl;
    
    // 1 g
    t.modifica(); // etsa ya llama a modifica24 si se pide

    return 0;
}




