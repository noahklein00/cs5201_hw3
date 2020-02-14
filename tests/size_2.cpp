#include "hw3_grader.h"

int main()
{
  VectorWrap<int>::type test2({1, 5, 7, 3, 7, 5, 3, 6});
  if (test2.size() != 8) {
    return 1;
  }
  return 0;
}
