// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Recursion NO FINAL.

// función que resuelve el problema
pair<int, int> resolver(int num) {
    pair <int, int> ret = { 0,0 };
    if (num < 10) 
        return {num,10};
    else {
        ret = resolver(num/10);
        ret.first = num % 10 * ret.second + ret.first;
    }
    return {ret.first, ret.second * 10};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num == 0)
        return false;

    pair<int, int> sol = resolver(num);

    // escribir sol
    cout << sol.first << "\n";
    return true;

}

int main() {
    /*
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif 
    */

    while (resuelveCaso());

    /*
    // Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    */
    return 0;
}
