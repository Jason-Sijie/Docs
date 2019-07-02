# Ubuntu 

## Create shortcur of application

1. create a file 'name.desktop' at '/usr/share/applications/'
    `sudo vim /usr/share/applications/intellij-idea.desktop`

2. The content of that file
    ```
    [Desktop Entry]
    Name= idea   (mandatory)
    Comment= idea  
    Exec= path to ./sh
    Icon= path to icon
    Terminal=false 
    Type=Application    (mandatory)
    Categories=Application;Development; 
    ```

3. change the mod of that file
    `sudo chmod +x /usr/share/applications/intellij-idea.desktop`

## network

1. port number
    1. `netstat -ap` show all the LISTEN and ESTABLISHED port. `nestat -ap | grep 8080` It can be combined with grep.

    2. -t: show tcp; -u: show udp； -n: no DNS 

    3. `kill -9 pid` kill the service

## Environment Variable

1. PATH var
    1. show all PATH variables
        1. `$ export `
        2. `$ echo $PATH`
    
    2. add a new PATH variable
        1. `$ export PATH=/opt/STM/STLinux-2.3/devkit/sh4/bin:$PATH`
        2. The added path would be deleted when the terminal is closed.
    
    3. perminantly add PATH variables
        ```bash
        vim /etc/profile

        // at the end of the file
        export PATH="/opt/STM/STLinux-2.3/devkit/sh4/bin:$PATH"

        // run
        source /etc/profile
        ```

## apt

1. install path: `/usr/share`

    1. java home is at `/usr/lib/jvm`