# fusion-chat
goofy ahh chat server+client

# Installation Instructions
## Linux
### Building from Source
Step 1. Install git<br>
Ubuntu:
```console
sudo apt update
sudo apt install git
```
Arch:
```console
pacman -Sy
pacman -S git
```
Step 2. Install a C++ compiler such as clang++<br>
Ubuntu:
```console
sudo apt update
sudo apt install clang
```
Arch:
```console
pacman -Sy
pacman -S clang
```
Step 3. Clone this repository to a folder<br>
```console
mkdir fusion-chat/
cd fusion-chat/
git clone https://github.com/xNoerPlaysCodes/fusion.git .
```
Step 4. Compile the client (Fusion supports only localhost at this moment)<br>
```console
clang++ -o fusion-client fusion-client.cpp
```
Step 5. Start the client<br>
```console
./fusion-client
```
and follow the instructions from there
### Using compiled executable
*Not supported*
## macOS
### Building from source
[Here](https://github.com/xNoerPlaysCodes/fusion#linux)
### Using Compiled Executable
*Not supported*

\* NOTE: Windows is not supported, you can build source yourself without instructions only
