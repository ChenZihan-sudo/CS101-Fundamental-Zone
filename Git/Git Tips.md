# Git Tips 

## Set your default branch
Github use `main` as a initial branch, but Git use `master`.
You can change the default initial branch using `git config --global init.defaultBranch <name>` to avoid branch problems.

## Set your default author identity
```bash
  git config --global user.email "you@example.com"
  git config --global user.name "Your Name"
```

## Set Proxy for Git
```bash
git config --global http.proxy <Your IP Address>
git config --global https.proxy <Your IP Address>
```

## Present modification of .gitignore to branch
After modify the `.gitignore` to ignore some files/folders
```bash
git rm -r --cached .
git add .
```

## Push your code to remote branch

```bash
git add . && git commit -m <commit comment> && git push origin <branch>
```

