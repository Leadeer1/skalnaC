//Jakub Morawski
//19-03-2024
#define _USE_MATH_DEFINES
#define EPS 1.0E-5 //makrodefinicja sta³ej
#include <stdio.h>
#include<math.h>
#include<ctype.h>
//#include <stdlib.h> 
//#include <time.h>

//int n,
//liczenie liczby pi ze wzoru Viete'a
double pieviete(int n) {
	double pi_val = 2.0f;
	double a = sqrt(2);
	while (--n) {
		pi_val *= 2 / a;
		a = sqrt(2 + a);
	}
	return pi_val;

}
//oblicza sume cyfr liczby
int sumofdigits(unsigned int a) {
	int s = 0;
	while (a) {
		s += a % 10;
		a /= 10;
	}
	return s;
}

//double fastroot(double x) {
//	double s = 1;
//	while (s * s < x) {
//		++s;
//	}
//	printf("x = %f", x);
//}

void test_pi() {
	int n;
	printf("Podaj dokladnosc obliczen: ");
	if (scanf_s("%d", &n) != 1) {
		printf("Bledne dane");
		return;
	}
	for (int i = 1; i < n; ++i) {
		printf("%.50f\n", pieviete(i));
	}
}

void test_sum() {
	int a[] = { 78, 34, 123, 678, 34, 567, 1023, 5869, 5, 435, 546, 666, 999 };
	int n = sizeof(a) / sizeof(*a);
	//printf("n = %d", n);
	for (int i = 0; i < n; ++i) {
		printf("suma cyfr liczby %d: %d\n", a[i], sumofdigits(a[i]));
	}
}

double fastsqrt(double x) {
	double s1 = 1;
	double s2 = 1;
	do {
		s1 = s2;
		s2 = (s1 + x / s1) / 2;
		printf("%f\n", s2);
	} while (abs(s1 - s2) >= EPS);
	return s2;
}

void testroot() {
	double x = 45; //6,708
	double root = fastsqrt(x);
	printf("%f", root);
}

int one(int liczba) {
	while (liczba != 0) {
		if ((liczba & 1) != 1) // Sprawdzamy, czy ostatni bit jest równy 1
			return 0; // Jeœli nie, to liczba nie ma samych jedynek
		liczba >>= 1; // Przesuwamy bity w prawo
	}
	return 1; // Jeœli przeszliœmy przez wszystkie bity i s¹ same jedynki, zwracamy 1
}
//num = (num<<1)|1;

void numbersbin111() {
	unsigned int num = 1;
	unsigned int max_num;

	printf("Wpisz do której liczby chcesz sprawdziæ, czy liczby sk³adaj¹ siê z samych jedynek: ");
	scanf_s("%d", &max_num);
	printf("Liczby z samymi jedynkami w bitach:\n");

	while (num != 0 && num <= max_num) {
		if (one(num)) { printf("%u\n", num); }
	}
}

unsigned int digitsqrt(unsigned int a) {
	while (a >= 10) {
		a = sumofdigits(a);
	}
	return a;
}

// Funkcja zliczaj¹ca liczbê du¿ych liter w zdaniu
int zdanie(char* s) {
	int count = 0;
	while (*s) {
		if (isupper(*s))
			count++;
		s++; 
	}
	return count;
}

// Funkcja testuj¹ca funkcjê zdanie
void test_zdanie() {
	char z[100];
	printf("Podaj zdanie: ");
	gets_s(z, sizeof(z)); // Wczytujemy zdanie ze standardowego wejœcia
	int bigboys = zdanie(z); // Obliczamy liczbê du¿ych liter w zdaniu
	printf("Liczba duzych liter w zdaniu: %d\n", bigboys);
}
