//Jakub Morawski
//26-03-2024
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#define MAX 10

inline void println() { printf("\n"); }
//int swap(int a, int b) { return b, a; }
void swap(int* x, int* y) {
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void testswap() {
	int x = 10, y = 20;
	printf("x=%d, y=%d\n", x, y);
	swap(&x, &y);
	printf("x=%d, y=%d\n", x, y);
}

void bubble_sort(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1]) { swap(&a[j], &a[j + 1]); }
		}
	}
}

void bubble_test() {
	int a[MAX];
	srand((unsigned)time(0));
	for (int i = 0; i < sizeof(a) / sizeof(*a); ++i) {
		a[i] = 9 + rand() % 100 - 9;
	}
	printf("Nieposortowane:\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d, ", a[i]);
	}
	bubble_sort(a, MAX);
	printf("\nPosortowane:\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d, ", a[i]);
	}
}

int imie_na_litere(char imie[], char litera) {
	return imie[0] == litera;
}

void testimie() {
	char* imiona[] = { "Jan", "Marek", "Zbyszek", "Dziunia" };
	char litera;
	printf("Podaj litere: ");
	litera = _getche();
	_putch('\n');
	if (!isalpha(litera) || !islower(litera)) {
		printf("Niepoprawny znak"); return;
	}

	int i = sizeof(imiona) / sizeof(imiona[0]);
	while (i--) {
		if (imie_na_litere(imiona[i], litera)) {
			printf("%s\n", imiona[i]);
		}
	}
}

void QuickSort(int tab[], int l, int r) {
	if (l < r) {
		int piv = tab[(r+l)/2];
		int i = l;
		int j = r;

		while (i <= j) {
			while (tab[i] < piv) { ++i; }
			while (tab[j] > piv) { ++j; }

			if (i <= j) {
				swap(&tab[i], &tab[j]);
				++i; --j;
			}
		}

		if (l < j) { QuickSort(tab, l, j); }
		if (r > i) { QuickSort(tab, i, r); }
	}
}

void test_quick() {
	int a[MAX];
	srand((unsigned)time(0));

	for (int i = 0; i < MAX; ++i) {
		a[i] = 9 + rand() % 100 - 9;
	}
	
	printf("Tablica przed sortowaniem:\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d, ", a[i]);
	}

	QuickSort(a, 0, MAX - 1);

	printf("Tablica po sortowaniu:\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d, ", a[i]);
	}
}