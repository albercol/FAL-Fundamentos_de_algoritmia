#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void imprime(vector<int> const &sol) {
	for (int i = 0; i < int(sol.size()); ++i) {
		cout << sol[i];
		if (i < int(sol.size() - 1))
			cout << " ";
	}
	cout << "\n";
}

bool esValido(vector<bool> const &marcaje, int i) {

	if (marcaje[i] == true)
		return false;

	return true;
}

/*
n = numero de jugetes
etapa = niño

(No estoy seguiro de si la variable maxSatisfaccion se pouede pasar por referencia, o seria mejor hacer un return normal con el maximo)
*/

// función que resuelve el problema
void resolver(vector<vector<int>> const &satisfaccion , int numJuguetes, int &actSatisf, int ninosTot, int etapa, int &maxSatisfaccionAct, vector<bool> &marcaje) {
	for (int i = 0; i < numJuguetes; ++i) {
		if (esValido(marcaje, i)) {
			marcaje[i] = true;
			actSatisf += satisfaccion[etapa][i];
			if (etapa == ninosTot - 1) {
				if (actSatisf > maxSatisfaccionAct)
					maxSatisfaccionAct = actSatisf;
			}
			else {
				resolver(satisfaccion, numJuguetes, actSatisf, ninosTot, etapa + 1, maxSatisfaccionAct, marcaje);
			}
			marcaje[i] = false;
			actSatisf -= satisfaccion[etapa][i];
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numJuguetes, ninos;
	cin >> numJuguetes >> ninos;
	if (!std::cin)
		return false;

	vector<int> sol(ninos * 2);
	vector<bool> marcaje(numJuguetes, false);

	vector<vector<int>> satisfaccion(ninos, vector<int>(numJuguetes));
	for (int i = 0; i < ninos; ++i) {
		for (int j = 0; j < numJuguetes; ++j) {
			cin >> satisfaccion[i][j];
		}
	}

	//Se inicializa al primer juguete que se le puede asignar al niño
	int maxSatisfaccionAct = 0;
	for (int i = 0; i < ninos; ++i)
		maxSatisfaccionAct += satisfaccion[i][i];

	int actSatisf = 0;
			//satisfaccion, numJuguetes, actSatisf, ninosTot, etapa, maxSatisfaccionAct, marcaje, sol
	resolver(satisfaccion, numJuguetes, actSatisf, ninos, 0, maxSatisfaccionAct, marcaje);
	cout << maxSatisfaccionAct << "\n";

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
