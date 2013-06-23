#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

char m[256];

void init() {
  m['Q'] = ' ';
  m['W'] = 'Q';
  m['E'] = 'W';
  m['R'] = 'E';
  m['T'] = 'R';
  m['Y'] = 'T';
  m['U'] = 'Y';
  m['I'] = 'U';
  m['O'] = 'I';
  m['P'] = 'O';
  m['['] = 'P';
  m[']'] = '[';
  m['\\'] = ']';
  m['A'] = ' ';
  m['S'] = 'A';
  m['D'] = 'S';
  m['F'] = 'D';
  m['G'] = 'F';
  m['H'] = 'G';
  m['J'] = 'H';
  m['K'] = 'J';
  m['L'] = 'K';
  m[';'] = 'L';
  m['\''] = ';';
  m[10] = '\'';
  m['Z'] = ' ';
  m['X'] = 'Z';
  m['C'] = 'X';
  m['V'] = 'C';
  m['B'] = 'V';
  m['N'] = 'B';
  m['M'] = 'N';
  m[','] = 'M';
  m['.'] = ',';
  m['/'] = '.';
  m[' '] = ' ';
  m['`'] = ' ';
  m['1'] = '`';
  m['2'] = '1';
  m['3'] = '2';
  m['4'] = '3';
  m['5'] = '4';
  m['6'] = '5';
  m['7'] = '6';
  m['8'] = '7';
  m['9'] = '8';
  m['0'] = '9';
  m['-'] = '0';
  m['='] = '-';
}

int main() {
  init();
  string line;
  while (true) {
    getline(cin, line);
    if (feof(stdin)) break;

    const char *str = line.c_str();
    int len = line.length();
    for (int i=0; i<len; i++) {
      char ch = str[i];
      char r = m[ch];
      cout << r;
    }
    cout << endl;
  }
}

// vim: ts=2 sts=2

