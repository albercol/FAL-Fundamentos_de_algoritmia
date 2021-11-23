#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &v) { //dev int ret
	sort(v.begin(), v.end());

	int ret = v[0];
	long long int maxRep = 1;
	long long int repeticiones = 1;
	for (long long int i = 1; i < v.size(); ++i) {
		if (v[i - 1] == v[i])
			++repeticiones;
		else
			repeticiones = 1;

		if (maxRep < repeticiones) {
			maxRep = repeticiones;
			ret = v[i];
		}
	}

	return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long long int numDatos;
	cin >> numDatos;
	
	if (numDatos == -1)
		return false;

	vector <int> v(numDatos);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v);

	// escribir sol
	cout << sol << "\n";

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
