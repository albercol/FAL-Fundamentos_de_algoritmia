#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


int buscaIzq(vector<int> const& v, int ini, int fin, int altura) {
    if (ini >= fin || ini+1 == fin) //Caso dev 0 o 1
        return ini;
    else {
        int m = (ini + fin - 1) / 2;
        /*
        Primero mira si el valor en el vector es menor que la altura porque 
        en el caso de ser igual, mirará a la izquierda
        */
        if (v[m] < altura) return buscaIzq(v, m+1, fin, altura);
        else return buscaIzq(v, ini, m+1, altura);
    }
}

/*Ojo hay que incluir el elemento del medio para que lo tenga en cuenta (m) NO OMITIRLO*/
int buscaDer(vector<int> const& v, int ini, int fin, int altura) {
    if (ini >= fin || ini+1 == fin) //Caso dev 0 o 1
        return ini;
    else {
        int m = (ini + fin)/2;
        /*
        Primero mira si el valor en el vector es mayor que la altura porque 
        en el caso de ser igual, mirará a la derecha.
        */
        if (v[m] > altura) return buscaDer(v, ini, m, altura);
        else return buscaDer(v, m, fin, altura);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numSospechosos, altura;
    cin >> numSospechosos >> altura;
    if (!std::cin)
        return false;
    vector<int> v(numSospechosos);
    for (int& i : v)
        cin >> i;

    int posIzq = buscaIzq(v, 0, int(v.size()), altura);
    /*
    Si en la izquierda no esta habra mirado en la derecha y 
    si no existe el elemento dará el último elemento.
    */
    if (posIzq == v.size() || v[posIzq] != altura) {
        cout << "NO EXISTE" << "\n";
    }
    else {
        int posDer = buscaDer(v, 0, int(v.size()), altura);
        if (posIzq == posDer) cout << posIzq << "\n";
        else cout << posIzq << " " << posDer << "\n";
    }

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
