#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cctype> // do funkcji isdigit

class Klient {
private:
    char nazwa_[20];

public:
    Klient(const char* nazwa) {
        if (nazwa == nullptr || strlen(nazwa) == 0) {
            throw std::invalid_argument("Nazwa klienta nie może być pusta.");
        }
        strncpy(nazwa_, nazwa, 19);
        nazwa_[19] = '\0';
    }

    const char* getNazwa() const {
        return nazwa_;
    }
};

enum class Stan {
    dostepne,
    niedostepne
};

class KontoBankowe {
private:
    char nrKonta_[27];
    double stanKonta_;
    Stan stan_;
    Klient& klient_;
    static int licznikAktywnych;

public:
    KontoBankowe(const char* nrKonta, double stanKonta, Stan stan, Klient& klient)
        : stanKonta_(stanKonta), stan_(stan), klient_(klient) {
        setNrKonta(nrKonta);

        if (stanKonta_ < 0) {
            throw std::invalid_argument("Stan konta nie może być ujemny.");
        }

        if (stan_ == Stan::dostepne) {
            ++licznikAktywnych;
        }
    }

    ~KontoBankowe() {
        if (stan_ == Stan::dostepne) {
            --licznikAktywnych;
        }
    }

    // Gettery i settery
    const char* getNrKonta() const {
        return nrKonta_;
    }

    void setNrKonta(const char* nrKonta) {
        if (strlen(nrKonta) != 26) {
            throw std::invalid_argument("Numer konta musi mieć dokładnie 26 cyfr.");
        }
        for (int i = 0; i < 26; ++i) {
            if (!isdigit(nrKonta[i])) {
                throw std::invalid_argument("Numer konta może zawierać tylko cyfry.");
            }
        }
        strncpy(nrKonta_, nrKonta, 26);
        nrKonta_[26] = '\0';
    }

    double getStanKonta() const {
        return stanKonta_;
    }

    void setStanKonta(double stanKonta) {
        if (stanKonta < 0) {
            throw std::invalid_argument("Stan konta nie może być ujemny.");
        }
        stanKonta_ = stanKonta;
    }

    Stan getStan() const {
        return stan_;
    }

    void setStan(Stan stan) {
        if (stan_ != stan) {
            if (stan == Stan::dostepne) {
                ++licznikAktywnych;
            } else {
                --licznikAktywnych;
            }
            stan_ = stan;
        }
    }

    const Klient& getKlient() const {
        return klient_;
    }

    static int getLicznikAktywnych() {
        return licznikAktywnych;
    }

    virtual double prognoza() const {
        return getStanKonta();
    }

    // Operator += do dodawania środków
    KontoBankowe& operator+=(double kwota) {
        if (kwota < 0) {
            throw std::invalid_argument("Kwota nie może być ujemna.");
        }
        stanKonta_ += kwota;
        return *this;
    }

    // Operator konwersji KontoBankowe ➔ double
    operator double() const {
        return getStanKonta();
    }

    // Operator << do wyświetlania informacji o koncie
    friend std::ostream& operator<<(std::ostream& os, const KontoBankowe& konto) {
        os << "Konto: " << konto.nrKonta_ << ", Stan: " << konto.stanKonta_ << " PLN, Stan konta: "
           << (konto.stan_ == Stan::dostepne ? "Dostępne" : "Niedostępne") << ", Właściciel: " << konto.klient_.getNazwa();
        return os;
    }
};

int KontoBankowe::licznikAktywnych = 0;

class KontoOszczednosciowe : public KontoBankowe {
private:
    double stopaOprocentowania_;

public:
    KontoOszczednosciowe(double stopaOprocentowania, const char* nrKonta, double stanKonta, Stan stan, Klient& klient)
        : KontoBankowe(nrKonta, stanKonta, stan, klient), stopaOprocentowania_(stopaOprocentowania) {
        if (stopaOprocentowania_ < 0) {
            throw std::invalid_argument("Stopa oprocentowania nie może być ujemna.");
        }
    }

    double getStopaOprocentowania() const {
        return stopaOprocentowania_;
    }

    void setStopaOprocentowania(double stopaOprocentowania) {
        if (stopaOprocentowania < 0) {
            throw std::invalid_argument("Stopa oprocentowania nie może być ujemna.");
        }
        stopaOprocentowania_ = stopaOprocentowania;
    }

    double prognoza() const override {
        return getStanKonta() * (1 + stopaOprocentowania_);
    }

    // Operator == do porównywania dwóch kont oszczędnościowych
    bool operator==(const KontoOszczednosciowe& inne) const {
        if (getNrKonta() == inne.getNrKonta() &&
            getStanKonta() == inne.getStanKonta() &&
            getStan() == inne.getStan() &&
            getKlient().getNazwa() == inne.getKlient().getNazwa() &&
            getStopaOprocentowania() == inne.getStopaOprocentowania()) {
            return true;
        } else {
            throw std::invalid_argument("Konta są identyczne, ale mają różne typy.");
        }
    }
};

int main() {
    try {
        Klient klient1("Jan Kowalski");
        KontoBankowe konto1("12345678901234567890123456", 1000.0, Stan::dostepne, klient1);
        KontoOszczednosciowe konto2(0.05, "12345678901234567890123457", 2000.0, Stan::dostepne, klient1);

        std::cout << konto1 << std::endl;
        std::cout << konto2 << std::endl;

        konto1 += 500.0;
        std::cout << "Stan konta po wpłacie: " << konto1 << std::endl;

        std::cout << "Prognoza stanu konta bankowego za rok: " << konto1.prognoza() << " PLN" << std::endl;
        std::cout << "Prognoza stanu konta oszczędnościowego za rok: " << konto2.prognoza() << " PLN" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << std::endl;
    }

    return 0;
}

