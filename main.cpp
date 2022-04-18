#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol531;

/*
Input:
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.

*/

tuple<vector<vector<char>>, int> testFixture1()
{
  auto input = vector<vector<char>>{
      {'W', 'W', 'B'},
      {'W', 'B', 'W'},
      {'B', 'W', 'W'}};

  return make_tuple(input, 3);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Test 1 - expect to see " << to_string(get<1>(f)) << endl;

  cout << "Result: " << sol.find(get<0>(f)) << endl;
}

main()
{
  test1();
  return 0;
}