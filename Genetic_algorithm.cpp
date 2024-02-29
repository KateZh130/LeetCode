#include <iostream>
#include <ctime>
using namespace std;

const int N = 15; //encoding length
const int chisl_popul = 10; //population size
int sum_prisp[chisl_popul];
int sum_w[chisl_popul];

double doubleRand() {
	return double(rand()) / (double(RAND_MAX) + 1.0);
}

int main() 
{
	srand(time(NULL));

	double p_crossover = 0.8; //probability of crossover
	double p_mutation = 0.2; //probability of mutation

	int c[N] = { 6, 3, 13, 30, 25, 4, 2, 30, 22, 23, 3, 3, 13, 8, 14 };
	int w[N] = { 17, 15, 3, 24, 23, 4, 29, 10, 11, 26, 28, 27, 23, 27, 30 };
	int counter = 0;

	int Wmax = 118; //weight limit
	const int count = 20; //number of generations
	int sumW = 0;
	int sumC = 0;
	int population[chisl_popul][N];

	cout << "Value:" << endl;
	for (int i = 0; i < N; i++) {
		cout << c[i] << "\t";
	}

	cout << "\nWeight:" << endl;
	for (int i = 0; i < N; i++) {
		cout << w[i] << "\t";
	}
	cout << "\nMax weight = " << Wmax << endl;

	//creating encodings
	for (int i = 0; i < chisl_popul; i++) {
		for (int j = 0; j < N; j++) {
			population[i][j] = rand() % 2;

			if (population[i][j] == 1) {
				sumW = sumW + w[j];
				if (sumW > Wmax) {
					population[i][j] = 0;
					sumW = sumW - w[j];
				}
			}
		}
		sum_w[i] = sumW;
		sumW = 0;
	}
	for (int g = 0; g < count; g++) {
		cout << "\n\nStep " << g + 1 << endl;

		cout << "Current population with fitness and weight:" << endl;

		for (int i = 0; i < chisl_popul; i++) {
			for (int j = 0; j < N; j++) {
				cout << population[i][j] << "\t";
				if (population[i][j] == 1)
					sumC += c[j];
			}
			sum_prisp[i] = sumC;
			sumC = 0;
			cout << "| " << sum_prisp[i] << " | " << sum_w[i] << endl;
		}
		int max_prisp = -1;
		int best;
		for (int i = 0; i < chisl_popul; i++) {
			if (sum_prisp[i] > max_prisp)
			{
				max_prisp = sum_prisp[i];
				best = i;
			}
		}
		cout << "\nThe best individual, its fitness and weight:" << endl;
		for (int j = 0; j < N; j++)
			cout << population[best][j] << "\t";
		cout << "| " << max_prisp << " | " << sum_w[best] << endl;

		int prisp_parents[chisl_popul];

		//parent selection
		int new_population[chisl_popul][N];
		int tmp;
		for (int i = 0; i < chisl_popul; i++) {
			tmp = rand() % chisl_popul;
			for (int j = 0; j < N; j++) {
				new_population[i][j] = population[tmp][j];
			}
			prisp_parents[i] = sum_prisp[tmp];
		}

		//crossover
		const int l = 7;
		int temp[N - l];
		for (int i = 0; i < chisl_popul; i += 2) {
			int x = 0;
			if (p_crossover > doubleRand()) {
				for (int j = l; j < N; j++) {
					temp[x] = new_population[i][j];
					new_population[i][j] = new_population[i + 1][j];
					new_population[i + 1][j] = temp[x];
					x++;
				}
			}
		}
		//mutation
		for (int i = 0; i < chisl_popul; i++) {
			if (p_mutation > doubleRand()) {
				for (int j = 0; j < N; j++) {
					if (new_population[i][j] == 1) {
						new_population[i][j] = 0;
					}
					else new_population[i][j] = 1;
				}
			}
		}
		sumW = 0;
		sumC = 0;
		for (int i = 0; i < chisl_popul; i++) {
			for (int j = 0; j < N; j++) {
				if (new_population[i][j] == 1) {
					sumW = sumW + w[j];
					sumC += c[j];
					if (sumW > Wmax) {
						new_population[i][j] = 0;
						sumW = sumW - w[j];
						sumC -= c[j];
					}
				}
			}
			sum_prisp[i] = sumC;
			sumW = 0;
			sumC = 0;

		}
		//evaluating
		int summa = 0;
		for (int i = 0; i < chisl_popul; i++) {
			summa += sum_prisp[i];
		}
		for (int i = 0; i < chisl_popul; i++) {
			double p = (sum_prisp[i] + 0.0) / summa;
			double a = doubleRand();
			if (p < a) {
				for (int j = 0; j < N; j++)
					new_population[i][j] = population[i][j];
				sum_prisp[i] = prisp_parents[i];
			}
		}
		//selection
		for (int i = 0; i < chisl_popul; i += 2) {
			for (int j = l; j < N; j++)
				population[i][j] = new_population[i][j];
		}
	}
}
