// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

struct tSol {
	bool pOrdenado;
	int max;
	int min;
};

/*
Recurrencia Divide y venceras con búsqueda binaria.
n = fin - ini;
T(n) = C0 n = 2; 2T(n/2)+C1 n > 2;
2(2T(n/2^2)+C1)+C1 = ....k veces... = 2^kT(n/2^k)+sum(2^j)*C1
n/2^k= 1; log(n) = k; 
nT(1)+nC1 ----> Por lo que pertenece al orden de O(n).

*/

// función que resuelve el problema
tSol resolver(vector<int> const &v, int ini, int fin) {

	if(ini+1 == fin) //Caso de un elemnto.
		return { true, v[ini], v[ini]};
	else if (ini+2 == fin) //Caso de dos elementos.
			if(v[ini] > v[ini+1])
				return { false, int(fmax(v[ini],v[ini + 1])), int(fmin(v[ini],v[ini + 1]))};
			else
				return { true, int(fmax(v[ini],v[ini + 1])), int(fmin(v[ini],v[ini + 1])) };
	else {
		int m = (fin + ini) / 2;
		tSol der = resolver(v, m, fin);
		tSol izq = resolver(v, ini, m);
		
		int min = int(fmin(der.min, izq.min));
		int max = int(fmax(der.max, izq.max));

		return { der.pOrdenado && izq.pOrdenado && (der.max >= izq.max && izq.min <= der.min), max, min};
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elemento;
	cin >> elemento;
	if (elemento == 0)
		return false;

	vector<int> v;
	while (elemento != 0) {
		v.push_back(elemento);
		cin >> elemento;
	}
	tSol sol = resolver(v, 0, int(v.size()));
	// escribir sol
	if (sol.pOrdenado == true)
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
