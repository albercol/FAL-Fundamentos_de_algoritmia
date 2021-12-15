#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
EQ RECURRENCIA:
f(n)={ v[ini]+1 if ini+1=fin (Caso base), resolver(v,m,fin) if ini<fin ^ v[m]-v[ini] == m-ini, resolver(v, ini, m) if ini<fin ^ v[m]-v[ini] != m-ini; 


COSTE:
n = numero de elementos de entrada.
T(n) = { C0 n == 1; t(n/2)+C1 n > 1;
despliegue => (t(n/2^2)+C1)+C1; (t(n/2^3)+C1)+C1+C1;... t(n/2^k)+KC1;
n/2^k = 1; n = 2^k; log(n) = k;
t(n/2^log(n))+ log(n)C1; t(1)+C1log(n); por lo que el coste es logarítmico.
O(log(n))
*/

// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin) {
	if (ini + 1 == fin) //Caso de un elemento
		return v[ini] + 1;
	else {
		int m = (ini + fin) / 2;
		if (abs(v[ini] - v[m]) == abs(ini - m))
			return resolver(v, m, fin);
		else
			return resolver(v, ini, m);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	cin >> numElem;

	vector<int> v(numElem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, 0, int(v.size()));

	// escribir sol
	cout << sol << "\n";

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
