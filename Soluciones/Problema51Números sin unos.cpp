#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct tSol {
	bool tieneUnos;
	int numUnos;
	long long int numDigitosTot;
};

// función que resuelve el problema
tSol resolver(long long int n) {
	tSol val;
	
	if(n < 10){
		if (n == 1)
			val = { true,1, 1};
		else if (n == 0)
			val = {false, 0, 1};
		else
			val = { false, 0, n};
	}
	else{
		val = resolver(n/10);
		if (n % 10 == 1) {
			if(val.tieneUnos)
				val.numDigitosTot = val.numDigitosTot * 9;
			else
				val.numDigitosTot = val.numDigitosTot*9 - 8;
			if (n % 10 == 1) {
				val.tieneUnos = true;
				++val.numUnos;
			}

			return val;
		}
		else if (n % 10 == 0) {
			if(val.tieneUnos)
				val.numDigitosTot = val.numDigitosTot * 9;
			else
				val.numDigitosTot = val.numDigitosTot * 9 - 8;
		}else {
			if(val.tieneUnos)
				val.numDigitosTot = val.numDigitosTot * 9;
			else
				val.numDigitosTot = val.numDigitosTot * 9 - (9 - n % 10);
		}
	}

	return val;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long long int dato;
	cin >> dato;

	if (!std::cin)
		return false;

	long long int sol = resolver(dato).numDigitosTot;

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
