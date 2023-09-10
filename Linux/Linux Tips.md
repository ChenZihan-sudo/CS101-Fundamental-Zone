# Linux Tips

## Ubuntu Development environment build commands

### Necessary software pack
```bash
sudo apt update
sudo apt install clang clangd clang-format clang-tidy gcc cmake
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


## update-alternatives

## sudo apt autoremove
Remove the not required package