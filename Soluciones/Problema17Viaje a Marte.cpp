#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Si los elementos cumplen la condicion establecida en el enunciado, se van decrementando desde las esquinas
//En el momento de que no cumplan la condicion estos se intercambiaran 
// función que resuelve el problema
int resolver(vector<pair<string, int>> &v, int altura) {
	int p = 0, q = v.size() - 1;
	while (p <= q) {
		if (v[p].second <= altura)
			++p;
		else if(v[q].second > altura)
			--q;
		else {
			swap(v[p], v[q]);
			++p; --q;
		}
	}

	return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPersonas, altura;
	cin >> numPersonas >> altura;
	if (!std::cin)
		return false;

	vector<pair<string, int>> v(numPersonas);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i].first >> v[i].second;
	}

	int bajos = resolver(v, altura);

	sort(v.begin(), v.begin() + bajos);
	sort(v.begin() + bajos, v.end());

	//Escribir bajos
	cout << "Bajos: ";
	for (int i = 0; i < bajos; ++i)
		cout << v[i].first << " ";
	cout << "\n";

	//Escribir altos.
	cout << "Altos: ";
	for (int i = bajos; i < v.size(); ++i)
		cout << v[i].first << " ";
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
