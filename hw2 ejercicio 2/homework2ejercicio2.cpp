#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "homework2ejercicio2.h"
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

//constructor
estudiante::estudiante(std::string n, int l, std::vector<std::pair<std::string, float>> c): nombrecompleto(n), legajo(l), cursos(c) {} 

float estudiante::getpromedio() const {
    if (cursos.empty()){
        return 0; // evitar división por cero
    } 
    float suma = 0;
    for (const std::pair<std::string, float>& curso : cursos) {
        suma += curso.second; //.first agarra el curso, .second la nota
    }
    return suma / cursos.size(); // promedio
}

void curso::inscribir(estudiante* e){
    if(estacompleto()==true){
        std::cout<< "el curso esta completo, no se puede inscribir" << std::endl;
    }
    else{
        estudiantes.push_back(e);
    }
}

void curso::desinscribir(int legajo){
    for (auto e = estudiantes.begin(); e != estudiantes.end(); ++e) {
        if ((*e)->getlegajo() == legajo) {
            estudiantes.erase(e);
            return;
        }
    }
}

bool curso::estainscripto(int legajo){
    for(estudiante* e : estudiantes){
        if(e->getlegajo()==legajo){
            return true;
        }
    }
    return false;
}

bool curso::estacompleto(){
    if(estudiantes.size()== capacidadmaxima){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const estudiante& e) {
    os << "nombre: " << e.getnombre();
    return os;
}
void curso::imprimelista(){
    std::sort(estudiantes.begin(), estudiantes.end(),[](estudiante* a, estudiante* b) {
            return *a < *b;  // comparamos por nombre
        });

    for(estudiante* e : estudiantes){
        std::cout << *e << "\n";  // usamos el operador <<
    }
}



// c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?

//los objetos curso apuntan a una lista de punteros a estudiante pero no son dueños de estos (no los destruyen ni hacen deep copy), permitiendo compartir estudiantes entre distintos cursos



//d. Proporcione un menú que permita evaluar lo pedido en este ejercicio. 
int main(){
    estudiante* e1 = new estudiante("juana", 1234, {{"Matemática", 8.5}, {"Historia", 7.0}, {"Física", 9.2}});
    estudiante* e2 = new estudiante("jose", 5678, {{"Matemática", 4}, {"Historia", 9.8}, {"Física", 3}});

    std::vector<estudiante*> listae = {e1,e2};
    curso c(listae);
    
    estudiante* e3 = new estudiante("clara", 6789,{{"Matemática", 4}, {"Historia", 9.8}, {"Física", 3}} );

    std::cout << "lista inicial \n";
    c.imprimelista();

    std::cout << "inscribimos a " << e3->getnombre() << "\n";
    c.inscribir(e3);

    std::cout << "lista: \n";
    c.imprimelista();

    std::cout << "promedio de " << e1->getnombre() << ": " << e1->getpromedio()<< "\n";

    std::string nombreE1 = e1->getnombre();
    std::cout << "desinscribimos a " << e1->getnombre() << "\n";
    c.desinscribir(e1->getlegajo());

    std::cout<<nombreE1 << " esta inscripto? \n";
    if (c.estainscripto(e1->getlegajo())) {
        std::cout << "si\n";
    } else {
        std::cout << "no\n";
    }
    std::cout<< e2->getnombre() << " esta inscripto? \n";
    if (c.estainscripto(e2->getlegajo())) {
        std::cout << "si\n";
    } else {
        std::cout << "no\n";
    }
    std::cout << "el curso esta completo? \n";
    if (c.estacompleto()) {
        std::cout << "si\n";
    } else {
        std::cout << "no\n";
    }


    //  MENU INTERACTIVO

    int res=-1;
    while(res!=0){
        std::cout << "que queres hacer?? \n";
        std::cout << "1. Ver el promedio de un estudiante\n";
        std::cout << "2. Inscribir un estudiante\n";
        std::cout << "3. Desinscribir un estudiante\n";
        std::cout << "4. Ver si un estudiante esta inscripto\n";
        std::cout << "5. Ver si el curso esta completo\n";
        std::cout << "6. Imprimir la lista del curso\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> res;

        if(res==1){
            std::string estnom;
            std::cout << "ingrese el nombre del estudiante ";
            std::cin >> estnom;
            bool encontrado = false;
            for (estudiante* e : listae) {
                if(e->getnombre()==estnom){
                    std::cout << "el promedio de " << estnom << " es " << e->getpromedio() << "\n";
                    encontrado = true;
                }
            }
            if(encontrado==false){
                std::cout << "error, el estudiante no esta en el curso \n";
            }
        }
        else if (res == 2) {
            std::string nombre;
            int legajo, cantidad;
            std::vector<std::pair<std::string, float>> notas;

            std::cout << "Nombre del estudiante: ";
            std::cin >> nombre;
            std::cout << "Legajo: ";
            std::cin >> legajo;
            std::cout << "Cantidad de materias: ";
            std::cin >> cantidad;

            for (int i = 0; i < cantidad; i++) {
                std::string materia;
                float nota;
                std::cout << "Nombre de la materia " << (i+1) << ": ";
                std::cin.ignore();
                std::getline(std::cin, materia);
                std::cout << "Nota final en " << materia << ": ";
                std::cin >> nota;
                notas.push_back(std::make_pair(materia, nota));
            }
            estudiante* nuevo = new estudiante(nombre, legajo, notas);
            c.inscribir(nuevo);
            listae.push_back(nuevo);
            std::cout << "Estudiante inscripto con éxito.\n";
        }

        else if(res==3){
            std::string estnom3;
            std::cout << "ingrese el nombre del estudiante ";
            std::cin >> estnom3;
            bool encontrado = false;
            for (auto ee = listae.begin(); ee != listae.end(); ++ee) {
                if ((*ee)->getnombre() == estnom3) {
                    c.desinscribir((*ee)->getlegajo());
                    delete *ee;            
                    listae.erase(ee);      
                    encontrado = true;
                    std::cout << "Estudiante desinscripto y eliminado correctamente.\n";
                    break;
                }
            }
            if(encontrado==false){
                std::cout << "el estudiante no esta en el curso, ya esta desinscripto \n";
            }
        }
        else if(res==4){
            std::string estnom4;
            std::cout << "ingrese el nombre del estdudiante ";
            std::cin >> estnom4;
            bool encontrado = false;
            for (estudiante* e : listae) {
                if(e->getnombre()==estnom4){
                    std::cout << "el estudiante esta inscripto \n";
                    encontrado = true;
                    break;
                }
            }
            if(encontrado==false){
                std::cout << "el estudiante no esta inscripto \n";
            }
        }

        else if(res == 5){
            if(c.estacompleto()){
                std::cout << "el curso esta completo \n";
            }
            else{
                std::cout << "el curso no esta completo \n";
            }
        }

        else if(res==6){
            c.imprimelista();

        }
        else if(res==0){
            for (estudiante* e : listae) {
                delete e;
            }// liberar memoria
            listae.clear();
            return 0;
        }

    }

}