#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
T(n) = ini ini>=fin, C1 + T(n/2) ini<fin
	C1 + C1 + T(n/2^2); C1 + C1 + C1 + T(n/2^3) -----> K*C1 + T(n/2^k)
	n/2^k = 1; log n = k ----------------------------> C1*log (n) + T(1)

				Por lo que pertecence a O(log(n))
*/

// función que resuelve el problema
int resolver(vector<char> const &v, int ini, int fin, int prim) {
	if (ini >= fin) // Devuelve 1
		return ini;
	else {
		int m = (ini + fin) / 2;
		int preso = prim + m;
		if (v[m] == preso)
			return resolver(v, m + 1, fin, prim);
		else
			return resolver(v, ini, m, prim);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char prim, ult;
	cin >> prim >> ult;

	vector <char> v(ult - prim);
	for (char &i : v)
		cin >> i;

	int sol = resolver(v, 0, int(v.size()), prim);
	// escribir sol
	char dato = prim + sol;
	cout << dato << "\n";

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
