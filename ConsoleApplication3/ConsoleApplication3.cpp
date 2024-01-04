#include <iostream>
#include<cmath>
#include<string>
#include <locale.h>
#include <cstdlib>
#define PI 3.14
using namespace std;
void mainpage();
void initMenuLanguage();
void initMenuDecision();
void initMenuDecisionAng();
void MenuDecision(char,double);
void MenuDecisionAng();
int main()
{
	char zn = 'T';
	setlocale(LC_CTYPE, "Polish");
	mainpage();
	do
	{
		system("cls");
		initMenuLanguage();
		char wyborjezyka;
		cin >> wyborjezyka;
		if (wyborjezyka == '1')
		{
			system("cls");
			initMenuDecision();
			char wybor='0';
			cin >> wybor;
			MenuDecision(wybor);
		}
		else if (wyborjezyka == '2')
		{
			system("cls");
			initMenuDecisionAng();
			int wyborAng;
			cin >> wyborAng;
			MenuDecisionAng();// Tutaj przekazuję 0 jako argumenty, bo wartości nie są jeszcze zdefiniowane
		}
		if (wyborjezyka != '1' && wyborjezyka != '2')
		{
			system("cls");
			cout << "Wybrałeś nie odpowiednią sygnaturę. You choose the wrong key." << endl;

		}
		do
		{
			cout << "Czy chcesz kontynuować? Do you want to continue?" << endl;
			cout << "T-true / F-false" << endl;
			cin >> zn;
			system("cls");
		} while (zn != 't' && zn != 'T' && zn != 'f' && zn != 'F');
		system("cls");
	} while (zn == 'T' || zn == 't');
	return 0;
}
void mainpage()
{
	char a;
	system("COLOR 2B");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << '\t' << '\t'
		<< '\t' << "Hello on the math website where are maths formulas! How can I help you?" << endl;
	cout << '\t' << '\t' << '\t' << "Witaj na stronie zbioru wzorów matematycznych! W czym moge ci pomóc?" << endl;
	cout << '\t' << '\t' << '\t' << "Czy chcesz kontynuować? Jeśli tak nacisnij dowolny klawisz i naciśnij enter." << endl;
	cout << '\t' << '\t' << '\t' << "Do you want to continue? If yes, press any key and enter" << endl;
	cin >> a;
	cin.ignore(1023, '\n');
}
void initMenuLanguage()
{
	cout << "Wybierz język:" << '\t' << "Choose the language:" << endl;
	cout << "1. Polski" << endl;
	cout << "2. Angielski" << endl;
}
void initMenuDecision()
{
	cout << "Wybierz który dział chcesz wykorzystać:" << endl;
	cout << "1. Kwadrat" << endl;
	cout << "2. Prostokąt" << endl;
	cout << "3. Trójkąt" << endl;
	cout << "4. Koło" << endl;
	cout << "5. Romb" << endl;
	cout << "6. Równoległobok" << endl;
	cout << "7. Stożek" << endl;
	cout << "8. Walec" << endl;
	cout << "9. Sześcian" << endl;
	cout << "10. Prostopadłościan" << endl;
	cout << "11. Kalkulator" << endl;
	cout << "12. Średnia arytmetyczna" << endl;

}
void MenuDecision(char wybor)
{
	
	double a = 0;
		double b, c, h, r, n, Pp, H, l, e, f, pole, obwod, Pb, V, Pc, przekatna1, przekatna2, bok, przekatna;
	
	switch (wybor)
	{
	case '1':
	{
		system("cls");
		cout << "Podaj bok kwadratu: " << endl;
		cin >> a;
		system("cls");
		pole = a * a;
		przekatna = a * sqrt(2);
		obwod = 4 * a;
		cout << "Oto wszystkie wzory dotyczące kwadratu dla a= " << a << ": " << endl;
		cout << "Pole=a*a= " << pole << endl << "Przekatna kwadratu =a * pierwiastekz2 " << przekatna << endl << "Obwod=a+a+a+a= " << obwod << endl;
		break;
	}
	case '2':
	{
		system("cls");
		cout << "Podaj szerokość prostokąta: " << endl;
		cin >> a;
		cout << "Podaj wysokość prostokąta: " << endl;
		cin >> b;
		system("cls");
		pole = a * b;
		obwod = 2 * a + 2 * b;
		cout << "Oto wszytskie wzory dotyczące prostokąta: " << endl;
		cout << " Pole= " << pole << endl << "Obwod= " << obwod << endl;
		break;
	}
	case '3':
	{
		cout << "Podaj podstawe trójkąta (znajdującego sie w podstawie graniastosłupa) na którą pada wysokość: " << endl;
	cin >> a;
	cout << "Podaj reszte boków trójkąta b= "<< endl;
	cin >> b;
	cout << "c= " <<  endl;
	cin >> c;
	cout << "Podaj wysokość trójkąta (znjadującego sie w podstawie graniastosłupa): " << endl;
	cin >> h;
	break;
	}
	case '4':
	{cout << "Podaj promień koła: " << endl;
		cin >> r;
	pole = PI * r * r;
	obwod = 2 * PI * r;
	cout << "Pole twojego okręgu wynosi= PI * r * r= " << pole << endl;
		cout<<"Obwód wynosi= 2 * PI * r= " << obwod << endl;
	break;
	}
	case '5':
	{
	cout << "Podaj bok rombu: " << endl;
	cin >> bok;
	cout << "Podaj przekątna a: " << endl;
	cin >> e;
		cout << "Podaj przekątną b: " << endl;
	cin >> f;
	pole = (e * f) / 2;
	obwod = 4 * bok;
	cout << "Pole tego rombu wynosi=(e*f)/2= " << pole << endl;
	cout << "Obwód tego rombu wynosi= a+a+a+a= " << obwod << endl;
	break;
	}
	case '6':
	{cout << "Podaj podstawe równoległoboku: "  << endl;
	cin >> a;
	cout << "Podaj wysokość równoległoboku: "<< endl;
	cin >> h;
	cout << "Podaj ramię równoległoboku: " << endl;
	cin >> b;
	pole = a * h;
	obwod = 2 * a + 2 * b;
		cout << "Pole tego równoległoboku wynosi=a*h= " << pole << endl;
	cout << "Obwód tego równoległoboku wynosi= a+a+b+b= " << obwod << endl;
	break;
	}
	case '7':
	{cout << "Podaj promień podstawy stożka: " << endl;
	cin >> r;
	cout << "Podaj tworzącą stożej: " << endl;
	cin >> l;
	cout << "Podaj wysokość stożka: " << endl;
	cin >> H;
	Pb = PI * r * l;
	Pc = PI * r * (r + l);
	V = (PI * r * r * H) / 3;
	cout << "Pole boczne wynosi = PI * r * l= " << Pb << endl;
	cout << "Pole całkowite wynosi = PI * r * (r + l)= " << Pc << endl;
	cout << "Objętość wynosi = (PI * r * r * H) / 3= " << V << endl;
	break;

	}
	case '8':
	{
		cout << "Podaj promień podstawy walca: " << endl;
		cin >> r;
		cout << "Podaj wysokość walca: " << endl;
		cin >> H;
		Pb = 2 * PI * r * H;
		Pc = 2 * PI * r * (r + H);
		V = PI * r * r * H;
		cout << "Pole boczne wynosi = 2*PI * r * H= " << Pb << endl;
		cout << "Pole całkowite wynosi = 2*PI * r * (r + H)= " << Pc << endl;
		cout << "Objętość wynosi = PI * r * r * H= " << V << endl;
		break;

	}
	case '9':
	{
		cout << "Podaj bok sześcianu: " << endl;
		cin >> a;
		Pb = 4 * a * a;
		Pc = 6 * a * a;
		V = a * a * a;
		cout << "Pole boczne wynosi =4*a*a = " << Pb << endl; 
			cout << "Pole całkowite wynosi = 6*a*a= " << Pc << endl;
		cout << "Objętość wynosi = a*a*a= " << V << endl;
		break;

	}

	case '10':
	{cout << "Co ten pratopodłośćian ma w podstawie? " << endl;
	cout << "1.Kwadrat" << endl;
	cout << "2.Prostokąt" << endl;
	cout << "3. Trójkąt" << endl;
	cout << "4. Trapez" << endl;
	cout << "5. Równoległobok" << endl;
	cout << "6.Romb" << endl;
	int wyb;
	cin >> wyb;
	if (wyb == 1)
	{
		cout << "Podaj jeden z boków podstawy: "  << endl;
		cin >> a;
		cout << "Podaj wysokość tego graniastusłupa: " << endl;
		cin >> H;
		V = a * a * H;
		Pb = 4 * a * H;
			Pc = a * a * 2 + a * H * 4;
		cout << "Pole boczne wynosi =4*a*H = " << Pb << endl; 
			cout << "Pole całkowite wynosi = 2*a*a+4*a*H= " << Pc << endl;
		cout << "Objętość wynosi = a*a*H= " << V << endl;

	}
	else if (wyb == 2)
	{
		
		cout << "Podaj jeden z boków podstawy: "  << endl;
		cin >> a;
		cout<<"Podaj drugi bok podstawy: " << endl;
		cin >> b;
		cout << "Podaj wysokość tego graniastusłupa: " << endl;
		cin >> H;
		V = a * b * H;
		Pb = 2 * a * H + 2 * b * H;
			Pc = a * b * 2 + a * H * 2 + b * H * 2;
		cout << "Pole boczne wynosi =2 * a * H + 2 *b * H = " << Pb << endl;
		cout << "Pole całkowite wynosi = a * b * 2 + a * H * 2+ b * H * 2= " << Pc << endl;
		cout << "Objętość wynosi = a*b*H= " << V << endl;

	}
	else if (wyb == 3)
	{
		cout << "Podaj podstawe trójkąta (znajdującego sie w podstawie graniastosłupa) na którą pada wysokość: " << endl;
		cin >> a;
		cout << "Podaj reszte boków trójkąta b= "  << endl;
		cin >> b;
		cout << "c = "  << endl;
		cin >> c;
		cout << "Podaj wysokość trójkąta (znjadującego sie w podstawie graniastosłupa): " << endl;
		cin >> h;
		cout << "Podaj wysokość całego graniastosłupa: "  << endl;
		cin >> H;
		V = ((a * h / 2)) * H ;
		Pb = a * H + b * H + c * H;
		Pc = 2 * ((a * h / 2) + a * H + b * H + c * H) ;
		cout << "Pole boczne wynosi =a * H + b * H + c * H = " << Pb << endl;
		cout << "Pole całkowite wynosi = 2 * ((a * h / 2) + a * H + b * H + c * H= " << Pc << endl;
		cout << "Objętość wynosi =((a * h / 2) * H= " << V << endl;

	}
	else if (wyb == 4)
	{
		cout << "Podaj podstawy trapeza zawartego w podstawie graniastosłupa:a= "  << endl;
		cin >> a;
		cout << "b= "  << endl;
		cin >> b;
		cout << "Podaj ramiona trapezu: "  << endl;
		cin >> c;
		cout << "Podaj wysokość trapezu (znjadującego sie w podstawie graniastosłupa): "  << endl;
		cin >> h;
		cout << "Podaj wysokość całego graniastosłupa: "  << endl;
		cin >> H;
		V = (((a + b) * h) / 2) * H;
		Pb = a * H + b * H + 2 * c * H;
		Pc = (((a + b) * h) / 2) + a * H + b * H + 2 * c * H;
		cout << "Pole boczne wynosi =a * H + b * H + 2*c * H = " << Pb << endl;
		cout << "Pole całkowite wynosi = (((a + b) * h) / 2)+ a * H + b * H + 2 * c * H= " << Pc << endl;
		cout << "Objętość wynosi =(((a +b)* h) / 2) * H= " << V << endl;

	}
	else if (wyb == 5)
	{
		cout << "Podaj podstawy trapeza zawartego w podstawie graniastosłupa:a= "  << endl;
		cin >> a;
		cout << "Podaj ramiona równoległoboku: b= " << endl;
			cin>>b;
		cout << "Podaj wysokość równoległoboku (znjadującego sie w podstawie graniastosłupa): "  << endl;
		cin >> h;
		cout << "Podaj wysokość całego graniastosłupa: "  << endl;
		cin >> H;
		V = a * h * H;
		Pb = 2 * a * H + 2 * b * H;
		Pc = 2 * a * h + 2 * a * H + 2 * b * H;
		cout << "Pole boczne wynosi =2 * a * H + 2 * b * H= " << Pb << endl;
		cout << "Pole całkowite wynosi = 2 * a * h + 2 * a * H + 2 * b * H= " << Pc << endl;
		cout << "Objętość wynosi =a * h * H= " << V << endl;
	}
	else if (wyb == 6)
	{
		cout << "Podaj bok rombu: "  << endl;
		cin >> a;
		cout << "Podaj pierwsza przekatna rombu: "  << endl;
		cin >> e;
		cout << "Podaj druga przekatna: "  << endl;
		cin >> f;
		V = ((e * f) / 2) * H;
		Pb = 4 * a * H;
		Pc = 2 * ((e * f) / 2) + 4 * a * H;
		cout << "Pole boczne wynosi = 4 * a * H= " << Pb << endl;
		cout << "Pole całkowite wynosi = 2 * ((e * f) / 2) + 4 * a * H= " << Pc << endl;
		cout << "Objętość wynosi =((e * f) / 2) * H= " << V << endl;
	}
	else
	{
		cout << "Podałeś niewłaściwy numer :(";
	}
	break;
	}
	case '11':
	{
		cout << "Menu:\n"
			<< "1) Dodawanie\n"
			<< "2) Odejmowanie\n"
			<< "3) Mnożenie\n"
			<< "4) Dzielenie\n"
			<< "> Twój wybór: ";
		int choice;
		cin >> choice;
		float x, y;
		if (choice == 1)
		{
			cout << "Liczenie sumy (a + b).\n";
			cout<< "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a + b wynosi " << (x + y);
		}
		else if (choice == 2)
		{
			cout << "Liczenie różnicy (a - b).\n";
			cout	<< "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a - b wynosi " << (x- y);
		}
		else if (choice == 3)
		{
			cout << "Liczenie iloczynu (a * b).\n";
			cout	<< "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a * b wynosi " << (x * y);
		}
		else if (choice == 4)
		{
			cout << "Liczenie ilorazu (a / b).\n";
				cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			if (y == 0)
				cout << "Nie można dzielić przez 0!";
			else
				cout << "a / b wynosi " << (x / y);
		}
		else
			cout << "Nieprawidłowa opcja: " << choice;
		break;
	}
		case '12':
		{
			int z, g;
			double w = 0.0;
			cin >> g;

			for (int i = 0; i < n; i++)
			{
				cin >> z;
				w += z;
			}
			cout << w / g;	
			break;	
		}
		

		default:
		{
			cout << "Niestety ale wybrałeś zły numerek, który znajduje się poza listą :(" << endl;
			break;
		}
		
		}

}

void initMenuDecisionAng()
{
	cout << "Choose the topic: " << endl;
	cout << "1. Kwadrat" << endl;
	cout << "2. Prostokąt" << endl;
	cout << "3. Trójkąt" << endl;
	cout << "4. Koło" << endl;
	cout << "5. Romb" << endl;
	cout << "6. Równoległobok" << endl;
	cout << "7. Stożek" << endl;
	cout << "8. Walec" << endl;
	cout << "9. Sześcian" << endl;
	cout << "10. Prostopadłościan" << endl;
	cout << "11. Ostrosłup" << endl;
	cout << "12. Ciąg geometryczny" << endl;
	cout << "13. Ciąg Arytmetyczny" << endl;
	cout << "14. Kalkulator" << endl;
	cout << "15. Wzory skróconego mnożenia" << endl;
	cout << "16. Trygonometria" << endl;
	cout << "17. Średnia arytmetyczna" << endl;


}
void MenuDecisionAng()
{
	char wyborAng{};
	double a, b, c, h, r, n, Pp, H, l, e, f, pole, obwod, Pb, V, Pc, przekatna1, przekatna2, bok, przekatna;

	switch (wyborAng)
	{
	case '1':
	{
		system("cls");
		cout << "Podaj bok kwadratu: " << endl;
		cin >> a;
		system("cls");
		pole = a * a;
		przekatna = a * sqrt(2);
		obwod = 4 * a;
		cout << "Oto wszystkie wzory dotyczące kwadratu dla a= " << a << ": " << endl;
		cout << "Pole=a*a= " << pole << endl << "Przekatna kwadratu =a * pierwiastekz2 " << przekatna << endl << "Obwod=a+a+a+a= " << obwod << endl;
		break;
	}
	case '2':
	{
		system("cls");
		cout << "Podaj szerokość prostokąta: " << endl;
		cin >> a;
		cout << "Podaj wysokość prostokąta: " << endl;
		cin >> b;
		system("cls");
		pole = a * b;
		obwod = 2 * a + 2 * b;
		cout << "Oto wszytskie wzory dotyczące prostokąta: " << endl;
		cout << " Pole= " << pole << endl << "Obwod= " << obwod << endl;
		break;
	}
	case '3':
	{cout << "Podaj podstawe trójkąta (znajdującego sie w podstawie graniastosłupa) na którą pada wysokość: " << a << endl;
	cout << "Podaj reszte boków trójkąta b= " << endl;
	cin >> b;
	cout << "c= " << endl;
	cin >> c;
	cout << "Podaj wysokość trójkąta (znjadującego sie w podstawie graniastosłupa): " << endl;
	cin >> h;
	break;
	}
	case '4':
	{cout << "Podaj promień koła: " << endl;
	cin >> r;
	pole = PI * r * r;
	obwod = 2 * PI * r;
	cout << "Pole twojego okręgu wynosi= PI * r * r= " << pole << endl;
	cout << "Obwód wynosi= 2 * PI * r= " << obwod << endl;
	break;
	}
	case '5':
	{
		cout << "Podaj bok rombu: " << endl;
		cin >> bok;
		cout << "Podaj przekątna a: " << endl;
		cin >> e;
		cout << "Podaj przekątną b: " << endl;
		cin >> f;
		pole = (e * f) / 2;
		obwod = 4 * bok;
		cout << "Pole tego rombu wynosi=(e*f)/2= " << pole << endl;
		cout << "Obwód tego rombu wynosi= a+a+a+a= " << obwod << endl;
		break;
	}
	case '6':
	{cout << "Podaj podstawe równoległoboku: " << endl;
	cin >> a;
	cout << "Podaj wysokość równoległoboku: " << endl;
	cin >> h;
	cout << "Podaj ramię równoległoboku: " << endl;
	cin >> b;
	pole = a * h;
	obwod = 2 * a + 2 * b;
	cout << "Pole tego równoległoboku wynosi=a*h= " << pole << endl;
	cout << "Obwód tego równoległoboku wynosi= a+a+b+b= " << obwod << endl;
	break;
	}
	case '7':
	{cout << "Podaj promień podstawy stożka: " << endl;
	cin >> r;
	cout << "Podaj tworzącą stożej: " << endl;
	cin >> l;
	cout << "Podaj wysokość stożka: " << endl;
	cin >> H;
	Pb = PI * r * l;
	Pc = PI * r * (r + l);
	V = (PI * r * r * H) / 3;
	cout << "Pole boczne wynosi = PI * r * l= " << Pb << endl;
	cout << "Pole całkowite wynosi = PI * r * (r + l)= " << Pc << endl;
	cout << "Objętość wynosi = (PI * r * r * H) / 3= " << V << endl;
	break;

	}
	case '8':
	{
		cout << "Podaj promień podstawy walca: " << endl;
		cin >> r;
		cout << "Podaj wysokość walca: " << endl;
		cin >> H;
		Pb = 2 * PI * r * H;
		Pc = 2 * PI * r * (r + H);
		V = PI * r * r * H;
		cout << "Pole boczne wynosi = 2*PI * r * H= " << Pb << endl;
		cout << "Pole całkowite wynosi = 2*PI * r * (r + H)= " << Pc << endl;
		cout << "Objętość wynosi = PI * r * r * H= " << V << endl;
		break;

	}
	case '9':
	{
		cout << "Podaj bok sześcianu: " << endl;
		cin >> a;
		Pb = 4 * a * a;
		Pc = 6 * a * a;
		V = a * a * a;
		cout << "Pole boczne wynosi =4*a*a = " << Pb << endl;
		cout << "Pole całkowite wynosi = 6*a*a= " << Pc << endl;
		cout << "Objętość wynosi = a*a*a= " << V << endl;
		break;

	}

	case '10':
	{cout << "Co ten pratopodłośćian ma w podstawie? " << endl;
	cout << "1.Kwadrat" << endl;
	cout << "2.Prostokąt" << endl;
	cout << "3. Trójkąt" << endl;
	cout << "4. Trapez" << endl;
	cout << "5. Równoległobok" << endl;
	cout << "6.Romb" << endl;
	int wyb;
	cin >> wyb;
	if (wyb == 1)
	{
		cout << "Podaj jeden z boków podstawy: " << endl;
		cin >> a;
		cout << "Podaj wysokość tego graniastusłupa: " << endl;
		cin >> H;
		V = a * a * H;
		Pb = 4 * a * H;
		Pc = a * a * 2 + a * H * 4;
		cout << "Pole boczne wynosi =4*a*H = " << Pb << endl;
		cout << "Pole całkowite wynosi = 2*a*a+4*a*H= " << Pc << endl;
		cout << "Objętość wynosi = a*a*H= " << V << endl;

	}
	else if (wyb == 2)
	{

		cout << "Podaj jeden z boków podstawy: " << endl;
		cin >> a;
		cout << "Podaj drugi bok podstawy: " << endl;
		cin >> b;
		cout << "Podaj wysokość tego graniastusłupa: " << endl;
		cin >> H;
		V = a * b * H;
		Pb = 2 * a * H + 2 * b * H;
		Pc = a * b * 2 + a * H * 2 + b * H * 2;
		cout << "Pole boczne wynosi =2 * a * H + 2 *b * H = " << Pb << endl;
		cout << "Pole całkowite wynosi = a * b * 2 + a * H * 2+ b * H * 2= " << Pc << endl;
		cout << "Objętość wynosi = a*b*H= " << V << endl;

	}
	else if (wyb == 3)
	{
		cout << "Podaj podstawe trójkąta (znajdującego sie w podstawie graniastosłupa) na którą pada wysokość: " << endl;
		cin >> a;
		cout << "Podaj reszte boków trójkąta b= " << endl;
		cin >> b;
		cout << "c = " << endl;
		cin >> c;
		cout << "Podaj wysokość trójkąta (znjadującego sie w podstawie graniastosłupa): " << endl;
		cin >> h;
		cout << "Podaj wysokość całego graniastosłupa: " << endl;
		cin >> H;
		V = ((a * h / 2)) * H;
		Pb = a * H + b * H + c * H;
		Pc = 2 * ((a * h / 2) + a * H + b * H + c * H);
		cout << "Pole boczne wynosi =a * H + b * H + c * H = " << Pb << endl;
		cout << "Pole całkowite wynosi = 2 * ((a * h / 2) + a * H + b * H + c * H= " << Pc << endl;
		cout << "Objętość wynosi =((a * h / 2) * H= " << V << endl;

	}
	else if (wyb == 4)
	{
		cout << "Podaj podstawy trapeza zawartego w podstawie graniastosłupa:a= " << endl;
		cin >> a;
		cout << "b= " << endl;
		cin >> b;
		cout << "Podaj ramiona trapezu: " << endl;
		cin >> c;
		cout << "Podaj wysokość trapezu (znjadującego sie w podstawie graniastosłupa): " << endl;
		cin >> h;
		cout << "Podaj wysokość całego graniastosłupa: " << endl;
		cin >> H;
		V = (((a + b) * h) / 2) * H;
		Pb = a * H + b * H + 2 * c * H;
		Pc = (((a + b) * h) / 2) + a * H + b * H + 2 * c * H;
		cout << "Pole boczne wynosi =a * H + b * H + 2*c * H = " << Pb << endl;
		cout << "Pole całkowite wynosi = (((a + b) * h) / 2)+ a * H + b * H + 2 * c * H= " << Pc << endl;
		cout << "Objętość wynosi =(((a +b)* h) / 2) * H= " << V << endl;

	}
	else if (wyb == 5)
	{
		cout << "Podaj podstawy trapeza zawartego w podstawie graniastosłupa:a= " << endl;
		cin >> a;
		cout << "Podaj ramiona równoległoboku: b= " << endl;
		cin >> b;
		cout << "Podaj wysokość równoległoboku (znjadującego sie w podstawie graniastosłupa): " << endl;
		cin >> h;
		cout << "Podaj wysokość całego graniastosłupa: " << endl;
		cin >> H;
		V = a * h * H;
		Pb = 2 * a * H + 2 * b * H;
		Pc = 2 * a * h + 2 * a * H + 2 * b * H;
		cout << "Pole boczne wynosi =2 * a * H + 2 * b * H= " << Pb << endl;
		cout << "Pole całkowite wynosi = 2 * a * h + 2 * a * H + 2 * b * H= " << Pc << endl;
		cout << "Objętość wynosi =a * h * H= " << V << endl;
	}
	else if (wyb == 6)
	{
		cout << "Podaj bok rombu: " << endl;
		cin >> a;
		cout << "Podaj pierwsza przekatna rombu: " << endl;
		cin >> e;
		cout << "Podaj druga przekatna: " << endl;
		cin >> f;
		V = ((e * f) / 2) * H;
		Pb = 4 * a * H;
		Pc = 2 * ((e * f) / 2) + 4 * a * H;
		cout << "Pole boczne wynosi = 4 * a * H= " << Pb << endl;
		cout << "Pole całkowite wynosi = 2 * ((e * f) / 2) + 4 * a * H= " << Pc << endl;
		cout << "Objętość wynosi =((e * f) / 2) * H= " << V << endl;
	}
	else
	{
		cout << "Podałeś niewłaściwy numer :(";
	}
	break;
	}
	case '11':
	{
		cout << "Menu:\n"
			<< "1) Dodawanie\n"
			<< "2) Odejmowanie\n"
			<< "3) Mnożenie\n"
			<< "4) Dzielenie\n"
			<< "> Twój wybór: ";
		int choice;
		cin >> choice;
		float x, y;
		if (choice == 1)
		{
			cout << "Liczenie sumy (a + b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a + b wynosi " << (x + y);
		}
		else if (choice == 2)
		{
			cout << "Liczenie różnicy (a - b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a - b wynosi " << (x - y);
		}
		else if (choice == 3)
		{
			cout << "Liczenie iloczynu (a * b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a * b wynosi " << (x * y);
		}
		else if (choice == 4)
		{
			cout << "Liczenie ilorazu (a / b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			if (y == 0)
				cout << "Nie można dzielić przez 0!";
			else
				cout << "a / b wynosi " << (x / y);
		}
		else
			cout << "Nieprawidłowa opcja: " << choice;
		break;
	}
	case '12':
	{
		int z, g;
		double w = 0.0;
		cin >> g;

		for (int i = 0; i < n; i++)
		{
			cin >> z;
			w += z;
		}
		cout << w / g;
		break;
	}


	default:
	{
		cout << "Niestety ale wybrałeś zły numerek, który znajduje się poza listą :(" << endl;
		break;
	}

	}
}

	