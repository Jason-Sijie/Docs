# Git

1. git忽略本地更新，更新远程修改到本地
	```
	git fetch --all (将远程库中所有的数据复制到本地remote文件夹中)
	git reset --hard origin/master
	```
	tips： git branch -a 可以查看当前所有的分支

2. checkout
	1. remove the changes made in working set
		`git checkout -- filename (*)`
	2. create branch
		1. create a branch and point to it
			`git checkout -b dev`
			It is equal to 
			```
			git branch dev
			git checkout dev
			```
		2. after made modifications, we change back to master and merge with dev
			```
			git checkout master
			git merge dev
			```
		3. then we can delete branch dev
			`git branch -d dev`

3. 