# C++

## Set

* constructor
```std::set<int> first = {1, 2, 3, 4};   
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

* modifiers
    * insert
    * erase
    * swap
    * clear
    * emplace
* operations
    * find
    * count