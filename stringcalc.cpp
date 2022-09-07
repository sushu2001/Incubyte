/*  Name: Sushant Sudhakar Awathare  
    Date: 07/09/2022 */

/*************************** STRING CALCULATOR ***************************/

#include<bits/stdc++.h>
using namespace std;

class StringCalculator{
private:
    string numbers;
public:
    StringCalculator(){}
    StringCalculator(string n){             // Initialization of parameterized constructor
        this->numbers = n;                  // This pointer is used to store the address of its self
    }
    int add(string numbers){
        int stringLength = numbers.size();  // Declaration of length of the string by using size() function
        int addition = 0;                   // Declaration of addition of numbers in the string
        string tempAnswer = "";

        bool ifNegative = false; 
        bool nextLine = false, Negative = false;
        vector<int> numberOfNegatives;

        for(int i=0; i < stringLength; i++){
            char ch = numbers[i];
            
            if(isdigit(ch)){                // To check whether character is  a digits (0 to 9) or not
                tempAnswer += ch;
            }
            else if(isalpha(ch)){           // To check whether character is  a alphaNumneric (lowecase & uppercase) or not
                int temp = ch - 'a' + 1;
                tempAnswer += to_string(temp);
            }
            else if((int)ch == 10 || ch==';'){
                nextLine = true;
            }
            else if(ch == '-'){
                ifNegative = true;
                Negative = true;
                continue;
            }
            else if(ch != ','){
                continue;
            }

            if((ch == ',' || i == stringLength-1 || nextLine) && tempAnswer.size() > 0){
                // cout << num << " ";
                int number = stoi(tempAnswer);
                tempAnswer = "";

                if(Negative){                             // if the number is negative then push it into the vector
                    numberOfNegatives.push_back(-number);
                    Negative = false;
                    continue;
                }
                nextLine = false;

                if(number > 1000) continue;
                addition += number;
            }
        }

        if(ifNegative){                                   // to check negative numbers in the array and to throw an exception
            for(auto &negNum : numberOfNegatives){
                cout << negNum << " ";
            }
            cout << endl;
            throw invalid_argument( "Negatives Not Allowed" );
        }

        return addition;           //Return the Result of Adfition of string

    }
};

int main()
{
    StringCalculator sc;
    int x = sc.add("1\n2,3");
    cout << "The Output of Test Case 5: " << endl;
    cout << "Input \"1\n2,3\": "<< x << endl;
    return 0;
}