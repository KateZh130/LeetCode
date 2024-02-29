#include <iostream> //Neighbor joining
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));
    double Q = 0; //summ
    const int N = 15; //number of cities
    int X[N]; //serial numbers of cities
    int S[N]; // resulting city crawl
    int min_el = 0; //next city
    int next_town;
    double min_dist = 10000; // minimum distance between cities
    double p[N][N] =
    { 0.00, 13.89, 13.60, 11.18, 11.05, 2.83, 10.20, 13.45, 7.21, 3.16, 9.49, 9.22, 7.62, 7.00, 8.06,
 13.89, 0.00, 1.41, 7.62, 8.06, 13.45, 9.22, 2.83, 12.53, 13.60, 10.44, 10.20, 11.18, 12.00, 11.05,
 13.60, 1.41, 0.00, 6.32, 9.00, 13.45, 10.05, 1.41, 13.00, 13.00, 11.18, 9.06, 11.70, 11.05, 10.00,
 11.18, 7.62, 6.32, 0.00, 12.53, 12.37, 13.00, 5.10, 14.04, 9.22, 13.60, 3.16, 13.15, 5.83, 4.47,
 11.05, 8.06, 9.00, 12.53, 0.00, 9.06, 1.41, 10.05, 5.83, 12.65, 2.83, 13.45, 4.47, 13.60, 13.45,
 2.83, 3.45, 13.45, 12.37, 9.06, 0.00, 8.00, 13.60, 4.47, 5.83, 7.07, 11.00, 5.10, 9.22, 10.05,
 10.20, 9.22, 10.05, 13.00, 1.41, 8.00, 0.00, 11.00, 4.47, 12.08, 1.41, 13.60, 3.16, 13.45, 13.45,
 13.45, 2.83, 1.41, 5.10, 10.05, 13.60, 11.00, 0.00, 13.60, 12.53, 12.04, 8.00, 12.37, 10.20, 9.06,
 7.21, 12.53, 13.00, 14.04, 5.83, 4.47, 4.47, 13.60, 0.00, 9.90, 3.16, 13.60, 1.41, 12.53, 13.00,
 3.16, 13.60, 13.00, 9.22, 12.65, 5.83, 12.08, 12.53, 9.90, 0.00, 11.66, 6.71, 10.00, 4.12, 5.39,
 9.49, 10.44, 11.18, 13.60, 2.83, 7.07, 1.41, 12.04, 3.16, 11.66, 0.00, 13.89, 2.00, 13.45, 13.60,
 9.22, 10.20, 9.06, 3.16, 13.45, 11.00, 13.60, 8.00, 13.60, 6.71, 13.89, 0.00, 13.00, 2.83, 1.41,
 7.62, 11.18, 11.70, 13.15, 4.47, 5.10, 3.16, 12.37, 1.41, 10.00, 2.00, 13.00, 0.00, 12.21, 12.53,
 7.00, 12.00, 11.05, 5.83, 13.60, 9.22, 13.45, 10.20, 12.53, 4.12, 13.45, 2.83, 12.21, 0.00, 1.41,
 8.06, 11.05, 10.00, 4.47, 13.45, 10.05, 13.45, 9.06, 13.00, 5.39, 13.60, 1.41, 12.53, 1.41, 0.00
    };




    cout << "Cities:" << endl;
    for (int i = 0; i < N; i++) {
        X[i] = i + 1;
        cout << X[i] << '\t';
    }
    cout << '\n' << endl;
    cout << "Distance matrix:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

            cout << p[i][j] << "\t";
        }
        cout << endl << "\n";
    }

    int tmp = rand() % N;
    cout << '\n';
    int k = tmp + 1;
    cout << "Random first city: " << k << endl;
    cout << '\n';

    double p1[N];
    for (int i = 0; i < N; i++) {
        p1[i] = p[k - 1][i];
        cout << p1[i] << "\t";
    }
    S[0] = tmp;
    for (int i = 1; i < N; i++)
    {
        S[i] = -1;
    }


    for (int j = 0; j < N - 1; j++)
    {
        cout << '\n' << endl;
        cout << "Step " << j + 1 << "\n";

        for (int i = 0; i < N; i++) {
            if (p[i][tmp] != 0) {
                if (p[i][tmp] < min_dist) {
                    min_dist = p[i][tmp];
                    min_el = i;
                }

            }
            p[tmp][i] = 0;
        }

        cout << "Current city: " << tmp + 1 << endl;
        cout << "Checking the row:" << endl;
        for (int i = 0; i < N; i++) {
            cout << p[i][tmp] << '\t';
        }
        cout << '\n' << endl;
        cout << "Minimum distance to another city: " << min_dist << endl;
        next_town = min_el + 1;
        cout << "Next city: " << next_town << "\t" << endl;

        tmp = min_el;
        S[j + 1] = min_el;
        Q = Q + min_dist;
        cout << "Current city crawl: " << endl;
        for (int i = 0; i < N; i++) {
            cout << S[i] + 1 << '\t';
        }
        cout << '\n' << endl;
        cout << "The length of the current city crawl: " << Q << endl;
        min_dist = 10000;
    }
    cout << "\n" << endl;
    cout << "The final cycle:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << S[i] + 1 << " \t";

    }

    Q = Q + p1[next_town - 1];
    cout << endl << "\n";

    cout << "The length of the final cycle: " << Q << endl;

}
