#include <iostream>
#include <stdexcept>
#include <cstring> // for strcpy and strlen

enum class StanDostepnosci { dostepny, niedostepny };

class Autor {
private:
    const char* nazwisko_;
public:
    Autor(const char* nazwisko) : nazwisko_(nazwisko) {}
    const char* getPodajNazwisko() const { return nazwisko_; }
    void setUstawNazwisko(const char* nazwisko) { nazwisko_ = nazwisko; }
};

class Ksiazka {
protected:
    const char* tytul_;
    StanDostepnosci stan_;
    int liczbaStron_;
    const Autor& autor_;
    static Ksiazka* wzorcowa_;
public:
    Ksiazka(const char* tytul, StanDostepnosci stan, int liczbaStron, const Autor& autor)
        : tytul_(tytul), stan_(stan), liczbaStron_(liczbaStron), autor_(autor) {}

    Ksiazka() {
        if (wzorcowa_ == nullptr) {
            throw std::runtime_error("Nie można utworzyć instancji bez wzorcowej książki.");
        }
        *this = *wzorcowa_;
    }

    const char* getPodajTytul() const { return tytul_; }
    StanDostepnosci getPodajStan() const { return stan_; }
    int getPodajLiczbeStron() const { return liczbaStron_; }
    const Autor& getPodajAutora() const { return autor_; }

    void setUstawTytul(const char* tytul) { tytul_ = tytul; }
    void setUstawStan(StanDostepnosci stan) { stan_ = stan; }

    void setUstawLiczbeStron(int liczbaStron) {
        if (liczbaStron <= 0) {
            throw std::invalid_argument("Liczba stron nie może być mniejsza bądź równa 0.");
        }
        liczbaStron_ = liczbaStron;
    }

    virtual double obliczCene() const {
        return 1.0 * liczbaStron_;
    }

    bool operator==(const Ksiazka& inna) const {
        return (liczbaStron_ == inna.liczbaStron_ && stan_ == inna.stan_ && strcmp(autor_.getPodajNazwisko(), inna.autor_.getPodajNazwisko()) == 0);
    }

    static void UstawWzorcowa(Ksiazka* wzorcowa) {
        wzorcowa_ = wzorcowa;
    }
};

Ksiazka* Ksiazka::wzorcowa_ = nullptr;

class Ebook : public Ksiazka {
private:
    int rozmiar_;
public:
    Ebook(const char* tytul, StanDostepnosci stan, int liczbaStron, const Autor& autor, int rozmiar)
        : Ksiazka(tytul, stan, liczbaStron, autor), rozmiar_(rozmiar) {
        if (rozmiar <= 0) {
            throw std::invalid_argument("Rozmiar musi być większy od 0.");
        }
    }

    int getPodajRozmiar() const { return rozmiar_; }
    void setUstawRozmiar(int rozmiar) {
        if (rozmiar <= 0) {
            throw std::invalid_argument("Rozmiar musi być większy od 0.");
        }
        rozmiar_ = rozmiar;
    }

    double obliczCene() const override {
        return Ksiazka::obliczCene() * 0.75;
    }
};

int main() {
    try {
        Autor autor("Kowalski");
        Ksiazka wzorcowa("Wzorcowy Tytul", StanDostepnosci::dostepny, 300, autor);
        Ksiazka::UstawWzorcowa(&wzorcowa);

        Ksiazka nowaKsiazka;
        std::cout << "Tytul: " << nowaKsiazka.getPodajTytul() << ", Stan: " << (nowaKsiazka.getPodajStan() == StanDostepnosci::dostepny ? "Dostepna" : "Niedostepna") << ", Liczba stron: " << nowaKsiazka.getPodajLiczbeStron() << ", Autor: " << nowaKsiazka.getPodajAutora().getPodajNazwisko() << std::endl;

        Ebook ebook("Ebook Tytul", StanDostepnosci::dostepny, 150, autor, 50);
        std::cout << "Cena ebooka: " << ebook.obliczCene() << " PLN" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
    }

    return 0;
}
