// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
void resolver(vector<pair<int, int>> const& datos, int presupuesto, int& presupuestoAct,
	int etapa, int& maxSuperficie, int& maxSuperficieAct, vector<bool>& sol, vector<int> const &estimacion) {

	//Rama del si.
	sol[etapa] = true;
	maxSuperficieAct += datos[etapa].second;
	presupuestoAct += datos[etapa].first;
	if (presupuestoAct <= presupuesto) { //Si vale.
		if (etapa == int(datos.size()) - 1) { //es Solucion
			if (maxSuperficieAct > maxSuperficie)
				maxSuperficie = maxSuperficieAct;
		}
		else
			resolver(datos, presupuesto, presupuestoAct,
				etapa + 1, maxSuperficie, maxSuperficieAct, sol, estimacion);
	}

	//Rama del no.
	sol[etapa] = false;
	maxSuperficieAct -= datos[etapa].second;
	presupuestoAct -= datos[etapa].first;
	if (etapa == int(datos.size()) - 1) { //es Solucion
		if (maxSuperficieAct > maxSuperficie)
			maxSuperficie = maxSuperficieAct;
	}
	else
		if(maxSuperficieAct + estimacion[etapa+1] > maxSuperficie)
			resolver(datos, presupuesto, presupuestoAct,
				etapa + 1, maxSuperficie, maxSuperficieAct, sol, estimacion);
	}

//ordenar por segundo elemento
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b){
	return (a.second > b.second);
}

vector<int> calculoEstimacion(vector<pair<int, int>> const &v,int presupuesto) {
	vector<int> ret(int(v.size()));
	ret[int(v.size())-1] = v[int(v.size()) - 1].second;
	for (int i = int(v.size())-2; i >= 0; --i) {
		ret[i] = ret[i + 1] + v[i].second;
	}
	return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElementos, presupuesto;
	cin >> numElementos >> presupuesto;
	if (!std::cin)
		return false;

	vector<pair<int, int>> v(numElementos); //Coste, Superficie
	for (pair<int, int>& i : v)
		cin >> i.first >> i.second;

	int maxSuperficie = 0;
	int maxSuperficieAct = 0;
	int presupuestoAct = 0;
	vector<bool> sol(numElementos);
	
	sort(v.begin(), v.end(), sortbysec);
	vector<int> estimacion = calculoEstimacion(v, presupuesto);
	resolver(v, presupuesto, presupuestoAct, 0, maxSuperficie, maxSuperficieAct, sol, estimacion);

	// escribir sol
	cout << maxSuperficie << "\n";

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