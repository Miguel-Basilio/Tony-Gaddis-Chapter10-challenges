//Miguel Basilio
// 2/16/2022
// 


#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>
#include "input121.h"

using namespace std;

int menuOption(); //prototype
void Challenge11();
void Challenge13();

// Determines the correct month name
string months(int);
// Inserts month, day and year into the date string.
void printDate(string, int, int);

void Challenge15();
void Challenge17();

void Challenge19();
char     tryAgain();
void   getData(string&, string&, string&);
void   checkRecipient(string&);
void     checkAmount(string&);
string removePunct(string&);
string toHundred(const string*, const string*, int);
string toThousand(string, const string*, int);
string toTenThousand(string, const string*, int);
string numToWord(string);
string formatCheck(string, string&, string);
void   displayCheck(string, const string, const string, const string);
// Validating input:
bool checkDate(string);


int main() //driver*
{


    cout << "\tMiguel Basilio\n";
    cout << "\tCMPR121" << endl;

    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
 
        case 11: Challenge11(); break;
        case 13: Challenge13(); break;
        case 15: Challenge15(); break;
        case 17: Challenge17(); break;
        case 19: Challenge19(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}


int menuOption()
{
    cout << " Chapter 10: assigment by Miguel Basilio" << endl;
    cout << "\n" << string(80, '-');
    cout << "\n\t 0. Exit.";
    cout << "\n\t 11. Challenge 11";
    cout << "\n\t 13. Challenge 13";
    cout << "\n\t 15. Challenge 15";
    cout << "\n\t 17. Challenge 17";
    cout << "\n\t 19. Challenge 19";
    cout << "\n" << string(80, '-');
    cout << "\nt Option: ";
   
    int option;
    cin >> option;

    return option;
}

void upper(char* array)
{
    //coverts a-z to upper case
    for (int i = 0; i < strlen(array); i++)
    {
        // check the characters is alphabet and convert to Uppercase
        if (isalpha(array[i]))
            array[i] = toupper(array[i]);
    }
}
void lower(char* array)
{
    //coverts a-z to upper case
    for (int i = 0; i < strlen(array); i++)
    {
        // check the characters is alphabet and convert to lowercase
        if (isalpha(array[i]))
            array[i] = tolower(array[i]);
    }
}
void reverse(char* array)
{
    //convert uppercase to lowercase and viceversa
    for (int i = 0; i < strlen(array); i++)
    {
       
        if (isupper(array[i]))
            array[i] = tolower(array[i]);
        else 
            array[i] = toupper(array[i]);

    }
}
void Challenge11()
{//document all functions:

    //promp user for size of array
    int size = inputInteger("Enter a size for the dinamic array: ", true); //forces to pass positives integers
    // dinamically allocate the array
    char *input = new char[size];
    cout << "Enter a String" << endl;
    cin.getline(input, size);
    //calling upper(), lower(), and reverse()
    reverse(input);
    cout << "\n" << input << endl;

    upper(input);
    cout << "\n" << input << endl;

    // char input[80] = "Miguel Basilio";
    lower(input);
    cout << "\n" << input << endl;
    //dealocate array
    delete[] input;
}
void Challenge13()
{
  
    int    month = 0,
        day = 0,
        year = 0;
    string date = " ";

    cout << "\n\tDATE PRINTER" << endl;
    cout  <<"Enter a date in the format 'mm/dd/yyyy', year must be between 1960 and 2100" << endl;
    cout<<"Please enter a date: ";
    getline(cin, date);

    while (checkDate(date) == false)
    {
        if (checkDate(date) == false)
        {
            cout << "The date is invalid try again.\n"
                << "Please enter a date: " << endl;
            getline(cin, date);
        }
    }

    month = stoi(date.substr(0));
    day = stoi(date.substr(3));
    year = stoi(date.substr(6));

    date = months(month);
    printDate(date, day, year);
}
bool checkDate(string date)
{
    //validating date
    bool validDate = true;
    bool isLeapYear = false;
    int  month = 0,
        day = 0,
        year = 0;
    char delimiter = '/';

    if (date.length() < 10)
    {
        return validDate = false;
    }
    //retrieving the ints out of the string
    if (date.at(2) != delimiter || date.at(5) != delimiter)
    {
        validDate = false;
    }
    //converting string numbers to int
    month = stoi(date.substr(0));

    if (month < 1 || month > 12)
    {
        validDate = false;
    }

    day = stoi(date.substr(3));

    if (day < 1 || day > 31)
    {
        validDate = false;
    }

    year = stoi(date.substr(6));

    if (year < 1960 || year > 2100)
    {
        validDate = false;
    }
    //validating the month of february for 28 or 29 days (leap year)
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        isLeapYear = true;
    }

    if (isLeapYear && month == 2 && day > 29)
    {
        validDate = false;
    }

    if (isLeapYear == false && month == 2 && day > 28)
    {
        validDate = false;
    }

    return validDate;
}
//adding month to date:
string months(const int month)
{
    const string monthNames[12] = { "January", "February", "March",
                                              "April", "May", "June", "July",
                                              "August", "September", "October",
                                              "November", "December" };

    return monthNames[month - 1];
}
//prints date
void printDate(string date, int day, int year)
{
    date.insert(date.length(), " " + to_string(day) + ", " + to_string(year));

    cout << "Date entered: " << date << endl;
}
void Challenge15()
{

    ifstream inputFile;
    //inputFile.open("text.txt");
    int uppercase = 0;
    int lowerCases = 0;
    int digits = 0;

    string fileName;

    cout << "enter name: " << endl;

    cin >> fileName;

    inputFile.open(fileName);

    if (inputFile.fail())
    {
        cout << " ERROR: cannot find fiel, " << fileName << endl;
        return;
    }
    string inputString; //counts 
    while (inputFile >> inputString && !inputFile.eof())
    {
        //
        for (int i = 0; i < inputString.length(); i++)
        {
            if (isupper(inputString[i]))
                uppercase++;
            if (islower(inputString[i]))
                lowerCases++;
            else if (isdigit(inputString[i]))
                digits++;
        }
    }
    //Closes File
    inputFile.close();
    //Outputs:
    cout << "Upper Case letter: " << uppercase << endl;
    cout << "Lower Case letter: " << lowerCases << endl;
    cout << "Digits counted: " << digits << endl;
}
void Challenge17()
{//assigning morse simbols 0-9, alphabet and morse conversion
    string digits[10] = { "-----", ".----","..---","...--","....-",".....","-....","--...","---..","----."};
    string morse[] = {".-","-...", "-.-.", "-..", ".", "..-.", "--.", "....",  "..",  ".---",  "-.-",
        ".-..", "--", "-.",  "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    
    
    
    //morse Code Convertor:
    string message; 
    string temp;
   //ask user for input
    cout << "Enter Message: ";
    //clears keyboard input to avoid errors on user input
    cin.ignore(); 
    getline(cin, message);
  
   
    //counts message
    for (int i = 0; i < message.length(); i++)
    {   
        //converting uppercase to lowercase
        if (isalpha(message[i]))
            message[i] = tolower(message[i]);
        //loop trough alphabet array to compare message input
        for (int j = 0; j < 26; j++)
        {
            string newMessage = " "; //to hold morse message
            //loops trough message and assigns morse code to each letter
            if (message[i] == alphabet[j])
            {
                newMessage += morse[j];
                newMessage += " ";
                // displays morse code message
                cout << newMessage;
            }
            
        }
        
           //checks if message contains any numbers
        if (isdigit(message[i]))
        {
            //
            cout << digits[message[i] - '0'] << " ";
        }
        //checks for spaces in message
        else if (isspace(message[i]))
            cout << " space ";
           
        //continue check for: , . '
        else if (message[i] == ',')
            cout << "--..--";
        else if (message[i] =='.')
            cout << ".-.-.-" << endl;
        else if (message[i] == '?')
            cout << "..--..";
    }
}

void Challenge19()
{
    //reuse date format from challenge 13.
    string amount;
    string date;
    string recipient;
    string centAmount;
    string wordAmount;
    char   again = ' ';

    do
    {
        amount.clear();
        date.clear();
        recipient.clear();
        wordAmount.clear();
        centAmount.clear();

        getData(amount, date, recipient);
        wordAmount = formatCheck(amount, wordAmount, centAmount);
        displayCheck(amount, date, recipient, wordAmount);

        again = tryAgain();

        if (again == 'N')
        {
            cout << "\Thank you! Have a nice day!" << endl;
        }

    } while (again != 'N');


}

  // getting customers data:

void getData(string& amount, string& date, string& recipient)
{
    cout << "\n\n\t\t\tCHECK WRITER\n\n"
        << "\n\tPlease enter the recipient's name: ";
    getline(cin, recipient);

    while (recipient.empty())
    {
        cout << "\n\tDear customer, the name field must not be empty!" << endl;
        cout << "\tPlease enter the recipient's name: ";
        getline(cin, recipient);
    }

    checkRecipient(recipient);

    cout << "\n\tPlease enter date: (Ex: 05/08/2017)" << endl;
    getline(cin, date);
    while (checkDate(date) == false)
    {
        if (checkDate(date) == false)
        {
            cout << "\n\tThe date is invalid try again.\n"
                << "\n\tremember the format shoulbe mm/dd/yyyy\n"
                << "\n\tPlease enter a date: " << endl;
            getline(cin, date);
        }
    }

    cout << "\n\tPlease enter amount: $";
    getline(cin, amount);

    checkAmount(amount);
}

//checks on the string object containing the recipient's name
void checkRecipient(string& recipient)
{
    for (size_t index = 0; index < recipient.length(); index++)
    {
        while (!isalpha(recipient.at(0)) || ispunct(recipient[index]) ||
            isdigit(recipient.at(index)) || isspace(recipient.at(0)))
        {
            cout << "\n\tField must not be empty, and it must not contain any numbers or punctuation marks!\n\n"
                << "\n\tPlease enter the recipient's name: ";
            getline(cin, recipient);
        }
    }
}

// Checks for validity of the entered amount. It must not be lower than 0.00 or higher than 9999.99.
void checkAmount(string& amount)
{
    while (stod(amount) <= 0.00 || stod(amount) > 9999.99)
    {
        cout << "\n\tInput Failure! Dear customer, you entered an amount\n"
            << "\tlower than 1 or greater than 9999.99. The maximum\n"
            << "\tamount is $9999.99.\n\n"
            << "\n\tPlease enter the desired amount:\t\t$";
        getline(cin, amount);
    }
}

//"converts" numbers between 1 and 9999.99 to words:
string numToWord(string amount)
{
    const string oToTwenty[] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten",
   "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };

    const string tenMult[] = { "", "", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninenty " };

    int     numStore = stoi(amount);
    string numWord;
    string words;

    if (amount.length() < 3)
    {
        words = toHundred(oToTwenty, tenMult, numStore);
    }
    else if (amount.length() == 3)
    {
        words = toThousand(amount, oToTwenty, numStore) +
            toHundred(oToTwenty, tenMult, numStore % 100);
    }
    else if (amount.length() == 4)
    {
        if (numStore % 1000 < 100)
        {
            words = toTenThousand(amount, oToTwenty, numStore) +
                toHundred(oToTwenty, tenMult, numStore % 100);
        }
        else
        {
            words = toTenThousand(amount, oToTwenty, numStore) +
                toThousand(amount, oToTwenty, numStore) +
                toHundred(oToTwenty, tenMult, numStore % 100);
        }
    }

    return numWord.append(words);
}
// to houndreds:
string toHundred(const string* oToTwenty,
    const string* tenMult, int numSize)
{
    string numStore;

    numSize < 20 ? numStore.append(oToTwenty[numSize]) :
        numStore.append(tenMult[numSize / 10] +
            oToTwenty[numSize % 10]);

    return numStore;
}

//to thousands:
string toThousand(string amount, const string* oToTwenty, int numSize)
{
    string numStore;

     /*This if/else statement covers all sums above and below
        below 1000. Depending on which, the corresponding subscript
        position is extracted and stored in numSize. numSize, after
        performing a calculation on it, points to the appropriate
        position in the string array containing the digit in word-
        form. */
    if (numSize > 999)
    {
        numSize = stoi(amount.erase(2, 3));
        numStore.append(oToTwenty[numSize % 1000 % 10] + "hundred ");
    }
    else
    {
        numSize = stoi(amount.erase(1, 2));
        numStore.append(oToTwenty[numSize] + "hundred ");
    }

    return numStore;
}
  //This function gets the index position of the "ten thousands"
string toTenThousand(string amount, const string* oToTwenty, int numSize)
{
    string numStore;

    numSize = stoi(amount.erase(1, 3));

    return numStore.append(oToTwenty[numSize] + "thousand ");
}

string removePunct(string& amount)
{
    string centAmount;
    //If the user enters an amount: "256.60", the cent amount is stored in a string object, and the '.' is erased.
//If the user enters an amount: "256" without '.', '00' is appended to 'centAmount'.

    for (size_t index = 0; index < amount.length(); index++)
    {
        if (ispunct(amount.at(index)))
        {
            centAmount.append(amount, index + 1, 3);
            amount.erase(index, 3);
        }
    }
    //If the user enters an amount: "256.2", a '0' is appended.
    if (centAmount.empty())
    {
        centAmount.append("00");
    }
    else if (centAmount.length() == 1)
    {
        centAmount.append("0");
    }

    return centAmount;
}


//formats the check output
string formatCheck(string amount, string& wordAmount, string centAmount)
{
    centAmount = removePunct(amount);
    wordAmount = numToWord(amount);
    //stores the result in a string object.The string object is returned.
    wordAmount.append("dollar(s) and " + centAmount + " cents");
    wordAmount.at(0) = toupper(wordAmount.at(0));

    return wordAmount;
}


// This function outputs the formatted check to screen.
void displayCheck(string amount, const string dueDate,
    const string recipient, const string wordAmount)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "\n\t" << setw(68) << setfill('-') << "\n\n";
    cout << setfill(' ') << "\n" << setw(64) << right
        << "Date: " << dueDate << "\n"
        << "\tPay to the order of: " << setw(28) << left << recipient
        << setw(2) << right << "$" << stod(amount) << "\n\n\t"
        << wordAmount << "\n\n\t"
        << setw(31) << setfill('_') << "\n"
        << "\n\n\t" << setw(68) << setfill('-') << "\n";
}


//asks the user if he or she wishes to write another check.
char tryAgain()
{
    char again = ' ';

    cout << "Do you wish to write another check? (y/N): " << endl;
    cin >> again;
    cin.ignore();

    /* Input validation */
    while (toupper(again) != 'Y' && toupper(again) != 'N')
    {
        cout << "Do you wish to write another check? (y/N): " << endl;
        cin >> again;
        cin.ignore();
    }

    return toupper(again);
}