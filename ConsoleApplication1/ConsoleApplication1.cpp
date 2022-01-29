#include <iostream>;
#include <ctime>;
#include <math.h>
using namespace std;

void printArray(int m, int mas[]) {
	for (int i = 0; i < m / sizeof(int); i++) {
		cout << mas[i] << " ";
	}
}

int main() {
	int mas[10] = {};
	srand(time(0));
	int m = sizeof(mas);

	for (int i = 0; i < m / sizeof(int); i++) {
		mas[i] = rand() % 100 - rand() % 100;
	}
	int max = abs(mas[0]);
	int min = abs(mas[0]);
	int sum = 0;
	int mult = 1;
	int indMax = 0;
	int indMin = 0;

	for (int i = 0; i < m / sizeof(int); i++) {
		if (abs(max) < abs(mas[i])) {
			max = abs(mas[i]);
			indMax = i;
		}
		else if (abs(min) > abs(mas[i])) {
			min = abs(mas[i]);
			indMin = i;
		}

		if (mas[i] > 0)
			sum += mas[i];
	}
	

	cout << "sum: " << sum << endl;
	cout << "max: " <<max << endl;
	cout << "min: " << min << endl;
	int start = 0;
	int end = 0;
	if (indMax >= indMin) {
		start = indMin;
		end = indMax;
	}
	else
	{
		end = indMin;
		start = indMax;
	}

	for (int i = start; i <= end; i++) {
		mult *= mas[i];
	}
	cout << "multiplication: " << mult<<endl;
	printArray(m, mas);

}
