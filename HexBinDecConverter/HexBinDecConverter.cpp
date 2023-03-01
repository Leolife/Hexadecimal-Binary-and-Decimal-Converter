#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class menu
{
public:
    void print()
    {
        cout << setw(25) << setfill('-') << "MENU" << setw(21) << "-" << setfill('-') << endl;
        cout << "       " << setw(25) << setfill('-') << "Select Conversion" << setw(7) << "-" << "       " << setfill(' ');
        cout << "\n" << setw(20) << "1) Hex to Bin" << "\n" << setw(20) << "2) Hex to Dec" << "\n" << setw(20) << "3) Bin to Hex" 
            << "\n" << setw(20) << "4) Bin to Dec" << "\n" << setw(20) << "5) Dec to Hex" << "\n" << setw(20) << "6) Dec to Bin" <<endl;
    }
};

class binToDec
{
private:
    int n = 0; //exponent of 2 to find the highest power
    int number = 0;
public:
    void binDec(string obj)
    {
        for (int i = obj.size(); i > 0; i--)
        {
            string objCopy;
            objCopy = obj[i - 1];
            if (objCopy == "1")
            {
                number += pow(2, (n));
            }
            n++;
        }
        cout << "Number: " << number;
    }

};

class decToHex
{
private:
    int n = 0; //exponent of 16 to find the highest power
    int highestPower; //highest power of 16 that is less than the obj
    int remainder;
    int quotientWholeNumber;
public:
    void decHex(int obj)
    {
        while ((highestPower = pow(16, n)) < obj)
            n++;
        while (n > 0)
        {
            n--; // 1
            highestPower = pow(16, n); // 16
            remainder = obj % highestPower; // 8
            quotientWholeNumber = obj / highestPower; // 14
            if (quotientWholeNumber > 0 && quotientWholeNumber <= 9)
            {
                cout << quotientWholeNumber;
            }
            switch (quotientWholeNumber)
            {
            case 10:
                cout << "A";
                break;
            case 11:
                cout << "B";
                break;
            case 12:
                cout << "C";
                break;
            case 13:
                cout << "D";
                break;
            case 14:
                cout << "E";
                break;
            case 15:
                cout << "F";
                break;
            }
            if (remainder < 16)
            {
                cout << remainder;
                break;
            }
            obj = remainder;
        }
    }
};

class decToBin
{
private:
    int n = 0; //exponent of 2 to find the highest power
    int highestPower; //highest power of 2 that is less than the input
    string bin;
public:
    void decBin(int obj)
    {
        while ((highestPower = pow(2, n)) < obj)
            n++;
        while (n >= 0)
        {
            n--;
            highestPower = pow(2, n);
            if (highestPower > obj)
            {
                bin += "0";
            }
            else if (highestPower <= obj && highestPower > 0)
            {
                bin += "1";
                obj -= highestPower;
            }
        }
        cout << "Binary: " << bin;
    }
};


int main()
{
    menu menu;
    menu.print();
    int selection;

    cout << "\n" << setw(24) << "Select conversion: ";
    cin >> selection;
    cout << endl;

    if (selection == 4)
    {
        string bin;
        binToDec a;
        cout << "Binary: ";
        cin >> bin;
        a.binDec(bin);

    }
    else if (selection == 5)
    {
        int num;
        decToHex a;
        cout << "Number: ";
        cin >> num;
        cout << "Hexadecimal: ";
        a.decHex(num);
    }
    else if (selection == 6)
    {
        int num;
        decToBin a;
        cout << "Number: ";
        cin >> num;
        a.decBin(num);
    }
    cout << endl;
}
