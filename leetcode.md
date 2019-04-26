# Leetcode

### 1. two sum

1. sort the vector nums by its index and start the two indexes at the 0 and n-1, iteratively getting closer to the right answer.
2. there is the source code.
	```C++
	class Solution {
		public:
			vector<int> twoSum(vector<int>& nums, int target) {
			int len = nums.size();
			vector<int> idx(len);
			iota(idx.begin(), idx.end(), 0);
			sort(idx.begin(), idx.end(), [&nums](int i1, int i2){return nums[i1]<nums[i2];});
			
			int left = 0, right = len-1;
			vector<int> res;
			while(left < right){
				if(nums[idx[left]]+nums[idx[right]] < target)
					left++;
				else if(nums[idx[left]]+nums[idx[right]] > target)
					right--;
				else{
					res.push_back(idx[left]);
					res.push_back(idx[right]);
					break;
				}
			}
			return res;
	    }
	};
	```

### 2. add two number

1. should add digits by digits using carry, not add by int or long.

### 3. Longest Substring Without Repeating Characters

1. using Set data structure to implement sliding window
2. using Hash map to optimize the sliding window
	```
	public class Solution {
		public int lengthOfLongestSubstring(String s) {
			int n = s.length(), ans = 0;
			Map<Character, Integer> map = new HashMap<>(); // current index of character
			// try to extend the range [i, j]
			for (int j = 0, i = 0; j < n; j++) {
				if (map.containsKey(s.charAt(j))) {
					i = Math.max(map.get(s.charAt(j)), i);
				}
				ans = Math.max(ans, j - i + 1);
				map.put(s.charAt(j), j + 1);
			}
			return ans;
		}
	}
	```

### 5. longest Palindromic Substring

1. dynamic programming. 
	P[i, j] = true, if S[i], ...,S[j] is palindromic
2. basic case: P[i, i] = true and P[i, i+1] = true if S[i] == S[i+1]
	P(i,j)=(P(i+1,j−1) and S[i] == S[j])

	

### 7. reverse integer

1. be careful of the rage of 'integer', using long instead.
2. The expression of int could still overflow the range of 'int' even without assigning value.
    `(2^30 * 10 + 3 < 0) == true`
3. 'int'%10 may become negative, when that 'int' is too large.
    Therefore use `(x%10 < 0)? -(x%10): x%10` instead.

### 11. container with most water

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
