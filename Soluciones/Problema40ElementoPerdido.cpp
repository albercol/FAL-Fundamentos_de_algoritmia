#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
Solucion recursiva por divide y venceras.
T(n) = C1 si n == 1, C1+T(n/2) n > 1;
C1 + C1 + T(n/2^2); C1 + C1 + C1 + T(n/2^3)... K*C1 + T(n/2^k)
n/2^k = 1; n = 2^k; log(n) = k -----> log(n)*C1 + T(n/2^log(n)) ------> log(n)*C1 + T(1)
		Por lo que pertenece al orden de O(log(n))
*/


// función que resuelve el problema
// P:{0 < v.size() ^ 0 <= v2.size() ^ Ordenado(v) ^ Ordenado(v2) ^ v = V ^ v2 = V2
// Donde: Ordenado(a) = P.t w: 0 < k < a.size() : a[w-1] < a[w]  
int resolver(vector<int> const &v, vector<int> const &v2, int ini, int fin) { //dev int pos
	if (ini >= fin) //Devuelve pos.
		return ini;
	else {
		int m = (ini + fin) / 2;
		if (v2[m] + v2[ini] > v[m] + v[ini]) // <-
			return resolver(v, v2, ini, m);
		else
			return resolver(v, v2, m+1, fin); // ->
	}
}
//Q:{ pos = # k : 0 <= k < v.size() : V[k] == V2[k] }

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	cin >> numElem;
	vector<int> v(numElem);
	for (int &i : v)
		cin >> i;

	vector<int> v2(numElem-1);
	for (int &i : v2)
		cin >> i;

	int sol = resolver(v, v2, 0, v2.size());
	// escribir sol
	cout << v[sol] << "\n";

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
