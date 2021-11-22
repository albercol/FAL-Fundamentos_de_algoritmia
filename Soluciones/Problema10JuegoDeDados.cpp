// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void resolver(vector<int> const &v, vector<int> &aux) {
	for (int i = 0; i < v.size(); ++i) {
		++aux[v[i]];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDatos, numCaras;

	cin >> numDatos;

	if (numDatos == -1)
		return false;
	else {
		cin >> numCaras;
		vector<int> v(numDatos);
		vector<int> aux(numCaras+1);

		for (int &i : v)
			cin >> i;

		resolver(v, aux);

		// escribir sol
		int max = 0;
		vector<int> sol;
		for (int s = 0; s < aux.size(); ++s) {
			if (max < aux[s]) {
				max = aux[s];
				sol.clear();
				sol.push_back(s);
			}
			else if (max == aux[s] && aux[s] != 0){
				sol.push_back(s);
			}
		}

		if (sol.size() > 0) cout << sol[sol.size()-1];
		for (int j = sol.size()-2; j >= 0; --j)
			cout << " " << sol[j];
		cout << "\n";

		return true;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
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
