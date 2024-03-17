//----------sekcja dokumentacji----------
//Jakub Morawski
//cw. 27-02-2024

//----------sekcja dyrektyw preprocesora----------
#include<stdio.h> //dyrektywa preprocesora - dolaczenie biblioteki stdio.h
#include<stdlib.h>
#include <math.h>

//----------sekcja deklaracji globalnych----------
//void cw1_zad1(); //prototyp funkcji w sekcji deklaracji globalnych
//void cw1_zad2();
//void cw1_zad3();
//void cw1_zad4();
//int max3(int a, int b, int c);
//void cw1_zad5();

//----------sekcja main----------
//int main() {
	//cw1_zad1();
	//cw1_zad2();
	//cw1_zad3();
	//cw1_zad4();
	//cw1_zad5();
//}

//----------sekcja podprogramów----------

//wypisz hello world
void cw1_zad1() {
	//wypisz hello world
	printf("Hello world!!!\n");
}

//wczytaj z stdin date urodzenia i wypisuje rok urodzenia. format daty DD/MM/YYYY
void cw1_zad2() {
	unsigned int day, month, year;
	printf("Podaj swoja date urodzenia (DD/MM/YYYY): ");
	if (scanf_s("%u/%u/%u", &day, &month, &year) < 3 || (year < 1900 && year>2023)) {
		printf("Niepoprawne dane");
		return;
	}
	printf("Urodzilxs sie w roku %u\n", year);

}

//czyta imie i nazwisko a potem wypisuje "witaj" oraz podane imie i nazwisko
void cw1_zad3() {
	char s[70] = ""; //inicjowanie pustym napisem
	printf("Podaj swoje imie i naziwsko: ");
	// jednak nie scanf_s("%s %s",)
	fgets(s, sizeof(s), stdin);
	printf("Witaj %s\n", s);
}

//czyta ze standardowego i/o trzy liczby calkowite i wypisuje najwieksza z nich
int max3(int a, int b, int c) {
	int m = a;
	if (m < b) { m = b; }
	if (m < c) { m = c; }
	return m;
}
void cw1_zad4() {
	int a, b, c;
	printf("Podaj trzy liczby: ");
	if (scanf_s("%d %d %d", &a, &b, &c) < 3) {
		printf("Niepoprawne dane!");
		return;
	}
	printf("max(%d,%d,%d) = %d", a, b, c, max3(a, b, c));
}

const char* wzrost_val(float wzrost) {
	if (wzrost > 180) {
		return "wzrost wysoki";
	}
	if (wzrost > 160) {
		return "wzrost sredni";
	}
	return "wzrost niski";
}

//zad5
void cw1_zad5() {
	float wzrost = 0.0f;
	printf("Podaj wzrost: ");
	if (scanf_s("%f", &wzrost) < 1 || wzrost > 300) {
		printf("niepoprawne dane!");
		return;
	}
	printf("%s", wzrost_val(wzrost));
}



/*zad6 Zadanie 6. Napisz funkcj²e, która ze standardowego wej´scia czyta kolejno imi²e, p³e´c, wiek i wzrost
osoby, a nast²epnie wypisuje odpowiednio informacje o tej osobie.Przyk³adowe wej´scie i wyj´scie :
Wej±cie:
Jan
M
55
70.8
Wyj±cie :
	Witaj Jan, jestes mezczyzna w wieku 55 lat i masz wzrost sredni*/

void cw1_zad6() {
	char imie[20] = "";
	char plec = "";
	int wiek = 0;
	float wzrost = 0.0;
	printf("Podaj imie, plec, wiek, wzrost\n");
	if (scanf_s("%s %c %d %f", &imie, 20, &plec, 1, &wiek, &wzrost) != 4) {
		printf("B³êdne dane\n");
		return;
	}
	const char* s1 = plec == 'K' ? "kobieta" : "mezczyzna";
	const char* s2 = wzrost_val(wzrost);
	printf("Witaj %s, jestes %s w wieku %d lat i masz %s", imie, s1, wiek, s2);
}

void cw1_dom1() {
	struct Data {
		int d;
		int m;
		int y;
	};
	struct Data data1, data2;
	printf("Podaj dwie daty w formacie dd/mm/yyyy dd/mm/yyyy");
	if (scanf_s("%d/%d/%d %d/%d/%d", &data1.d, &data1.m, &data1.y, &data2.d, &data2.m, &data2.y) < 6) {
		printf("Bledne dane");
		return;
	}
	int war_y = data1.y > data2.y;
	int war_m = (data1.y == data2.y && data1.m > data2.m);
	int war_d = (data1.y == data2.y && data1.m == data2.m && data1.d > data2.d);
	if (war_y || war_m || war_d) {
		printf("Data %02d/%02d/%d jest wczesniejsza niz data %02d/%02d/%d", data1.d, data1.m, data1.y, data2.d, data2.m, data2.y);
	}
	else {
		printf("Data %02d/%02d/%d jest wczesniejsza niz data %02d/%02d/%d", data2.d, data2.m, data2.y, data1.d, data1.m, data1.y);
	}
}

void trojmian(float a, float b, float c) {
	double delta = b * b - 4 * a * c;

	if (delta > 0) {
		double x1 = (-b + sqrt(delta)) / (2 * a);
		double x2 = (-b - sqrt(delta)) / (2 * a);
		printf("x1 = %.21f, x2 = %.21f",x1,x2);
		return;
	}
	if (delta == 0) {
		double x0 = -b / (2 * a);
		printf("x0 = %.21f", x0);
		return;
	}
	else {
		double re = -b / (2 * a);
		double im = sqrt(-delta);
		printf("x1 = %.21f + %.21fi, x2 = %.21f - %.21fi", re, im, re, im);
		return;
	}
}

void cw1_dom2() {
	double a, b, c;
	printf("Podaj wspolczynniki wielomianu: (a b c): ");
	if (scanf_s("%lf %lf %lf", &a, &b, &c) < 3) {
		printf("Bledne dane");
		return;
	}
	trojmian(a, b, c);
}