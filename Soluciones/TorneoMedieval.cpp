#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
	int min; //Maximo que necesita;
	int max; //suma de todos;
	int total; //(max-min)
};

tSol generarEspacioDeSoluciones(vector<int> const &v) {
	int min = v[0]; 
	int max = v[0];
	for (int i = 1; i < int(v.size()); ++i) {
		if (min < v[i])
			min = v[i];

		max += v[i];
	}

	return {min, max, (max-min)+1 };
}

bool comprueba(vector<int> const &v,int arma, int torneos) {
	int cuentaTorneos = 0;
	int i = 0;
	int sumaTorneo = 0;
	while (i < int(v.size()) && cuentaTorneos < torneos) {
		sumaTorneo += v[i];
		if (sumaTorneo <= arma) {
			++i;
		}
		else {
			sumaTorneo = 0;
			++cuentaTorneos;
		}
	}

	if (i == int(v.size()) && cuentaTorneos < torneos)
		return true;
	else
		return false;
}

/*
Coste de la solucion recursiva:
t(n) = { C0 n == 1
		t(n/2)+n  n>1
	  }
t(n/2)+n; T(n/2^2)+n+n; t(n/2^3)+n+n+n; ...k veces... ; t(n/2^k)+kn;
n/2^k= 1; n = 2^k; log(n) = k;
t(n/2^log(n))+ nlog(n); t(n/n)+nlog(n); t(1)+nlog(n) -> por lo que el coste de la solución es O(nlog(n)) 

*/
int resuelveEspacio(vector<int> const &v, int torneos, int ini, int fin, tSol espacio) {
	if (ini + 1 == fin) { //Caso base
		return espacio.min+ini;
	}
	else { //Caso recursivo
		int m = (ini + fin - 1) / 2;
		if (comprueba(v, espacio.min + m, torneos))
			return resuelveEspacio(v, torneos, ini, m+1, espacio);
		else
			return resuelveEspacio(v, torneos, m+1, fin, espacio);
	}
}

// función que resuelve el problema
int resolver(vector<int> const &v, int precio) {
	tSol espacio = generarEspacioDeSoluciones(v);
	return resuelveEspacio(v, precio, 0, espacio.total, espacio);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numEnem, torneos;
	cin >> numEnem;
	if (numEnem == -1)
		return false;

	cin >> torneos;

	vector<int> v(numEnem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, torneos);

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