//  Computer Science II
//  Palindrome.cpp
//
//  Dennis Frenkel
//

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

string removePunctuation(string str);
string convertToLower(string str);
string reverse(string str);
void display(vector<string> vstrings);
bool isPalindrome(string str);

int main() {
    vector<string> palindromes, not_palindromes;
    string temp;

    cout << "Enter your palindrome or type quit: " << endl;
    getline(cin, temp);

    while (temp != "quit") {
        if (isPalindrome(temp))
            palindromes.push_back(temp);
        else
            not_palindromes.push_back(temp);

        cout << "Enter your palindrome or type quit: " << endl;
        getline(cin, temp);
    }

    cout << "Palindromes:" << endl;
    display(palindromes);

    cout << "NOT Palindromes:" << endl;
    display(not_palindromes);

    return 0;
}

bool isPalindrome(string palindrome) {
    string str = removePunctuation(palindrome);
    str = convertToLower(str);

    if (str == reverse(str)) {
        return true;
    }
    
    return false;
}

string removePunctuation(string sentence) {
    string res = "";
    for (int i = 0; i < sentence.size(); i++) {
        if (!ispunct(sentence[i]) && sentence[i] != ' ')
            res += sentence[i];
    }
    return res;
}

string convertToLower(string mixed) {
    string res = "";
    for (int i = 0; i < mixed.size(); i++) {
        res += tolower(mixed[i]);
    }
    return res;
}

string reverse(string input) {
    string res = "";
    for (int i = input.size() - 1; i >= 0; i--) {
        res += input[i];
    }
    return res;
}

void display(vector<string> vstrings) {
    for (int i = 0; i < vstrings.size(); i++) {
        cout << vstrings[i] << endl;
    }
}

/*
 Enter your palindrome or type quit: A man, a plan, a canal, Panama
 Enter your palindrome or type quit: Be at a time I emit a beat
 Enter your palindrome or type quit: Racecar
 Enter your palindrome or type quit: A lad named E. Mandala
 Enter your palindrome or type quit: A Toyota's a Toyota
 Enter your palindrome or type quit: Race and tell a dancer
 Enter your palindrome or type quit: quit
 Palindromes:
 A man, a plan, a canal, Panama
 Racecar
 A lad named E. Mandala
 A Toyota's a Toyota
 NOT Palindromes:
 Be at a time I emit a beat
 Race and tell a dancer
 Program ended with exit code: 0
 */
