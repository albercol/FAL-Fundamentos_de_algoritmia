// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
vector<int> resolver(vector<int> const &v1, vector<int> const &v2) {
	vector<int> sol;
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] == v2[j]) {
			sol.push_back(v1[i]);
			++i;
			++j;
		}
		else if (v1[i] > v2[j])
			++j;
		else
			++i;
	}

	return sol;
}

void leeVector(vector<int> &v) {
	int dato;
	cin >> dato;
	while (dato != 0) {
		v.push_back(dato);
		cin >> dato;
	}
	sort(v.begin(), v.end());
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	vector<int> v1, v2;
	
	leeVector(v1);
	leeVector(v2);
	
	vector<int> sol = resolver(v1, v2);
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