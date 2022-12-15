#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;
            if (!cin) {
               cout << "Invalid time, try again (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt)
   {
       int input;
       char buffer;
       bool flag = false;

       if (prompt) {
           cout << prompt;
       }

       do {
           cin >> input;
           if (!cin) {
               cout << "Bad integer value, try again: ";
               cin.clear();
               cin.ignore(BUFFER_SIZE, '\n');
           }
           else {
               cin.get(buffer);
               if (buffer != '\n') {
                   cout << "Enter only an integer, try again: ";
                   cin.clear();
                   cin.ignore(BUFFER_SIZE, '\n');
               }
               else flag = true;
           }
       } while (!flag);
       return input;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       int input;
       char buffer;
       bool flag = false;

       if (prompt) {
           cout << prompt;
       }

       do {
           cin >> input;
           if (!cin) {
               cout << "Bad integer value, try again: ";
               cin.clear();
               cin.ignore(BUFFER_SIZE, '\n');
           }
           else {
               cin.get(buffer);
               if (buffer != '\n') {
                   cout << "Enter only an integer, try again: ";
                   cin.clear();
                   cin.ignore(BUFFER_SIZE, '\n');
               }
               else if (input < min || input > max) {
                   if (errorMessage) {
                       cout << errorMessage;
                   }
                   if (showRangeAtError) {
                       cout << "[" << min << " <= value <= " << max << "]: ";
                   }
               }
               else flag = true;
           }
       } while (!flag);
       return input;
   }

   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
       char input[BUFFER_SIZE]; 
       char* returnString;
       int num = 0, i = 0;

       if (prompt) {
           cout << prompt;
       }

       istr.getline(input, BUFFER_SIZE, delimiter);
       while (input[num] != '\0') num++;

       returnString = new char[num + 1];

       while (input[i] != '\0') {
           returnString[i] = input[i];
           i++;
       }
       returnString[i] = '\0';

       return returnString;
   }
}