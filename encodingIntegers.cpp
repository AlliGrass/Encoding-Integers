#include <iostream>
#include <string> // added to use std::string

using namespace std;

int countDigits(int num) {
    int count = 0;

    if (num == 0)
        return 1;

    while (num != 0) {
        num /= 10;
        count++;
    }

    return count;
}

int main()
{
    int data, newdata;
    string protection; // added to use extra protection

    cout << "Enter data: " << endl;
    cin >> data;

    while (data > 99999999 || data < 10) {
        cout << "Enter valid data: " << endl;
        cin >> data;
    }

    int digitcount = countDigits(data);
    cout << "Number contains " << digitcount << " digits." << endl;

    switch (digitcount) {
        case 2:
        {
            int digit1 = (data / 10) % 10;
            int digit2 = data % 10;

            newdata = digit2 * 10 + digit1;

            cout << "Encoded number is " << newdata << endl;
            break;
        }

        case 3:
        {
            int digit1 = (data / 100) % 10;
            int digit2 = (data / 10) % 10;
            int digit3 = data % 10;

            newdata = digit3 * 100 + digit2 * 10 + digit1;

            cout << "Encoded number is " << newdata << endl;
            break;
        }

        case 8:{

            int multiplier = 1;
            int remainder;
            int newdata = 0; // initialized newdata

            for (int i = 0; i < digitcount; i++) {
                remainder = (data % 10 + i + 1) % 10;
                newdata += remainder * multiplier;
                data /= 10;
                multiplier *= 10;
            }

            cout << "Encoded number is: " << newdata << endl;

            cout << "Would you like to enable extra protection? (Yes/No)" << endl;
            cin >> protection;

            if (protection == "Yes")
            {
                string dataString = to_string(newdata); // use newdata for swap operation
                swap(dataString[0], dataString[7]);
                swap(dataString[1], dataString[6]);
                swap(dataString[2], dataString[5]);
                swap(dataString[3], dataString[4]);

                newdata = stoi(dataString); // update newdata with swapped value

                cout << "Encoded number is " << newdata << endl;


        	} else if (protection == "No")
        	{
        		cout << "Encoded number is " << newdata << endl;
        	}

        	break;

        }


        default: {

        	int multiplier = 1;
            int remainder;
            newdata = 0;

            for (int i = 0; i < digitcount; i++) {
                remainder = (data % 10 + i + 1) % 10;
                newdata += remainder * multiplier;
                data /= 10;
                multiplier *= 10;
            }

            cout << "Encoded number is " << newdata << endl;
            break;
			}
    }

    return 0;
}
