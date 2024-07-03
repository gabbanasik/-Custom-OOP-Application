#include <iostream>
#include <stdexcept>
#include <cstring> // for strcpy and strlen
    enum class Stan { DOSTEPNA, NIEDOSTEPNA };
class Autor {
public:
    Autor(const char* nazwisko) : nazwisko_(nazwisko) {}

    const char* PobierzNazwisko() const { return nazwisko_; }

private:
    const char* nazwisko_;
};

class Ksiazka {
public:


    // Konstruktor argumentowy
    Ksiazka(const char* tytul, int liczbaStron, Stan stanDostepnosci, const Autor& autor)
        : autor_(autor) {
        UstawTytul(tytul);
        UstawLiczbeStron(liczbaStron);
        UstawStanDostepnosci(stanDostepnosci);
    }

    // Konstruktor domyślny
    Ksiazka() : Ksiazka(wzorcowa_->tytul_, wzorcowa_->liczbaStron_, wzorcowa_->stanDostepnosci_, wzorcowa_->autor_) {}

    // Gettery
    const char* PobierzTytul() const { return tytul_; }
    int PobierzLiczbeStron() const { return liczbaStron_; }
    Stan PobierzStanDostepnosci() const { return stanDostepnosci_; }
    const Autor& PobierzAutora() const { return autor_; }

    // Settery
    void UstawTytul(const char* tytul) {
        if (strlen(tytul) == 0) {
            throw std::invalid_argument("Tytul nie moze byc pusty.");
        }
        tytul_ = tytul;
    }

    void UstawLiczbeStron(int liczbaStron) {
        if (liczbaStron <= 0) {
            throw std::invalid_argument("Liczba stron musi byc dodatnia.");
        }
        liczbaStron_ = liczbaStron;
    }

    void UstawStanDostepnosci(Stan stanDostepnosci) {
        stanDostepnosci_ = stanDostepnosci;
    }

    static void UstawWzorcowa(Ksiazka* wzorcowa) {
        wzorcowa_ = wzorcowa;
    }

    virtual double ObliczCene() const {
        return 1.0 * liczbaStron_;
    }

    explicit operator const char*() const {
        static char opis[256];
        snprintf(opis, sizeof(opis), "Tytul: %s, Liczba stron: %d, Stan: %s, Autor: %s",
                 tytul_, liczbaStron_, 
                 (stanDostepnosci_ == Stan::DOSTEPNA ? "Dostepna" : "Niedostepna"), 
                 autor_.PobierzNazwisko());
        return opis;
    }

    bool operator==(const Ksiazka& other) const {
        return (liczbaStron_ == other.liczbaStron_ &&
                stanDostepnosci_ == other.stanDostepnosci_ &&
                strcmp(autor_.PobierzNazwisko(), other.autor_.PobierzNazwisko()) == 0);
    }

protected:
    const char* tytul_;
    int liczbaStron_;
    Stan stanDostepnosci_;
    const Autor& autor_;
    static Ksiazka* wzorcowa_;
};

Ksiazka* Ksiazka::wzorcowa_ = nullptr;
class EBook : public Ksiazka {
public:
    EBook(const char* tytul, int liczbaStron, Stan stanDostepnosci, const Autor& autor, double rozmiarMB)
        : Ksiazka(tytul, liczbaStron, stanDostepnosci, autor), rozmiarMB_(rozmiarMB) {
        if (rozmiarMB <= 0) {
            throw std::invalid_argument("Rozmiar w MB musi byc dodatni.");
        }
    }

    double PobierzRozmiarMB() const { return rozmiarMB_; }

    void UstawRozmiarMB(double rozmiarMB) {
        if (rozmiarMB <= 0) {
            throw std::invalid_argument("Rozmiar w MB musi byc dodatni.");
        }
        rozmiarMB_ = rozmiarMB;
    }

    double ObliczCene() const override {
        return Ksiazka::ObliczCene() * 0.75;
    }

private:
    double rozmiarMB_;
};
int main() {
    Autor autor("Kowalski");
    Ksiazka wzorcowaKsiazka("Wzorcowy Tytul", 300, Ksiazka::Stan::DOSTEPNA, autor);
    Ksiazka::UstawWzorcowa(&wzorcowaKsiazka);

    try {
        Ksiazka nowaKsiazka;
        std::cout << static_cast<const char*>(nowaKsiazka) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
    }

    Ksiazka innaKsiazka("Inny Tytul", 250, Ksiazka::Stan::NIEDOSTEPNA, autor);
    EBook ebook("Ebook Tytul", 150, Ksiazka::Stan::DOSTEPNA, autor, 50.0);

    std::cout << "Cena ksiazki: " << innaKsiazka.ObliczCene() << " PLN" << std::endl;
    std::cout << "Cena ebooka: " << ebook.ObliczCene() << " PLN" << std::endl;

    std::cout << static_cast<const char*>(innaKsiazka) << std::endl;
    std::cout << static_cast<const char*>(ebook) << std::endl;

    if (innaKsiazka == wzorcowaKsiazka) {
        std::cout << "Ksiazki sa identyczne." << std::endl;
    } else {
        std::cout << "Ksiazki nie sa identyczne." << std::endl;
    }

    return 0;
}
