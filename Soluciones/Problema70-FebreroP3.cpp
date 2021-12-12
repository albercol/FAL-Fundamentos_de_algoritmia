// Nombre del alumno Alberto Collado Mamblona
// Usuario del Juez A17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct tSol {
	vector<int> v;
	int satisfaccion;
	tSol(int i) : v(i), satisfaccion(0) {}
};

bool esValido(vector<vector<int>> const &d, vector<bool> const &marcas, int i, int etapa){
	//A nadie se le asigna un puesto para el que tenga satisfaccion negativa
	if (d[etapa][i] < 0)
		return false;
	//El invitado esta asignado.
	if (marcas[i] == true)
		return false;

	return true;
}


bool supersticiones(tSol const &sol) {
	int i = 0, cont = 0;
	while (i < int(sol.v.size())) {
		if (sol.v[i] == i) 
			++cont;

		++i;
	}

	if (cont > (int(sol.v.size()) / 3))
		return false;

	return true;
}

bool esSolucion(tSol const &sol, tSol const &mejorSol, bool hada) {
	
	if (!hada) //Si no esta el hada mala.
		return false;
	
	if (sol.satisfaccion < mejorSol.satisfaccion) //Si la satisdaccion actual es peor que la mejor hasta el momento.
		return false;

	if (!supersticiones(sol)) //Si mas un tercio de los invitados ocupan la misma posicion que el numero asignado. 
		return false;

	return true;
}

/*
CON ESTIMACION

O(n^m)
Ramas (n) = Habitantes;
etapa (m) = Invitado;
*/

void calculoEstimacion(vector<vector<int>> const &d, vector<int> &estimacion) {
	//Se busca la maxima satisfaccion de cada fila del array
	vector<int> vectorMaximos(int(estimacion.size()));
	for (int i = 0; i < int(d.size()); ++i) {
		int max = d[i][0];
		for (int j = 1; j < int(d[i].size()); ++j) {
			if (max < d[i][j])
				max = d[i][j];
		}
		vectorMaximos[i] = max;
	}

	//Se genera el vector de estimacion.
	estimacion[int(estimacion.size()) - 1] = vectorMaximos[int(estimacion.size()) - 1];
	for (int i = int(estimacion.size())-2; i >= 0; --i)
		estimacion[i] = estimacion[i+1] + vectorMaximos[i];

}

// función que resuelve el problema
void resolver(vector<vector<int>> const &d, int nHabitantes, int nInvitados, int hadaMala, bool hada ,int etapa,
				tSol &sol, tSol &mejorSol, vector<bool> &marcas, int &contSoluciones, vector<int> const &estimacion) {

	for (int i = 0; i < nHabitantes; ++i) {
		sol.v[etapa] = i;
		sol.satisfaccion += d[etapa][i];
		if (esValido(d,marcas, i, etapa)) {
			marcas[i] = true;
			if(hadaMala == i)
				hada = true;
			if (etapa == nInvitados-1) { // si hemos llegado al final de la posible solucion.
				if (esSolucion(sol, mejorSol ,hada)) {
					if (sol.satisfaccion > mejorSol.satisfaccion) {
						contSoluciones = 1;
						mejorSol.satisfaccion = sol.satisfaccion;
						mejorSol.v = sol.v;
					}
					else 
						++contSoluciones;
				}
			}//Realizamos la estimacion, si puede alcanzar una solucion mejor.
			else{
				if(sol.satisfaccion + estimacion[etapa+1] >= mejorSol.satisfaccion)
					resolver(d, nHabitantes, nInvitados, hadaMala, hada, etapa + 1, sol, mejorSol, marcas, contSoluciones, estimacion);
			}
			marcas[i] = false;
			if (hadaMala == i)
				hada = false;
		}
		sol.satisfaccion -= d[etapa][i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nHabitantes, nInvitados, hadaMala;
	cin >> nHabitantes;
	if (nHabitantes == 0)
		return false;

	cin >> nInvitados >> hadaMala;
	vector<vector<int>> v(nInvitados, vector<int>(nHabitantes)); //Satisfaccion de invitados.
	for (int i = 0; i < nInvitados; ++i)
		for (int j = 0; j < nHabitantes; ++j)
			cin >> v[i][j];
	
	tSol sol(nInvitados);
	tSol mejorSol(nInvitados);
	vector<bool> marcas(nHabitantes, false);
	int contSoluciones = 0;
	bool hada = false;

	vector<int> estimacion(nInvitados);
	calculoEstimacion(v, estimacion);

	resolver(v, nHabitantes, nInvitados, hadaMala, hada, 0, sol, mejorSol, marcas, contSoluciones, estimacion);

	// escribir sol
	if (contSoluciones != 0)
		cout << mejorSol.satisfaccion << " " << contSoluciones << "\n";
	else
		cout << "No" << "\n";

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