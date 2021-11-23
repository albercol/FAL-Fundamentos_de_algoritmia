#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int trataNumero(int num) {
	int res = num;
	if (num%2 == 0)
		res += 1;
	else
		res -= 1;

	return res;
}

//Recursicidad NO FINAL

// función que resuelve el problema
int resolver(int numero) {
	int res = 0;
	if (numero/10 == 0) res = trataNumero(numero % 10);
	else {
		res = resolver(numero / 10)*10;
		res += trataNumero(numero % 10);
	}
	return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numero;
	cin >> numero;

	int sol = resolver(numero);
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
