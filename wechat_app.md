# wechat app

1. git忽略本地更新，更新远程修改到本地
```
git fetch --all (将远程库中所有的数据复制到本地remote文件夹中)
git reset --hard origin/master
```

tips： git branch -a 可以查看当前所有的分支

2. post上传文件
request中的FILES来获取文件内容，必须要在html的form中加上这个属性
<enctype="multipart/form-data">

3. wx.uploadfile
上传的file用 request.FILES.get()函数来获取
formdata用 request.POST.get()函数来获取

4. anaconda 配置django和opencv环境
conda create -n name python=3.6
pip upgrade
pip install python-opencv
pip install django
