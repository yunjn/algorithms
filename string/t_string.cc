#include <iostream>

#include "String.hpp"

using namespace std;
int main() {
  String S1, S2, S3;
  StrAssign(&S1, "abcdefghijk");
  Print(S1);
  S2 = SubString(S1, 1, 11);
  Print(S2);
  S3 = Concat(S1, S2);
  Print(S3);
  cout << StrCompare(S1, S2) << endl;
  DestoryString(&S1);
  DestoryString(&S2);
  DestoryString(&S3);
  return 0;
}