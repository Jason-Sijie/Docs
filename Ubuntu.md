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