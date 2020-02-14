#include "hw3_grader.h"

int main()
{
  VectorWrap<int>::type test1({4, 7, 9, 18, 22});
  std::vector<int> correct({4, 7, 9, 18, 22});
  std::size_t i = 0;
  for (const auto& num : test1)
  {
    if (num != correct[i++]) return 1;
  }
  return 0;
}
