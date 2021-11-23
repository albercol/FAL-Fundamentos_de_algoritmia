#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema

void resolver(vector<int> const &v, vector<long long int> & sumAcu) {
	sumAcu[0] = 0;
	for (int i = 1; i <= v.size(); ++i) {
		sumAcu[i] = sumAcu[i-1] + v[i-1];
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int ini, fin;
	cin >> ini >> fin;
	if (ini == 0 && fin == 0)
		return false;

	else {
		
		vector<int> v((fin-ini)+1);
		int datos;
		for (int &i: v) {
			cin >> i;
		}

		vector<long long int> sumAcu(v.size()+1);
		resolver(v, sumAcu);

		int numPreg;
		cin >> numPreg;
		for (int i = 0; i < numPreg; ++i) {
			int aIni, aFin;
			cin >> aIni >> aFin;
			cout << sumAcu[(aFin-ini)+1] - sumAcu[aIni-ini] << "\n";
		}
		cout << "---" << "\n";

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
