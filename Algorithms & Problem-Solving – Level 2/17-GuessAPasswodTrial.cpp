#include <iostream>
using namespace std;




string ReadString(string Message)
{
    string word = "";  
    do
    {
        cout << Message << endl;  
        getline(cin , word);  
    } while (word == "");  

    return word;  
}



bool GuessPassword(string OriginalPassword)
{
    string word = "";  
    int Counter = 0;   

    cout << "\n";      

    for (int i = 65; i <= 90; i++)         
    {
        for (int j = 65; j <= 90; j++)     
        {
            for (int k = 65; k <= 90; k++) 
            {
              
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                
                Counter++;  
                cout << "Trial [" << Counter << "] : " << word << endl;
                

                if (word == OriginalPassword)
                {
                    cout << "\nPassword is " << word << "\n";
                    cout << "Found after " << Counter << " Trial(s)\n";
                    
                    return true;  
                }
                
                word = "";
            }
        }
    }
    
    return false;  
}

int main(){


      GuessPassword(ReadString("Enter Your Password"));

      return 0;
}