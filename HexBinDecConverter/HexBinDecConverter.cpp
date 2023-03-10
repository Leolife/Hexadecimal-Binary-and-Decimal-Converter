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
            << "\n" << setw(20) << "4) Bin to Dec" << "\n" << setw(20) << "5) Dec to Hex" << "\n" << setw(20) << "6) Dec to Bin" << endl;
    }
};

class hexToDec
{
private:
    int numObj;
    int decimal = 0;
    int n = 0; //exponent of 16 for calculations
    int power; //power of 16 for caluclations
public:
    void hexDec(string obj)
    {
        for (int i = (obj.size() - 1); i >= 0; i--)
        {
            if (obj[i] == '1' || obj[i] == '2' || obj[i] == '3' || obj[i] == '4' || obj[i] == '5' || obj[i] == '6' || obj[i] == '7' || obj[i] == '8' || obj[i] == '9')
            {
                numObj = obj[i] - '0';
            }
            else if (obj[i] == 'A')
            {
                numObj = 10;
            }
            else if (obj[i] == 'B')
            {
                numObj = 11;
            }
            else if (obj[i] == 'C')
            {
                numObj = 12;
            }
            else if (obj[i] == 'D')
            {
                numObj = 13;
            }
            else if (obj[i] == 'E')
            {
                numObj = 14;
            }
            else if (obj[i] == 'F')
            {
                numObj = 15;
            }
            power = pow(16, n);
            decimal += (numObj * power);
            n++;
        }
        cout << "Number: " << decimal;
    }
};

class hexToBin
{
private:
    string bin;
    string currentBin;
    int numObj;
    int n = 0; //exponent for power of 2 in regards to binary
    int highestPower; //highest power of 2 that is less than the obj
public:
    void hexBin(string obj)
    {
        for (int i = 0; i <= obj.size(); i++)
        {
            if (obj[i] == '1' || obj[i] == '2' || obj[i] == '3' || obj[i] == '4' || obj[i] == '5' || obj[i] == '6' || obj[i] == '7' || obj[i] == '8' || obj[i] == '9')
            {
                currentBin = "";
                numObj = obj[i] - '0';
                while ((highestPower = pow(2, n)) < numObj)
                    n++;
                while (n >= 0)
                {
                    if (highestPower = pow(2, n) > numObj)
                        n--;
                    highestPower = pow(2, n);
                    if (highestPower > numObj)
                    {
                        if (currentBin.size() < 4)
                        {
                            currentBin += "0";
                        }
                    }
                    else if (highestPower <= numObj && numObj >= 1)
                    {
                        if (currentBin.size() < 4)
                        {
                            currentBin += "1";
                        }
                        numObj -= highestPower;
                    }
                }
                for (int j = currentBin.size(); j < 4; j++)
                {
                    currentBin = '0' + currentBin;
                }
                bin += currentBin;
            }
            switch (obj[i])
            {
            case 'A':
                bin += "1010";
                break;
            case 'B':
                bin += "1011";
                break;
            case 'C':
                bin += "1100";
                break;
            case 'D':
                bin += "1101";
                break;
            case 'E':
                bin += "1110";
                break;
            case 'F':
                bin += "1111";
                break;
            }
        }
        cout << "Binary: " << bin;
    }

};

class binToHex
{
private:
    int hexNum = 0;
    string hexStr;
    int binaryDecimal = 0;
    int n = 0; //exponent for purposes of converting
public:
    void binHex(string obj)
    {
        for (int i = (obj.size() - 1); i >= 0; i--)
        {
            binaryDecimal = obj[i] - '0'; //converts the binary string into an int variable
            hexNum += binaryDecimal * pow(2, n);
            n++;
            if (n == 4)
            {
                if (hexNum >= 1 && hexNum <= 9)
                {
                    hexStr += hexNum + '0';
                }
                switch (hexNum)
                {
                case 10:
                    hexStr += "A";
                    break;
                case 11:
                    hexStr += "B";
                    break;
                case 12:
                    hexStr += "C";
                    break;
                case 13:
                    hexStr += "D";
                    break;
                case 14:
                    hexStr += "E";
                    break;
                case 15:
                    hexStr += "F";
                    break;
                }
                hexNum = 0;
                n = 0;
            }
        }
        for (int i = hexStr.size(); i >= 0; i--) //Because the current hexadecimal string will print backwards, this reverses it to print correctly
        {
            cout << hexStr[i];
        }
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
            n--;
            highestPower = pow(16, n);
            remainder = obj % highestPower;
            quotientWholeNumber = obj / highestPower;
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

    if (selection == 1)
    {
        string hex;
        hexToBin a;
        cout << "Hexadecimal: ";
        cin >> hex;
        a.hexBin(hex);
    }
    else if (selection == 2)
    {
        string hex;
        hexToDec a;
        cout << "Hexadecimal: ";
        cin >> hex;
        a.hexDec(hex);
    }
    else if (selection == 3)
    {
        string bin;
        binToHex a;
        cout << "Binary (In increments of 4 bits): ";
        cin >> bin;
        cout << "Hexadecimal: ";
        a.binHex(bin);
    }
    else if (selection == 4)
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
