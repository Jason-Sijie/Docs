# Java

## stdin and stdout

### stdin
1. An object 'Scanner' is used for input and output. `Scanner scan = new Scanner(System.in)`
2. function scan.next() 
    1. ignore the blank space before valid input.
    2. It ends with ' ' or '\n'
3. function scan.nextLine()
    1. include all the blank spaces.
    2. only ends with '\n'.
4. nextInt(), nextDouble(), ... all of them do not read in '\n'.
5. function hasNextLine(), hasNext()
    1. whether it reaches EOF.

### stdout
1. System.out.println()
    1. println(10 + 'a') is 107, but println(10 + "a") is 10a.
2. System.out.printf()
    1. It is the same as printf() in C.
    2. "%04d" means that fill the int to four digits with '0'
    3. "%-15s" means start at the left side and fill the string to 15 digits


## Static Initialize

1. **public static variable** can be init directly or by using `static{}` and **private static function()**
2. All the static variables and `static{}` runs by order.

## Integer

1. Integer.toString()


## String

1. charAt()
    String does not have [] indexing, only has charAt()
2. int indexOf(char ch, int fromidx)/(str, fromidx)/(char)/(str)
    Find the index of first corresponding content. If does not exist, then return -1.
3. String.valueOf()
    Convert object to String.
4. **String.format()**
    1. string or char
        1. `String str = String.format("%-7s", "hello);`
    2. int
        1. '-': align-left
        2. '0': fill with 0
        3. '+': result will contain '+' or '-'
        4. '#': show '0' or '0x' if it's hex or ox number
        5. "%x": hex, "%o": ox
    3. float
        1. "%f"
        2. "%a": hex number
        3. "%e": in exponential 
        4. "%g"
    4. Time
        1. it must have "%t"
        ```
        Date now = new Date();
        String str = String.format("%tF", now);
        ```
        2. c，星期六 十月 27 14:21:20 CST 2007
            F，2007-10-27
            D，10/27/07
            r，02:25:51 下午
            T，14:28:16
            R，14:28
            b, 月份简称
            B, 月份全称
            a, 星期简称
            A, 星期全称
5. str.equals(), str.equalsIgnoreCase(), compareTo(), startsWith(), endsWith().
6. str.substring(int start, int end)
7. str.replace(String, String)
    replace all the matching substring.
8. **StringBuffer**
    1. StringBuffer is synchronized but StringBuilder is not.
    2. The methods that is beyond String
        1. append(String str)
        2. reverse()
        3. delete(int start, int end)
        4. insert(int offset, String str)
        5. replace(int start, int end, String str)
        6. toString()


## Number format

    ```
    NumberFormat.getInstance().format(myNumber); 23,323.332
    //currency in different country
    NumberFormat.getCurrencyInstance(Locale.CHINA).format(myNumber); ￥23,323.33
    
    NumberFormat.getNumberInstance().format(myNumber); 23,323.332
    NumberFormat.getPercentInstance().format(test); 34%
    ```


## HashSet

1. constructor
    1. The data type is not necessary in the constructor. Both `HashSet hs = new HashSet();` and `HashSet<String> hs = new HashSet<String>();` are true;
2. modifiers
    1. boolean add(E e): insert if not exist
    2. void clear()
    3. boolean contains(object o)
    4. isEmpty()
    5. iterator()
    6. boolean remove(object o)
    7. size()


## Map

1. constructor

2. Traversal Map
    ```
    //第一种：普遍使用，二次取值
    System.out.println("通过Map.keySet遍历key和value：");
    for (String key : map.keySet()) {
    System.out.println("key= "+ key + " and value= " + map.get(key));
    }
    
    //第二种
    System.out.println("通过Map.entrySet使用iterator遍历key和value：");
    Iterator<Map.Entry<String, String>> it = map.entrySet().iterator();
    while (it.hasNext()) {
    Map.Entry<String, String> entry = it.next();
    System.out.println("key= " + entry.getKey() + " and value= " + entry.getValue());
    }
    
    //第三种：推荐，尤其是容量大时
    System.out.println("通过Map.entrySet遍历key和value");
    for (Map.Entry<String, String> entry : map.entrySet()) {
    System.out.println("key= " + entry.getKey() + " and value= " + entry.getValue());
    }
    
    //第四种
    System.out.println("通过Map.values()遍历所有的value，但不能遍历key");
    for (String v : map.values()) {
    System.out.println("value= " + v);
    ```
3. modifiers
    1. containsKey(object key)
    2. containsValue(object value)
    3. Set<Map.Entry<K,V>> entrySet()
    4. equals(obj)
    5. get(object key): get the value
    6. isEmpty()
    7. keySet()
    8. **put(K key, V value)**
    9. putAll(Map<> m): put the whole map into it
    10. remove(object key)
    11. Collection<V> values()

## Regular Expression

1. First new Object Pattern, but it does not has constructor, need to use Pattern.compile()
    `Pattern p = Pattern.compile(REGEX)`
2. Object Matcher to complete the matches
    `Matcher m = p.matcher(INPUT);`
3. Matcher Methods
    1. Indexing
        1. boolean find()
            if it finds the matching substring to REGEX.
        2. boolean find(int start)
            start at the given offset to find the matching substring
        3. boolean matches()
            if the whole string matches REGEX
        4. int start(), int end()
            return the starting(ending) index of last finding result
    2. Replacing
        1. **Matcher appendReplacement(StringBuffer sb, String replacement)**
            append the replaced substring starting from the last finding result to sb(StringBuffer).
        2. StringBuffer appendTail(StringBuffer sb)
            append the content starting from the last finding result to sb(StringBuffer).
        3. replaceAll(String replace)
        4. replaceFirst(String replace)
    3. Region
        1. region(int start, int end)
            set the limits of this matcher's region
        2. int regionStart(), int regionEnd()

