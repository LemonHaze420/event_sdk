# event_sdk
Shenmue II (for Dreamcast) uses _"event scripts"_, which are loaded on-the-fly, in order to perform most of the game logic, called _EV1/2/3_. 

This repository provides tools which will allow a developer to write their own EV1/2/3 scripts which can be used on the game, using gcc and binutils.

## Prerequisites

  [gcc-11.3.0](https://mirrorservice.org/sites/sourceware.org/pub/gcc/releases/gcc-11.3.0/gcc-11.3.0.tar.gz)

  [binutils-2.38](https://ftp.gnu.org/gnu/binutils/binutils-2.38.tar.gz)
  
## Setup
  
 1. Retrieve and unpack the above source code and insert the following lines into `~/.bashrc`, using something like `nano ~/.bashrc`.
    ```
    export PREFIX="$HOME/opt/dc"
    export TARGET=sh4-elf
    export PATH="$PREFIX/bin:$PATH"
    ```

 2. Execute the following commands to build and install binutils:
    ```
    cd binutils-2.38
    mkdir build
    cd build
    ../configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
    make -j
    make -j install
    ```

 3. Execute the following commands to build and install gcc:
    ```
    cd gcc-11.3.0
    contrib/download_prerequisites
    mkdir build
    cd build
    ../configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
    make -j all-gcc
    make -j all-target-libgcc
    make -j install-gcc
    make -j install-target-libgcc
    ```
    
You should now have a working development environment to run `make` in any of the directories in this repository.

## Build

Building the scripts is as easy as invoking `make` in a directory containing the included sample Makefile. In order to build..

an EV1:

      make -j TYPE=EV1
    
    
an EV2:

      make -j TYPE=EV2
    
    
an EV3:

      make -j TYPE=EV3
      
These commands will build EV* scripts which use the physical address of the Dreamcast system RAM. This doesn't work for Retail builds of the game for obvious reasons and so to compile and run EV* scripts for use on Retail builds of the game, it's necessary to add `RETAIL=1` to the `make` command and to also add a 'P' to the `TYPE` name, for example, to build an EV3 for use on a Retail build:-

      make -j TYPE=EV3P RETAIL=1
    
    
## Development

Initial testing with the toolchain indicated that `-fPIC` seems to be working for the most part, but this needs more testing. It may be possible to alleviate the need of ensuring the scripts are compiled with the relevant VMA through the use of `-fPIC`.

There are a few limitations and unresolved issues which still require some work. 

  * ~~the examples and SDK code currently uses hard-coded function offsets which means it only supports the build i am currently working on. we can change this to use the event function table and using only indexes for that table, which will give us compatibility with all known Shenmue 2 Dreamcast builds.~~ - Moved all functions which can be into inlined functions which calculate the fn address before calling. Should support all builds now (tested with US and GameJam).
  * absolutely no support for tasks with parameters and completely missing any heap space memory management functions. this is useful for sharing data between tasks etc.
  * ~~the function calls in the simple example are probably 90% not required/useful, so tracking down the function responsible for relinquishing control back to the user and ultimately removing the loading screen needs to be identified.~~ - Done, 2 functions out of the 7-8 are responsible for removing the loading screen and relinquishing control. Edited `dev_load_scene`.
  * ~~the location of `start` (the entrypoint) needs to be fixed at 0x0. this can be done thru linker flags. for now, any pure functions defined by our code must be explicitly forward declared and must be placed after `start` to ensure that it is always at 0x0 in the resulting binary.~~ - Written up a simple linker script which puts `.text.main` above everything else. Should be fixed now.
  * ... and likely countless more, except these are the most important for now.

## Limitations

Event scripts in Shenmue II are limited by their size. 
The size constraints are as follows:-

| Type |   Size  |
|------|---------|
| EV1  | 0x10000 | 
| EV2  | 0x10000 |
| EV3  | 0x18000 |
