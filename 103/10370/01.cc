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

#define MM 1001

int main() {
  int tc;
  cin >> tc;
  int arr[MM];
  while (tc--) {
    int n;
    cin >> n;

    int sum = 0;
    for (int i=0; i<n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }

    double avg = (double)sum / (double)n;

    int cnt = 0;
    for (int i=0; i<n; i++) {
      if (arr[i] > avg) cnt++;
    }

    printf("%.3f%%\n", (double)cnt/(double)n*100.0);
  }
}

// vim: ts=2 sts=2

