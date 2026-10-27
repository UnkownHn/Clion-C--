//Úloha č. 1
//Vytvořte program na řešení kvadratické rovnice pomocí objektového programování.
//Vytvořte třídu KvadratickaRovnice, která bude mít tři atributy - koeficienty kvadratické rovnice - A, B a C.
//Tyto koeficienty vytvořte jako DYNAMICKÉ proměnné. Přidejte konstruktor a destruktor a všechny potřebné metody.
//Vytvořte jednu DYNAMICKOU instanci. A následně přidejte jednoduché menu s nastavením koeficientů a výpočtem kvadratické rovnice.
//Ošetřete všechny stavy řešení.
//ax² + bx + c = 0 ( a nesmi byt 0 )

#include <iostream>
#include <cmath>
using namespace std;

class KvadratickaRovnice
{
private:
    double *A;
    double *B;
    double *C;

public:
    // Konstruktor
    KvadratickaRovnice()
    {
        A = new double(1);
        B = new double(0);
        C = new double(0);
    }

    // Destruktor
    ~KvadratickaRovnice()
    {
        delete A;
        delete B;
        delete C;
    }

    // Nastaveni koeficientu
    void NastavA(double a) const {
        *A = a;
    }

    void NastavB(double b) const {
        *B = b;
    }

    void NastavC(double c) const {
        *C = c;
    }

    // Vypis koeficientu
    void VypisKoeficienty() const {
        cout << "A = " << *A << endl;
        cout << "B = " << *B << endl;
        cout << "C = " << *C << endl;
    }

    // Vypocet kvadraticke rovnice
    void Vypocitej()
    {
        if (*A == 0)
        {
            cout << "Chyba: Koeficient A nesmi byt 0 neni kvadraticka rovnice!"
                 << endl;
            return;
        }

        double D = (*B) * (*B) - 4 * (*A) * (*C);

        cout << "Diskriminant D = " << D << endl;

        if (D > 0)
        {
            double x1 = (-(*B) + sqrt(D)) / (2 * (*A));
            double x2 = (-(*B) - sqrt(D)) / (2 * (*A));

            cout << "Rovnice ma dva ruzne realne koreny:"
                 << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (D == 0)
        {
            double x = -(*B) / (2 * (*A));

            cout << "Rovnice ma jeden dvojnasobny koren:"
                 << endl;
            cout << "x = " << x << endl;
        }
        else
        {
            cout << "Rovnice nema reseni v R cislech."
                 << endl;
        }
    }
};

int main()
{
    KvadratickaRovnice *rovnice =
        new KvadratickaRovnice();

    int volba;
    double hodnota;

    do
    {
        cout << "\n------ MENU ------" << endl;
        cout << "1. Nastavit koeficient A" << endl;
        cout << "2. Nastavit koeficient B" << endl;
        cout << "3. Nastavit koeficient C" << endl;
        cout << "4. Vypsat koeficienty" << endl;
        cout << "5. Vypocitat rovnici" << endl;
        cout << "0. Konec" << endl;
        cout << "Vyberte moznost: ";
        cin >> volba;

        switch (volba)
        {
            case 1:
                cout << "Zadejte A: ";
                cin >> hodnota;
                rovnice->NastavA(hodnota);
                break;

            case 2:
                cout << "Zadejte B: ";
                cin >> hodnota;
                rovnice->NastavB(hodnota);
                break;

            case 3:
                cout << "Zadejte C: ";
                cin >> hodnota;
                rovnice->NastavC(hodnota);
                break;

            case 4:
                rovnice->VypisKoeficienty();
                break;

            case 5:
                rovnice->Vypocitej();
                break;

            case 0:
                cout << "Program ukoncen." << endl;
                break;

            default:
                cout << "Neplatna volba!" << endl;
        }

    } while (volba != 0);

    delete rovnice;

    return 0;
}