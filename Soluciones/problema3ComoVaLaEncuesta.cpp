// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
pair<long long, int> resolver(vector<int> const & datos, int numDatos) {
	long long sumElem;
	int minElem, numMinElem, totales;
	sumElem = 0;
	numMinElem = 0;
	minElem = datos[0];
	for (int i = 0; i < datos.size(); ++i) {
		sumElem += datos[i];
		if (minElem > datos[i]) {
			minElem = datos[i];
			numMinElem = 1;
		}else if (minElem == datos[i])
			++numMinElem;
	}
	
	sumElem -= (minElem * numMinElem);
	totales = numDatos - numMinElem;

	return { sumElem, totales };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numDatos, elem;
	cin >> numDatos;
	vector<int> datos(numDatos);

	for (int& i : datos)
		cin >> i;


	pair<long long, int> sol = resolver(datos, numDatos);
	// escribir sol
	cout << sol.first << " " << sol.second << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
	#ifndef DOMJUDGE
	 ifstream in("datos.txt");
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
	 cin.rdbuf(cinbuf);
	 system("PAUSE");
	 #endif
	*/
	return 0;
}

