#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
using namespace sol531;
using namespace std;

/*takeaways
  - visit the picture to record how many black pixels
    in each row and col
  - for each black pixel determine if it's a lonely
    pixel by consulting the counts we collected
    in the previous step
*/

int Solution::find(vector<vector<char>> &picture)
{
  const int m = picture.size();
  const int n = picture[0].size();
  /* how many black pixels are there in a row */
  auto row_count = vector<int>(m);
  /* how many black pixels are there in a col */
  auto col_count = vector<int>(n);

  /* count the black pixels */
  for (auto i = 0; i < m; i++)
    for (auto j = 0; j < n; j++)
      if (picture[i][j] == 'B')
        row_count[i]++, col_count[j]++;

  auto count = 0;

  for (auto i = 0; i < m; i++)
  {
    /* this row only has one black pixel
       - it's a candidate
    */
    if (row_count[i] == 1)
      for (auto j = 0; j < n; j++)
        /* we found the only back pixel in this row
           - check if this is the only black pixel
             in this col as well
        */
        if (col_count[j] == 1)
        {
          count++;
          /* there shouldn't be another black pixel in this row
             - exit now
          */
          break;
        }
  }

  return count;
}