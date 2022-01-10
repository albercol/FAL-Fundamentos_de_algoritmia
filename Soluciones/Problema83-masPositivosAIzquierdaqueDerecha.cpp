// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*

1.1) definicion de funcion:
P:{ 0 < v.size ^ 0 < k <= v.size() ^ k%2==0}
int resolver(vector<int> const &v, int k) //dev int numTramos
Q:{ 
	numTramos == # w1,w2: 0 <= w1 < w2 < v.size ^ (w2-w1+1) == k: cuentaElementos(v, w1, (k/2)-1) >= cuentaElementps(v, k/2, w2))
		donde: 
			cuentaElementos(v, a, k): #q: a <= q <= k: v[q] > 0; 
}


1.2) n corresponde al número de elementos del vector (v.size). 
	 k corresponde longitud del tramo pedida.

(primer bucle) -> Funcion cota: f(n) = k - i + 1;
I: {
	0 <= i <= k ^
	izq = # s: 0 <= s <= i: s < k/2 ^ v[q] > 0; 
	der = # s1: 0 <= s1 <= i: s >= k/2 ^ v[q] > 0;
}

(segundo bucle) -> Funcion cota: f(n) = n - j + 1;
I: {
	0 <= i < j <= v.size() ^
	izq = # p: i <= p <= j: p < k/2 ^ v[q] > 0;
	der = # p1: i <= p1 <= j: p1 >= k/2 ^ v[q] > 0;
	numTramos = # h1,h2: i <= h1 < h2 <= j ^ (h2-h1+1) == k: cuentaElementos(v, h1, (k/2)-1) >= cuentaElementps(v, k/2, h2))
		donde:
			cuentaElementos(v, a, k): #q: a <= q <= k: v[q] > 0;
}
*/
// función que resuelve el problema
int resolver(vector<int> const &v, int k) {
	int der = 0;
	int izq = 0;
	int numTramos = 0;
	for (int i = 0; i < k; ++i) {
		if (i < k / 2 && v[i]>0)
			++izq;
		else if (i >= k / 2 && v[i] > 0)
			++der;
	}

	if (der <= izq)
		++numTramos;
	int i = 0; 
	int j = k-1;
	while (j < int(v.size())-1) {
		if (v[i] > 0)
			--izq;
		++i;

		++j;
		if (v[(j-k/2)] > 0) {
			++izq;
			--der;
		}

		if (v[j] > 0)
			++der;

		if (der <= izq)
			++numTramos;

	}

	return numTramos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, k;
	cin >> numElem;
	if (numElem == 0)
		return false;
	cin >> k;

	vector<int> v(numElem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, k);

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
