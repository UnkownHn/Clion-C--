//Úloha č.1
//Napište program pro výpočet obvodu a obsahu (podle Heronova vzorce) obecného trojúhelníku v rovině.
//Konstrukce bude následující: Třída bod, mající atributy x a y (poloha bodu) a třída trojúhelník, která bude obsahovat (agregovat) instance tří bodů,
//které charakterizují trojúhelník. Doplňte potřebné metody.


#include <iostream>
#include <cmath>
using namespace std;

class bod
{
private:
    double x, y;

public:

    bod(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    void Nastav(double noveX, double noveY)
    {
        x = noveX;
        y = noveY;
    }

    void Vypis() const
    {
        cout << "(" << x << ", " << y << ")";
    }

    double Vzdalenost(const bod& druhy) const
    {
        double dx = x - druhy.x;
        double dy = y - druhy.y;

        return sqrt(dx * dx + dy * dy);
    }
};

class trojuhelnik
{
private:
    bod A, B, C;

public:
    // Konstruktor
    trojuhelnik(bod a, bod b, bod c)
        : A(a), B(b), C(c)
    {
    }

    void VypisBody() const
    {
        cout << "A = ";
        A.Vypis();

        cout << "\nB = ";
        B.Vypis();

        cout << "\nC = ";
        C.Vypis();

        cout << endl;
    }

    void Vypocitej() const
    {
        double a = B.Vzdalenost(C);
        double b = A.Vzdalenost(C);
        double c = A.Vzdalenost(B);

        if (a + b <= c || a + c <= b || b + c <= a)
        {
            cout << "Trojuhelnik neexistuje!" << endl;
            return;
        }

        double O = a + b + c;
        double s = O / 2.0;
        double S = sqrt(s * (s - a) * (s - b) * (s - c));

        cout << "Strana a = " << a << endl;
        cout << "Strana b = " << b << endl;
        cout << "Strana c = " << c << endl;
        cout << "Obvod = " << O << endl;
        cout << "Obsah = " << S << endl;
    }
};

int main()
{
    double x, y;

    bod A, B, C;

    cout << "Zadejte souradnici x bodu A: ";
    cin >> x;
    cout << "Zadejte souradnici y bodu A: ";
    cin >> y;
    A.Nastav(x, y);

    cout << "Zadejte souradnici x bodu B: ";
    cin >> x;
    cout << "Zadejte souradnici y bodu B: ";
    cin >> y;
    B.Nastav(x, y);

    cout << "Zadejte souradnici x bodu C: ";
    cin >> x;
    cout << "Zadejte souradnici y bodu C: ";
    cin >> y;
    C.Nastav(x, y);

    trojuhelnik t(A, B, C);

    cout << "\nSouradnice vrcholu trojuhelniku:" << endl;
    t.VypisBody();

    cout << "\nVypocet trojuhelniku:" << endl;
    t.Vypocitej();

    return 0;
}
