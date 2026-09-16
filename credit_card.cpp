#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min

using namespace std;

// Function Prototypes
vector<int> readCardNumber();
int getPrefix(vector<int> number, int k);
bool prefixMatched(vector<int> number);
int getSize(vector<int> number);
int sumOfOddPlace(vector<int> number);
int getDigit(int number);
int sumOfDoubleEvenPlace(vector<int> number);
bool isValid(vector<int> number);

// Return true if credit card conditions are met
bool isValid(vector<int> number)
{
    int size = getSize(number);
    if (size < 13 || size > 16) {
        return false;
    }
    
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0) && prefixMatched(number);
}

// Right-to-left: Double every second digit starting from the second-to-last
int sumOfDoubleEvenPlace(vector<int> number)
{
    int sum = 0;
    // For a 16-digit card, indices are 14, 12, 10... 0
    for (int i = number.size() - 2; i >= 0; i -= 2)
    {
        int digit = number[i];
        digit = digit * 2;
        sum += getDigit(digit);
    }
    return sum;
}

// Return this number if it is a single digit, otherwise sum the two digits
int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }
    else
    {
        return number / 10 + number % 10;
    }
}

// Right-to-left: Sum up every odd place starting from the very last digit
int sumOfOddPlace(vector<int> number)
{
    int sum = 0;
    // For a 16-digit card, indices are 15, 13, 11... 1
    for (int i = number.size() - 1; i >= 0; i -= 2)
    {
        sum += number[i];
    }
    return sum;
}

int getSize(vector<int> number)
{
    return number.size();
}

bool prefixMatched(vector<int> number)
{
    return (getPrefix(number, 1) == 4 || 
            getPrefix(number, 1) == 5 || 
            getPrefix(number, 2) == 37 || 
            getPrefix(number, 1) == 6);
}

vector<int> readCardNumber()
{
    string number;
    cout << "Enter number: \n";
    cin >> number;

    vector<int> card_digits;
    for (char digit : number)
    {
        if (isdigit(digit)) { // Ensures non-numeric spaces/dashes don't break it
            card_digits.push_back(digit - '0');
        }
    }
    return card_digits;
}

// Return the first k number of digits from number
int getPrefix(vector<int> number, int k)
{
    int k_prefix = 0;
    int length = min(k, static_cast<int>(number.size()));

    for (int i = 0; i < length; i++)
    {
        k_prefix = k_prefix * 10 + number[i];
    }
    return k_prefix;
}

int main()
{
    vector<int> number = readCardNumber();
    
    if(number.empty()) {
        cout << "Invalid Input!\n";
        return 0;
    }

    cout << "\n--- Card Analysis ---\n";
    cout << "Prefix (2 digits): " << getPrefix(number, 2) << "\n";
    cout << "Matched Prefix:    " << (prefixMatched(number) ? "True" : "False") << "\n";
    cout << "Size:              " << getSize(number) << "\n";
    cout << "Sum of Odds:       " << sumOfOddPlace(number) << "\n";
    cout << "Sum of Even x2:    " << sumOfDoubleEvenPlace(number) << "\n";
    cout << "Valid Card:        " << (isValid(number) ? "YES" : "NO") << "\n";
    
    return 0;
}
