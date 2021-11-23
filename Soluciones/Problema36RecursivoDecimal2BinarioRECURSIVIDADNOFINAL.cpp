#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//RECURSIVIDAD NOFINAL:

// función que resuelve el problema
string resolver(int numero) {
	string binario = "";
	if (numero < 2)
		binario += to_string(numero % 2);
	else if (numero/2 < 2) {
		binario += to_string(numero / 2) + to_string(numero % 2);
		return binario;
	}
	else {
		binario += resolver(numero/2);
		binario += to_string(numero%2);
	}
	return binario;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numero;
	cin >> numero;

	string sol = resolver(numero);
	// escribir sol
	cout << sol << "\n";

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
