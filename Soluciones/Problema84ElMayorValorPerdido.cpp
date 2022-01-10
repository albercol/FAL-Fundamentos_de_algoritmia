#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
Coste de la solucion recursiva:
n = numero de elementos que componen el vector.
t(n) = { C0 n == 1
		 t(n/2)+C1  n>1;
	}
t(n/2)+C1; t(n/2^2)+C1+C1; t(n/2^3)+C1+C1+C1;... k veces...; t(n/2^k)+K*C1;
n/2^k = 1; n = 2^k; log(n)= k;
t(n/2^log(n))+C1*log(n); t(n/n)+C1*log(n); t(1)+C1*log(n); C0+C1*log(n);
por lo que el coste de la solucion recursiva es logarítmico -> O(log(n))

*/
// función que resuelve el problema
int resolver(vector<int> const & v, int ini, int fin) {
	if (ini + 1 == fin) { //Caso de un elemento.
		return v[ini]-1;
	}
	else {
		int m = (fin + ini - 1) / 2;
		if (v[fin-1] - v[m] > ((fin-1)-m))
			return resolver(v, m + 1, fin);
		else 
			return resolver(v, ini, m + 1);
		
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElem;
	cin >> nElem;
	if (nElem == 0)
		return false;

	vector<int> v(nElem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, 0, int(v.size()));

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
