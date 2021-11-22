// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Mediante Divide y Venceras (mergeSort)
n = fin-ini;
T(n)= C1 n <= 2; 2T(n/2)+ n >= 3						
2(2T(n/2^2)+n/2)+n;... k veces...; 2^kT(n/2^k)+Kn
n/2^k = 1; log(n) = k;

2^log(n)T(n/2^log(n))+log(n)n; nT(1)+nlog(n)---> por lo que pertenece al orden de O(nlog(n))

*/

// función que resuelve el problema
int resolver(vector<int> &v, int ini, int fin) {
	if (ini + 1 == fin) //Caso de un elemento.
		return 0;
	if (ini + 2 == fin) {//Caso de dos elementos.
		if (v[ini] > v[ini + 1]) {
			swap(v[ini], v[ini+1]);
			return 1;
		}
		else
			return 0;
	}
	else {
		int m = (fin + ini) / 2;
		int invDer = resolver(v, m, fin);
		int invIzq = resolver(v, ini, m);

		int i = ini, j = m;
		int numInversiones = invDer + invIzq;

		while (i < m && j < fin) {
			if (v[i] > v[j]) {
				numInversiones += m-i; //La cantidad de inversiones que se realizan por elemento
				++j;
			}
			else 
				++i;
		}
		inplace_merge(v.begin() + ini, v.begin() + m, v.begin() + fin);

		return numInversiones;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numNaves;
	cin >> numNaves;
	if (!std::cin)
		return false;

	vector<int> v(numNaves);
	for (int &i : v)
		cin >> i;
	
	int sol = resolver(v, 0, int(v.size()));

	// escribir sol
	cout << sol << "\n";
	
	
	return true;

}

int main() {
	/*
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	endif 
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