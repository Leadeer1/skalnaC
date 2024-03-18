//Jakub Morawski
//12-03-2024

#include <stdio.h>
#include <stdlib.h> //uzywamy do liczb ps.los.
#include <time.h> //czas

//zad1
int div3or5(int x) {
	return (x % 3 == 0) || (x % 5 == 0);
}

//zad2 - obliczanie sumy i œredniej z liczb podz przez 3 lub 5
void sum_avg_n() {
	int n, sum = 0, count = 0; //sum - suma liczb, count - licznik podzielnych
	printf("podaj n: ");
	if (scanf_s("%d", &n) < 1 || n < 1) {
		printf("Bledne dane!");
		return;
	}
	srand((unsigned)time(0)); //wziecie czasu z systemu - inicjalizacja generatora PRNG
	for (int i = 0; i < n; ++i) {
		int x = 9 + rand() % (1000 - 9 + 1);
		//printf("%d, ", x);
		if (div3or5(x)) {
			sum += x; ++count; printf("[%d]\n", x);
		}
		else printf("%d\n", x);
	}
	printf("Suma wynosi: %d\nSrednia wynosi: %f\n", sum, (float)sum / count);
}

//zad3
int if_pow2(unsigned int x) {
	unsigned int i = 0, y;
	while ((y = 1 << i++) < x) {}
	return x == y;
}

void test_if_pow2() {
	int n = 1000;
	for (int i = 0; i < 100000; ++i) {
		if (if_pow2(i)) { printf("[%d]\n", i); }
		//else { printf("%d\n", i); }
	}
	/*unsigned int x = 14, y = 32;
	printf("%u %d\n %u %d\n",
		x, if_pow2(x),
		y, if_pow2(y));*/
}

//zad4
void monte(unsigned n) {
	if (scanf_s("%u", &n) < 1 || n < 1) {
		return;
	}
	srand((unsigned)time(0));
	int m = 0;
	float x = 0.0, y = 0.0;
	for (unsigned int i = 0; i < n; ++i) {
		x = (float)rand() / RAND_MAX;
		y = (float)rand() / RAND_MAX;
		if (x * x + y * y <= 1) { ++m; }
	}
	printf("%f", 4 * (float)m / n);
}

//zad5
void random_nums(){
	int n = 1;
	printf("Podaj liczbe danych wejsciowych: ");
	if (scanf_s("%d", &n) < 1 || n < 1) {
		printf("Bledne dane");
		return;
	}
	srand((unsigned)time(0));
	float num = 0.0, sum = 0.0, avg = 0.0, max = 0.0, min = 0.0;
	int count = 0;
	int b = 1;
	for (int i = 0; i < n; ++i) {
		num = rand() % (100 + 1) - 50; //przesuwam zakres losowania na [-50;50]
		if (num > 0) {
			sum += num;
			if (b) {
				max = num; min = num; b = 0;
			}
			if (max < num) { max = num; }
			if (min > num) { min = num; }
			++count;
		}

	}
	avg = sum / count;
	printf("Suma to: %f\nSrednia to: %f\nMax to: %f\nMin to: %f\n", sum, avg, max, min);
}
