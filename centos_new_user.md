# Centos create new user
## 1.Create user

- adduser username
- passwd username

## 2.Grant sudo previlege
- give the sudo command to new user, need to change the /etc/sudoers file
- chmod -v u+w /etc/sudoers
- add one line at "username  ALL=(ALL)       ALL"
- chmod -v u-w /etc/sudoers
- then you can switch to the new user
