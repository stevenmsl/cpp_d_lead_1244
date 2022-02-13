#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace sol1244;
using namespace std;

/*takeaways
  - use an unordered_map to keep the scores and
    to check if a player has been added
  - use a vector to keep a list of players
  - use "nth_element" to sort the players
    in descending order by their score
  - use "accumulate" to total up the scores
    from player 0 to player k-1
*/

void Leaderboard::addScore(int id, int score)
{
  if (!scores.count(id))
    players.push_back(id);
  scores[id] += score;
}

int Leaderboard::top(int k)
{
  /*
    - sort the players by their score - up to k-1
      - players.begin() + k is not included
      - use custom compare so the sorting is
        based on their scores
  */
  nth_element(players.begin(), players.begin() + k, players.end(), [&](int p1, int p2)
              { return scores[p1] > scores[p2]; });

  /*
    - once the players are sorted total up their scores
  */
  auto total = accumulate(players.begin(), players.begin() + k, 0, [&](int sum, int p)
                          { return sum + scores[p]; });

  return total;
}
void Leaderboard::reset(int id)
{
  scores[id] = 0;
}