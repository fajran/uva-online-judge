#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
  bool word = false;
  char first;
  while (true) {
    char ch = getchar();
    if (feof(stdin)) break;

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      if (!word) {
        word = true;

        switch (ch) {
          case 'a':
          case 'i':
          case 'u':
          case 'e':
          case 'o':
          case 'A':
          case 'I':
          case 'U':
          case 'E':
          case 'O':
            cout << ch;
            first = 0;
            break;
          default:
            first = ch;
            break;
        }
      }
      else {
        cout << ch;
      }
    }
    else if (word) {
      if (first != 0) {
        cout << first;
      }
      cout << "ay";
      word = false;

      cout << ch;
    }
    else {
      cout << ch;
    }
  }

  if (word) {
    if (first != 0)
      cout << first;
    cout << "ay";
  }
}

// vim: ts=2 sts=2

