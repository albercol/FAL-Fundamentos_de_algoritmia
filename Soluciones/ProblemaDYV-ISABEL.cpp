#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
n=fin-ini;
T(n) = C0 n = 1; T(n/2) + C1 n > 1;

T(n/2)+C1; T(n/2^2)+C1+C1; ... K vueltas ... T(n/2^k)+k*C1;
n/2^k = 1; log n = k;
T(n/2^log(n))+C1*log(n) = T(1)+C1*log(n) -----> Pertenece al orden de O(log(n)).
*/

// función que resuelve el problema
int resolver(vector<int> const &v1, vector<int> const &v2, int ini, int fin) {
	if (ini + 1 == fin) { //Vector con solo un elemento.
		return ini;
	}
	else {
		int m = (ini + fin) / 2;
		if (v1[m] > v2[m])
			return resolver(v1, v2, ini, m);
		else
			return  resolver(v1, v2, m, fin);

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem1;
	cin >> numElem1;

	if (!std::cin)
		return false;

	vector<int> v1(numElem1);
	for (int &i : v1)
		cin >> i;

	vector<int> v2(numElem1);
	for (int &i : v2)
		cin >> i;

	int sol = resolver(v1, v2, 0, int(v1.size()));

	// escribir sol
	cout << v1[sol] << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	//#ifndef DOMJUDGE
	//std::ifstream in("datos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	//#endif


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
	//#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	//#endif


	return 0;
}
