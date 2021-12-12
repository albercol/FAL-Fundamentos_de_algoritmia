// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


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
void resolver(vector<vector<int>> const &satisfaccion, int numJuguetes, int &actSatisf, int ninosTot, int etapa, int &maxSatisfaccionAct, vector<bool> &marcaje, vector<int> const &estimacionSatisf) {
	for (int i = 0; i < numJuguetes; ++i) {
		if (esValido(marcaje, i)) {
			marcaje[i] = true;
			actSatisf += satisfaccion[etapa][i];
			if (etapa == ninosTot - 1) {
				if (actSatisf > maxSatisfaccionAct)
					maxSatisfaccionAct = actSatisf;
			}
			else {
				if(actSatisf + estimacionSatisf[etapa+1] > maxSatisfaccionAct) //Poda.
					resolver(satisfaccion, numJuguetes, actSatisf, ninosTot, etapa + 1, maxSatisfaccionAct, marcaje, estimacionSatisf);
			}
			marcaje[i] = false;
			actSatisf -= satisfaccion[etapa][i];
		}
	}
}

vector<int> vectorAcumulados(vector<vector<int>> const &satisfaccion, int numJuguetes, int ninos) {
	int maximo;
	vector<int> vectorMaximos(ninos);
	
	//Se genera el vector de maximos para todas las satisfacciones:
	for (int i = 0; i < ninos; ++i) {
		maximo = satisfaccion[i][0];
		for (int j = 0; j < numJuguetes; ++j) {
			if (maximo < satisfaccion[i][j])
				maximo = satisfaccion[i][j];
		}
		vectorMaximos[i] = maximo;
	}

	//se genera el vector de acumulados:
	//Ojo se tiene que generar en orden inverso.
	vector<int> acumulados(ninos);
	acumulados[ninos-1] = vectorMaximos[ninos-1];
	for (int i = ninos-2; i >= 0; --i) {
		acumulados[i] = acumulados[i+1] + vectorMaximos[i];
	}

	return acumulados;
	
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

	vector<int> v = vectorAcumulados(satisfaccion, numJuguetes, ninos);

	int actSatisf = 0;
	//satisfaccion, numJuguetes, actSatisf, ninosTot, etapa, maxSatisfaccionAct, marcaje, sol
	resolver(satisfaccion, numJuguetes, actSatisf, ninos, 0, maxSatisfaccionAct, marcaje, v);
	cout << maxSatisfaccionAct << "\n";

	return true;

}

/*
4 3
-8 -9 -3 -1
-6 -4 -5 -3
-2 -2 -9 -9
*/
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