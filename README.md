# SNESticle
SNESticle source code (circa ~2004) modified to build and run under "modern" windows and Playstation 2[W.I.P]


Pull requests are welcome! Other platforms may follow

Latest download here:

https://github.com/Wolf3s/SNESticle/releases/tag/latest

Forked from:
https://github.com/iaddis/SNESticle and https://github.com/tmaul/SNESticle

# Windows

You need a Visual Studio 2022 installed and then hit the SNESticle_2022.sln file plus choose the arch you want to build.
The Available arch´s is:
x86
x64

# Playstation 2

You need PS2SDK installed on your machine, To install it follow the instructions on this [repository](https://github.com/ps2dev/ps2dev.git)
WARNING: It needs to be latest version. 
then proceed to: SNESticle/Project/ps2 and then hit ```make all``` it will generate a SNESticle.elf

# TODO SECTION:
* [PS2]Remove compiled irx modules and replace by the generated ps2dev ones[HARD].
* [PS2]Replace libcdvd with PS2DEV libcdvd latest version[MEDIUM].
* [PS2]Update Makefile to latest PS2SDK version[MEDIUM](Done).
* [PS2]Remove some implementation GS files and use gsKit instead[MEDIUM].
* Port C code to C89[Workful].