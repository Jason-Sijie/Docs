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

7. git push
	1. Specify the branches both at local and remote repositories. `git push <remote host name> <local branch>:<remote branch>`
	2. If we ignore the `<remote branch>`, then it would automatically be pushed to the branch that has the same name. (create a new branch if it cannot find such branch at remote host).
	3. Delete remote branch `git push origin --delete <branch name>`

8. git pull
	1. `git pull <remote host> <remote branch>:<local branch>`. It first fetch the remote branch and then merge with the local branch
	2. If we ignore the `<local branch>`, it would automatically fetch and merge with the current branch.

9. git merge
	1. checkout to the destination branch
	2. `git merge <branch>` : `git merge origin/fast-dev`

10. git log
	1. pretty nice log: `git log --graph --decorate --pretty=oneline --abbrev-commit --all`

11. solve conflict
	1. first `git rebase -i <commit>` to the first diverged node. This squashes all the commits into one
	2. then `git merge <remote branch>` and solve the conflict