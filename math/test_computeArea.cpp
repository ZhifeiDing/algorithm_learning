#include "leetcode.hpp"

void test_computeArea() {
  srand((unsigned int)time(NULL));
  int A = rand()%11;
  int B = rand()%11;
  int C = rand()%11;
  int D = rand()%11;
  int E = rand()%11;
  int F = rand()%11;
  int G = rand()%11;
  int H = rand()%11;
  cout << "The area covered by : " << endl;
  cout << "(" << A << "," << B << "),(" << C << "," << D << ")" << endl;
  cout << "(" << E << "," << F << "),(" << G << "," << H << ")" << endl;
  cout << computeArea(A,B,C,D,E,F,G,H) << endl;
}
