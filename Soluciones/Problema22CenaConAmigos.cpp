// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSol {
	int suma;
	int comienzo;
	int longitud;
};

/*
Casos de prueba extra:
8
2 3 -6 0 5 -3 -1 1
5 4 1

8
2 3 -6 0 3 2 -1 1
5 0 2
*/

// función que resuelve el problema
tSol resolver(vector <int> const &v) {
	int ini = 0; int fin = int(v.size()-1);
	int sumaAcu = 0; int sumaMax = 0;
	int a = 0; int b = 0;
	while (b < v.size()) {
		sumaAcu += v[b];
		if (sumaAcu > 0) {
			if (sumaAcu > sumaMax) {
				sumaMax = sumaAcu;
				ini = a;
				fin = b;
			}
			else if (sumaAcu == sumaMax && (fin - ini + 1) > (b - a + 1)) {
				sumaMax = sumaAcu;
				ini = a;
				fin = b;
			}
			++b;
		}
		else {
			sumaAcu = 0;
			++b;
			a = b;
		}
	}

	return { sumaMax, ini, fin-ini+1 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nDatos;
	cin >> nDatos;
	if (!std::cin)
		return false;

	vector <int> v(nDatos);
	for (int &i : v)
		cin >> i;

	tSol sol = resolver(v);

	// escribir sol
	cout << sol.suma << " " << sol.comienzo << " " << sol.longitud << "\n";

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