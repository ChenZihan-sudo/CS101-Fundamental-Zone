# Linux Tips

## Ubuntu Development environment build commands

### Disable Windows ENV:PATH
```bash
sudo su
echo -e  "[interop] \nappendWindowsPath=false">>/etc/wsl.conf
```
### Necessary software pack
```bash
sudo apt update
sudo apt install cmake
```
### Bypass DNS Host Parse
Why? Bypass DNS server parse to avoid domain name pollution by GFW in China.
* Find IP of Hostname by DNS lookup
```bash
nano /etc/hosts
# Format: XXX.XXX.XXX.XXX example.com
```

### Use Windows Proxy
https://zhuanlan.zhihu.com/p/153124468  
Get DNS Server IP, which point to windows
**Apply only once**
```bash
cat /etc/resolv.conf
export ALL_PROXY="<DNS Server IP Address>"
```
**Persistence the proxy**
```bash
sudo su
echo "host_ip=\$(cat /etc/resolv.conf | grep nameserver | cut -f 2 -d \" \")">>/etc/profile
echo "export ALL_PROXY=\"<Protocol>://\$host_ip:<your proxy port>\"">>/etc/profile
source /etc/profile
```

### Install Homebrew

### Install and config Oh-my-posh

### Install LLVM
```bash
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh <version number> all
```

### WSL Commands
```powershell
wsl --install
wsl --list --online
wsl --shutdown
wsl --mount <DiskPath>
wsl --unmount <DiskPath>
```



## Environement Variables
https://blog.csdn.net/xjjxjy_2021/article/details/130875975

### Common Environement Variables
**PATH:** Search path of commands.  
**HOME**  
**LOGNAME**  
**HOSTNAME**  
**SHELL**  

### Usage in Shell
**Print environment variable values**  
`echo $<env var name>`
Example: `echo $PATH`

**Set a new environment variable**  
Example: 
```bash
export a_env_var="A Environment Variable"
env | grep a_env_var
```

**Unset a environment variable**
Example: 
```bash
unset a_env_var
env | grep a_env_var
```

**Add/Delete a item for $PATH**
```bash
# Add
export PATH=$PATH:<path>

# Delete
echo $PATH # Copy without the path that ready to delete
export PATH=<paths>
```

**Persistence environment varibale**
```bash
sudo su
echo "export PATH=\$PATH:<path>">>/etc/profile
source /etc/profile
```


## Proxy

### Set DNS Server
```bash
nano /etc/resolv.conf

# Add nameserver below (Google DNS Server)
nameserver 8.8.8.8
nameserver 8.8.4.4

source /etc/resolv.conf
```

### Set proxy alias
```bash
sudo su
echo -e "\nalias setproxy=\"export ALL_PROXY=socks5://198.18.0.1:16001 && echo \${ALL_PROXY}\"\n">>~/.bashrc
echo -e "\nalias unsetproxy=\"unset ALL_PROXY && echo 'proxy unseted.'\"\n">>~/.bashrc
source ~/.bashrc
```


## Commands

### update-alternatives
**Switch the software version by update-alternatives**
https://blog.csdn.net/qq_21367897/article/details/89606953

**Add a new alternatives group**
```bash
update-alternatives --install <link> <name> <path> <priority>
# example: sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-16 1
```
**Switch the version of software**
```bash
update-alternatives --config <name>
# example: sudo update-alternatives --config clang
```
**Remove alternatives group link**
```bash
update-alternatives --remove <name> <path>
# example: sudo update-alternatives --remove clang /usr/bin/clang-14
```

### alias
**Define alias**
```bash
# Example: 
alias print_hello_world="echo 'Hello world!'"
print_hello_world # Output: Hello world!
```
**Show alias**  
`alias -p`

**Persistence alias by put command into shell configuration file**
```bash
sudo su
echo -e "\n <Some commands>">>~/.bashrc
echo -e "\n <Some commands>">>~/.bashrc
source ~/.bashrc
```

### source
The Linux source command is a shell command that reads and executes commands from a file in current shell environment. file is typically a shell script, but it can also be any text file containing a series of commands. source command is often used to set environment variables, define functions, and execute initialization scripts.


## Some Tips
### sudo apt autoremove
Remove not required packages

### Admin back to user account
Use: `su <user name>`

