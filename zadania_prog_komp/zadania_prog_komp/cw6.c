//Jakub Morawski
//09-04-2024
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include"cw5.h"

typedef long long int llint;

void selectionsort(int a[], int n) {
	for (int i = 0; i < n-1; ++i) {
		int k = i;
		for (int j = i + 1; j < n; ++j){
			if (a[j] < a[k]) { k = j; }

		}
		if (i != k) { swap(&a[i], &a[k]); }
	}
}

llint factorial(int n) {
	if (n <= 1) { return 1; }
	return n * factorial(n - 1);
}

void factorial_test() {
	for (int i = 0; i <= 20; ++i) {
		printf("%d! = %lld\n", i, factorial(i));
	}
}

int nwd(int a, int b) {
	//if (b == 0) return a;
	//return nwd(b, a % b);
	return b == 0 ? a : nwd(b, a % b);
}

void nwd_test() {
	/*int a, b;
	printf("Podaj 2 liczby: ");
	if (scanf_s("%d%d", &a, &b) != 2) {
		printf("bledne dane!");
		return;
	}*/
	srand((unsigned int)time(0));
	for (int i = 0; i < 10; ++i) {
		int a = rand() % 248 + 3;
		int b = rand() % 148 + 3;
		printf("nwd(%d, %d) = %d\n", a, b, nwd(a, b));
	}
	
}

void szachy() {
	int tab[10][10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 9; ++j) {
			tab[i][j] = (i + j) % 2;
			printf("[%d]", tab[i][j]);
		}
		printf("\n");
	}
}