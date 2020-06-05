/* Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any. */


/* Approach - pre sum and binary search */

// Time Complexity - O(n), where n is length of vector w
// Space Complexity - O(n)

class Solution {
private:
    vector<int> preSumArray;
public:
    Solution(vector<int> w) {
        preSumArray = vector<int> ();
        int sum = 0;
        for (int weight : w) {
            sum += weight;
            preSumArray.push_back(sum);
        }
    }
    
    int pickIndex() {
        int sum = preSumArray.back();
        int random = rand() % sum;
        auto itr = upper_bound(preSumArray.begin(), preSumArray.end(), random);
        return itr - preSumArray.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */