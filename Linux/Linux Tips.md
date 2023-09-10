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

### Install Homebrew

### Install and config Oh-my-posh

### Install LLVM
```bash
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh <version number> all
```

## WSL Commands
```powershell
wsl --install
wsl --list --online
wsl --shutdown
wsl --mount <DiskPath>
wsl --unmount <DiskPath>
```

## Switch the software version by update-alternatives
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

## sudo apt autoremove
Remove not required packages

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

## Command: Source
The Linux source command is a shell command that reads and executes commands from a file in current shell environment. file is typically a shell script, but it can also be any text file containing a series of commands. source command is often used to set environment variables, define functions, and execute initialization scripts.


## Admin back to user account
Use: `su <user name>`