// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tsol{
	int maxPartidos = 0;
	int numVecesMaxPartidos = 0;
	int numPartidosJugados = 0;
};

// función que resuelve el problema
//{ P: 0 < v.size }
tsol resolver(vector<int> const &v) {
	int maxGanadosAct = 0; 
	int maxGanados = 0;
	int contRachas = 0; 
	int partidosRest = -1;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > 0) {
			++maxGanadosAct;
			if (maxGanadosAct > maxGanados) {
				++maxGanados;
				contRachas = 1;
				partidosRest = i;
			}else if (maxGanadosAct == maxGanados) {
				++contRachas;
				partidosRest = i;
			}
		}else
			maxGanadosAct = 0;
		
	}
	return { maxGanados, contRachas, int(v.size())-partidosRest-1 };
}
/*  {O : maxPartidos = Max p, q : 0 <= p <= q < v.size : cuenta(v,p,q) 
		 numVecesMaxPartidos = # k: 0 <= k < v.size: maxP(v)
		 numPartidosJugados = ¿?
		
	}
		Donde: maxP(v) = Max p, q : 0 <= p <= q < v.size : cuenta(v,p,q)
		Donde: cuenta(v,p,q) = # w: p <= w <= q: v[w] > 0
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	int tamDatos;
	cin >> tamDatos;
	if (!std::cin)
		return false;

	vector<int> v(tamDatos);
	for (int &i : v)
		cin >> i;

	tsol sol = resolver(v);

	// escribir sol
	cout << sol.maxPartidos << " " << sol.numVecesMaxPartidos << " " << sol.numPartidosJugados << "\n";

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