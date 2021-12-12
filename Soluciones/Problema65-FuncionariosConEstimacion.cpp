// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
n = trabajo.
m = trabador.
*/

// función que resuelve el problema
void resolver(vector<vector<int> > const &d, int funcionatios, int etapa, int &productividadActual, int &maxProductividad, vector<bool> &marcaje, vector<int> const &est) {
	for (int i = 0; i < funcionatios; ++i) {
		if (!marcaje[i]) { //EsValido().
			marcaje[i] = true;
			productividadActual += d[etapa][i];
			if (etapa == funcionatios - 1) {
				if (productividadActual < maxProductividad)
					maxProductividad = productividadActual;

			}
			else {
				if(productividadActual + est[etapa+1] < maxProductividad)
					resolver(d, funcionatios, etapa + 1, productividadActual, maxProductividad, marcaje, est);
			}
			marcaje[i] = false;
			productividadActual -= d[etapa][i];
		}
	}

}

vector<int> estimacion(vector<vector<int>> const &datos) {
	int minVals;
	vector<int> mejoresValores(datos.size());
	for (int i = 0; i < int(datos.size()); ++i) {
		minVals = datos[i][0];
		for (int j = 1; j < int(datos.size()); ++j) {
			if (minVals > datos[i][j])
				minVals = datos[i][j];
		}
		mejoresValores[i] = minVals;
	}

	vector<int> acumulados(int(datos.size()));
	acumulados[int(datos.size())-1] = mejoresValores[int(datos.size())-1];
	for (int i = int(datos.size()) - 2; i >= 0; --i)
		acumulados[i] = acumulados[i + 1] + mejoresValores[i];

	return acumulados;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int funcionarios;
	cin >> funcionarios;
	if (funcionarios == 0)
		return false;

	vector<vector<int> > datos(funcionarios, vector<int>(funcionarios));

	for (int i = 0; i < funcionarios; ++i)
		for (int j = 0; j < funcionarios; ++j)
			cin >> datos[i][j];

	int maxProductividad = 0;
	for (int i = 0; i < funcionarios; ++i)
		maxProductividad += datos[i][i];

	vector<bool> marcaje(funcionarios, false);
	int tiempos = 0;
	int pordAct = 0;

	vector<int> est = estimacion(datos);

	resolver(datos, funcionarios, 0, pordAct, maxProductividad, marcaje, est);

	// escribir sol
	cout << maxProductividad << "\n";

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
