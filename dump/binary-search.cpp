#include <bits/stdc++.h>
using namespace std;

// Basic Binary Search: Exact Match (Iterative)
// Closed interval [low, high]
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

// Basic Binary Search: Exact Match (Iterative)
// Half open interval [low, high)
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


// Basic Binary Search: Exact Match (Recursive)
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

// FF...FT...TT
// Pattern 1: Find LEFTMOST position where condition is TRUE
// Returns the smallest index where condition(index) is true
// If no such index exists, returns right + 1
int binarySearchLeft(int left, int right, function<bool(int)> condition) {
    int result = right + 1;  // Default: not found
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (condition(mid)) {
            result = mid;      // Found a candidate
            right = mid - 1;   // Look for earlier occurrence
        } else {
            left = mid + 1;    // Move right
        }
    }
    
    return result;
}

// TT...TF...FF
// Pattern 2: Find RIGHTMOST position where condition is TRUE  
// Returns the largest index where condition(index) is true
// If no such index exists, returns left - 1
int binarySearchRight(int left, int right, function<bool(int)> condition) {
    int result = left - 1;  // Default: not found
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (condition(mid)) {
            result = mid;      // Found a candidate
            left = mid + 1;    // Look for later occurrence
        } else {
            right = mid - 1;   // Move left
        }
    }
    
    return result;
}

// Using template function FF...FT...TT
int lowerBound(vector<int>& arr, int target) {
    return binarySearchLeft(0, arr.size() - 1, 
        [&](int i) { return arr[i] >= target; });
}

// Using template function TT...TF...FF
int lastOccurrence(vector<int>& arr, int target) {
    return binarySearchRight(0, arr.size() - 1,
        [&](int i) { return arr[i] <= target; });
    // Verify arr[result] == target
}

// Problem involving complex condition
int searchRotated(vector<int>& arr, int target) {
    int n = arr.size();
    return binarySearchLeft(0, n - 1, [&](int i) {
        // Complex condition: check if target could be at position i
        if (arr[i] == target) return true;
        
        // Determine which half is sorted
        if (arr[0] <= arr[i]) {  // Left half sorted
            return target >= arr[0] && target < arr[i];
        } else {  // Right half sorted
            return target > arr[i] || target < arr[0];
        }
    });
}


// Binary search on answers
int minEatingSpeed(vector<int>& piles, int h) {
    auto canFinish = [&](int speed) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;
        }
        return hours <= h;
    };
    
    return binarySearchLeft(1, *max_element(piles.begin(), piles.end()), canFinish);
}

// Half open interval template function
int binarySearchHO(vector<int> &nums, function<bool(int)> condition)
{
    int low = 0, high = nums.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (condition(mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

// Testing arena
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    int ind = binarySearchRecursive(a, 0, a.size() - 1, target);
    if (ind == -1) cout << "The target is not present.\n";
    else cout << "The target is at index: " << ind << "\n";

    cout << "lower_bound index: " << lowerBound(a, target) << "\n";

    return 0;
}
