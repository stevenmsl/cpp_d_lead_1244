
#include "util.h"
#include <cstring>
#include <string>

using namespace sol1181;

/* C++ notes
   - don't pass in the "input" by reference
     as strtok is going to remove delimiters
     from it
*/

vector<string> Util::split(string input, const char *delimiter)
{
    auto i = &input[0];
    auto token = strtok(i, delimiter);
    auto result = vector<string>();
    while (token != nullptr)
    {
        result.push_back(string(token));
        token = strtok(nullptr, delimiter);
    }

    return result;
}
