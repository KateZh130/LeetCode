#include <iostream>
using namespace std;

int main()
{
    int Q = 0; //total value of all items in knapsack
    const int N = 5; //number of items
    int Wmax = 50; //weight limit
    int S[N]; // resulting set of items
    int sumW = 0;
    int c[N] = { 6, 3, 13, 30, 25 };
    int w[N] = { 17, 15, 3, 24, 23 };
    int max = 0;
    int max_el, cl;

    for (int i = 0; i < N; i++)
        S[i] = 0;

    cout << "Items" << endl;
    for (int i = 0; i < N; i++)
        cout << i + 1 << '\t';

    cout << "\nPrices" << endl;
    for (int i = 0; i < N; i++)
        cout << c[i] << '\t';

    cout << "\nWeight" << endl;
    for (int i = 0; i < N; i++)
        cout << w[i] << '\t';

    cout << "\nMax weight:" << Wmax << endl;



    for (int i = 0; i < N; i++) {
        max = c[i];
        //search for the maximum
        for (int j = 0; j < N; j++)
        {
            if (c[j] > max) {
                max = c[j];
                cl = max;
                max_el = j;
            }
        }
        //item selection
        if (sumW + w[max_el] <= Wmax) {
            Q += cl;
            sumW += w[max_el];
            S[max_el] = 1;


            cout << "\n\nStep:" << i + 1 << endl;
            cout << "Selected item:" << max_el + 1 << endl;
            cout << "Weight of the selected item:" << w[max_el] << endl;
            cout << "Price of the selected item:" << c[max_el] << endl;
            cout << "Current price of knapsack:" << Q << endl;
            cout << "Current weight of knapsack:" << sumW << endl;
            c[max_el] = 0;


        }
        else break;
    }
    cout << "\n\nResult: items" << endl;
    for (int i = 0; i < N; i++) {
        cout << S[i] << '\t';
    }
    cout << "\n\nTotal cost:" << Q << endl;
    cout << "Total weight:" << sumW << endl;



}
