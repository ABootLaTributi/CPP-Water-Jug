#include <iostream>
#include "Jug.h"

using namespace std;

int main() {
  string solution;

  Jug head1(3, 5, 4, 1, 2, 3, 4, 5, 6);
  if (head1.solve(solution) != 1) {
    cout << "Error 3" << endl;
  }
  else
  {
    cout << solution << endl;
    cout << endl;
  }

  solution.clear();
  
  Jug head2(3, 5, 4, 1, 2, 3, 4, 5, 0);
  if (head2.solve(solution) != 1)
  {
    cout << "Error 4" << endl;
  }
  else
  {
    cout << solution << endl;
  }
  return 0;
}