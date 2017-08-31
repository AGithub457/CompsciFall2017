#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
        double c, f;
        double maxChar;
        double cArr[] = {212.0, 72.0, 32.0};

        cout << fixed << showpoint << setprecision(1);
        cout << right;

        cout << endl;
        cout << "Temperature Program" << endl;
        cout << "-------------------" << endl;

        //F -> C
        cout << endl;
        cout << "Fahrenheit  Celsius" << endl;
        cout << "----------  -------" << endl;

        for(double i : cArr) {
          int length = (int)to_string(i).length();
          cout << length << endl;
        }
        //Temperature 1 of 3
        f = 212.0;
        c = 5.0 / 9.0 * (f - 32);
        cout << setw(10) << f << "  " << setw(7) << c << endl;

        //Temperature 2 of 3
        f = 72.0;
        c = 5.0 / 9.0 * (f - 32);
        cout << setw(10) << f << "  " << setw(7) << c << endl;

        //Temperature 1 of 3
        f = 32.0;
        c = 5.0 / 9.0 * (f - 32);
        cout << setw(10) << f << "  " << setw(7) << c << endl;

        //C -> F
        cout << endl;
        cout << "Celsius  Fahrenheit" << endl;
        cout << "-------  ----------" << endl;

        //Temperature 1 of 8
        c = 100.0;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;

        //Temperature 2 of 8
        c = 40.0;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;

        //Temperature 3 of 8
        c = 30.0;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;

        //Temperature 4 of 8
        c = 22.2;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;

        //Temperature 5 of 8
        c = 20.0;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;

        //Temperature 6 of 8
        c = 10.0;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;

        //Temperature 7 of 8
        c = 0.0;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;

        //Temperature 8 of 8
        c = -40.0;
        f = (9.0 / 5.0 * c) + 32;
        cout << setw(7) << c << "  " << setw(10) << f << endl;
}
