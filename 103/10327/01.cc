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

int main() {
  while (true) {
    int n;
    cin >> n;
    if (feof(stdin)) break;

    int arr[n];
    for (int i=0; i<n; i++) {
      cin >> arr[i];
    }

    int cnt = 0;
    for (int i=n-1; i>0; i--) {
      for (int j=0; j<i; j++) {
        if (arr[j] > arr[j+1]) {
          int tmp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = tmp;
          cnt++;
        }
      }
    }

    // printf("~>");
    // for (int i=0; i<n; i++) {
    //   printf(" %d", arr[i]);
    // }
    // printf("\n");

    printf("Minimum exchange operations : %d\n", cnt);
  }
}

// vim: ts=2 sts=2

