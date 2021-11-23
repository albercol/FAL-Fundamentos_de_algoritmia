#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
n = fin-ini;
T(n) = C0 n = 1; T(n/2)+C1 n > 1;
T(n/2)+C1; T(n/2^2)+C1+C1; T(n/2^3)+C1+C1+C1;...K veces...; T(n/2^k)+KC1;
n/2^k=1; log(n) = k
T(n/2^log(n))+C1*log(n) = T(1)+C1*log(n).

Por lo que pertenece al orden de O(log(n))
*/

// función que resuelve el problema
int resolver(vector<int> const &v, int numeroCantado ,int ini, int fin) {
	if (ini + 1 == fin) //Solo un elemento;
		return ini;
	else {
		int m = (fin + ini) / 2;
		if ((numeroCantado + m) < v[m])
			return resolver(v, numeroCantado, ini, m);
		else
			return resolver(v, numeroCantado, m, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem, numeroCantado;
	cin >> numElem >> numeroCantado;
	vector<int> v(numElem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, numeroCantado ,0, int(v.size()));
	// escribir sol
	if(numeroCantado+sol == v[sol])
		cout << v[sol] << "\n";
	else
		cout << "NO\n";

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
