// Nombre del alumno .....
// Usuario del Juez ......


// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
//Coste de la función es lineal respecto al tamaño del vector O(n) siendo n el tamañod el vector.
int resolver(vector<long long int> &v, int valError) {
	int valCorrect = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] != valError) {
			v[valCorrect] = v[i];
			++valCorrect;
		}
	}
	v.resize(valCorrect);
	return v.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int maxElem, valError;
	cin >> maxElem >> valError;

	vector<long long int> v(maxElem);
	for (long long int &i : v) 
		cin >> i;

	int sol = resolver(v, valError);
	
	// escribir sol
	cout << sol << "\n";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
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