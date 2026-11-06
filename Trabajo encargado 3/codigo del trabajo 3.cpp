#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double datos[100];
    double suma = 0, promedio, varianza = 0, desviacion;
    cout << "Cantidad de datos: ";
    cin >> n;

    // Leer los datos
    for (int i = 0; i < n; i++) {
        cout << "Dato " << i + 1 << ": ";
        cin >> datos[i];
        suma = suma + datos[i];
    }

    promedio = suma / n;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (datos[j] > datos[j + 1]) {
                double aux = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = aux;
            }
        }
    }

    // Mediana
    double mediana;
    if (n % 2 == 0) {
        mediana = (datos[n / 2 - 1] + datos[n / 2]) / 2;
    } else {
        mediana = datos[n / 2];
    }

    // Varianza muestral
    for (int i = 0; i < n; i++) {
        varianza = varianza + (datos[i] - promedio) * (datos[i] - promedio);
    }
    varianza = varianza / (n - 1);

    desviacion = sqrt(varianza);
	cout << "RESULTADOS:" << endl;
    cout << "Minimo: " << datos[0] << endl;
    cout << "Maximo: " << datos[n - 1] << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Varianza: " << varianza << endl;
    cout << "Desviacion estandar: " << desviacion << endl;
    cout << "Coeficiente de variacion: " << desviacion / promedio * 100 << " %" << endl;

    return 0;
}
