// Nombre del alumno Alberto Collado MAmblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema
pair<int, int> resolver(vector <pair<char, int>> &v) {
	int p = 0; int q = int(v.size())-1; int k = 0;
	while (k <= q){
		if (v[k].first == 'a') {
			swap(v[k], v[p]);
			++k; ++p;
		}
		else if (v[k].first == 'r') {
			swap(v[k], v[q]);
			--q;
		}
		else if (v[k].first == 'v') {
			++k;
		}
	}
	
	return { p, q };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDat;
	cin >> numDat;
	if (!std::cin)
		return false;

	vector <pair<char, int>> v(numDat);
	for (int i = 0; i < v.size(); ++i) 
		cin >> v[i].first >> v[i].second;

	pair<int, int> verdes = resolver(v);

	// escribir sol
	sort(v.begin(), v.begin() + verdes.first);
	cout << "Azules:";
	for (int i = 0; i < verdes.first; ++i) {
		cout << " " << v[i].second;
	}
	cout << "\n";

	sort(v.begin()+verdes.first, v.begin()+1+verdes.second);
	cout << "Verdes:";
	for (int i = verdes.first; i <= verdes.second; ++i) {
		cout << " " << v[i].second;
	}
	cout << "\n";

	sort(v.begin()+1+verdes.second, v.end());
	cout << "Rojas:";
	for (int i = verdes.second+1; i < v.size(); ++i) {
		cout << " " << v[i].second;
	}
	cout << "\n";
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