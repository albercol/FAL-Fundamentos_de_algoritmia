// Nombre del alumno: Alberto Collado Mamblona
// Usuario del Juez: A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct tPlaya{
	string id;
	int alturaEdificio;
	int alturaPiso;
};

// función que resuelve el problema
/*
P: { v.size > 0 ^ sol.size = 0}
*/
void resolver(vector<tPlaya> const &v, vector<string> &sol) { //dev vector<string> sol
	int alturaMaxima = v[v.size() - 1].alturaEdificio;
	
	if (v[v.size() - 1].alturaPiso >= 0)
		sol.push_back(v[v.size() - 1].id);

	for (int i = v.size() - 2; i >= 0; --i) {
		if (v[i].alturaPiso > alturaMaxima)
			sol.push_back(v[i].id);

		if (v[i].alturaEdificio > alturaMaxima)
			alturaMaxima = v[i].alturaEdificio;
	}
}
/*
Q: { sol = P.t w: 0 <= w < sol.size: sol[w] = (Ex k: 0 <= k < v.size: v[k])
	^ P.t z : 0 <= z < v.size ^ tieneVista(v,z): v[z];
	}

	tieneVistas(v,i) = P.t k : i < k < v.size: v[i].alturaPiso > v[k].alturaEdificio
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos;
	cin >> numCasos;
	if (numCasos == 0)
		return false;

	string id; int alturaEd; int alturaP;
	vector<tPlaya> v(numCasos);
	for (int i = 0; i < v.size(); ++i) {
		cin >> id >> alturaEd >> alturaP;
		v[i].id = id; 
		v[i].alturaEdificio = alturaEd;
		v[i].alturaPiso = alturaP;
	}
	
	vector<string> sol;
	resolver(v, sol);

	// escribir sol
	if (sol.size() > 0) {
		cout << sol.size() << "\n";
		cout << sol[0];
	}
	else
		cout << "Ninguno" << "\n";

	for (int i = 1; i < sol.size(); ++i)
		cout << " " << sol[i];
	cout << "\n";

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
