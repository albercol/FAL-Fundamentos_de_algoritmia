// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol{
	bool coinciden;
	int prim;
	int seg;
};

/*
COSTE:
n = numero de elementos de entrada.
T(n) = { C0 n == 1; t(n/2)+C1 n > 1;
despliegue => (t(n/2^2)+C1)+C1; (t(n/2^3)+C1)+C1+C1;... t(n/2^k)+KC1;
n/2^k = 1; n = 2^k; log(n) = k;
t(n/2^log(n))+ log(n)C1; t(1)+C1log(n); por lo que el coste es logarítmico.
O(log(n))
*/

// función que resuelve el problema
tSol resolver(vector<int> const &v1, vector<int> const &v2, int ini, int fin) {
	if (ini + 1 == fin)
		if (v1[ini] == v2[ini])
			return { true, ini, 0 };
		else if( v1[ini] > v2[ini])
			return { false, -1, 0 };
		else
			return { false, ini, ini+1};
	else {
		int m = (ini + fin) / 2;
		if (v1[m] > v2[m])
			return resolver(v1, v2, ini, m);
		else
			return resolver(v1, v2, m, fin);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	cin >> numElem;
	if (numElem == 0)
		return false;

	vector<int> v1(numElem);
	vector<int> v2(numElem);
	for (int &i : v1)
		cin >> i;

	for (int &i : v2)
		cin >> i;

	tSol sol = resolver(v1, v2, 0, numElem);

	// escribir sol
	if (sol.coinciden)
		cout << "SI " << sol.prim << "\n";
	else
		cout << "NO " << sol.prim << " " << sol.seg << "\n";

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
