# Shell

## Run the script
- make the script executable
`chmod +x ./test.sh`

- run by interpretor
`/bin/sh test.sh`

## Variables

- can assign values by statement
```sh
for file in `ls /etc`
for file in $(ls /etc)
```
- not need `$` when assigning value, but need $ to read the variable
- delete var `unset var`
- make var readonly `readonly myUrl`

### String
- \' would not apply varibles and Escape character
- \" use variable within string `echo "I am good at ${skill}Script"`
- get length `echo ${#string}`
- get substring `echo ${string:1:4}` means start from second char and get the 4 consecutive chars

### Array
- create
    ```sh
    array = (val1 val2 val3)
    array = (
        val1
        val2
        val3
    )
    array[0] = val0
    array[3] = val3
    ```
- read
    - `${array[index]}`
    - `echo ${array[@]}` can output all the values in the array
    - 