// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void imprimesolucion(string const &sol){
	cout << sol << "\n";
}

// función que resuelve el problema
void resolver(int m, int n, int nivel, string &sol) {
	for (int i = int('a'); i < 'a' + m; ++i) {
		sol += char(i);
		if (nivel == n-1)
			imprimesolucion(sol);
		else {
			resolver(m, n, nivel+1, sol);
		}
		sol.pop_back();
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int letrasAlf, letrasPal;
	cin >> letrasAlf >> letrasPal;
	if (!std::cin)
		return false;

	string sol = "";
	int nivel = 0;
	resolver(letrasAlf, letrasPal, nivel, sol);

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