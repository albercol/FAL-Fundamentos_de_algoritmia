#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int tiempo) {
	int ret = 0;
	int sumMax = 0;
	int sumTot = 0;
	pair<int, int> maxPun = { 0,0 }; //valor, posicion
	for (int i = 0; i < tiempo; ++i) {
		sumTot += v[i];
		if (v[i] >= maxPun.first) {
			maxPun.first = v[i];
			maxPun.second = i;
		}
	}

	int a = 0;
	int b = tiempo - 1;
	ret = a;
	sumMax = sumTot;
	++b;
	while (b < v.size()) {
		sumTot -= v[a];
		sumTot += v[b];
		if (v[b] >= maxPun.first) {
			if (sumTot >= sumMax) {
				sumMax = sumTot;
				ret = a+1;
			}
			else if (v[b] > maxPun.first) {
				sumMax = sumTot;
				ret = a + 1;
			}
				
			maxPun.first = v[b];
			maxPun.second = b;
			
		}
		else if(sumTot >= sumMax && maxPun.second > a) {
			sumMax = sumTot;
			ret = a+1;
		}

		++b; ++a;
	}

	return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPag, tiempo;
	cin >> numPag >> tiempo;
	if (numPag == 0 && tiempo == 0)
		return false;

	vector<int> v(numPag);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, tiempo);

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
