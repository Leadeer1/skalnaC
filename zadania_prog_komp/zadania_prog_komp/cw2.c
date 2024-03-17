//Jakub Morawski
//05-03-2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cw2_zad1() {
	int a, b;
	printf("Podaj dwie liczby: ");
	if (scanf_s("%d%d", &a, &b) < 2 || a < 0 || b < 0) {
		printf("Bledne dane!");
		return;
	}
	/*if (a == b) {
		printf("Pole kwadratu o bokach %dx%d wynosi %d", a, b, a * b);
	}
	else {
		printf("Pole prostokata o bokach %dx%d wynosi %d", a, b, a * b);
	}*/
	char* s = a == b ? "kwadratu" : "prostokata";
	printf("Pole %s o bokach %d %d wynosi %d\n", s, a, b, a * b);
}

void cw2_zad2() {
	int a, b, c;
	printf("Podaj trzy dlugosci odcinka: ");
	if (scanf_s("%d%d%d", &a, &b, &c) < 3 || a < 0 || b < 0 || c < 0) {
		printf("Bledne dane!");
		return;
	}
	char* s = " nie";
	if (a + b > c && a + c > b && b + c > a) s = "";
	printf("Trojkat o bokach %d,%d,%d,%s istnieje", a, b, c, s);
}

void cw2_zad3() {
	float wzrost;
	printf("Podaj wzrost: ");
	if (scanf_s("%f", &wzrost) < 1) {
		printf("Bledne dane");
		return;
	}
	char* s;
	s = (wzrost < 160) ? "niski" : ((160 <= wzrost < 180) ? "sredni" : "wysoki");
	printf("wzrost %s", s);
}

void cw2_zad4() {
	char znak;
	float a, b;
	printf("Podaj dzialanie matematyczne w formacie [liczba] [znak] [liczba] (dostepne znaki: +,-,*,/): ");
	if (scanf_s("%f %c %f", &a, &znak, 1, &b) < 3) {
		printf("Bledne dane");
		return;
	}
	//unsigned int znak_int = (unsigned int)sizeof(znak);
	switch (znak) {
	case '+':
		printf("a %c b = %f", znak,a+b);
		break;
	case '-':
		printf("a %c b = %f", znak, a - b);
		break;
	case '*':
		printf("a %c b = %f", znak, a * b);
		break;
	case '/':
		if (b == 0) { printf("Nie da sie dzielic przez zero!"); break; }
		printf("a %c b = %f", znak, a / b);
		break;
	default:
		printf("Bledny znak");
	}

}

void  cw2_zad5() {
	int n = 1;
	printf("Podaj liczbe danych wejsciowych: ");
	if (scanf_s("%d",&n) < 1 || n < 1) {
		printf("Bledne dane");
		return;
	}
	printf("Podaj te liczby oddzielaj¹c je klawiszem enter\n");
	float num = 0.0, sum = 0.0, avg = 0.0, max=0.0, min=0.0;
	for (int i = 0; i < n; ++i) {
		printf("Podaj %d liczbe: ", i+1);
		while((scanf_s("%f",&num) < 1) ){
			printf("Podano zly format liczby lub nie wprowadzono jej wcale. Wprowadz liczbe ponownie: ");
		}
		sum += num;
		if (i == 0) {
			max = num; min = num;
		}
		if (max < num) { max = num; }
		if (min > num) { min = num; }

	}
	avg = sum / n;
	printf("Suma to: %f\nSrednia to: %f\nMax to: %f\nMin to: %f\n", sum, avg, max, min);
}

void cw2_zad6() {
	srand((unsigned)time(0));
	int n = rand() % 1001;
	int t, proby=0;
	do {
		printf("Zgadnij liczbe ktora wylosowal komputer: ");
		while (scanf_s("%d",&t)<1) {
			printf("Podano zly format liczby lub nie wprowadzono jej wcale. Wprowadz liczbe ponownie: ");
		}
		++proby;
		
		if (t == n) {
			printf("Zgadles\nLiczba zgadnieta po %d probie\n", proby);
		}
		else {
			if (t < n) {
				printf("Za malo\n");
			}
			else {
				printf("Za duzo");
			}
		}
	} while (n != t);
}

void cw2_zad7() {
	printf("Podaj slowo i litere w nim zawarta (format: [slowo],[litera]): ");
	char slowo[100]="", litera;
	if (scanf_s("%99[^,], %c",&slowo,100, &litera,1) < 2) {
		printf("Bledne dane");
		return;
	}

	int pozycja = -1;
	for (int i = 0; slowo[i] != '\0'; i++) {
		if (slowo[i] == litera) {
			pozycja = i + 1; 
			break;
		}
	}
	if (pozycja != -1) {
		printf("%d\n", pozycja);
	}
	else {
		printf("Podana litera nie wystepuje w slowie");
	}
}

void pd_cw2() {
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
		num = rand()%(100+1)-50; //przesuwam zakres losowania na [-50;50]
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