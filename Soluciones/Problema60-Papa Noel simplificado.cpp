// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


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

bool esValido(vector<string> const &juguete ,vector<int> const &sol, int etapa) {
	
	if ((etapa+1)%2== 0 && juguete[sol[etapa - 1]] == juguete[sol[etapa]])
		return false;

	if ((etapa+1)%2==0 && sol[etapa-1] >= sol[etapa])
		return false;

	return true;
}

// función que resuelve el problema
int resolver(vector<string> const &juguete, int numJuguetes, int ninosTot ,int etapa, vector<int> &sol) {
	int cont = 0;
	for (int i = 0; i < numJuguetes; ++i) {
		sol[etapa] = i;
		if (esValido(juguete, sol, etapa)) {
			if (etapa == ninosTot-1) {
				imprime(sol);
				++cont;
			}
			else {
				cont += resolver(juguete, numJuguetes, ninosTot, etapa + 1, sol);
			}
		}
	}

	return cont;
}

bool esta(vector<string> &juguete, string tipo) {
	int i = 0;
	while (i < int(juguete.size()) && tipo == juguete[i])
		++i;

	return i != int(juguete.size());
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
	vector<string> juguete(numJuguetes);
	vector<bool> marcaje(numJuguetes);

	string tipo;
	for (int i = 0; i < int(juguete.size()); ++i) {
		cin >> tipo;
		juguete[i] = tipo;
	}

	if (resolver(juguete, numJuguetes, ninos * 2, 0, sol) == 0)
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