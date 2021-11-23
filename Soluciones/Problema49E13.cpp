#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
	int min;
	int sumaMax;
	int tamano;
};

bool comprueba(vector<int> const &v, int capacidad, int numViajes) {
	int viaje = 0;
	int i = 0;
	int camion = 0;

	while (viaje < numViajes && i < int(v.size())) {
		camion += v[i];
		if (camion <= capacidad)
			++i;
		else {
			camion = 0;
			++viaje;
		}
	}

	if (viaje < numViajes && i == int(v.size()))
		return true;
	else
		return false;
}

tSol espacioDeSoluciones(vector<int> const &v) {
	int min = v[0]; //minimo (El mayor)
	int sumaMax = v[0]; //sumaMax;
	for (int i = 1; i < int(v.size()); ++i) {
		if (min < v[i])
			min = v[i];

		sumaMax += v[i];
	}

	return { min, sumaMax, sumaMax - min + 1 };

}

/*
Recursividad de busqueda en el espacio de soluciones.

n = fin-ini;
T(n)= C0 n = 1; T(n/2) + n n>1;
T(n/2^2)+n+n; T(n/2^3)+n;.... K veces....; T(n/2^k)+kn;
n/2^k = 0; log(n) = k;
T(1)+ nlog(n); ----> por lo que pertenece al orden

*/
int resuelveProblema(vector<int> const &v, tSol espacio, int ini, int fin, int numViajes) {

	if (ini + 1 == fin) //Solo un elemento.
		return espacio.min+ini;
	else {
		int m = (fin + ini - 1) / 2;
		if (comprueba(v, espacio.min+m, numViajes)) {
			return resuelveProblema(v, espacio, ini, m + 1, numViajes);
		}
		else
			return resuelveProblema(v, espacio, m+1, fin, numViajes);
	}
}

int resolver(vector<int> const &v, int ini, int fin, int numViajes) {
	tSol espacio = espacioDeSoluciones(v);
	return resuelveProblema(v, espacio, 0, espacio.tamano, numViajes);
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int obras, numViajes;
	cin >> obras >> numViajes;
	if (obras == 0 && numViajes == 0)
		return false;

	vector <int> v(obras);
	for (int &i : v)
		cin >> i;

	int sol = resolver(v, 0, int(v.size()), numViajes);

	// escribir sol
	cout << sol << "\n";
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
