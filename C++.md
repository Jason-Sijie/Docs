# C++

## lambda expression

1. `auto add = [](int a, int b){return a*b;};` 这里方括号是捕捉器，用来获取外界的变量。
    方括号默认为复制捕捉，即不改变外界的变量；但如果使用引用的话，则会改变
2. 使用[=],[&], 分别是复制捕获所有变量，引用捕获所有变量

## Set

* constructor
    
    ```
    std::set<int> first = {1, 2, 3, 4};   
    int myints[]= {10,20,30,40,50};
    std::set<int> second (myints,myints+5);      
    std::set<int> third (second);               
    std::set<int> fourth (second.begin(), second.end());  
    std::set<int,classcomp> fifth;    // class as Compare
    ``` 
* modifiers
    * insert
    * erase
        * erase by iterator or element value
    * swap
        ```
        std::set<int> first (myints,myints+3);     // 10,12,75
        std::set<int> second (myints+3,myints+6);  // 20,25,32

        first.swap(second);
        // change the content of two sets with the same size
        ```

    * clear
    * emplace
        ```
        pair<iterator, bool> emplace(args);
        // insert an element. If it is new, then return <ite, true>; else return <ite, false>
        ```

    * emplace_hint

* Operations
    * find
        * get iterator to element
    * count
        * count elements with a specific value

## Map

* Map is stored in order by Red Black Tree, so the time for each search is O(logN). If we want to implement hash map, we should use unordered_map instead, which has O(1) for each indexing.
    * the operation of unordered_map is nearly the same with map.
* modifiers
    * insert
        * need to use make_pair() function
    * erase
    * swap
    * clear
    * emplace
* operations
    * find
        * it will return iterator end() if not find.
    * count

## Algorithm

* sort
    * Time complexity is O(N*log2(N)), and we can sort by our own function.
        
        ```
        bool myfunction (int i,int j) { return (i<j); };
        // using function for comp
        std::sort (myvector.begin()+4, myvector.end(), myfunction);
        ```

        

## Numeric

* iota
    * Assigns to every element in the range [first,last) successive values of val, as if incremented with ++val after each element is written.
    
        ```
        template <class ForwardIterator, class T>
            void iota (ForwardIterator first, ForwardIterator last, T val)
        {
            while (first!=last) {
                *first = val;
                ++first;
                ++val;
            }
        }
        ```

## Stack

* constructor
    `stack<int> mystack;`
* modifiers
    * push
    * pop
    * empty
    * size
    * top: a reference to the top element


