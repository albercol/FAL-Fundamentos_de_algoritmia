#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//RECURSION FINAL:
// función que resuelve el problema
int resolver(int num1, int num2, int sum, int prod) {
	int res = 0;
	if (num1 < 10 && num2 < 10) {
		int calculo = ((num1 + num2)%10)*prod + sum;
		if (calculo == 0)
			return sum;
		else
			sum = calculo;

		return sum;
	}
	else { 
		int calculo = (((num1 % 10) + (num2 % 10)) % 10)*prod;
		if (calculo == 0) {
			calculo = sum;
		}
		else 
			calculo = calculo + sum;
			
		res = resolver(num1 / 10, num2 / 10, calculo, prod * 10);


		//res = resolver(num1/10, num2/10, (((num1 % 10)+(num2 % 10))% 10)*prod+sum, prod*10);
	}

	return res;
}

//RECURSION NO FINAL:
// función que resuelve el problema
int resolver(int num1, int num2) {
	int res = 0;
	if (num1 < 10 && num2 < 10)
		return (num1 + num2)%10;
	else {
		res = resolver(num1/10, num2/10);
		res = res*10 + ((num1%10) + (num2%10))%10;
	}

	return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num1, num2;
	cin >> num1 >> num2;

	int solNoFinal = resolver(num1, num2);
	int solFinal = resolver(num1, num2, 0, 1);
	// escribir sol
	cout << solNoFinal << " " << solFinal << "\n";
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
