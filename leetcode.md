# Leetcode

## 7. reverse integer

1. be careful of the rage of 'integer', using long instead.
2. The expression of int could still overflow the range of 'int' even without assigning value.
    `(2^30 * 10 + 3 < 0) == true`
3. 'int'%10 may become negative, when that 'int' is too large.
    Therefore use `(x%10 < 0)? -(x%10): x%10` instead.

## 11. container with most water

1. C++ sort and keep track of indexes
    1. can implement by 'iota' and lambdas expression
        
        ```
        <template <typename T>
        vector<size_t> sort_indexes(const vector<T> &v) {
            // initialize original index locations
            vector<size_t> idx(v.size());
            iota(idx.begin(), idx.end(), 0);
            // sort indexes based on comparing values in v
            sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});
            return idx;
        }
        ``` 

2. two pointer solution
    1. Set two pointer at the start and the end of the vector. And iteratively move the shorter line inwards until the two pointers are adjacent.