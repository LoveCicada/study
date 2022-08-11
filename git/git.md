### git基础使用

 ### `git提交代码`
 ```
git add . 把本地增删改添加到暂存区
git commit -m "comment" 提交到本地仓库，添加注释
git push origin master 推送到远程master分支
 ``` 

### `git 放弃本地修改`
- `未使用 git add 缓存代码时`
```
使用 git checkout -- filepathname (
比如： git checkout -- readme.md  ，不要忘记中间的 “--” ，不写就成了检出分支了！！)。
放弃所有的文件修改可以使用 git checkout .  命令。

此命令用来放弃掉所有还没有加入到缓存区（就是 git add 命令）的修改：内容修改与整个文件删除。
但此命令不会删除掉刚新建的文件。因为刚新建的文件还没已有加入到 git 的管理系统中。
所以对于git是未知的。自己手动删除就好了。
```

- `已经使用了  git add 缓存了代码`
```
可以使用 git reset HEAD filepathname （比如： git reset HEAD readme.md）来放弃指定文件的缓存，
放弃所以的缓存可以使用 git reset HEAD . 命令。

此命令用来清除 git  对于文件修改的缓存。相当于撤销 git add 命令所在的工作。
在使用本命令后，本地的修改并不会消失，而是回到了如（一）所示的状态。继续用（一）中的操作，
就可以放弃本地的修改。
```

- `已经用 git commit  提交了代码`
```
使用 git reset --hard HEAD^ 来回退到上一次commit的状态。
此命令可以用来回退到任意版本：git reset --hard  commitid 

你可以使用 git log 命令来查看git的提交历史。

回到了如（二）所示的状态。继续用（二、一）中的操作，就可放弃本地的修改
```

- `删除未监视的文件untracked files`
```

# 删除 untracked files
git clean -f
 
# 连 untracked 的目录也一起删掉
git clean -fd
 
# 连 gitignore 的untrack 文件/目录也一起删掉 （慎用，一般这个是用来删掉编译出来的 .o之类的文件用的）
git clean -xfd
 
# 在用上述 git clean 前，墙裂建议加上 -n 参数来先看看会删掉哪些文件，防止重要文件被误删
git clean -nxfd
git clean -nf
git clean -nfd
```

- `强制pull`
```
git fetch --all  
git reset --hard origin/master
git pull
```

### `git切换分支`

- `git查看远程所有分支`
```
git branch -a
```

- `git查看当前分支`
```
git branch
```

- `git切换分支`
```
git checkout -b control origin/control
```

### `git合并代码`
- `pull`
```
git pull origin/master
pull = fetch + merge
```

- `merge`
```
git merge branchB 合并branchB分支到当前分支
```

- `rebase`
```
git fetch 拉取远端最新代码状态
git rebase origin/master 合并远端分支origin/master到当前分支

git rebase master 合并本地master分支到当前分支
```

### `git基础命令`
- `git常用命令`
```
git status  查看当前状态
git log     查看提交日志
git merge dev  合并dev分支至当前分支
git add .      添加当前目录全部文件至暂存区
git commit -m '测试'    提交，提交信息为测试
git push origin master  推送至远端分支（master为需要推送分支，按实际需要选择）
git pull origin master  合并远端分支至本地 (git pull 等于 git fetch + git merge)
git pull --rebase origin master rebase方式合并远端分支至本地
git branch          查看当前分支
git branch dev      创建dev分支  （dev可选）
git branch -d dev   删除dev分支
git branch -r       查看远程分支
git branch -a       查看所有分支 （包括远程分支）
git checkout master 切换至master分支
git checkout -b dev 创建dev分支并切换至dev分支
git checkout -b dev origin/dev 创建远程分支到本地
git restore file    丢弃工作区修改（file为具体文件名称）
git restore *       丢弃所有工作区修改
git restore --staged file   回退暂存区文件 不会更改文件内容
git rebase --continue       rebase后继续操作
git rebase --abort          退出rebase 操作
```

***
[git解决冲突](https://blog.csdn.net/qq_44536533/article/details/123412327)

***