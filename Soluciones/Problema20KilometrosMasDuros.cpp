// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSol {
	int maxDesnivel;
	int primerTramo;
	int segundoTramo;
};
// función que resuelve el problema
tSol resolver(vector<int> const &v, int tramo) {
	int desnivelAct = 0;
	int primerTramo = 0, segundoTramo = 0;
	for (int i = 0; i < tramo; ++i) {
		desnivelAct += v[i];
	}
	int maxDesnivel = desnivelAct;
	int a = 0, b = tramo;
	while (b < v.size()) {
		desnivelAct -= v[a];
		desnivelAct += v[b];
		if (desnivelAct > maxDesnivel) {
			maxDesnivel = desnivelAct;
			primerTramo = a+1;
			segundoTramo = primerTramo;
		}
		else if (desnivelAct == maxDesnivel) {
			segundoTramo = a+1;
		}
		++a; ++b;
	}

	return { maxDesnivel, primerTramo, segundoTramo };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nDatos, tramo;
	cin >> nDatos >> tramo;
	if (nDatos == 0 && tramo == 0)
		return false;

	vector<int> v(nDatos);
	for (int &i : v)
		cin >> i;
	tSol sol = resolver(v, tramo);

	// escribir sol
	cout << sol.maxDesnivel << " " << sol.primerTramo << " " << sol.segundoTramo << "\n";

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