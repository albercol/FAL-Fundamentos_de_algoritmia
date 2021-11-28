﻿// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void imprime(vector<int> const &v){
	for (int i = 0; i < int(v.size()); ++i) {
		if (v[i] == 0)
			cout << "azul";
		else if (v[i] == 1)
			cout << "rojo";
		else
			cout << "verde";

		if (i+1 < int(v.size()))
			cout << " ";
	}
	cout << "\n";
}

/*
Ramas = colores:									    Azul												Rojo           Verde
Etapa = altura torre:		Azul					    Rojo					   Verde			    	...			    ...
					Azul	Rojo	Verde		Azul	Rojo	Verde		Azul	Rojo	Verde
							...							...							...
*/

// función que resuelve el problema
void resolver(int numero, int etapa ,vector<int> &v) {
	for (int i = 0; i < 3; ++i) {
		v[etapa] = i;
		if (etapa == numero - 1) {
			imprime(v);
		}
		else {
			resolver(numero, etapa + 1, v);
		}

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numero;
	cin >> numero;

	if (numero == 0)
		return false;

	vector<int> v(numero);
	resolver(numero, 0, v);
	cout << "\n";
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