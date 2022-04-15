### git基础使用

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