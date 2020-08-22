// Job Challenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//This program converts roman numerals to modern numbers and visa versa.  

#include <iostream>
#include <string>

using namespace std;

//Roman numeral to Modern number constants
const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;

//This function takes a roman numeral as a char and converts it to a modern number
//If it is not an acceptable roman numeral, it returns 0
int returnNumberValue(char inputChar) {
   switch (inputChar) {
   case 'I':
      return I;
      break;
   case 'V':
      return V;
      break;
   case 'X':
      return X;
      break;
   case 'L':
      return L;
      break;
   case 'C':
      return C;
      break;
   case 'D':
      return D;
      break;
   case 'M':
      return M;
      break;
   default:
      return 0;
      break;
   }
   return 0;
}

int main()
{
   int conversionTypeInput = 0;
   while (conversionTypeInput != 3) {
      //Asks from what to what you are converting the numbers
      cout << "Would you like to convert a roman numeral to a modern number,  a modern number to  a roman numeral, or are you done with this program?\n";
      cout << "(Roman numerals must be in upper case)\n";
      cout << "-For roman to modern type 1\n";
      cout << "-For modern to roman type 2\n";
      cout << "-To end the program type 3\n\n";
      cin >> conversionTypeInput;

      //Tests for wrong input
      if (cin.fail()) {
         cin.clear();
         cin.ignore();
         conversionTypeInput = 0;
      }

      //Roman to Modern option
      if (conversionTypeInput == 1) {

         //Gets user input and checks for wring input
         string romanInput = " ";
         bool isRomanNumeral = false;
         
         while (false == isRomanNumeral)  {
            isRomanNumeral = true;
            cout << "What roman numeral would you like to convert?\n";
            cin >> romanInput;
            for (int i = 0; i < romanInput.length(); i++) {
               if (returnNumberValue(romanInput[i]) == 0) {
                  isRomanNumeral = false;
               }
            } 

            if (!isRomanNumeral) {
               cout << "That isnt a Roman numeral, please enter one\n";
            }
         } 

         //Assigns modern number to user input
         int modernNumber = 0;
         for (int i = romanInput.size() - 1; i >= 0; i--) {
            int pointerValue = 0;
            int leftOfPointerValue = 0;

            //Assign the numbers of the letter the pointer is on and the one left to it using returnNumberValue function
            pointerValue = returnNumberValue(romanInput[i]);
            if (i != 0) {
               leftOfPointerValue = returnNumberValue(romanInput[i - 1]);
            }

            //Adds up all the letters to the final output number
            if (pointerValue <= leftOfPointerValue) {
               //Just the letter the pointer is on is added to final sum if the letter next to it is greater
               modernNumber += pointerValue;
            }
            else {
               //The letter the pointer is on minus the letter next to it is added to the final sum if the letter next to it is smaller
               //And the pointer skips the letter left of it
               modernNumber += pointerValue - leftOfPointerValue;
               i--;
            }
         }

         //Outputs modern number
         cout << "\nThe modern number is " << modernNumber << "!\n\n";
      }
      //Modern to Roman option
      else if (conversionTypeInput == 2) {
         int modernNumber = 0;
         string romanNumeral = "";
         //Gets modern number input and checks for wring input
         bool isValidInput = true;
         do {
            isValidInput = true;
            cout << "What modern number would you like to convert?\n";
            cin >> modernNumber;

            if (cin.fail()) {
               isValidInput = false;
               cin.clear();
               cin.ignore();
               cout << "That is not a valid number, please enter a valid number\n";
            }
         } while (!isValidInput);

         //Builds roman numeral string by checking one or two letters at a time
         //Checks for M
         while (modernNumber - M >= 0) {
            romanNumeral += "M";
            modernNumber -= M;
         }
         //Checks for CM
         if (modernNumber - (M - C) >= 0) {
            romanNumeral += "CM";
            modernNumber -= M - C;
         }

         //Checks for D
         while (modernNumber - D >= 0) {
            romanNumeral += "D";
            modernNumber -= D;
         }
         //Checks for CD
         if (modernNumber - (D - C) >= 0) {
            romanNumeral += "CD";
            modernNumber -= D - C;
         }
         //Checks for LD
         if (modernNumber - (D - L) >= 0) {
            romanNumeral += "LD";
            modernNumber -= D - L;
         }

         //Checks for C
         while (modernNumber - C >= 0) {
            romanNumeral += "C";
            modernNumber -= C;
         }
         //Checks for XC
         if (modernNumber - (C - X) >= 0) {
            romanNumeral += "XC";
            modernNumber -= C - X;
         }

         //Checks for L
         while (modernNumber - L >= 0) {
            romanNumeral += "L";
            modernNumber -= L;
         }
         //Checks for XL
         if (modernNumber - (L - X) >= 0) {
            romanNumeral += "XL";
            modernNumber -= L - X;
         }
         //Checks for VL
         if (modernNumber - (L - V) >= 0) {
            romanNumeral += "VL";
            modernNumber -= L - V;
         }

         //Checks for X
         while (modernNumber - X >= 0) {
            romanNumeral += "X";
            modernNumber -= X;
         }
         //Checks for IX
         if (modernNumber - (X - I) >= 0) {
            romanNumeral += "IX";
            modernNumber -= X - I;
         }

         //Checks for V
         while (modernNumber - V >= 0) {
            romanNumeral += "V";
            modernNumber -= V;
         }
         //Checks for IV
         if (modernNumber - (V - I) >= 0) {
            romanNumeral += "IV";
            modernNumber -= V - I;
         }

         //Checks for I
         for (modernNumber; modernNumber > 0; modernNumber--) {
            romanNumeral += "I";
         }

         //Output Roman Numeral
         cout << "\nYour Roman Numeral is " << romanNumeral << "!\n\n";
      }
      //Any other wrong input
      else if (conversionTypeInput != 3) {
         cout << "That was not one of the answers\n\n";
      }
   }
      return 0;
   }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
