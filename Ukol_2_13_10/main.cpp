//Úloha č. 2
//Upravte program ze 2 výukového týdne (struktura Zaměstnanec se jménem (DYNAMICKÁ PROMĚNNÁ), příjmením, rokem narozením, a výší platu) do objektového programování - vytvořte třídu Zaměstnanec. Následně vytvořte pole instancí této třídy. Do hlavního menu přidejte:
//1. Vložení nového zaměstnance (s možností kopie jiné již dříve vytvořené instance - použijte k tomu kopírovací konstruktor)
//2. Výpočet průměrné mzdy všech zaměstnanců.
//3. Vypsání jména a příjmení nejstaršího a nejmladšího zaměstnance.
//4. Vypsání všech zaměstnanců na obrazovku.
//5. Ukončení programu.

#include <iostream>
#include <fstream>
using namespace std;

class Zamestnanec
{
public:
    char* jmeno;
    char prijmeni[20];
    int roknarozeni;
    float plat;

    // Konstruktor
    Zamestnanec()
    {
        jmeno = new char[20];
        jmeno[0] = '\0';
        prijmeni[0] = '\0';
        roknarozeni = 0;
        plat = 0;
    }

    // Kopirovaci konstruktor
    Zamestnanec(const Zamestnanec& z)
    {
        jmeno = new char[20];

        int i = 0;
        while (z.jmeno[i] != '\0' && i < 19)
        {
            jmeno[i] = z.jmeno[i];
            i++;
        }
        jmeno[i] = '\0';

        i = 0;
        while (z.prijmeni[i] != '\0' && i < 19)
        {
            prijmeni[i] = z.prijmeni[i];
            i++;
        }
        prijmeni[i] = '\0';

        roknarozeni = z.roknarozeni;
        plat = z.plat;
    }

    // Destruktor
    ~Zamestnanec()
    {
        delete[] jmeno;
    }

    // Nacteni udaju
    void Nacti()
    {
        char noveJmeno[20];

        cout << "Jmeno: ";
        cin >> noveJmeno;

        int i = 0;
        while (noveJmeno[i] != '\0' && i < 19)
        {
            jmeno[i] = noveJmeno[i];
            i++;
        }
        jmeno[i] = '\0';

        cout << "Prijmeni: ";
        cin >> prijmeni;

        cout << "Rok narozeni: ";
        cin >> roknarozeni;

        cout << "Plat: ";
        cin >> plat;
    }
};

int main()
{
    const int MAX = 100;
    int pocet = 3;

    Zamestnanec zamestnanci[MAX];

    // Prvni zamestnanec
    Zamestnanec prvni;
    char j1[] = "Dan";
    int i = 0;
    while (j1[i] != '\0')
    {
        prvni.jmeno[i] = j1[i];
        i++;
    }
    prvni.jmeno[i] = '\0';

    char p1[] = "Novak";
    i = 0;
    while (p1[i] != '\0')
    {
        prvni.prijmeni[i] = p1[i];
        i++;
    }
    prvni.prijmeni[i] = '\0';
    prvni.roknarozeni = 1980;
    prvni.plat = 35000;

    // Zkopirovani udaju do prvniho zamestnance v poli
    i = 0;
    while (prvni.jmeno[i] != '\0')
    {
        zamestnanci[0].jmeno[i] = prvni.jmeno[i];
        i++;
    }
    zamestnanci[0].jmeno[i] = '\0';

    i = 0;
    while (prvni.prijmeni[i] != '\0')
    {
        zamestnanci[0].prijmeni[i] = prvni.prijmeni[i];
        i++;
    }
    zamestnanci[0].prijmeni[i] = '\0';
    zamestnanci[0].roknarozeni = prvni.roknarozeni;
    zamestnanci[0].plat = prvni.plat;

    // Druhy zamestnanec
    char j2[] = "Martin";
    i = 0;
    while (j2[i] != '\0')
    {
        zamestnanci[1].jmeno[i] = j2[i];
        i++;
    }
    zamestnanci[1].jmeno[i] = '\0';

    char p2[] = "Svobodny";
    i = 0;
    while (p2[i] != '\0')
    {
        zamestnanci[1].prijmeni[i] = p2[i];
        i++;
    }
    zamestnanci[1].prijmeni[i] = '\0';
    zamestnanci[1].roknarozeni = 1965;
    zamestnanci[1].plat = 42000;

    // Treti zamestnanec
    char j3[] = "Anna";
    i = 0;
    while (j3[i] != '\0')
    {
        zamestnanci[2].jmeno[i] = j3[i];
        i++;
    }
    zamestnanci[2].jmeno[i] = '\0';

    char p3[] = "Dvorakova";
    i = 0;
    while (p3[i] != '\0')
    {
        zamestnanci[2].prijmeni[i] = p3[i];
        i++;
    }
    zamestnanci[2].prijmeni[i] = '\0';
    zamestnanci[2].roknarozeni = 1995;
    zamestnanci[2].plat = 30310;

    int volba;

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Vlozit noveho zamestnance\n";
        cout << "2. Vypocitat prumernou mzdu\n";
        cout << "3. Nejstarsi a nejmladsi zamestnanec\n";
        cout << "4. Vypsat vsechny zamestnance\n";
        cout << "5. Ukoncit program\n";
        cout << "Vyberte moznost: ";
        cin >> volba;

        switch (volba)
        {
        case 1:
        {
            if (pocet >= MAX)
            {
                cout << "Pole je plne.\n";
                break;
            }

            int kopie;
            cout << "Chcete zkopirovat zamestnance? (1 = ano, 0 = ne): ";
            cin >> kopie;

            if (kopie == 1)
            {
                int cislo;
                cout << "Cislo zamestnance ke kopii (1-"
                     << pocet << "): ";
                cin >> cislo;

                if (cislo >= 1 && cislo <= pocet)
                {
                    // Kopirovaci konstruktor
                    Zamestnanec nova(zamestnanci[cislo - 1]);

                    // Prekopirovani do dalsiho mista v poli
                    i = 0;
                    while (nova.jmeno[i] != '\0')
                    {
                        zamestnanci[pocet].jmeno[i] = nova.jmeno[i];
                        i++;
                    }
                    zamestnanci[pocet].jmeno[i] = '\0';

                    i = 0;
                    while (nova.prijmeni[i] != '\0')
                    {
                        zamestnanci[pocet].prijmeni[i] = nova.prijmeni[i];
                        i++;
                    }
                    zamestnanci[pocet].prijmeni[i] = '\0';

                    zamestnanci[pocet].roknarozeni = nova.roknarozeni;
                    zamestnanci[pocet].plat = nova.plat;

                    pocet++;
                    cout << "Zamestnanec byl zkopirovan.\n";
                }
                else
                {
                    cout << "Neplatne cislo zamestnance.\n";
                }
            }
            else if (kopie == 0)
            {
                zamestnanci[pocet].Nacti();
                pocet++;
                cout << "Zamestnanec byl pridan.\n";
            }
            else
            {
                cout << "Neplatna volba.\n";
            }

            break;
        }

        case 2:
        {
            float soucet = 0;

            for (int i = 0; i < pocet; i++)
                soucet += zamestnanci[i].plat;

            cout << "Prumerna mzda: "
                 << soucet / pocet << " Kc\n";
            break;
        }

        case 3:
        {
            int nejstarsi = 0;
            int nejmladsi = 0;

            for (int i = 1; i < pocet; i++)
            {
                if (zamestnanci[i].roknarozeni <
                    zamestnanci[nejstarsi].roknarozeni)
                    nejstarsi = i;

                if (zamestnanci[i].roknarozeni >
                    zamestnanci[nejmladsi].roknarozeni)
                    nejmladsi = i;
            }

            cout << "Nejstarsi: "
                 << zamestnanci[nejstarsi].jmeno << " "
                 << zamestnanci[nejstarsi].prijmeni << endl;

            cout << "Nejmladsi: "
                 << zamestnanci[nejmladsi].jmeno << " "
                 << zamestnanci[nejmladsi].prijmeni << endl;
            break;
        }

        case 4:
        {
            for (int i = 0; i < pocet; i++)
            {
                cout << i + 1 << ". "
                     << zamestnanci[i].jmeno << " "
                     << zamestnanci[i].prijmeni
                     << ", rok narozeni: "
                     << zamestnanci[i].roknarozeni
                     << ", plat: " << zamestnanci[i].plat
                     << " Kc\n";
            }
            break;
        }

        case 5:
            cout << "Program byl ukoncen.\n";
            break;

        default:
            cout << "Neplatna volba.\n";
        }

    } while (volba != 5);

    return 0;
}