#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

void go(long num) {
  printf("%ld\n", num * (num + 1) / 2 + 1);
}

int main() {
  long num;
  while (true) {
    cin >> num;
    if (num < 0) break;
    go(num);
  }
}

// vim: ts=2 sts=2

//0 -> 0  -> 1
//1 -> 2  -> +1
//2 -> 4  -> +2
//3 -> 7  -> +3
//4 -> 11 -> +4
//5 -> 16 -> +5
//6 -> 22 -> +6
//7 -> 29 -> +7
//8 -> 37 -> +8
//9 -> 46 -> +9
//10 -> 56
//
//10 * 11 / 2 + 1
//
//1 * 2 
//
//4 -> 4 * 5 / 2 + 1 = 10 + 1 = 11



