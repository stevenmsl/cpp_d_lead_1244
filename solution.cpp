#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <set>
#include <map>
#include <cstdlib>
using namespace sol1181;
using namespace std;

/*
  - build a map of first-last words pair for
    each phrase so later we can have easier
    comparisons among phrases
  - use a set to make sure the puzzles
    are sorted
*/

vector<string> Solution::create(vector<string> &phrases)
{
  const auto n = phrases.size();
  /* first-last words pair */
  auto flPairs = unordered_map<int, pair<string, string>>();
  auto del = ' ';
  for (auto i = 0; i < n; i++)
  {
    auto words = Util::split(phrases[i], &del);
    auto pair = make_pair(
        *words.begin(),
        *(words.end() - 1));
    flPairs[i] = pair;
  }

  /* make sure the puzzles are sorted lexicographically */
  auto ordered = set<string>();

  /* walk through all the possible pairs */
  for (auto i = 0; i < n; i++)
  {
    auto phrase = phrases[i];
    auto lastWord = flPairs[i].second;
    for (auto p : flPairs)
    {
      auto j = p.first;
      auto firstWord = p.second.first;
      if (i == j || lastWord != firstWord)
        continue;
      /* remove the last word */
      phrase.resize(phrase.size() - lastWord.size());
      /* compose the before and after puzzle  */
      phrase += phrases[j];
      /* make sure puzzles are distinct */
      if (ordered.count(phrase) <= 0)
        ordered.insert(phrase);
    }
  }
  return vector<string>(ordered.begin(), ordered.end());
}