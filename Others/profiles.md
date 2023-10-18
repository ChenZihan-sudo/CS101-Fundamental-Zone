**User profile .zshrc for Mac**
```bash
# >>> USER PROFILES >>>
alias la="ls"
eval "$(oh-my-posh init zsh --config $(brew --prefix oh-my-posh)/themes/M365Princess.omp.json)"
alias setproxy="export https_proxy=http://127.0.0.1:7890 http_proxy=http://127.0.0.1:7890 all_proxy=socks5://127.0.0.1:7890"
alias unsetproxy="unset https_proxy http_proxy all_proxy"
# <<< USER PROFILES <<<
```

**Make Your Boring Mac Terminal So Much Better**  
https://www.youtube.com/watch?v=CF1tMjvHDRA  
https://www.josean.com/posts/terminal-setup

**Check IP Address**  
`curl cip.cc`  

**Set Terminal Font for VSCode**  
`"terminal.integrated.fontFamily":"<Font family>"`


