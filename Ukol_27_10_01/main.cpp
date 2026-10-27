//Úloha č.1
//1. Upravte program na zpracování bodu s transformacemi (2. úloha ze 4 výukového týdne)
//s využitím dědičnosti. Bude vytvořena třída Poloha mající soukromé atributy souřadnice x a y a dále třída Bod,
//která tyto vlastnosti zdědí a přidá si jednu svoji, zda je bod viditelný či nikoliv. Dále bude obsahovat metody na zobrazení/uschování a
//transformace (posun, rotace, zkosení, zrcadlení).

//uloha2. ze 4 týdne:


#include <iostream>
#include <cmath>

using namespace std;

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

class Bod : public Poloha {
private:
    bool viditelny;

public:
    Bod(double x = 0, double y = 0)
        : Poloha(x, y), viditelny(true) {
    }

    void zobraz() const {
        if (viditelny) {
            cout << "Bod: (" << dejX()
                 << ", " << dejY() << ")" << endl;
        }
    }

    void zobrazBod() {
        viditelny = true;
    }

    void skryjBod() {
        viditelny = false;
    }

    bool jeViditelny() const {
        return viditelny;
    }

    void posun(double x, double y) {
        nastavPolohu(dejX() + x, dejY() + y);
    }

    void otoceni(double uhel) {
        double radiany = uhel * 3.14159265359 / 180;

        double noveX = dejX() * cos(radiany)
                     - dejY() * sin(radiany);

        double noveY = dejX() * sin(radiany)
                     + dejY() * cos(radiany);

        nastavPolohu(noveX, noveY);
    }

    void zkoseniX(double hodnota) {
        nastavPolohu(dejX() + hodnota * dejY(), dejY());
    }

    void zkoseniY(double hodnota) {
        nastavPolohu(dejX(), dejY() + hodnota * dejX());
    }

    void zrcadleniX() {
        nastavPolohu(dejX(), -dejY());
    }

    void zrcadleniY() {
        nastavPolohu(-dejX(), dejY());
    }
};

int main() {
    double x, y;
    int volba;

    cout << "Zadej souradnici X: ";
    cin >> x;

    cout << "Zadej souradnici Y: ";
    cin >> y;

    Bod bod(x, y);

    do {
        cout << endl;
        bod.zobraz();

        cout << endl;
        cout << "Nabidka menu:" << endl;
        cout << "*************" << endl;
        cout << "1 - Zadat novy bod" << endl;
        cout << "2 - Posun bodu" << endl;
        cout << "3 - Otoceni bodu" << endl;
        cout << "4 - Zkoseni bodu" << endl;
        cout << "5 - Zrcadleni bodu" << endl;

        if (bod.jeViditelny()) {
            cout << "6 - Schovej bod" << endl;
        }
        else {
            cout << "6 - Ukaz bod" << endl;
        }

        cout << "7 - Konec programu" << endl;

        cout << "Vyber moznost: ";
        cin >> volba;

        switch (volba) {
        case 1:
            cout << "Zadej novou souradnici X: ";
            cin >> x;

            cout << "Zadej novou souradnici Y: ";
            cin >> y;

            bod.nastavPolohu(x, y);
            bod.zobrazBod();
            break;

        case 2: {
            double posunX, posunY;

            cout << "O kolik posunout X: ";
            cin >> posunX;

            cout << "O kolik posunout Y: ";
            cin >> posunY;

            bod.posun(posunX, posunY);
            break;
        }

        case 3: {
            double uhel;

            cout << "Zadej uhel otoceni: ";
            cin >> uhel;

            bod.otoceni(uhel);
            break;
        }

        case 4: {
            int smer;
            double hodnota;

            cout << "1 - Zkoseni v ose X" << endl;
            cout << "2 - Zkoseni v ose Y" << endl;
            cout << "Vyber smer: ";
            cin >> smer;

            cout << "Zadej hodnotu zkosení: ";
            cin >> hodnota;

            if (smer == 1) {
                bod.zkoseniX(hodnota);
            }
            else if (smer == 2) {
                bod.zkoseniY(hodnota);
            }
            else {
                cout << "Neplatna volba." << endl;
            }
            break;
        }

        case 5: {
            int osa;

            cout << "1 - Zrcadleni podle osy X" << endl;
            cout << "2 - Zrcadleni podle osy Y" << endl;
            cout << "Vyber osu: ";
            cin >> osa;

            if (osa == 1) {
                bod.zrcadleniX();
            }
            else if (osa == 2) {
                bod.zrcadleniY();
            }
            else {
                cout << "Neplatna volba." << endl;
            }
            break;
        }

        case 6:
            if (bod.jeViditelny()) {
                bod.skryjBod();
            }
            else {
                bod.zobrazBod();
            }
            break;

        case 7:
            cout << "Konec programu." << endl;
            break;

        default:
            cout << "Neplatna volba." << endl;
        }

    } while (volba != 7);

    return 0;
}

