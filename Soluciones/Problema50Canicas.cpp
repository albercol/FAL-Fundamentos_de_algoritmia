// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*
n = fin - ini;
T(n) = C0 n = 2, 2T(n/2)+C1 n > 2;
2(2T(n/2^2)+C1)+C1;.... K veces...; 2^kT(n/2^k)+sum(2^j)C1;
n/2^k= 1; log(n)= k;
2^log(n)T(n/2^log(n))+ (2^log(n)-1) C1;
nT(0)+ nC1 -C1-----> por lo que pertenece al orden de n O(n).
*/

// función que resuelve el problema
pair<string, int> resolver(vector <pair<string, int>> const &v, int ini, int fin) {
	
	if (ini + 2 == fin) { //Dos elementos.
		if (v[ini].second >= v[ini + 1].second)
			return { v[ini].first, v[ini].second + (v[ini + 1].second/2) };
		else
			return { v[ini + 1].first, v[ini + 1].second + (v[ini].second/2) };
	}
	else {
		int m = (fin + ini) / 2;
		pair<string, int> izq = resolver(v, ini, m);
		pair<string, int> der = resolver(v, m, fin);

		if (izq.second >= der.second)
			return { izq.first, izq.second + (der.second/2) };
		else
			return{ der.first, der.second + (izq.second/2) };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int personas;
	cin >> personas;
	if (!std::cin)
		return false;

	vector <pair<string, int> >v(personas);
	for (int i = 0; i < personas; ++i) {
		cin >> v[i].first >> v[i].second;

	}

	pair<string, int> sol = resolver(v, 0, int(v.size()));

	// escribir sol
	cout << sol.first << " " << sol.second << "\n";

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