#include "fun.h"
/* your includes here */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// I had to state the helpFun function here before using it to make sure that the fun
// function can use it properly
unsigned int helpFun(unsigned int x, unsigned int y, map<pair<unsigned int, unsigned int>, unsigned int> &dict);

// Main use of fun is to create the "map" and to keep the running values collected
unsigned int fun(unsigned int x, unsigned int y)
{
    map<pair<unsigned int, unsigned int>, unsigned int> dictionary;
    return helpFun(x, y, dictionary);
}

/* your helper function here if you have any */
unsigned int helpFun(unsigned int x, unsigned int y, map<pair<unsigned int, unsigned int>, unsigned int> &dict)
{
    // Have to initialize the pair type to account for the pair of x,y values.
    pair<unsigned int, unsigned int> xypair = make_pair(x, y);

    // Checks to see if the pair exists already
    if (dict.find(xypair) != dict.end())
        return dict[xypair];

    // Base Case
    if (x == 0 && y == 0)
    {
        dict[xypair] = 1;
        return 1;
    }

    // Maps the pair
    else if (x == 0 && y != 0)
    {
        int result = helpFun(1, y - 1, dict);
        dict[xypair] = result;
        return result;
    }

    // Alternate base case
    else if (x != 0 && y == 0)
    {
        dict[xypair] = x + 1;
        return x + 1;
    }

    // Maps the pair
    else
    {
        int result = helpFun(x - 1, helpFun(x - 1, y - 1, dict), dict);
        dict[xypair] = result;
        return result;
    }
}

// Main function to test correctness
int main()
{
    int x = 2;
    int y = 3;
    cout << "The value of fun (" << x << "," << y << ") is " << fun(x, y) << endl;
}