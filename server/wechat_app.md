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

3. Global variables or function
	1. write in app.js and use `var app = getApp()` function to obtain the app object outside of app.js

4. String, Json, Map
	1. String to Json: `JSON.parse(string)`
	2. Json to String: `JSON.stringify(json)`


## Django

### URL
1. path() function can pass multiple parameter to views
	```
	path('download/<str:file_name>', views.download)
	def download(request, file_name)
	```
2. create namespace for app
	1. path('app/', include('app.urls', namespace = 'app'))
		first `from django.urls import include, path`		
		can create urls.py in app directory. and then in the main urls.py include('app.urls').
		The truncated part of url will pass to the app's urls.py
	2. add `app_name = 'your app name'` to the 'your app/urls.py'
	3. path name
		`path('polls/<int:id>/', views.func, name='id')`
		The url is named as id, and we can use it in templates
		`<a href="{% url 'app:id' question.id %}">`
	4. apply **{% url 'app: view name' \<parameters> %}**
	
3. POST form in HTML
	1. add `{% csrf token %}` inside the post form
	2. add `enctype = 'multipart/form-data'` in `<form enctype = 'multipart/form-data' method = 'post' action = ''>`


### Models

#### Basic
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

    python manage.py migrate

  

2. Model Attribute
  3. choices
   4. use tuples to determine the chosen value of a attribute.
        ```python
        	class Person(models.Model):
        		SHIRT_SIZES = (
        			('S', 'Small'),
        			('M', 'Medium'),
        			('L', 'Large'),
        		)
        		name = models.CharField(max_length=60)
        		shirt_size = models.CharField(max_length=1, choices=SHIRT_SIZES)
        ```
   5. The value stored in DB is the first element in the tuple. But the value displayed is the second element.
3. DateTimeField

   1. DateTimeField: datetime.datetime; DateField: datetime.date; TimeField: datetime.time

   2. 'auto_now'

      1. every time Models.save() is called, the attribute is updated to the current timedate.
      2. However, it can not be changed by update() anymore.

   3. 'auto_now_add'

      1. assign value when the object is created
      2. However, it can not be changed by update() anymore.

      

4. admin API
   1. `python manage.py createsuperuser`

   2. Add models in app/admin.py
     ```
     from .models import Question
     admin.site.register(ModelName)
     ```


### HttpResponse
1. HttpResponse()
	1. parameter `content_type = ''` to specify data type
	2. Add header
		```
		response = HttpResponse()
		response['file_name'] = "image.png"
		return response 
		```
	3. Add body
		`response.write('<p>text of testing.</p>')`
	4. Get body
		`response.content`

2. JsonResponse()
	1. default to send json data body
	```
	from django.http import JsonResponse
	response = JsonResponse({'foo': 'bar'})
	response.content
	```



### Apache WSGI
1. application issues on mod_wsgi. An extension module like (cv2) not designed to work in sub interpreter. Add one line in **httpd.conf** to force it run in main interpreter.
`WSGIApplicationGroup %{GLOBAL}`
2. Reference **application issues on mod_wsgi**


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


### Aliyun
1. Aliyun Security Group: must set the http 80/80 first

2. Apache's group and user should be changed to the user owing mysite directory


