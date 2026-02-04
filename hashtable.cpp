// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> target_indices;
        unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); i++)
        {
            int second_integer = target - nums.at(i);
            if (hash_table.find(second_integer) != hash_table.end())
            {
                target_indices.push_back(hash_table.find(second_integer)->second);
                target_indices.push_back(i);
                
                break;
            }
            else
            {
                hash_table[nums.at(i)] = i;
            }
        }

        return target_indices;
    }
};

int main()
{
    Solution s1;
    vector<int> nums;
    vector<int> target_indx;
    int target;
    int x;
    for (int i = 0; i < 5; i++)
    {
        cout << "[" << i << "]" << " element";
        cin >> x;
        nums.push_back(x);
    }
    cout << "Enter the target";
    cin >> target;
    target_indx = s1.twoSum(nums, target);

    for (int i = 0; i < target_indx.size(); i++)
    {
        cout << target_indx[i] << " ";
    }
    
}