#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tNumPiezas {
	int azul;
	int rojo;
	int verde;
};

bool esValido(vector<int> const &v, vector<int> const &marcaje,int etapa, tNumPiezas const &piezas) {
	if (v[etapa - 1] == 2 && v[etapa] == 2)
		return false;
	if (marcaje[2] > marcaje[0])
		return false;
	if (marcaje[0] > piezas.azul || marcaje[1] > piezas.rojo || marcaje[2] > piezas.verde)
		return false;

	return true;
}

void imprime(vector<int> const &v) {
	for (int i = 0; i < int(v.size()); ++i) {
		if (v[i] == 0)
			cout << "azul";
		else if (v[i] == 1)
			cout << "rojo";
		else
			cout << "verde";

		if (i + 1 < int(v.size()))
			cout << " ";
	}
	cout << "\n";
}

/*
Ramas = colores:																							Rojo
Etapa = altura torre:								    Azul												Rojo           Verde
							Azul					    Rojo			    		Verde			    	...			    ...
					Azul	Rojo	Verde		Azul	Rojo	Verde		Azul	Rojo	Verde
							...							...							...
*/

// función que resuelve el problema
int resolver(int numero, int etapa, vector<int> &v, vector<int> &marcaje, tNumPiezas const &piezas) {
	int cont = 0;
	if (numero > 1) {
		for (int i = 0; i < 3; ++i) {
			v[etapa] = i;
			++marcaje[i];
			if (esValido(v, marcaje, etapa, piezas)) {
				if (etapa == numero - 1) {
					if (marcaje[1] > (marcaje[0] + marcaje[2])) {
						imprime(v);
						++cont;
					}
				}
				else {
					cont = resolver(numero, etapa + 1, v, marcaje, piezas);
				}
			}
			--marcaje[i];
		}
	}
	else {
		imprime(v);
		++cont;
	}

	return cont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numero,azul, rojo, verde;
	cin >> numero >> azul >> rojo >> verde;
	if (numero == 0 && azul == 0 && rojo == 0 && verde == 0)
		return false;

	tNumPiezas piezas = { azul, rojo, verde };
	vector<int> marcaje(3, 0); //numero de piezas que se van colocando.
	vector<int> v(numero);
	v[0] = 1;
	++marcaje[1];
	if (resolver(numero, 1, v, marcaje, piezas) == 0)
		cout << "SIN SOLUCION" << "\n";
	
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
