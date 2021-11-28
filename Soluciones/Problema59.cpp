// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tDatos {
	vector <int> abrigo;
	vector<int> lluvia;
};

bool esValido(tDatos const &datos, int etapa, int i, vector<int> const &marcaje, vector<int> const &sol) {
	if (datos.lluvia[etapa] > datos.abrigo[i])
		return false;

	if (etapa > 0 && sol[etapa] == sol[etapa - 1])
		return false;

	if (marcaje[i] > (2 + (etapa/3)))
		return false;

	return true;
}

// función que resuelve el problema
int resolver(tDatos const &datos, int etapa, vector<int> &marcaje, vector<int>&sol) {
	int cont = 0;
	for (int i = 0; i < int(datos.abrigo.size()); ++i) {
		sol[etapa] = i;
		++marcaje[i];
		if (esValido(datos, etapa, i, marcaje, sol)) {
			if (etapa == int(datos.lluvia.size()) - 1) {
				if(sol[0] != sol[etapa])
					++cont;
			}
			else {
				cont += resolver(datos, etapa+1, marcaje, sol);
			}
		}
		--marcaje[i];

	}

	return cont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int dias, abrigos;
	cin >> dias >> abrigos;
	if (dias == 0 && abrigos == 0)
		return false;

	vector<int> marcaje(abrigos);
	vector<int> sol(dias);
	
	tDatos datos;
	int dato;
	for (int i = 0; i < dias; ++i) {
		cin >> dato;
		datos.lluvia.push_back(dato);
	}
	for (int i = 0; i < abrigos; ++i) {
		cin >> dato;
		datos.abrigo.push_back(dato);
	}

	int cont = resolver(datos, 0, marcaje, sol);
	if (cont == 0)
		cout << "Lo puedes comprar" << "\n";
	else
		cout << cont << "\n";

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
