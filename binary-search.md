Binary search isn’t hard because of logic, it’s hard because of **boundary discipline**.

### Template

Half-open interval : `[low, high)`


```cpp
int low = 0, high = n;

while (low < high) {
    int mid = low + (high - low) / 2;

    if (condition(mid))
        high = mid;      // keep mid
    else
        low = mid + 1;   // discard mid
}

return low;
```

### How to think about `condition(mid)`

Ask a YES / NO question: Is `mid` a valid answer or could the answer be to the left?” If YES then `high = mid` and if NO then `low = mid + 1`

---

lower_bound (first `>= target`)

```cpp
bool condition(int mid) {
    return nums[mid] >= target;
}
```

upper_bound (first `> target`)

```cpp
bool condition(int mid) {
    return nums[mid] > target;
}
```

first index where predicate becomes true

```cpp
bool condition(int mid) {
    return isValid(mid);
}
```

---


If you ever write `high = mid - 1`; You are in `[low, high]` land and must use `while (low <= high)`

If you use `high = mid`; You are in `[low, high)` land and must use `while (low < high)`

---

Why competitive programmers love `[low, high)` 

* Works for all variants
* No infinite loops
* No special casing
* Clean math
