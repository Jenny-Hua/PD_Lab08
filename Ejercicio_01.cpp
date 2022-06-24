//
// Lab 08 - Máximo número de hamburguesas
//
#include "bits/stdc++.h"

using  namespace  std;

const int INF = INT_MIN;
int maxHamburguesas(int m, int n, int T)
{
    if (T < m)
        return INF;
    else if (T == m || T == n)
        return 1;
    else


    return -1;
}

int main()
{
    // Prueba de testeo
    int input[][3] {
            {3,5,54},
            {3,5,55},
            {2,7,17},
            {2,7,18},
            {3,5,10000}
    };
    int output[] {
        18,
        17,
        6,
        9,
        3332
    };

    cout << setw(10) << "Entrada" << setw(6) << "Salida" << setw(10) << "Resultado" << setw(6) << "Test" <<endl;
    for (int i = 0; i < 5; ++i) {
        cout << input[i][0] << " " << input[i][1] << " " << input[i][2];
        int resultado = maxHamburguesas(input[i][0], input[i][1], input[i][2]);
        cout << setw(6) << output[i] << setw(10) << resultado
             << setw(6);
        if (resultado == output[i])
            cout << "Pasó";
        else
            cout << "Falló";
        cout << endl;
    }
    return 0;
}