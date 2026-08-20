#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadPinCode
// Purpose: Prompts the user to enter a PIN code and reads it from input.
// Returns: A string containing the entered PIN code.
string ReadPinCode()
{
    string PinCode;  // Variable to store the entered PIN code.

    // Prompt the user to enter their PIN code.
    cout << "Please enter PIN code \n";
    cin >> PinCode;

    return PinCode;  // Return the entered PIN code.
}

// Function: Login
// Purpose: Authenticates the user by checking if the entered PIN matches "1234".
// Returns: true if login is successful, false otherwise.
bool Login()
{
    string PinCode;  //


    do
    {
        PinCode = ReadPinCode();  

        if (PinCode == "1234")  
        {
            return true;  
        }
        else
        {
            cout << "\nWrong PIN\n";  
            system("color 4F");  
        }

    } while (PinCode != "1234");  

    return false;  
}


int main()
{
    if (Login())
    {
        system("color 2F");  
        cout << "\nYour account balance is " << 7500 << '\n';  
    }

    return 0;  
}