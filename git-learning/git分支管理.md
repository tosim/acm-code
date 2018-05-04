# git command line

# 分支管理
## 一、本地

### 创建本地分支
	git branch dev						//创建本地dev分支
	git checkout -b dev					//创建本地dev分支并切换到dev分支
    
### 删除本地分支
	git branch -d dev					//删除本地dev分支，dev分支上的内容已经被合并
    git branch -D dev					//删除本地dev分支，无论dev分支上的内容是否被合并

## 二、远程

### 推送本地分支到远程
	git push origin dev 				//推送dev分支到名为origin的远程仓库

### 克隆远程分支到本地
	git branch dev origin/dev			//创建本地dev分支并与origin/dev关联
    git checkout -b dev origin/dev		//创建本地dev分支并与origin/dev关联
    
    若本地已经有dev分支了但是没有与远程关联，则添加关联
    git branch --set-upstream-to=origin/dev
    
### 删除远程分支
	git push origin --delete dev		//删除远程的dev分支
