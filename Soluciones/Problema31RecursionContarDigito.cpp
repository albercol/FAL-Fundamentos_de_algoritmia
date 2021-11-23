#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//funcion recursiva no final.
int repNoFinal(long long int numero, int digitRep) {
	int ret = 0;
	if (numero < 10) {
		if (numero == digitRep)
			return 1;
	}
	else{
		if (numero % 10 == digitRep) {
			ret = 1;
			ret += repNoFinal(numero / 10, digitRep);
		}
		else
			ret += repNoFinal(numero / 10, digitRep);
	}


	return ret;
}

//funcion recursiva final.
int repFinal(long long int numero, int digitRep, int rep) {
	if (numero/10 == 0) {
		if (numero == digitRep) ++rep;
	}
	else {
		if (numero % 10 == digitRep)
			rep = repFinal(numero / 10, digitRep, ++rep);
		else 
			rep = repFinal(numero / 10, digitRep, rep);
	}

	return rep;
}

// función que resuelve el problema
pair<int,int> resolver(long long int numero, int digitRep) {
	int recNoFinal = repNoFinal(numero, digitRep);
	int recFinal = repFinal(numero, digitRep, 0);

	return { recNoFinal, recFinal };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	long long int numero;
	int digitRep;
	cin >> numero >> digitRep;
	pair<int,int> sol = resolver(numero, digitRep); //Sol Devuelve el resultado de la funcion recursiva no final y final.
	// escribir sol
	cout << sol.first << " " << sol.second << "\n";

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
