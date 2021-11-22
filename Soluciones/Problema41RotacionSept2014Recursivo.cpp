// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


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
int resolver(vector<int> const &v, int ini, int fin) {
	if (ini + 1 == fin) { //Vector con solo un elemento.
		return ini;
	}
	else {
		int m = (ini + fin) / 2;
		if (v[m] > v[ini])
			return resolver(v, ini, m);
		else
			return  resolver(v, m, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	cin >> numElem;

	if (!std::cin)
		return false;

	vector<int> v(numElem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, 0, int(v.size()));

	// escribir sol
	cout << v[sol] << "\n";

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






//EJERCICIO HECHO DE FORMA LINEAL (MAL).

/*
Esta Mal pues se pide en O(log(n)) y esta solucion es de O(n).

T(n) = C1 n==0 || n==1, 2T(n/2)+ C2 n>1 (siendo n = fin-ini)
2(2T(n/2^k)+C1)+C1; 2^k*T(n/2^k)+(K-1)*C1;
n/2^k=1; n = 2^k; log(n) = k;
2^(log(n))T(n/2^(log(n)))+ log(n)*C1; n*T(1) + log(n)C1;

seria en orden lineal. O(n)
*/

/*
// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin) {
	if (ini+1 < fin) {
		int m = (ini + fin) / 2;
		int der = resolver(v, m, fin);
		int izq = resolver(v, ini, m);

		if (v[der] < v[izq])
			return der;
		else
			return izq;
	}
	else
		return ini;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	cin >> numElem;

	if (!std::cin)
		return false;

	vector<int> v(numElem);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, 0, int(v.size()));

	// escribir sol
	cout << v[sol] << "\n";

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

*/