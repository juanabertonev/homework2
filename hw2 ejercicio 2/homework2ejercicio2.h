#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// 2. Escribir una clase denominada Curso que contiene un vector (std::vector) con punteros a objetos estudiantes. 

// a. El objeto estudiante simplemente cuenta con el nombre completo, su legajo (que es único por alumno), una lista de cursos con su nota final y los métodos
// que crea necesarios para obtener los datos del alumno: nombre completo, legajo y su promedio general. En función de esto, califique todos los atributos
// correctamente.
// b. Como se mencionó anteriormente, un objeto de la clase Curso contendrá la lista de estudiantes del curso (el vector conteniendo objetos tipo estudiante). La
// clase Curso permite:
//         i. Inscribir y desinscribir estudiantes al curso.
//         ii. Ver si un estudiante se encuentra inscripto o no en el curso buscándolo por su legajo.
//         iii. Indicar si el curso está completo o no, teniendo en cuenta que el curso tiene una capacidad de 20 alumnos.
//         iv. Imprimir la lista de estudiantes en orden alfabético. Para ello, utilice el algoritmo std::sort() en <algorithm>, el cual requerirá sobreescribir el
//         operador “<”, y sobreescriba el operador “<<” (del método y clase que correspondan) para presentar los datos por pantalla.
//         v. Dado que algunos cursos comparten la mayor parte de los estudiantes, se desea poder hacer una copia del objeto curso. Justifique su respuesta con
//         un comentario en el código (esta puede llevar varias líneas), indicando de que tipo de copia se trata y como la hizo.
// c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
// d. Proporcione un menú que permita evaluar lo pedido en este ejercicio. 
class estudiante
{
private:
    std::string nombrecompleto;
    int legajo;
    std::vector<std::pair<std::string, float>> cursos; // (curso, notafinal)
    // cursos = { {"Matemática", 8.5}, {"Historia", 7.0}, {"Física", 9.2} }; como un dict

public:
    //constructor
    estudiante(std::string n, int l, std::vector<std::pair<std::string, float>> c);

    std::string getnombre()const{ return nombrecompleto;}
    int getlegajo()const{return legajo;}
    float getpromedio() const; // definido en cpp

    bool operator<(const estudiante& otro) const {return nombrecompleto < otro.nombrecompleto;}//iv 

    ~estudiante(){};
};

class curso
{
private:
    std::vector<estudiante*> estudiantes;
    static const int capacidadmaxima=20;

public:
    curso(std::vector<estudiante*> e): estudiantes(e){};
    curso(const curso& otro) : estudiantes(otro.estudiantes){}; //shallow copy
    //copia el vector de punteros, no los objetos a los que apuntan
    //los cursos pueden compartir estudiantes!!
    //la deep copy duplicaria objetos (estudiantes) y no queremos eso
    void inscribir(estudiante* e);
    void desinscribir(int legajo);
    bool estainscripto(int legajo);
    bool estacompleto();
    void imprimelista();

    ~curso(){};
};

