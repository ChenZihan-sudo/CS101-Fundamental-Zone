# Git Tips 
https://learngitbranching.js.org/https://learngitbranching.js.org

## Configurations
### Set your default branch
Github use `main` as a initial branch, but Git use `master`.
You can change the default initial branch using `git config --global init.defaultBranch <name>` to avoid branch problems.

### Set your default author identity
```bash
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```

### Set Proxy for your Git
```bash
git config --global http.proxy <Your IP Address>
git config --global https.proxy <Your IP Address>
```

### Unset any git config
```bash
git config --unset <name>
```

## Basic command operations

### git init

### git clone

### git add

### git commit
`git commit --amend`

### git push
`push.default`

### git pull
`git pull`          `git fetch` and `git merge`  
`git pull --rebase` `git fetch` and `git rebase origin main`  


## Advanced command operations
### Remote branch
`<remote name>/<branch name>`  
Default remote name is `origin`

### git branch
List, create, or delete branches
`git branch -f <src branch> <dst branch>`
`git branch <new branch> <destination>`

### git checkout
Switch branches or restore working tree files  

Command `git checkout -b <branch>` equal to 
```bash
git branch <branch>
git checkout <branch>
```
### git merge

### git rebase
**git rebase -i**

### git reset

### git revert

### git cherry-pick

### git fetch

### git tag

### git describe

### git bisect

## Symobol reference
### HEAD
HEAD is the symbolic name for the currently checked out commit.  
### Relative reference
`^` Move up 1 commit record. Example: `HEAD^`  
`^^` Move up 2 commit record. Example: `main^^`  
`~<num>` Move up `<num>` commit record. Example: `main~3`  
### Chain operation
Example: `git checkout HEAD~^2~2`

## Applications
### Push your code to remote branch
```bash
git add . && git commit -m <commit comment> && git push origin <branch>
```
### Pull Request

### Present modification of .gitignore to branch
After modify the `.gitignore` to ignore some files/folders
```bash
git rm -r --cached .
git add .
```

### Delete remote branch
```bash  
git push origin --delete MdAdd
```

## Sub Commands
```bash
git show-branch
git show-ref
git log
```