// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*

t(n) = C1 (n=0), t(n/10)+C1 (n>=10)

Formula general: K*C1 + t(n/10^k)
si	n = 10^k -----> log (n) = k -----> C1 * log (n) + t(1);

	Por lo que la complejidad del algoritmo es O(log(n))

*/

// función que resuelve el problema
pair<bool, int> resolver(int numero, int precede) {
	if (numero/10 == 0 && precede%(numero % 10) == 0) {
		return {true, numero%10};
	}
	else {
		if (numero%10 == 0 || precede % (numero%10) != 0)
			return {false, numero%10};
		else {
			pair<bool, int> sucede = resolver(numero/10, precede + (numero%10));
			if (sucede.first == false || sucede.second % (numero % 10) != 0)
				return { false, sucede.second + (numero % 10) };
			else
				return { true, sucede.second + (numero % 10) };
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numero;
	cin >> numero;
	pair<bool, int> sol = resolver(numero, 0);
	
	// escribir sol
	if (sol.first == true)
		cout << "SI" << "\n";
	else
		cout << "NO" << "\n";

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

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	/*
	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	*/
	return 0;
}