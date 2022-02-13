#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1181;

/*
Input: phrases = ["writing code","code rocks"]
Output: ["writing code rocks"]
*/
tuple<vector<string>, vector<string>>
testFixture1()
{
  auto phrases = vector<string>{"writing code", "code rocks"};
  auto output = vector<string>{"writing code rocks"};
  return make_tuple(phrases, output);
}

/*
Input: phrases = ["mission statement",
                  "a quick bite to eat",
                  "a chip off the old block",
                  "chocolate bar",
                  "mission impossible",
                  "a man on a mission",
                  "block party",
                  "eat my words",
                  "bar of soap"]
Output: ["a chip off the old block party",
         "a man on a mission impossible",
         "a man on a mission statement",
         "a quick bite to eat my words",
         "chocolate bar of soap"]
*/
tuple<vector<string>, vector<string>>
testFixture2()
{
  auto phrases = vector<string>{"mission statement",
                                "a quick bite to eat",
                                "a chip off the old block",
                                "chocolate bar",
                                "mission impossible",
                                "a man on a mission",
                                "block party",
                                "eat my words",
                                "bar of soap"};
  auto output = vector<string>{"a chip off the old block party",
                               "a man on a mission impossible",
                               "a man on a mission statement",
                               "a quick bite to eat my words",
                               "chocolate bar of soap"};
  return make_tuple(phrases, output);
}

/*
Input: phrases = ["a","b","a"]
Output: ["a"]
*/
tuple<vector<string>, vector<string>>
testFixture3()
{
  auto phrases = vector<string>{"a", "b", "a"};
  auto output = vector<string>{"a"};
  return make_tuple(phrases, output);
}

string toString(vector<string> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += e;
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

void test1()
{
  auto f = testFixture1();

  cout << "Test 1 - expect to see: " << toString(get<1>(f)) << endl;

  Solution sol;
  auto result = sol.create(get<0>(f));
  cout << "result: " << toString(result) << endl;
}

void test2()
{
  auto f = testFixture2();

  cout << "Test 2 - expect to see: " << toString(get<1>(f)) << endl;

  Solution sol;
  auto result = sol.create(get<0>(f));
  cout << "result: " << toString(result) << endl;
}

void test3()
{
  auto f = testFixture3();

  cout << "Test 3 - expect to see: " << toString(get<1>(f)) << endl;

  Solution sol;
  auto result = sol.create(get<0>(f));
  cout << "result: " << toString(result) << endl;
}

void testSplit()
{
  auto f = testFixture2();
  auto input = get<1>(f)[0];
  auto del = ' ';
  auto result = Util::split(input, &del);
}

main()
{
  test1();
  test2();
  test3();
  // testSplit();

  return 0;
}