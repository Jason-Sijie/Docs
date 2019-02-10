# wechat app

## CentOS python3.6

1. Create user
	```
	adduser username
	passwd username
	```

2. Grant sudo previlege
	give the sudo command to new user, need to change the /etc/sudoers file
	`chmod -v u+w /etc/sudoers`
 	add one line at "username  ALL=(ALL)       ALL"
	`chmod -v u-w /etc/sudoers`
	then you can switch to the new user

3. anaconda 配置django和opencv环境
	```	
	conda create -n name python=3.6
	pip upgrade
	pip install python-opencv
	pip install django
	```

4. intsall python3.6 without anaconda (using yum)
	1. you should install python36-devel together with python36, because it is required by http and django
	`sudo yum install python36 python36-devel`

	2. If there is no pip3.6 after install python36 using yum
	```
	yum install epel-release -y
	yum install https://centos7.iuscommunity.org/ius-release.rpm -y
	yum install python36u-pip -y
	```

5. using pip3.6 install opencv-python
	1. problem: error in loading cv2 module (missing libSM.so.6)
        solution: `sudo yum install libXext libSM libXrender`


## Wechat App Doc

1. post上传文件
request中的FILES来获取文件内容，必须要在html的form中加上这个属性
<enctype="multipart/form-data">

2. wx.uploadfile
上传的file用 request.FILES.get()函数来获取
formdata用 request.POST.get()函数来获取


## Django

1. URL
	1. path() function can pass multiple parameter to views
		```
		path('download/<str:file_name>', views.download)
		def download(request, file_name)
		```
	2. create namespace for app
		1. add `app_name = 'your app name'` to the 'your app/urls.py'
		2. add namespace in the main urls.py file
			`path('app/', include('app.urls', namespace = 'app'))`
		3. apply **{% url 'app: view name' \<parameters> %}**
	3. POST form in HTML
		1. add `{% csrf token %}` inside the post form
		2. add `enctype = 'multipart/form-data'` in `<form enctype = 'multipart/form-data' method = 'post' action = ''>`


## Aliyun

1. Aliyun Security Group: must set the http 80/80 first

2. Apache's group and user should be changed to the user owing mysite directory


