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
  string line;
  while (getline(cin, line)) {
    for (int i=0, len=line.length(); i<len; i++) {
      char ch = line[i];
      cout << (char)((unsigned int)ch-7);
    }
    cout << endl;
  }
}

// vim: ts=2 sts=2

