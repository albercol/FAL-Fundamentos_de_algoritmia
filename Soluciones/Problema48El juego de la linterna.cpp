// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
	bool condicion;
	int min;
	int max;
};

pair<int, int> particion(vector<int> const &v, int ini, int fin) {
	//1) Buscar el elemento mas grande
	pair<int, int> max; //valor, posicion.
	max.first = v[ini]; 
	max.second = ini;

	for (int i = ini+1; i < fin; ++i) {
		if (v[i] > max.first) {
			max.first = v[i];
			max.second = i;
		}
	}

	return { max.first, max.second };
}


/*
Divide y venceras mediante el algoritmo de Quicksort.
n = fin - ini;
T(n) = C0 n<3, T(n-1) + n  n>=3 (caso peor), 2T(n/2)+n n >=3 (Caso mejor)

caso peor: 
T(n-2)+n+n; T(n-3)+n+n+n;... k veces...; T(n-k)+kn;
n-k = 0; n = k;
T(0)+n*n = T(0)+n^2; ------> por lo que pertenece al orden de O(n^2)

caso mejor:
2(2T(n/2^2)+n/2)+n;....k veces...; 2^kT(n/2^k)+Kn;
n/2^k=0; n = 2^k; log(n) = k;
2^log(n)T(n/2^log(n))+ log(n)n; nT(1)+nlog(n)-----> por lo que pertenece al orden de O(nlog(n))

*/

tSol resolver(vector<int> &v, int ini, int fin) {
	pair<int, int> max; //Valor, pos;
	tSol izq, der;
	int minret;

	if (ini + 3 <= fin) { //Por lo menos 3 elementos.
		max = particion(v, ini, fin); //Detecto donde esta el elemento maximo.
		
		if (max.second == ini){
			 der = resolver(v, max.second + 1, fin);
			 return { der.condicion, der.min, max.first };
		}
		else if (max.second + 1 == fin) {
			izq = resolver(v, ini, max.second);
			return { izq.condicion, izq.min, max.first};
		}
		else {
			der = resolver(v, max.second + 1, fin);
			izq = resolver(v, ini, max.second);

			if (der.min < izq.min) minret = der.min;
			else minret = izq.min;

			return { der.condicion && izq.condicion && !(izq.min < der.max), minret, max.first};
		}	
	}
	else if(ini+2 == fin){ //Cuando hay 2 elementos
		if (v[ini] > v[ini + 1])
			return { true, v[ini + 1], v[ini] };
		else
			return { true, v[ini], v[ini+1] };
	}
	else if(ini+1 == fin){ //Cuando hay un elemento.
		return { true, v[ini], v[ini] };
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

	tSol sol = resolver(v, 0, int(v.size()));

	if(sol.condicion == true)
		// escribir sol
		cout << "SIEMPRE PREMIO" << "\n";
	else
		// escribir sol
		cout << "ELEGIR OTRA" << "\n";

	
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