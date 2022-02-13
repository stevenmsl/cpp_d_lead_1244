

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol1244
{
  class Leaderboard
  {
  private:
    /* keep the score for each player */
    unordered_map<int, int> scores;
    /* a list of players sorted  */
    vector<int> players;

  public:
    void addScore(int id, int score);
    int top(int k);
    void reset(int id);
  };

  class Solution
  {
  public:
  };

}
#endif