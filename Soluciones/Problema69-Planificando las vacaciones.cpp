#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
	vector<int> v;
	int coste;
	tSol(int i) : v(i, 0), coste(0) {};
};

/*
Con estimación.

Ramas = ciudades.
etapas = dias.

*/
// función que resuelve el problema
void resolver(vector<vector<int>> const &billetes, tSol &sol, int nc, int etapa, tSol &mejorSol, vector<bool> &marcas, int estimacion) {
	for (int i = 1; i < nc; ++i) {
		sol.v[etapa] = i;
		sol.coste += billetes[sol.v[etapa-1]][i];
		if(!marcas[i] && sol.coste < mejorSol.coste) { // esValida()
			marcas[i] = true;
			if(etapa == nc-1){ // esSolucion();    (ojo al 0) hay que sumarle la vuelta.
				if (sol.coste + billetes[sol.v[etapa]][0] < mejorSol.coste) { //esSolucionMejor()
					mejorSol.v = sol.v;
					mejorSol.coste = sol.coste + billetes[sol.v[etapa]][0];
				}
			} //las ciudades que quedan por el mínimo de la matriz
			else if(sol.coste + (nc-etapa)*estimacion < mejorSol.coste){
					resolver(billetes, sol, nc, etapa + 1, mejorSol, marcas, estimacion);
			}
			marcas[i] = false;
		}
		sol.coste -= billetes[sol.v[etapa - 1]][i];
	}
}


int calculoEstimacion(vector<vector<int>> const & v) {
	int min=v[int(v.size())-1][0];
	for (int i = 0; i < int(v.size()); ++i) {
		for (int j = 0; j < int(v.size()); ++j) {
			if (min > v[i][j] && v[i][j] != 0)
				min = v[i][j];
		}
	}
	return min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nc;
	cin >> nc;
	if (nc == 0)
		return false;

	vector<vector<int>> v(nc, vector<int>(nc)); //Billetes.
	for (int i = 0; i < nc; ++i)
		for (int j = 0; j < nc; ++j)
			cin >> v[i][j];

	tSol sol(nc); //Vector solución.
	sol.v[0] = 0;

	vector<bool> marcas(nc, false); //Vector marcas.
	marcas[0] = true;

	tSol mejorSol(nc);
	mejorSol.v[0] = 0;
	mejorSol.coste = 0;
	for (int i = 1; i < nc; ++i) {
		mejorSol.v[i] = i;
		mejorSol.coste += v[i - 1][i];
	}
	mejorSol.coste += v[nc - 1][0];
		
	int estimacion = calculoEstimacion(v);

	resolver(v,sol, nc, 1, mejorSol, marcas, estimacion);

	// escribir sol
	cout << mejorSol.coste << "\n";

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
