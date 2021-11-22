// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
n=fin-ini;
T(n)= { C0 n = 1; 2T(n/2)+C1 n > 1;
2T(n/2)+C1; 2(2T(n/2^2)+C1);... K veces ...; 2^kT(n/2^k) + sum(2^j)C1;
n/2^k; log(n) = k;
2^log(n)T(n/2^log(n))+2^log(n)*C1;
nT(1)+nC1 ----> Por lo que pertenece al orden de O(n).
*/

// función que resuelve el problema
bool resolver(vector<int> const &v, int k ,int ini, int fin) {
	if (ini + 1 == fin) { //Caso de 1 elemento
		return true;
	}
	else {
		int m = (fin + ini)/2;
		bool der = resolver(v, k, ini, m);
		bool izq = resolver(v, k, m, fin);
		return der == true && izq == true && abs(v[ini] - v[fin-1]) >= k;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, dispersion;
	cin >> numElem >> dispersion;
	if (!std::cin)
		return false;

	vector<int> v(numElem);
	for (int &i : v)
		cin >> i;
	 
	bool sol = resolver(v, dispersion ,0, int(v.size()));

	// escribir sol
	if (sol == true)
		cout << "SI\n";
	else
		cout << "NO\n";

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