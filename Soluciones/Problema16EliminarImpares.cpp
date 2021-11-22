// Nombre y apellidos del alumno: Alberto Collado Mamblona
// Usuario del juez de clase: A17
// Usuario de la prueba de hoy: A09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Explicación del algoritmo utilizado
/*
Se define una variable que apunta al inicio del vector y 
va poniendo los datos validos al principio de este.
Avanza cuando el dato es valido y si no, se queda donde esta.
Posteriormente se le asigna el tamaño del vector a dicha variable, que será el número de datos validos.
*/


// Explicación del coste del algoritmo implementado
/*
El Coste del algoritmo es lineal en el numero de datos de entrada, mas concretamente en el tamaño del vector.
Se tiene que recorrer el vector entero.
O(n)

*/


// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int>& v) {
    // Codigo del alumno
    int pares = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2 == 0) {
            v[pares] = v[i];
            ++pares;
        }
    }
    v.resize(pares);
}

// A PARTIR DE AQUI NO SE DEBE MODIFICAR NADA

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
    #ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif

    return 0;
}

