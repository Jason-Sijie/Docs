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

3. stash
	1. push all the changes on the current working set into a stack
		`git stash`
	2. `git stash list` show all the stash info
	3. `git stash pop` return the top and remove it from stack
		`git stash apply` recovery
		`git stash drop` delete it from stack
	**tips**
	1. the stash cannot push untracked file, which means that you have to add it beforehand but not committed yet

4. remote
	1. `git remote -v` show all the remote
	2. `git push origin master(dev)` the second is your local repo
	3. git pull
		`git pull --set-upstream-to=origin/<branch> <branch>`
		pull is fetch plus merge

5. git add
	1. `git add --all <filepath>` can also add the removal

6. git ignore
	1. download the corresponding .gitignore file on github and place it at the root directory
	2. remove the ignored files from tracked files
		`git rm -r --cached <file/dir name>`