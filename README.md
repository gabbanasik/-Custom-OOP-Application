#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cmath>

enum class StanDopuszczenia { dopuszczony, niedopuszczony };

class Wlasciciel {
public:
    // Pusta klasa Wlasciciel
};

class Samochod {
private:
    char numerRejestracyjny_[20];
    int stanLicznika_;
    StanDopuszczenia stanDopuszczenia_;
    const Wlasciciel& wlasciciel_;
    static Samochod* wzorcowy_;
    static constexpr double WAR_POCZ = 10000.0;

protected:
    // Getter dla właściciela, niezmienialny
    const Wlasciciel& getWlasciciel() const { return wlasciciel_; }

public:
    Samochod(const char* numerRejestracyjny, int stanLicznika, StanDopuszczenia stanDopuszczenia, const Wlasciciel& wlasciciel)
        : wlasciciel_(wlasciciel) {
        setNumerRejestracyjny(numerRejestracyjny);
        setStanLicznika(stanLicznika);
        stanDopuszczenia_ = stanDopuszczenia;
    }

    Samochod() : wlasciciel_(wzorcowy_->wlasciciel_) {
        if (!wzorcowy_) {
            throw std::runtime_error("Wzorcowy samochod nie jest ustawiony.");
        }
        *this == *wzorcowy_;
    }

    static void setWzorcowy(Samochod* wzorcowy) {
        wzorcowy_ = wzorcowy;
    }

    // Settery i gettery
    const char* getNumerRejestracyjny() const { return numerRejestracyjny_; }
    void setNumerRejestracyjny(const char* numerRejestracyjny) {
        strncpy_s(numerRejestracyjny_, numerRejestracyjny, sizeof(numerRejestracyjny_) - 1);
        numerRejestracyjny_[sizeof(numerRejestracyjny_) - 1] = '\0';
    }

    int getStanLicznika() const { return stanLicznika_; }
    void setStanLicznika(int stanLicznika) {
        if (stanLicznika < 0) {
            throw std::invalid_argument("Stan licznika nie może być ujemny.");
        }
        stanLicznika_ = stanLicznika;
    }

    StanDopuszczenia getStanDopuszczenia() const { return stanDopuszczenia_; }
    void setStanDopuszczenia(StanDopuszczenia stanDopuszczenia) {
        stanDopuszczenia_ = stanDopuszczenia;
    }

    double obliczWartosc(double WSP_SPARW) const {
        double wartosc = (WAR_POCZ - 0.2 * stanLicznika_) * (stanDopuszczenia_ == StanDopuszczenia::dopuszczony ? WSP_SPARW : 0.2);
        return std::max(wartosc, 400.0);
    }

    // Metoda wirtualna do obliczenia zasięgu
    virtual double obliczZasieg() const {
        if (stanDopuszczenia_ == StanDopuszczenia::niedopuszczony) {
            throw std::runtime_error("Samochod jest niedopuszczony do jazdy.");
        }
        return 800.0;
    }

    bool operator==(const Samochod& inny) const {
        return std::abs(stanLicznika_ - inny.stanLicznika_) <= 20 && stanDopuszczenia_ == inny.stanDopuszczenia_;
    }

    virtual operator double() const {
        return obliczWartosc(1.0);
    }

    const char* opis() const {
        static char opis[256];
        snprintf(opis, sizeof(opis), "Numer rejestracyjny: %s, Stan licznika: %d, Stan dopuszczenia: %s",
            numerRejestracyjny_,
            stanLicznika_,
            stanDopuszczenia_ == StanDopuszczenia::dopuszczony ? "dopuszczony" : "niedopuszczony");
        return opis;
    }
};

Samochod* Samochod::wzorcowy_ = nullptr;

class SamochodElektryczny : public Samochod {
private:
    int stanBaterii_;

public:
    SamochodElektryczny(const char* numerRejestracyjny, int stanLicznika, StanDopuszczenia stanDopuszczenia, const Wlasciciel& wlasciciel, int stanBaterii)
        : Samochod(numerRejestracyjny, stanLicznika, stanDopuszczenia, wlasciciel), stanBaterii_(stanBaterii) {
        if (stanBaterii < 0 || stanBaterii > 100) {
            throw std::invalid_argument("Stan baterii musi być w przedziale 0-100%.");
        }
    }

    double obliczZasieg() const override {
        if (getStanDopuszczenia() == StanDopuszczenia::niedopuszczony) {
            throw std::runtime_error("Samochod jest niedopuszczony do jazdy.");
        }
        return 2.5 * stanBaterii_;
    }

    double obliczWartosc(double WSP_SPARW) const  {
        double wartosc = Samochod::obliczWartosc(WSP_SPARW) * 0.7;
        return std::max(wartosc, 400.0);
    }

    operator double() const override {
        return obliczWartosc(1.0);
    }

    const char* opis() const {
        static char opis[256];
        snprintf(opis, sizeof(opis), "Numer rejestracyjny: %s, Stan licznika: %d, Stan dopuszczenia: %s, Stan baterii: %d%%",
            getNumerRejestracyjny(),
            getStanLicznika(),
            getStanDopuszczenia() == StanDopuszczenia::dopuszczony ? "dopuszczony" : "niedopuszczony",
            stanBaterii_);
        return opis;
    }
};

int main() {
    try {
        Wlasciciel wlasciciel;

        Samochod wzorcowy("XYZ-12345", 100000, StanDopuszczenia::dopuszczony, wlasciciel);
        Samochod::setWzorcowy(&wzorcowy);

        Samochod nowySamochod;
        std::cout << "Nowy Samochod: " << static_cast<double>(nowySamochod) << " PLN" << std::endl;
        std::cout << "Opis: " << nowySamochod.opis() << std::endl;

        SamochodElektryczny elektryczny("ELE-98765", 50000, StanDopuszczenia::dopuszczony, wlasciciel, 80);
        std::cout << "Samochod Elektryczny: " << static_cast<double>(elektryczny) << " PLN" << std::endl;
        std::cout << "Opis: " << elektryczny.opis() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
    }

    return 0;
}
