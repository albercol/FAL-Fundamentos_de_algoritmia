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
void resolver(vector<vector<int> > const &d, int funcionatios, int etapa ,int &productividadActual, int &maxProductividad, vector<bool> &marcaje) {
	for (int i = 0; i < funcionatios; ++i) {
		if (!marcaje[i]) { //EsValido().
			marcaje[i] = true;
			productividadActual += d[etapa][i];
			if (etapa == funcionatios - 1) {
				if (productividadActual < maxProductividad)
					maxProductividad = productividadActual;
				
			}
			else
				resolver(d, funcionatios, etapa + 1, productividadActual, maxProductividad, marcaje);

			marcaje[i] = false;
			productividadActual -= d[etapa][i];
		}
	}

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
	resolver(datos, funcionarios, 0, pordAct, maxProductividad, marcaje);

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
