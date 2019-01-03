# Leetcode

## 7. reverse integer

1. be careful of the rage of 'integer', using long instead.
2. The expression of int could still overflow the range of 'int' even without assigning value.
    `(2^30 * 10 + 3 < 0) == true`
3. 'int'%10 may become negative, if that 'int' is too large.
    Therefore use `(x%10 < 0)? -(x%10): x%10` instead.