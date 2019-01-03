# Install Python36 on Centos7

## Install python36 using yum
- you should install python36-devel together with python36, because it is required by http and django
- `sudo yum install python36 python36-devel`

**Problem**:

1. If there is no pip3.6 after install python36 using yum

```
yum install epel-release -y
yum install https://centos7.iuscommunity.org/ius-release.rpm -y
yum install python36u-pip -y
```

2. Aliyun Security Group: must set the http 80/80 first

3. Apache's group and user should be changed to the user owing mysite directory
