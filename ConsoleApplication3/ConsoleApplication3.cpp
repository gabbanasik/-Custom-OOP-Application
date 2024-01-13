#include <iostream>
#include <cmath>
#include <string>
#include <locale.h>
#include <cstdlib>

#define PI 3.14
using namespace std;

void mainpage();
void initMenuLanguage();
void initMenuDecision();
void initMenuDecisionAng();
void MenuDecision(int);
void MenuDecisionAng(int);

int main()
{
	char zn = 'T';
	setlocale(LC_CTYPE, "Polish");
	mainpage();

	do {
		system("cls");
		initMenuLanguage();
		char chooseLanguage;
		cin >> chooseLanguage;

		if (chooseLanguage == '1') {
			system("cls");
			initMenuDecision();
			int choose = 0;
			cin >> choose;
			MenuDecision(choose);
		}
		else if (chooseLanguage == '2') {
			system("cls");
			initMenuDecisionAng();
			int chooseAng = 0;
			cin >> chooseAng;
			MenuDecisionAng(chooseAng);
		}

		if (chooseLanguage != '1' && chooseLanguage != '2') {
			system("cls");
			cout << "Wybrałeś nie odpowiednią sygnaturę. You choose the wrong key." << endl;
		}

		do {
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
		<< '\t' << "POL: Witaj na stronie zbioru wzorów matematycznych! W czym moge ci pomóc?" << endl;
	cout << '\t' << '\t' << '\t' << "Czy chcesz kontynuować? Jeśli tak nacisnij dowolny klawisz i naciśnij enter." << endl;
	cout << '\t' << '\t' << '\t' << "ENG: Hello on the math website where are maths formulas! How can I help you?" << endl;
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
void MenuDecision(int choose)
{

	double a, b, c, h, r, e, f, l, H, Pc, Pb, V, pole, przekatna, obwod;


	switch (choose)
	{
	case 1:
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
	case 2:
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
		cout << " Pole=a * b=  " << pole << endl << "Obwod= 2 * a + 2 * b=  " << obwod << endl;
		break;
	}
	case 3:
	{cout << "Podaj podstawe trójkąta na którą pada wysokość: " << endl;
	cin >> a;
	cout << "Podaj reszte boków trójkąta b= " << endl;
	cin >> b;
	cout << "c= " << endl;
	cin >> c;
	cout << "Podaj wysokość trójkąta: " << endl;
	cin >> h;
	obwod = a + b + c;
	pole = 0.5 * h * a;
	cout << "Pole tego trójkąta wynosi= 0.5 * h * a= " << pole << endl;
	cout << "Obwód=a+b+c= " << obwod << endl;

	break;
	}
	case 4:
	{cout << "Podaj promień koła: " << endl;
	cin >> r;
	pole = PI * r * r;
	obwod = 2 * PI * r;
	cout << "Pole twojego okręgu wynosi= PI * r * r= " << pole << endl;
	cout << "Obwód wynosi= 2 * PI * r= " << obwod << endl;
	break;
	}
	case 5:
	{
		cout << "Podaj bok rombu: " << endl;
		cin >> a;
		cout << "Podaj przekątna a: " << endl;
		cin >> e;
		cout << "Podaj przekątną b: " << endl;
		cin >> f;
		pole = (e * f) / 2;
		obwod = 4 * a;
		cout << "Pole tego rombu wynosi=(e*f)/2= " << pole << endl;
		cout << "Obwód tego rombu wynosi= a+a+a+a= " << obwod << endl;
		break;
	}
	case 6:
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
	case 7:
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
	case 8:
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
	case 9:
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
	case 10:
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
		cout << "Podaj wysokość całego graniastosłupa" << endl;
		cin >> H;
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
	case 11:
	{
		cout << "Menu:\n"
			<< "1) Dodawanie\n"
			<< "2) Odejmowanie\n"
			<< "3) Mnożenie\n"
			<< "4) Dzielenie\n"
			<< "Twój wybór: ";
		int wybor2;
		cin >> wybor2;
		float x, y;
		if (wybor2 == 1)
		{
			cout << "Liczenie sumy (a + b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a + b wynosi " << (x + y) << endl;
		}
		else if (wybor2 == 2)
		{
			cout << "Liczenie różnicy (a - b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a - b wynosi " << (x - y) << endl;
		}
		else if (wybor2 == 3)
		{
			cout << "Liczenie iloczynu (a * b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			cout << "a * b wynosi " << (x * y) << endl;
		}
		else if (wybor2 == 4)
		{
			cout << "Liczenie ilorazu (a / b).\n";
			cout << "Proszę wpisać pierwszą liczbę: ";
			cin >> x;

			cout << "Proszę wpisać drugą liczbę: ";
			cin >> y;

			if (y == 0)
				cout << "Nie można dzielić przez 0!" << endl;
			else
				cout << "a / b wynosi " << (x / y) << endl;
		}
		else
			cout << "Nieprawidłowa opcja: " << wybor2 << endl;
		break;
	}
	case 12:
	{
		int kolejnyElement, liczbaElementow;
		double suma = 0.0;
		cin >> liczbaElementow;


		for (int i = 0; i < liczbaElementow; i++)
		{
			cout << "Podaj swoją liczbę: " << endl;
			cin >> kolejnyElement;
			suma += kolejnyElement;
		}
		double wynik = suma / liczbaElementow;
		cout << " Twoja średnia to: " << suma << "/" << liczbaElementow << "=" << suma / liczbaElementow << endl;
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
	cout << "1. Square" << endl;
	cout << "2. Rectangle" << endl;
	cout << "3. Triangle" << endl;
	cout << "4. Circle" << endl;
	cout << "5. Rhombus" << endl;
	cout << "6. Parallelogram" << endl;
	cout << "7. Cone" << endl;
	cout << "8. Cylinder" << endl;
	cout << "9. Cube" << endl;
	cout << "10. Cuboid" << endl;
	cout << "11. Simple Calculator" << endl;
	cout << "12. Arithmetic mean" << endl;



}
void MenuDecisionAng(int chooseAng)
{
	double a, b, c, h, r, e, f, l, H, Pc, Pb, V, area, diagonal, perimeter;

	switch (chooseAng)
	{
	case 1:
	{
		system("cls");
		cout << "Specify the side of the square: " << endl;
		cin >> a;
		system("cls");
		area = a * a;
		diagonal = a * sqrt(2);
		perimeter = 4 * a;
		cout << "Here are all the formulas for the square for a= " << a << ": " << endl;
		cout << "Area=a*a= " << area << endl << "Diagonal of square =a * elementFrom2 " << diagonal << endl << "Perimeter of square=a+a+a+a= " << perimeter << endl;
		break;
	}
	case 2:
	{
		system("cls");
		cout << "Enter the width of the rectangle: " << endl;
		cin >> a;
		cout << "Enter the height of the rectangle: " << endl;
		cin >> b;
		system("cls");
		area = a * b;
		perimeter = 2 * a + 2 * b;
		cout << "Here are all the formulas for a rectangle: " << endl;
		cout << " Area=a * b=  " << area << endl << "Perimeter of square=2 * a + 2 * b=  " << perimeter << endl;
		break;
	}
	case 3:
	{cout << "Specify the base of the triangle on which the height falls: " << endl;
	cin >> a;
	cout << "Give the remainder of sides of triangle b= " << endl;
	cin >> b;
	cout << "c= " << endl;
	cin >> c;
	cout << "Specify the height of the triangle :" << endl;
	cin >> h;
	perimeter = a + b + c;
	area = 0.5 * h * a;
	cout << "The area of this triangle is= 0.5 * h * a = " << area << endl;
	cout << "Perimeter of square=a+b+c= " << perimeter << endl;
	break;
	}
	case 4:
	{cout << "Specify the radius of the circle: " << endl;
	cin >> r;
	area = PI * r * r;
	perimeter = 2 * PI * r;
	cout << "The area of your circle is= PI * r * r= " << area << endl;
	cout << "Perimeter of square= 2 * PI * r= " << perimeter << endl;
	break;
	}
	case 5:
	{
		cout << "Specify the side of the diamond: " << endl;
		cin >> a;
		cout << "Give the diagonal e: " << endl;
		cin >> e;
		cout << "Give the diagonal f: " << endl;
		cin >> f;
		area = (e * f) / 2;
		perimeter = 4 * a;
		cout << "The area of this diamond is=(e*f)/2= " << area << endl;
		cout << "The circumference of this diamond is= a+a+a+a= " << perimeter << endl;
		break;
	}
	case 6:
	{cout << "Give the base of the parallelogram: " << endl;
	cin >> a;
	cout << "Specify the height of the parallelogram: " << endl;
	cin >> h;
	cout << "Give the arm of the parallelogram: " << endl;
	cin >> b;
	area = a * h;
	perimeter = 2 * a + 2 * b;
	cout << "The area of this parallelogram is=a*h= " << area << endl;
	cout << "The circumference of this parallelogram is= a+a+b+b= " << perimeter << endl;
	break;
	}
	case 7:
	{cout << "Specify the radius of the base of the cone: " << endl;
	cin >> r;
	cout << "Specify the forming cone: " << endl;
	cin >> l;
	cout << "Specify the height of the cone: " << endl;
	cin >> H;
	Pb = PI * r * l;
	Pc = PI * r * (r + l);
	V = (PI * r * r * H) / 3;
	cout << "The lateral area is = PI * r * l= " << Pb << endl;
	cout << "The integer field is = PI * r * (r + l)= " << Pc << endl;
	cout << "The volume is = (PI * r * r * H) / 3= " << V << endl;
	break;
	}
	case 8:
	{
		cout << "Specify the radius of the base of the cylinder: " << endl;
		cin >> r;
		cout << "Specify the height of the cylinder: " << endl;
		cin >> H;
		Pb = 2 * PI * r * H;
		Pc = 2 * PI * r * (r + H);
		V = PI * r * r * H;
		cout << "The lateral area is = 2*PI * r * H= " << Pb << endl;
		cout << "The integer field is = 2*PI * r * (r + H)= " << Pc << endl;
		cout << "The volume is = PI * r * r * H= " << V << endl;
		break;

	}
	case 9:
	{
		cout << "Specify the side of the cube: " << endl;
		cin >> a;
		Pb = 4 * a * a;
		Pc = 6 * a * a;
		V = a * a * a;
		cout << "The lateral area is =4*a*a = " << Pb << endl;
		cout << "The integer field is = 6*a*a= " << Pc << endl;
		cout << "The volume is = a*a*a= " << V << endl;
		break;

	}
	case 10:
	{cout << "What does this protoepidotic have in the base? " << endl;
	cout << "1. Square" << endl;
	cout << "2. Rectangle" << endl;
	cout << "3. Triangle" << endl;
	cout << "4. Trapezoid" << endl;
	cout << "5. Parallelogram" << endl;
	cout << "6. Rhombus" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << " Specify one of the sides of the base: " << endl;
		cin >> a;
		cout << "Specify the height of this prism: " << endl;
		cin >> H;
		V = a * a * H;
		Pb = 4 * a * H;
		Pc = a * a * 2 + a * H * 4;
		cout << "The lateral area is =4*a*H = " << Pb << endl;
		cout << "The integer field is = 2*a*a+4*a*H= " << Pc << endl;
		cout << "The volume is = a*a*H= " << V << endl;

	}
	else if (choice == 2)
	{

		cout << "Provide one of the sides of the base: " << endl;
		cin >> a;
		cout << "Provide the other side of the base: " << endl;
		cin >> b;
		cout << "Specify the height of this prism: " << endl;
		cin >> H;
		V = a * b * H;
		Pb = 2 * a * H + 2 * b * H;
		Pc = a * b * 2 + a * H * 2 + b * H * 2;
		cout << "The lateral area is =2 * a * H + 2 *b * H = " << Pb << endl;
		cout << "The integer field is = a * b * 2 + a * H * 2+ b * H * 2= " << Pc << endl;
		cout << "The volume is = a*b*H= " << V << endl;

	}
	else if (choice == 3)
	{
		cout << "Specify the base of the triangle (located at the base of the prism) on which the height falls: " << endl;
		cin >> a;
		cout << "Give the rest of the sides of the triangle: b= " << endl;
		cin >> b;
		cout << "c = " << endl;
		cin >> c;
		cout << "Specify the height of the triangle (which is located at the base of the prism): " << endl;
		cin >> h;
		cout << "Specify the height of this prism: " << endl;
		cin >> H;
		V = ((a * h / 2)) * H;
		Pb = a * H + b * H + c * H;
		Pc = 2 * ((a * h / 2) + a * H + b * H + c * H);
		cout << "The lateral area is =a * H + b * H + c * H = " << Pb << endl;
		cout << "The integer field is = 2 * ((a * h / 2) + a * H + b * H + c * H= " << Pc << endl;
		cout << "The volume is =((a * h / 2) * H= " << V << endl;

	}
	else if (choice == 4)
	{
		cout << "Specify the bases of the trapezoid contained in the base of the prism: a = " << endl;
		cin >> a;
		cout << "b= " << endl;
		cin >> b;
		cout << "Give the arms of the trapezoid: " << endl;
		cin >> c;
		cout << "Specify the height of the trapezoid (located at the base of the prism): " << endl;
		cin >> h;
		cout << "Specify the height of this prism: " << endl;
		cin >> H;
		V = (((a + b) * h) / 2) * H;
		Pb = a * H + b * H + 2 * c * H;
		Pc = (((a + b) * h) / 2) + a * H + b * H + 2 * c * H;
		cout << "The lateral area is =a * H + b * H + 2*c * H = " << Pb << endl;
		cout << "The integer field is = (((a + b) * h) / 2)+ a * H + b * H + 2 * c * H= " << Pc << endl;
		cout << "The volume is =(((a +b)* h) / 2) * H= " << V << endl;

	}
	else if (choice == 5)
	{
		cout << "Give the bases of the parallelogram contained in the base of the prism: a = " << endl;
		cin >> a;
		cout << "Give Arms of Parallelogram: b= " << endl;
		cin >> b;
		cout << "Specify the height of the parallelogram (located at the base of the prism): " << endl;
		cin >> h;
		cout << "Specify the height of this prism: " << endl;
		cin >> H;
		V = a * h * H;
		Pb = 2 * a * H + 2 * b * H;
		Pc = 2 * a * h + 2 * a * H + 2 * b * H;
		cout << "The lateral area is =2 * a * H + 2 * b * H= " << Pb << endl;
		cout << "The integer field is = 2 * a * h + 2 * a * H + 2 * b * H= " << Pc << endl;
		cout << "The volume is =a * h * H= " << V << endl;
	}
	else if (choice == 6)
	{
		cout << "Specify the side of the diamond: " << endl;
		cin >> a;
		cout << "Specify the first diagonal of the diamond: " << endl;
		cin >> e;
		cout << "Enter the second diagonal: " << endl;
		cin >> f;
		cout << "Specify the height of this prism: " << endl;
		cin >> H;
		V = ((e * f) / 2) * H;
		Pb = 4 * a * H;
		Pc = 2 * ((e * f) / 2) + 4 * a * H;
		cout << "The lateral area is = 4 * a * H= " << Pb << endl;
		cout << "The integer field is = 2 * ((e * f) / 2) + 4 * a * H= " << Pc << endl;
		cout << "The volume is =((e * f) / 2) * H= " << V << endl;
	}
	else
	{
		cout << "You have entered the wrong signature :(";
	}
	break;
	}
	case 11:
	{
		cout << "Menu:\n"
			<< "1) Addition\n"
			<< "2) Subtraction\n"
			<< "3) Multiplication\n"
			<< "4) Divided\n"
			<< "Your choice: ";
		int choice2;
		cin >> choice2;
		float x, y;
		if (choice2 == 1)
		{
			cout << "Counting the sum (a + b).\n";
			cout << "Please enter the first number: ";
			cin >> x;

			cout << "Please enter the second number: ";
			cin >> y;

			cout << "a + b = " << (x + y) << endl;
		}
		else if (choice2 == 2)
		{
			cout << "Counting the difference (a - b).\n";
			cout << "Please enter the first number: ";
			cin >> x;

			cout << "Please enter the second number: ";
			cin >> y;

			cout << "a - b = " << (x - y) << endl;
		}
		else if (choice2 == 3)
		{
			cout << "Multiplication calculation(a * b).\n";
			cout << "Please enter the first number: ";
			cin >> x;

			cout << "Please enter the second number: ";
			cin >> y;

			cout << "a * b = " << (x * y) << endl;
		}
		else if (choice2 == 4)
		{
			cout << "Division calculation (a / b).\n";
			cout << "Please enter the first number: ";
			cin >> x;

			cout << "Please enter the second number: ";
			cin >> y;

			if (y == 0)
				cout << "Cannot be divided by 0!" << endl;
			else
				cout << "a / b = " << (x / y) << endl;
		}
		else
			cout << "Invalid option: " << choice2 << endl;
		break;
	}
	case 12:
	{
		int NextElement, numberElements;
		double suma = 0.0;
		cout << "Please enter the number of all items" << endl;
		cin >> numberElements;


		for (int i = 0; i < numberElements; i++)
		{
			cout << "Please enter your number: " << endl;
			cin >> NextElement;
			suma += NextElement;
		}
		double results = suma / numberElements;
		cout << "Your average is= suma/numberElements=  " << suma << "/" << numberElements << "= " << results << endl;
		break;
	}
	default:
	{
		cout << "Sorry, but you chose the wrong number that is off the list :(" << endl;
		break;
	}

	}
}
/*Jedynym problemem programu jest to, że gdy podamy w wyborze zamiast liczby litere cały program zawiesza się*/