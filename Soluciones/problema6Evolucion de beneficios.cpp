// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
// O(n) siendo n la suma de todos los componentes de v1.
void resolver(vector<int> const & v1, vector<int> & sol, int anyoIni) {
	int maxVentas = v1[0];

	for (int i = 1; i < v1.size(); ++i) {
		if (maxVentas < v1[i]) {
			sol.push_back(anyoIni+i);
			maxVentas = v1[i];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int anyoIni, anyoFin;
	cin >> anyoIni >> anyoFin;

	vector<int> v1((anyoFin - anyoIni)+1);
	vector<int> sol;

	for (int &i : v1)
		cin >> i;

	resolver(v1, sol,anyoIni);
	// escribir sol
	for (int s = 0; s < sol.size(); ++s) {
		if (s != 0) //imprime los espacios entre numeros.
			cout << " ";
		cout << sol[s];
	}
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
	cin >> numCasos;
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