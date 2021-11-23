#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct tSol {
	bool jugador;
	int partidoJugado;
	int ronda;
};

/*
n = fin - ini 
T(n) = C0 n = 2; 2T(n/2)+C1 si n > 2;
2T(n/2)+C1; 2(2T(n/2^2)+C1)+C1;.... K veces.....; 2^kT(n/2^k)+sum(2^j)C1;
n/2^k =1; log(n) = k;
2^log(n)*T(n/2^log(n))+(2^log(n)-1)C1; nT(1)+ n-C1 ----> Por lo que pertence al orden de O(n).
*/

// función que resuelve el problema
tSol resolver(vector<string> const &v, int ini, int fin, int ronda) {
	if (ini + 2 == fin) { //Caso de dos elementos
		if (v[ini] != "NP" && v[ini+1] != "NP")
			return { true, 1 , ronda-1};
		else {
			if (v[ini] != "NP")
				return { true, 0,ronda-1};
			else if (v[ini + 1] != "NP")
				return  { true, 0 , ronda-1};
			else
				return { false, 0, ronda-1};
		}
	}
	else {
		int m = (fin + ini) / 2;
		tSol der = resolver(v, m, fin, ronda);
		tSol izq = resolver(v, ini, m, ronda);

		if (der.ronda > 0 && izq.ronda > 0) { //Si ronda aun no ha llegado a cero
			if (der.jugador && izq.jugador)
				return { der.jugador, (der.partidoJugado + izq.partidoJugado) + 1, der.ronda - 1 };
			else if (der.jugador)
				return { der.jugador, (der.partidoJugado + izq.partidoJugado), der.ronda - 1 };
			else if (izq.jugador)
				return { izq.jugador, (der.partidoJugado + izq.partidoJugado), izq.ronda - 1 };
			else
				return { false, (der.partidoJugado + izq.partidoJugado), izq.ronda - 1 };
		}else //Si ronda ha llegado a cero, se devuelve lo que se tiene y se pasa "NP" para que no cuente.
			return { false, (der.partidoJugado + izq.partidoJugado), der.ronda};
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, ronda;
	cin >> numElem >> ronda;
	if (!std::cin)
		return false;

	vector<string> v(numElem);
	for (string &i : v)
		cin >> i;

	tSol sol = resolver(v, 0, int(v.size()), ronda);

	// escribir sol
	cout << sol.partidoJugado << "\n";
 
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
