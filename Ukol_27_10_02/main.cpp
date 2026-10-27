//Úloha č.2
//Upravte předchozí program tak, že ze třídy bod smažte transformace. Přidejte novou třídu
//Kruh, která dědí ze třídy Bod (a tím pádem i Poloha). Tato nová třída bude mít navíc atribut poloměr, který bude možné změnit.
//V hlavní smyčce programu se vytvoří jedna instance třídy Bod a jedna instance třídy kruh.
//následně půjde skrze textovou nabídky oba objekty zobrazovat/schovávat, změnit veškeré parametry a u kruhu zvětšovat/zmenšovat poloměr.
//Spustitelná ukázka je přiložena.

#include <iostream>

using namespace std;

// Zakladni trida Poloha
class Poloha {
private:
    double SouradniceX;
    double SouradniceY;

public:
    Poloha(double x = 0, double y = 0)
        : SouradniceX(x), SouradniceY(y) {
    }

    void nastavPolohu(double x, double y) {
        SouradniceX = x;
        SouradniceY = y;
    }

    double dejX() const {
        return SouradniceX;
    }

    double dejY() const {
        return SouradniceY;
    }
};

// Trida Bod dedi z tridy Poloha
class Bod : public Poloha {
private:
    bool viditelny;

public:
    Bod(double x = 0, double y = 0)
        : Poloha(x, y), viditelny(true) {
    }

    void zobraz() const {
        if (viditelny) {
            cout << "Bod ma souradnice "
                 << dejX() << "," << dejY() << endl;
        }
    }

    void skryj() {
        viditelny = false;
    }

    void ukaz() {
        viditelny = true;
    }

    bool jeViditelny() const {
        return viditelny;
    }

    void nastavBod(double x, double y) {
        nastavPolohu(x, y);
        viditelny = true;
    }
};

// Trida Kruh dedi z tridy Bod
class Kruh : public Bod {
private:
    double polomer;

public:
    Kruh(double x = 0, double y = 0, double r = 1)
        : Bod(x, y), polomer(r) {
    }

    void zobrazKruh() const {
        if (jeViditelny()) {
            cout << "Kruh je na souradnicich "
                 << dejX() << "," << dejY()
                 << " a ma polomer " << polomer << endl;
        }
    }

    void nastavKruh(double x, double y, double r) {
        if (r > 0) {
            nastavBod(x, y);
            polomer = r;
        }
        else {
            cout << "Polomer musi byt vetsi nez 0." << endl;
        }
    }

    void zmensiPolomer(double hodnota) {
        if (hodnota > 0 && polomer - hodnota > 0) {
            polomer -= hodnota;
        }
        else {
            cout << "Neplatna zmena polomeru." << endl;
        }
    }

    void zvetsiPolomer(double hodnota) {
        if (hodnota > 0) {
            polomer += hodnota;
        }
        else {
            cout << "Zmena musi byt kladna." << endl;
        }
    }

    void skryjKruh() {
        skryj();
    }

    void ukazKruh() {
        ukaz();
    }
};

int main() {
    int volba;
    double x, y, r, zmena;

    Bod bod(0, 0);
    Kruh kruh(0, 0, 1);

    do {
        cout << endl;

        bod.zobraz();
        kruh.zobrazKruh();

        cout << endl;
        cout << "Nabidka menu:" << endl;
        cout << "*************" << endl;

        if (bod.jeViditelny()) {
            cout << "0 - Schovej bod" << endl;
        }
        else {
            cout << "0 - Ukaz bod" << endl;
        }
        if (kruh.jeViditelny()) {
            cout << "1 - Schovej kruh" << endl;
        }
        else {
            cout << "1 - Ukaz kruh" << endl;
        }
        cout << "2 - Zadat novy bod" << endl;
        cout << "3 - Zadat novy kruh" << endl;
        cout << "4 - Zmensi polomer kruhu" << endl;
        cout << "5 - Zvetsi polomer kruhu" << endl;
        cout << "6 - Konec programu" << endl;

        cout << "Vyber moznost: ";
        cin >> volba;

        switch (volba) {
        case 0:
            if (bod.jeViditelny()) {
                bod.skryj();
            }
            else {
                bod.ukaz();
            }
            break;

        case 1:
            if (kruh.jeViditelny()) {
                kruh.skryjKruh();
            }
            else {
                kruh.ukazKruh();
            }
            break;

        case 2:
            cout << "Zadej souradnici X: ";
            cin >> x;

            cout << "Zadej souradnici Y: ";
            cin >> y;

            bod.nastavBod(x, y);
            break;

        case 3:
            cout << "Zadej souradnici X kruhu: ";
            cin >> x;

            cout << "Zadej souradnici Y kruhu: ";
            cin >> y;

            cout << "Zadej polomer kruhu: ";
            cin >> r;

            kruh.nastavKruh(x, y, r);
            break;

        case 4:
            cout << "O kolik zmensit polomer: ";
            cin >> zmena;

            kruh.zmensiPolomer(zmena);
            break;

        case 5:
            cout << "O kolik zvetsit polomer: ";
            cin >> zmena;

            kruh.zvetsiPolomer(zmena);
            break;

        case 6:
            cout << "Konec programu." << endl;
            break;

        default:
            cout << "Neplatna volba." << endl;
        }

    } while (volba != 6);

    return 0;
}
