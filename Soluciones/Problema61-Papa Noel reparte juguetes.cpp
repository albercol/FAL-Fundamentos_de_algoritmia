// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct tData {
	vector<pair<string, int>> juguete; //Tipo, unidades.
	vector<vector<int>> satisfaccion;
	int minimaSatisfaccion;
};

void imprime(vector<int> const &sol) {
	for (int i = 0; i < int(sol.size()); ++i) {
		cout << sol[i];
		if (i < int(sol.size() - 1))
			cout << " ";
	}
	cout << "\n";
}

bool esValido(tData const &data, vector<int> const &marcaje, vector<int> const &sol, int etapa, int i, int actSatisf) {

	if ((etapa + 1) % 2 == 0 && data.juguete[sol[etapa - 1]].first == data.juguete[sol[etapa]].first)
		return false;

	if ((etapa + 1) % 2 == 0 && sol[etapa - 1] >= sol[etapa])
		return false;

	if (marcaje[i] == data.juguete[i].second)
		return false;

	if ((etapa + 1) % 2 == 0 && actSatisf < data.minimaSatisfaccion)
		return false;

	return true;
}

/*

n = numero de jugetes
etapa = niño -> etapa%2 == 0 (regalo1) etapa%2==1 (Regalo2)

*/

// función que resuelve el problema
int resolver(tData const &data, int numJuguetes, int actSatisf ,int ninosTot, int etapa, int ninoAct ,vector<int> &marcaje ,vector<int> &sol) {
	int cont = 0;
	for (int i = 0; i < numJuguetes; ++i) {
		sol[etapa] = i;
		actSatisf += data.satisfaccion[ninoAct][i];

		if (esValido(data, marcaje, sol, etapa, i, actSatisf)) {
			++marcaje[i];
			if (etapa == ninosTot - 1) {
				imprime(sol);
				++cont;
			}
			else {
				if ((etapa + 1) % 2 == 0) {
					cont += resolver(data, numJuguetes, 0, ninosTot, etapa + 1, ninoAct+1, marcaje, sol);
				}else
					cont += resolver(data, numJuguetes, actSatisf, ninosTot, etapa + 1, ninoAct, marcaje, sol);
			}
			--marcaje[i];
		}

		actSatisf -= data.satisfaccion[ninoAct][i];
	}

	return cont;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numJuguetes, ninos, minSatisf;
	cin >> numJuguetes >> ninos >> minSatisf;
	if (!std::cin)
		return false;

	vector<int> sol(ninos * 2);
	vector<int> marcaje(numJuguetes, 0);
	
	tData data;

	data.juguete.resize(numJuguetes);
	//Se crea los tipos con sus unidades.
	int unidades;
	for (int i = 0; i < numJuguetes; ++i) {
		cin >> unidades;
		data.juguete[i].second = unidades;
	}

	string tipo;
	for (int i = 0; i < numJuguetes; ++i) {
		cin >> tipo;
		data.juguete[i].first = tipo;
	}

	data.satisfaccion.resize(ninos);
	for (int i = 0; i < ninos; ++i) {
		data.satisfaccion[i].resize(numJuguetes);
		for (int j = 0; j < numJuguetes; ++j) {
			cin >> data.satisfaccion[i][j];
		}
	}
	
	data.minimaSatisfaccion = minSatisf;
	int actSatisf = 0;
	if (resolver(data, numJuguetes, actSatisf, ninos*2, 0, 0, marcaje, sol) == 0)
		cout << "SIN SOLUCION" << "\n";

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