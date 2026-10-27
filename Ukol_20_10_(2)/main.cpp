//Úloha č.2
//Vytvořte program, který bude evidovat množství ovoce  (např. jablek a hrušek) ve skladu.
// Každý druh ovoce bude mít samostatnou třídu se soukromými položkami kolik bylo koupeno a prodáno.
// Kromě nich bude mít program ještě spřátelenou funkci k oběma třídám. Tato funkce bude zjišťovat (vypíše se na obrazovku),
// kolik je aktuálně celkové množství ovoce ve skladu (koupeno - prodáno pro každý druh ovoce).


#include <iostream>
using namespace std;

class Jablka;
class Hrusky;

void Sklad(Jablka j, Hrusky h);

class Jablka
{
private:
    int koupeno, prodano;

public:
    Jablka() : koupeno(0), prodano(0) {}

    void NastavKoupeno(int k)
    {
        koupeno = k;
    }

    void NastavProdano(int p)
    {
        prodano = p;
    }

    friend void Sklad(Jablka j, Hrusky h);
};

class Hrusky
{
private:
    int koupeno, prodano;

public:
    Hrusky() : koupeno(0), prodano(0) {}

    void NastavKoupeno(int k)
    {
        koupeno = k;
    }

    void NastavProdano(int p)
    {
        prodano = p;
    }

    friend void Sklad(Jablka j, Hrusky h);
};

void Sklad(Jablka j, Hrusky h)
{
    int jablka = j.koupeno - j.prodano;
    int hrusky = h.koupeno - h.prodano;

    cout << "\n--- Stav skladu ---" << endl;
    cout << "Jablka na sklade: " << jablka << endl;
    cout << "Hrusky na sklade: " << hrusky << endl;
    cout << "Celkove mnozstvi ovoce: "
         << jablka + hrusky << endl;
}

int main()
{
    Jablka j;
    Hrusky h;

    int volba;
    int mnozstvi;

    do
    {
        cout << "\n------ MENU ------" << endl;
        cout << "1. Zadat nakoupene mnozstvi jablek" << endl;
        cout << "2. Zadat prodane mnozstvi jablek" << endl;
        cout << "3. Zadat nakoupene mnozstvi hrusek" << endl;
        cout << "4. Zadat prodane mnozstvi hrusek" << endl;
        cout << "5. Vypsat aktualni mnozstvi ovoce ve skladu" << endl;
        cout << "0. Konec programu" << endl;
        cout << "Vyberte moznost: ";
        cin >> volba;

        switch (volba)
        {
            case 1:
                cout << "Zadejte pocet koupenych jablek: ";
                cin >> mnozstvi;
                j.NastavKoupeno(mnozstvi);
                break;

            case 2:
                cout << "Zadejte pocet prodanych jablek: ";
                cin >> mnozstvi;
                j.NastavProdano(mnozstvi);
                break;

            case 3:
                cout << "Zadejte pocet koupenych hrusek: ";
                cin >> mnozstvi;
                h.NastavKoupeno(mnozstvi);
                break;

            case 4:
                cout << "Zadejte pocet prodanych hrusek: ";
                cin >> mnozstvi;
                h.NastavProdano(mnozstvi);
                break;

            case 5:
                Sklad(j, h);
                break;

            case 0:
                cout << "Program ukoncen." << endl;
                break;

            default:
                cout << "Neplatna volba!" << endl;
        }

    } while (volba != 0);

    return 0;
}
