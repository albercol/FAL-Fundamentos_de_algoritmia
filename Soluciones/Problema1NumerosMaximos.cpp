// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int maxNum = 0;
	int rep = 0;
	int dato;
	// leer los datos de la entrada
	cin >> maxNum;
	dato = maxNum;
	while (dato != 0) {
		if (maxNum < dato) {
			maxNum = dato;
			rep = 1;
		}
		else if(maxNum == dato)
			++rep;
		
		cin >> dato;
	}

	cout << maxNum << " " << rep << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	ifstream in("datos.txt");
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
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}