/* 
 * File: lab6_skeleton.cpp
 *
 * Lab 6: Recursion - Alien Word Parsing
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 256; 

bool correct_word(char str[], int start, int end) {
    // Task 1: Base case with only a single character
    if (end - start == 1) {
        if (static_cast<int>(str[start]) >= 97 && static_cast<int>(str[start]) <= 122) {
            return true;
        }
    }
    // Task 2: Recursive case with suffix characters '@', or '#'
    if (str[end] == '@' || str[end] == '#') {
        return correct_word(str, start, end - 1);
    }
    // Task 3: Recursive case with concatenation characters '|' at suffix position.
    if (str[end] == '|') {
        for (int i = start; i <= end; i++) {
            if (correct_word(str, start, i) && !correct_word(str, start, i + 1)) {
                return correct_word(str, i + 1, end - 1);
            }
        }
    }
    // Task 4: Recursive case with concatenation characters '#' at prefix position.
    if (str[start] == '#') {
        for (int i = start + 1; i <= end; i++) {
            if (correct_word(str, start + 1, i) && !correct_word(str, start + 1, i + 1)) {
                return correct_word(str, i + 1, end);
            }
        }
    }
    // All remaining cases are wrong
    return false;
}
int main()
{
   char word[MAX_LEN];
   char c;
   
   do{
      cout << "Enter a word: ";
      cin >> word;
      if (correct_word(word, 0, strlen(word) - 1))
         cout << "The word is CORRECT!\n";
      else
         cout << "The word is INCORRECT!\n";
      cout << "Do you want to enter a new word ('Y'/'y' for Yes, 'N'/'n' for No)? ";
      cin >> c; 
   } while (c == 'Y' || c=='y');

   return 0;
}

