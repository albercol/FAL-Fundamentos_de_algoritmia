// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> const &v, vector<int> &sol, int pista) {
	int contadorPista = 1, primElem = 0; 
	int a = 0; int b = 1;
	while (b < v.size()) {

		if (abs(v[a] - v[b]) == 1 || abs(v[a] - v[b]) == 0) {
			++b; ++a; ++contadorPista;
		}
		else if (contadorPista >= pista) {
			sol.push_back(primElem);
			contadorPista = 1;
			primElem = b;
			a = b;
			++b;
		}
		else {
			primElem = b;
			contadorPista = 1;
			++b; ++a;
		}

		if (b == v.size() && contadorPista >= pista) {
			sol.push_back(primElem);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nDatos, pista;
	cin >> nDatos >> pista;
	if (nDatos == 0 && pista == 0)
		return false;

	vector<int> v(nDatos);
	vector<int> sol;
	for (int &i : v)
		cin >> i;

	resolver(v, sol ,pista);

	// escribir sol
	cout << sol.size();
	for (int i = 0; i < sol.size(); ++i) {
		cout << " " << sol[i];
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
