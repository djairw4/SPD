
#include <iostream>
#include <algorithm>
#include "RandomNumberGenerator.h"

using namespace std;


int main()
{
    
    int seed, n;
    int p[1000], r[1000], S[1000], C[1000];
    int A;
    int pi[1000];

    while (1)
    {
        A = 0;
        cout << "Wprowadz zrodlo losowania: ";
        cin >> seed;
        cout << "Wprowadz rozmiar problemu: ";
        cin >> n;

        RandomNumberGenerator generator(seed);

        cout << "n: " << n << endl << endl;
        for (int i = 0; i < n; i++)
        {
            p[i] = generator.nextInt(1, 29);
            A += p[i];
            pi[i] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            r[i] = generator.nextInt(1, A);
        }


        cout << "nr: [";
        for (int i = 1; i <= n; i++) {
            cout << i;
            if (i != n)
                cout << ",";
        }
        cout << "]\n";


        cout << "r: [";
        for (int i = 0; i < n; i++) {
            cout << r[i];
            if (i != n-1)
                cout << ",";
        }
        cout << "]\n";

        cout << "p: [";
        for (int i = 1; i <= n; i++) {
            cout << p[i - 1];
            if (i != n)
                cout << ",";
        }
        cout << "]\n";

        cout << endl;


        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                S[i] = r[i];
            else
            {
                S[i] = max(r[i], C[i - 1]);
            }
            C[i] = S[i] + p[i];
        }




        cout << "pi: [";
        for (int i = 1; i <= n; i++) {
            cout << pi[i - 1];
            if (i != n)
                cout << ",";
        }
        cout << "]\n";

        cout << "S: [";
        for (int i = 1; i <= n; i++) {
            cout << S[i - 1];
            if (i != n)
                cout << ",";
        }
        cout << "]\n";

        cout << "C: [";
        for (int i = 1; i <= n; i++) {
            cout << C[i - 1];
            if (i != n)
                cout << ",";
        }
        cout << "]\n";

        cout << endl;


        for (int j = 0; j < n - 1; j++)
            for (int i = 0; i < n - 1; i++)
                if (r[i] > r[i + 1]) {
                    swap(r[i], r[i + 1]);
                    swap(p[i], p[i + 1]);
                    swap(pi[i], pi[i + 1]);
                }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                S[i] = r[i];
            else
            {
                S[i] = max(r[i], C[i - 1]);
            }
            C[i] = S[i] + p[i];
        }
       




        cout << "pi: [";
        for (int i = 1; i <= n; i++) {
            cout << pi[i - 1];
            if (i != n)
                cout << ",";
        }
        cout << "]\n";

        cout << "S: [";
        for (int i = 1; i <= n; i++) {
            cout << S[i - 1];
            if (i != n)
                cout << ",";
        }
        cout << "]\n";

        cout << "C: [";
        for (int i = 1; i <= n; i++) {
            cout << C[i - 1];
            if (i != n)
                cout << ",";
        }
        cout << "]\n";

        cout << endl;
    }
}
