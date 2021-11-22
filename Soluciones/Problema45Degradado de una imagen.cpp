// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
Recursión mediante el método de divide y venceras. 
Divide el problema en subproblemas que se van resolviendo hasta combinandose los
resultados de cada parte en la solución final.

n = fin - ini;
T(n) = C0 n = 1; 2T(n/2)+C1 n > 1;
2(2T(n/2^2)+C1)+C1; ....K veces ... 2^kT(n/2^k)+sum(2^j)C1;
n/2^k = 1; log(n)=k;
2^log(n)*T(n/2^log(n))+ 2^log(n)*C1; nT(1)+nC1 

----> por lo que el coste de la funcion resolver es del orden de O(n)
*/
// función que resuelve el problema
pair<bool, int> resolver(vector<vector<int>> const &v, int ini, int fin, int fila) {
	if (ini + 1 == fin) //Caso de un elemento.
		return { true, v[fila][ini] };
	if (ini + 2 == fin) { //Caso de dos elementos
		if (v[fila][ini] < v[fila][ini + 1])
			return {true, (v[fila][ini] + v[fila][ini+1])};
		else
			return {false, (v[fila][ini] + v[fila][ini+1])};
	}
	else {
		int m = (fin + ini) / 2;
		pair<bool, int> der = resolver(v, m, fin, fila);
		pair<bool, int> izq = resolver(v, ini, m, fila);
		
		return { (der.first && izq.first) && izq.second < der.second, (der.second+izq.second)};
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numFilas, numCol;
	cin >> numFilas >> numCol;
	if (!std::cin)
		return false;

	vector<vector<int>> v(numFilas, vector<int> (numCol));
	for (int i = 0; i < numFilas; ++i) {
		for (int j = 0; j < numCol; ++j)
			cin >> v[i][j];
	}

	pair<bool, int> sol = { true, 0 };
	int i = 0;
	while (i < numFilas && sol.first) {
		sol = resolver(v, 0, numCol, i);
		++i;
	}

	// escribir sol
	if (sol.first)
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