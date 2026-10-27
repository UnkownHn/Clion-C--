//*Úloha č. 1
//Vytvořte třídu pro komplexní číslo. Tato třída bude obsahovat dvě proměnné - reálnou a imaginární složku.
//Následně v hlavní smyčce programu vytvořte čtyři instance. U prvních dvou instancí naplňte z klávesnice reálnou a imaginární složku -
//použijte pro to konstruktor. Do třetí instance uložte součet a do čtvrté rozdíl prvních dvou komplexních čísel (složek z prvních dvou instancí).
//Výsledky zobrazte v konzolovém okně.*//

// const = funkce nesmí měnit objekt

#include <iostream>
using namespace std;

class KomplexniCislo {
private:
    int realna;
    int imaginarni;

public:
    KomplexniCislo(int a, int b) {
        realna = a;
        imaginarni = b;
    }
    //metody
    void zobraz() const {
        cout << realna;

        if (imaginarni >= 0)
            cout << " + " << imaginarni << "i";
        else
            cout << " - " << -imaginarni << "i";

        cout << endl;
    }

    KomplexniCislo soucet(KomplexniCislo cislo) const {
        return KomplexniCislo(
            realna + cislo.realna,
            imaginarni + cislo.imaginarni
        );
    }

    KomplexniCislo rozdil(KomplexniCislo cislo) const {
        return KomplexniCislo(
            realna - cislo.realna,
            imaginarni - cislo.imaginarni
        );
    }
};

int main() {
    int a, b;
    //1
    cout << "Zadej realnou cast prvniho cisla: ";
    cin >> a;

    cout << "Zadej imaginarni cast prvniho cisla: ";
    cin >> b;

    KomplexniCislo cislo1(a, b);

    //2
    cout << "Zadej realnou cast druheho cisla: ";
    cin >> a;

    cout << "Zadej imaginarni cast druheho cisla: ";
    cin >> b;

    KomplexniCislo cislo2(a, b);

    KomplexniCislo cislo3 = cislo1.soucet(cislo2);

    KomplexniCislo cislo4 = cislo1.rozdil(cislo2);

    cout << endl;
    cout << "Prvni komplexni cislo: ";
    cislo1.zobraz();

    cout << "Druhe komplexni cislo: ";
    cislo2.zobraz();

    cout << "Soucet: ";
    cislo3.zobraz();

    cout << "Rozdil: ";
    cislo4.zobraz();

    return 0;
}