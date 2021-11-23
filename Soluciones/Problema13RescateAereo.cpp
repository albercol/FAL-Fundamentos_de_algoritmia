#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//El coste de la solucion es lineal en fundion del tamaño del vector O(n)
// función que resuelve el problema
//{ P: 0 < v.size && 0 < transporte }
pair<int, int> resolver(vector<int> const &v, int transporte) {
	int fin=0;
	int longitud=0;
	int maxEscondite = 0;
	int ini = 0;

	for(int i = 0; i < v.size(); ++i){
		if (transporte < v[i])
			++longitud;
		else
			longitud = 0;

		if (maxEscondite < longitud) {
			maxEscondite = longitud;
			fin = i;
			ini = (fin - maxEscondite) + 1;
		}

	}
		
	return {ini,fin};
}
//{ O: (ini = Min i, j: 0 <= i <= j < v.size: cuenta(v, i, j)) ^ }
//{ (fin = Max i, j: 0 <= i <= j < v.size : cuenta(v, i, j))
//Donde: cuenta(v, i, j) = Pt w : i <= w <= j : (v[w] > transporte) -> w

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numEdificios, transporte;
	cin >> numEdificios >> transporte;

	vector<int> v(numEdificios);
	for (int &i : v)
		cin >> i;

	pair<int, int> sol = resolver(v, transporte);

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
