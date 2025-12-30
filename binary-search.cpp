#include <bits/stdc++.h>
using namespace std;

// Binary Search: Exact Match (Iterative)
int binarySearch1(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Binary Search: Exact Match (Iterative)
int binarySearch2(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    // low is the first index where nums[low] >= target
    if (low < nums.size() && nums[low] == target)
        return low;

    return -1;
}


// Binary Search: Exact Match (Recursive)
int binarySearchRecursive(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarySearchRecursive(nums, mid + 1, high, target);
    else
        return binarySearchRecursive(nums, low, mid - 1, target);
}

// Index of first element >= target
// lower_bound(nums.begin(), nums.end(), target) - nums.begin();
int lowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Index of first element > target
// upper_bound(nums.begin(), nums.end(), target) - nums.begin();
int upperBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    int ind = binarySearchRecursive(a, 0, a.size() - 1, target);

    if (ind == -1)
        cout << "The target is not present.\n";
    else
        cout << "The target is at index: " << ind << "\n";

    cout << "lower_bound index: " << lowerBound(a, target) << "\n";
    cout << "upper_bound index: " << upperBound(a, target) << "\n";

    return 0;
}
