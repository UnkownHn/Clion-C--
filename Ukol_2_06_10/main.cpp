// ul 2
// Vytvořte třídu Bod. Ta bude obsahovat dvě proměnné - souřadnice x a y.
// Následně vytvořte jednu instanci (za pomocí konstruktoru).
// Poté přidejte nabídku pro standardní transformace tohoto bodu - posun,
// otáčení (kolem počátku souřadnicového systému), zkosení a zrcadlení.
// Výsledky zobrazte v konzolovém okně.

#include <iostream>
#include <cmath>

using namespace std;

class Bod {
private:
    double SouradniceX;
    double SouradniceY;

public:
    // Konstruktor
    Bod(double x, double y) {
        SouradniceX = x;
        SouradniceY = y;
    }

    void zobraz() const {
        cout << "Bod: (" << SouradniceX << ", " << SouradniceY << ")" << endl;
    }

    void posun(double x, double y) {
        SouradniceX = SouradniceX + x;
        SouradniceY = SouradniceY + y;
    }

    void otoceni(double uhel) {
        double radiany = uhel * 3.14159265359 / 180;

        double noveX = SouradniceX * cos(radiany)
                     - SouradniceY * sin(radiany);

        double noveY = SouradniceX * sin(radiany)
                     + SouradniceY * cos(radiany);

        SouradniceX = noveX;
        SouradniceY = noveY;
    }

    void zkoseniX(double hodnota) {
        SouradniceX = SouradniceX + hodnota * SouradniceY;
    }

    void zkoseniY(double hodnota) {
        SouradniceY = SouradniceY + hodnota * SouradniceX;
    }

    void zrcadleniX() {
        SouradniceY = -SouradniceY;
    }

    void zrcadleniY() {
        SouradniceX = -SouradniceX;
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
        cout << "3 - Pootoceni bodu" << endl;
        cout << "4 - Zkoseni bodu" << endl;
        cout << "5 - Zrcadleni bodu" << endl;
        cout << "6 - Konec programu" << endl;

        cout << "Vyber moznost: ";
        cin >> volba;

        switch (volba) {

        case 1:
            cout << "Zadej novou souradnici X: ";
            cin >> x;

            cout << "Zadej novou souradnici Y: ";
            cin >> y;

            bod = Bod(x, y);
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
            cout << "Konec programu." << endl;
            break;

        default:
            cout << "Neplatna volba." << endl;
        }

    } while (volba != 6);

    return 0;
}