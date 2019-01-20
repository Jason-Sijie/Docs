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
`<enctype="multipart/form-data">`

2. wx.uploadfile
上传的file用 request.FILES.get()函数来获取
formdata用 request.POST.get()函数来获取


## Django

### URL
1. path() function can pass multiple parameter to views
	```
	path('download/<str:file_name>', views.download)
	def download(request, file_name)
	```
2. path('app/', include('app.urls'))
	first `from django.urls import include, path`		
	can create urls.py in app directory. and then in the main urls.py include('app.urls').
	The truncated part of url will pass to the app's urls.py
3. path name
	`path('polls/<int:id>/', views.func, name='id')`
	The url is named as id, and we can use it in templates
	`<a href="{% url 'id' question.id %}">`



### Models
1. create a new model in new app
	1. create models in app/models.py
		```
		from django.db import models
		class XXXX(model.Models):
			name = models.datatype()
		```

	2. create migration files of app models in your server
		Add one line `app.apps.XXXXConfig` in mysite/settings.py INSTALLED_APPS.
		And then run `python manage.py makemigrations app` to migrate the database

	3. migrate the app's DB to server DB
		`python manage.py migrate`
2. admin API
	1. `python manage.py createsuperuser`
	2. Add models in app/admin.py
		```
		from .models import Question
		admin.site.register(ModelName)
		```
3. 



### python encoding
1. have to use 4 spaces to replace all the tabs in the file
    1. vim (global setting)
	```
	sudo vim /etc/vimrc
	// add at the end of the file
	set nu
	set tabstop=4
	set expandtab
	```


## Apache Install

### Mod_wsgi


### Aliyun
1. Aliyun Security Group: must set the http 80/80 first

2. Apache's group and user should be changed to the user owing mysite directory


