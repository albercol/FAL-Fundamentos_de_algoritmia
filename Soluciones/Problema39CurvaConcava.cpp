#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
T(n) = C1 n == 1, T(n/2)+C1 n>1
C1+ C1+T(n/2^2) ; C1 + C1 + C1 + T(n/2^3)....
K*C1 + T(n/2^k) -----> n/2^k = 1 ; log n = k;
		C1*log (n) + T(1) ----> Por lo que pertenece al orden de O(log(n))
*/

// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin) {
	if (ini+1 == fin) //SI SOLO HAY UN ELEMENTO.
		return ini;
	else if (ini + 2 == fin) { //SI HAY DOS ELEMENTOS.
		if (v[ini] < v[ini + 1])
			return ini;
		else
			return ini+1;
	}
	else {
		int m = (fin + ini) / 2;
		if (v[m] < v[m - 1])
			return resolver(v, m, fin);
		else
			return resolver(v, ini, m);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	cin >> numElem;
	if (!std::cin)
		return false;

	vector <int> v(numElem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, 0, int(v.size()));

	// escribir sol
	cout << v[sol] << "\n";

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
