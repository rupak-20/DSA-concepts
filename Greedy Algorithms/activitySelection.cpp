// you are given 'n' activities and 'm' discrete resources available. Each activity costs a certain amount of resources
// to complete. The resources cannot be shared by the activities. Find the maximum number of activities which can be
// completed by using minimum amount of resources

// input:
// activities = {5, 13, 8, 4, 10}
// resources = {2, 11, 7, 8, 5, 9}

// output: 4

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int activitySelection(vector<int> n, vector<int> m)
{
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());

    int i = 0, j = 0, res = 0;
    while (i < n.size() && j < m.size())
    {
        if (n[i]<=m[j]) {
            res++;
            i++;
            j++;
        }

        else {
            j++;
        }
    }

    return res;
}

//driver code
int main() {
    vector<int> n = {4, 5, 8, 10, 13};
    vector<int> m = {2, 5, 7, 8, 9, 11};

    cout<<activitySelection(n, m);
    return 0;
}