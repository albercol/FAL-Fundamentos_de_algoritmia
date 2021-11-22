// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//Recursividad No Final.
int sumaDigitos(int n) {
	int sumaNum = 0;
	if (n == 0) return 0;
	sumaNum = n % 10;
	sumaNum += sumaDigitos(n/10);

	return sumaNum;
}

// función que resuelve el problema
vector<long long int> resolver(vector<long long int> const &v, int digitoDado) {
    vector<long long int> res;
    int resDigitosVector;
    int sumaDigitoDado = sumaDigitos(digitoDado);
    for (int i = 0; i < v.size(); ++i) {
        int resDigitosVector = sumaDigitos(v[i]);
        if (resDigitosVector == sumaDigitoDado)
            res.push_back(v[i]);
    }

    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numDatos, digitoDado;
    cin >> numDatos >> digitoDado;
    vector<long long int>v(numDatos);
    for (long long int& i : v)
        cin >> i;

    vector<long long int> sol = resolver(v, digitoDado);
    // escribir sol
    if (sol.size() != 0) cout << sol[0];
    for (int i = 1; i < sol.size(); ++i)
        cout << " " << sol[i];
    cout << "\n";
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

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    /*
    // Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    */

    return 0;
}