#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const &datos, int p) {
	bool sol;
	int maximoIzq = datos[0];
	int i;
	for (i = 1; i <= p; ++i) {
		if (maximoIzq < datos[i])
			maximoIzq = datos[i];
	}
	
	while (i < datos.size() && maximoIzq < datos[i])
			++i;
	
	return i == datos.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int maxElems, p;
	cin >> maxElems >> p;
	vector<int> datos(maxElems);

	for (int &i : datos) {
		cin >> i;
	}

	bool sol = resolver(datos, p);

	sol ? cout << "SI" << "\n" : cout << "NO" << "\n";
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
