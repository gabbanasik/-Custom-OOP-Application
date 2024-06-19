#include <iostream>
#include <cstring>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Wlasciciel {
    string nazwisko;
public:
    Wlasciciel(const string& nazwisko) : nazwisko(nazwisko) {}
    const string& getNazwisko() const { return nazwisko; }
};

class Samochod {
    char numerRejestracyjny[10]; // XXX-YYYYY
    double stanLicznika;
    bool dopuszczonyDoJazdy;
    Wlasciciel* wlasciciel;
    static int ostatniNumer;

    void generujNumerRejestracyjny(const char* XXX) {
        if (strlen(XXX) != 3) {
            throw invalid_argument("XXX must be 3 characters long");
        }
        strncpy_s(numerRejestracyjny, XXX, 3);
        numerRejestracyjny[3] = '-';
        snprintf(numerRejestracyjny + 4, 6, "%05d", ++ostatniNumer);
    }

public:
    Samochod(const char* XXX, double stanLicznika, bool dopuszczonyDoJazdy, Wlasciciel* wlasciciel)
        : stanLicznika(stanLicznika), dopuszczonyDoJazdy(dopuszczonyDoJazdy), wlasciciel(wlasciciel) {
        generujNumerRejestracyjny(XXX);
    }

    const char* getNumerRejestracyjny() const {
        return numerRejestracyjny;
    }

    double getStanLicznika() const {
        return stanLicznika;
    }

    void setStanLicznika(double stan) {
        if (stan < 0) {
            throw invalid_argument("Stan licznika cannot be negative");
        }
        stanLicznika = stan;
    }

    bool isDopuszczonyDoJazdy() const {
        return dopuszczonyDoJazdy;
    }

    void setDopuszczonyDoJazdy(bool stan) {
        dopuszczonyDoJazdy = stan;
    }

    const Wlasciciel* getWlasciciel() const {
        return wlasciciel;
    }

    void setWlasciciel(Wlasciciel* wlasc) {
        wlasciciel = wlasc;
    }

    virtual double obliczZasieg() const {
        return 800;
    }

    operator double() const {
        const double WARTOSC_POCZ = 50000;
        double WSP_SPRAW = dopuszczonyDoJazdy ? 1.0 : 0.2;
        double wartosc = WARTOSC_POCZ - 0.1 * stanLicznika * WSP_SPRAW;
        return max(wartosc, 400.0);
    }

    bool operator==(const Samochod& other) const {
        return strncmp(numerRejestracyjny, other.numerRejestracyjny, 3) == 0 &&
               abs(stanLicznika - other.stanLicznika) <= 10;
    }

    friend ostream& operator<<(ostream& os, const Samochod& s) {
        os << "[" << s.getNumerRejestracyjny() << "] "
           << s.getWlasciciel()->getNazwisko() << " : "
           << s.getStanLicznika() << " km, "
           << (s.isDopuszczonyDoJazdy() ? "dopuszczony" : "niedopuszczony");
        return os;
    }
};

int Samochod::ostatniNumer = 0;

class SamochodElektryczny : public Samochod {
    double stanBaterii; // 0-100%

public:
    SamochodElektryczny(const char* XXX, double stanLicznika, bool dopuszczonyDoJazdy, Wlasciciel* wlasciciel, double stanBaterii)
        : Samochod(XXX, stanLicznika, dopuszczonyDoJazdy, wlasciciel), stanBaterii(stanBaterii) {
        if (stanBaterii < 0 || stanBaterii > 100) {
            throw invalid_argument("Stan baterii must be between 0 and 100");
        }
    }

    double getStanBaterii() const {
        return stanBaterii;
    }

    void setStanBaterii(double stan) {
        if (stan < 0 || stan > 100) {
            throw invalid_argument("Stan baterii must be between 0 and 100");
        }
        stanBaterii = stan;
    }

    virtual double obliczZasieg() const override {
        return 2.5 * stanBaterii;
    }
};

int main() {
    Wlasciciel wlasciciel1("Kowalski");
    Wlasciciel wlasciciel2("Nowak");

    Samochod samochod1("ABC", 15000, true, &wlasciciel1);
    Samochod samochod2("XYZ", 12000, false, &wlasciciel2);

    SamochodElektryczny samochodElektryczny("ELE", 8000, true, &wlasciciel1, 80);

    cout << samochod1 << endl;
    cout << samochod2 << endl;
    cout << samochodElektryczny << endl;

    cout << "Zasieg samochodu: " << samochod1.obliczZasieg() << " km" << endl;
    cout << "Zasieg samochodu elektrycznego: " << samochodElektryczny.obliczZasieg() << " km" << endl;

    cout << "Wartosc samochodu 1: " << static_cast<double>(samochod1) << " PLN" << endl;
    cout << "Wartosc samochodu 2: " << static_cast<double>(samochod2) << " PLN" << endl;

    cout << "Samochod 1 i 2 sa " << (samochod1 == samochod2 ? "takie same" : "rozne") << endl;

    return 0;
}
