//
// Lab 08 - Máximo número de hamburguesas
// Versión TOP DOWN
//
#include "bits/stdc++.h"

using  namespace  std;

const int max_kg = 4096;

// Función Recursiva
int maxHamburguesas(int m, int n, int T)
{
    int minimo = min(m, n);
    if (T < minimo)
        return INT_MIN;
    else if (T == m || T == n)
        return 1;
    else {
        int mHamb = maxHamburguesas(m, n, T-m);
        int nHamb = maxHamburguesas(m, n, T-n);
        int maxNumHamb = max(mHamb, nHamb) + 1;
        return  maxNumHamb;
    }
}

// Función con Memoización
int maxHamburguesasMemoi(int m, int n, int T)
{
    vector<vector<int>> memo (2, vector<int> (T + 1, 1));

    if (T == m || T == n)
        return 1;

    int minimo = min(m, n);
    if (T < minimo)
        return -1;

    //    if (memo[0][T] != -1  || memo[1][T] != -1 )
//        return  max(memo[0][T], memo[1][T]);

    // Almacenando valores de cada tabla
    int mHamb = maxHamburguesas(m, n, T-m);
    memo[0][T] = mHamb;
    int nHamb = maxHamburguesas(m, n, T-n);
    memo[1][T] = nHamb;

    int maxNumHamb = max(memo[0][T], memo[1][T]) + 1;

    return  maxNumHamb;
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

    cout << setw(10) << "Entrada" << setw(8) << "Salida" << setw(10) << "Resultado" << setw(8) << "Test" <<endl;
    for (int i = 0; i < 4; ++i) {
        cout << input[i][0] << " " << input[i][1] << " " << input[i][2];
        int resultado = maxHamburguesasMemoi(input[i][0], input[i][1], input[i][2]);
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