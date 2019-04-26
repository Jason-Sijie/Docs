# C++

## lambda expression

1. `auto add = [](int a, int b){return a*b;};` 这里方括号是捕捉器，用来获取外界的变量。
    方括号默认为复制捕捉，即不改变外界的变量；但如果使用引用的话，则会改变
2. 使用[=],[&], 分别是复制捕获所有变量，引用捕获所有变量

## Set

1. iterator
    it has all the kinds of iterators but not []
2. constructor
    ```
    std::set<int> first = {1, 2, 3, 4};   
    int myints[]= {10,20,30,40,50};
    std::set<int> second (myints,myints+5);      
    std::set<int> third (second);               
    std::set<int> fourth (second.begin(), second.end());  
    std::set<int,classcomp> fifth;    // class as Compare
    ```
3. modifiers
    * insert
        1. same with `<map>`
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

4. Operations
    * find
        * get iterator to element, or return set::end() iterator
    * count
        * count elements with a specific value

## Map

1. Map is stored in order by Red Black Tree, so the time for each search is O(logN). If we want to implement hash map, we should use unordered_map instead, which has O(1) for each indexing.
    * the operation of unordered_map is nearly the same with map.
2. modifiers
    * insert
        * need to use make_pair() function
        * return a pair, first is the iterator, second is true or false
        ```C++
        ret = mymap.insert ( std::pair<char,int>('z',500) );
        if (ret.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }
        ```
    * erase
    * swap
    * clear
    * emplace
3. operations
    * find
        * it will return iterator end() if not find. by key not value
    * count
    * all the iterator
        access by it->first and it->second


## Stack

1. constructor
    `stack<int> mystack;`
2. modifiers
    * push
    * pop
    * empty
    * size
    * top: a reference to the top element


## Vector

1. data()
    Data() function is to get the basic array
    `int * arr = vector<int>.data();`
2. modifiers
    * erase(iterator)

## Queue

### Priority queue
1. constructor
    ```c++
    int myints[]= {10,60,50,20};

    std::priority_queue<int> first;
    std::priority_queue<int> second (myints,myints+4);
    std::priority_queue<int, std::vector<int>, std::greater<int>> third (myints,myints+4);
    ```
    **greater<int>**: The top is the smallest
    **less<int>**: The top is the largest

2. Member functions
    1. empty
    2. size
    3. push
    4. pop
    5. top
    6. emplace


## Heap

1. Constructor
    ```C++
    #include <algorithm>
    using namespace std;

    vector<int> v1 = {20, 30, 40, 25, 15};

    // Max Heap
    make_heap(v1.begin(), v1.end()); 
    cout << v1.front();

    // Min Heap
    make_heap(v1.begin(), v1.end(), greater<int>());
    cout << v1.front();
    ```

2. Modifiers
    1. push: it must together with push_back()
    ```C++
    v1.push_back(50); 
      
    // using push_heap() to reorder elements 
    push_heap(v1.begin(), v1.end()); 
    ```

    2. pop: it must together with pop_back();
    ```C++
    // using pop_heap() to delete maximum element 
    pop_heap(v1.begin(), v1.end()); 
    v1.pop_back(); 
    ```

    3. sort heap: after this, it is no longer a heap
    ```C++
    // sorting heap using sort_heap() 
    sort_heap(v1.begin(), v1.end()); 
    ```


## Deque

1. The difference between Deque and Vector is that deque is stored in discreted memory units, different from Vector (which is continuous memory).
2. It is double linked container and can push\pop at the start, not only the end.

## String and number

1. string to number
    1. `#include <cstdlib>`, `auto num = std::sto*(str)`
    2. C++ way
    ```C++
    #include <sstream>
    #include <string>

    std::string text = "123";
    std::string text2 = "345";
    int number;
    std::istringstream iss (text);
    iss >> number;
    iss.str(text2);
    iss >> number;
    if (!iss.good ()) {
        //something happened
    }
    ```
2. number to string
    1. `string res = std::to_string(num)`
    2. C++ way
    ```C++
    #include <sstream>

    int i = 123;
    std::string out_string;
    std::stringstream ss;
    ss << i;
    out_string = ss.str();
    ```
3. insert char to string
    `string.insert(size_t pos, int repeat_time, char val);`


## Copy and Reference

1. C++ is different from Java. In C++, if do not specify **&** then it passes by **copy**. However, Java considered all the objects passing by **reference**.

2. If a method returns a reference, it can not be the reference of a local variable.


## Algorithm

1. sort
    1. Time complexity is O(N*log2(N)), and we can sort by our own function.
        
        ```C++
        // increase order
        std::sort(V.begin(), V.end(), [](int x, int y){return x < y;});
        // decrease order
        std::sort (myvector.begin(), myvector.end(), greater<int>());

        ```


        
## Numeric

1. iota
    * Assigns to every element in the range [first,last) successive values of val, as if incremented with ++val after each element is written.
    ```C++
    int numbers[10];
    std::iota (numbers,numbers+10,100);
    ```

## OOP

1. Inherit
    1. type
        1. public: public -> public, protected -> protected
        2. protected: public and protected -> protected
        3. private: public and protected -> private
    2. Multi inherit
        1. constructor
        ```C++
        class Derive: public Base1, public Base2{
            // the constructor was called in the order of
            // Base1, Base2, Derive

            // the deconstructor
            // Derive, Base2, Base1
        }

        ```
2. Polymophism
    1. Virtual function
    ```C++
    class Shape{
        public: 
        // pure virtual function
        // it must be implemented by derived classes
        virtual int Area() = 0;

        // virtual function
        virtual int Area() {// base implementation}
    }
    ```

    2. Pointer
    ```C++
    try {
        Base * pba = new Derived;
        Base * pbb = new Base;
        Derived * pd;

        pd = dynamic_cast<Derived*>(pba);
        if (pd==0) cout << "Null pointer on first type-cast.\n";

        pd = dynamic_cast<Derived*>(pbb);
        if (pd==0) cout << "Null pointer on second type-cast.\n";

    } catch (exception& e) {cout << "Exception: " << e.what();}
    ```

3. Overload functions
    1. Operator
    ```C++
    // +
    Class operator+ (const Class& c1){
        return Class;
    }

    // cout
    friend ostream &operator<<( ostream &output, const Distance &D )
    { 
        output << "F : " << D.feet << " I : " << D.inches;
        return output;            
    }

    // ++a
    Time operator++ ()  
    {
        ++minutes;          // 对象加 1
        if(minutes >= 60)  
        {
        ++hours;
        minutes -= 60;
        }
        return Time(hours, minutes);
    }
    // a++
    Time operator++( int )         
    {
        // 保存原始值
        Time T(hours, minutes);
        // 对象加 1
        ++minutes;                    
        if(minutes >= 60)
        {
        ++hours;
        minutes -= 60;
        }
        // 返回旧的原始值
        return T; 
    }
    ```

4. Const
    1. const function, if a function do not change any member variable, then it should be declared as const function.
    ```C++
    // const function, it can not change any member variable or call any non-const functions
    void SomeFunc() const;
    ```

5. Inline
    1. `inline` must be associated with the definition. Only with the declaration is not useful.


## Design Pattern
1. Singleton
    1. Create only one instance of a class. (Used as coordinator or manager)
    2. Need to let all the **constructor and operator =** to be private or unaccessible.
    ```C++
    class S
    {
        public:
            static S& getInstance()
            {
                static S    instance; // Guaranteed to be destroyed.
                                    // Instantiated on first use.
                return instance;
            }
        private:
            S() {}                    // Constructor? (the {} brackets) are needed here.

        public:
            // do not create this methods
            S(S const&)               = delete;
            void operator=(S const&)  = delete;

    };
    ```

2. Factory Method
    1. Do not directly new class objects of hierarchy relationship.
    2. We create a class with a static containter of all the objects. Using the factory level of abstraction to get rid of the specific implementation of different derived classes.

3. Strategy
    1. The strategy pattern allows grouping related algorithms under an abstraction, which allows switching out one algorithm or policy for another without modifying the client. 

4. Observer
    1. This pattern is a one-to-many dependency between objects so that when one object changes state, all its dependents are notified. 

5. Builder

6. Adaptor
    1. Tanslation between two different types of API.

7. State
    1. like a state machine

