#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Con estimación
Etapas = Canciones;
Ramas = ida, vuelta, no.
*/

// función que resuelve el problema
void resolver(vector <pair<int, int>> const& v, int etapa, int ida, int vuelta, int& tiempoActIda, int& tiempoActVuelta, int& satisfaccion,
	int& satisfaccionMax, vector<bool>& solIda, vector<bool>& solVuelta, vector<int> const &estimacion) {
	//Rama IDA:
	solIda[etapa] = true;
	tiempoActIda += v[etapa].first;
	satisfaccion += v[etapa].second;
	if (tiempoActIda <= ida) { //esValida()
		if (etapa == int(v.size()) - 1) {
			if (satisfaccion > satisfaccionMax && tiempoActIda == ida && tiempoActVuelta == vuelta) //esSolucion()
				satisfaccionMax = satisfaccion;
		}
		else
			if(satisfaccion+estimacion[etapa+1] > satisfaccionMax)
				resolver(v, etapa + 1, ida, vuelta, tiempoActIda, tiempoActVuelta, satisfaccion,
					satisfaccionMax, solIda, solVuelta, estimacion);

	}
	solIda[etapa] = false;
	tiempoActIda -= v[etapa].first;
	satisfaccion -= v[etapa].second;

	//Rama VUELTA:
	solVuelta[etapa] = true;
	tiempoActVuelta += v[etapa].first;
	satisfaccion += v[etapa].second;
	if (tiempoActVuelta <= vuelta) { //esValida()
		if (etapa == int(v.size()) - 1) {
			if (satisfaccion > satisfaccionMax && tiempoActVuelta == vuelta && tiempoActIda == ida) //esSolucion()
				satisfaccionMax = satisfaccion;
		}
		else
			if (satisfaccion + estimacion[etapa + 1] > satisfaccionMax)
				resolver(v, etapa + 1, ida, vuelta, tiempoActIda, tiempoActVuelta, satisfaccion,
					satisfaccionMax, solIda, solVuelta, estimacion);

	}
	solVuelta[etapa] = false;
	tiempoActVuelta -= v[etapa].first;
	satisfaccion -= v[etapa].second;


	//Rama NO:
	if (etapa == int(v.size()) - 1) {
		if (satisfaccion > satisfaccionMax && tiempoActVuelta == vuelta && tiempoActIda == ida) //esSolucion()
			satisfaccionMax = satisfaccion;

	}
	else
		if (satisfaccion + estimacion[etapa + 1] > satisfaccionMax)
			resolver(v, etapa + 1, ida, vuelta, tiempoActIda, tiempoActVuelta, satisfaccion,
				satisfaccionMax, solIda, solVuelta, estimacion);

}


bool orden(pair<int, int> const& a, pair<int, int> const& b) {
	return (a.second > b.second);
}

void calculoEstimacion(vector <pair<int, int>> const &v, vector<int> &estimacion){
	estimacion[int(v.size()) - 1] = v[int(v.size())-1].second;
	for (int i = int(v.size()) - 2; i >= 0; --i) {
		estimacion[i] = estimacion[i + 1] + v[i].second;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCanciones, ida, vuelta;
	cin >> numCanciones >> ida >> vuelta;
	if (numCanciones == 0 && ida == 0 && vuelta == 0)
		return false;

	vector <pair<int, int>> v(numCanciones); //Duracion, Satisfaccion.
	for (int i = 0; i < numCanciones; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), orden);

	vector<bool> solIda(numCanciones, false);
	vector<bool> solVuelta(numCanciones, false);

	int tiempoActIda = 0;
	int tiempoActVuelta = 0;

	int satisfaccion = 0;
	int satisfaccionMax = 0;

	vector<int> estimacion(numCanciones);
	calculoEstimacion(v, estimacion);

	resolver(v, 0, ida, vuelta, tiempoActIda, tiempoActVuelta, satisfaccion,
		satisfaccionMax, solIda, solVuelta, estimacion);

	// escribir sol
	if (satisfaccionMax != 0)
		cout << satisfaccionMax << "\n";
	else
		cout << "Imposible" << "\n";

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
