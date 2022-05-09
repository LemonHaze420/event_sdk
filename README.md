# event_sdk
Shenmue II (for Dreamcast) uses _"event scripts"_, which are loaded on-the-fly, in order to perform most of the game logic, called _EV1/2/3_. 

This repository provides tools which will allow a developer to write their own EV1/2/3 scripts which can be used on the game, using gcc and binutils.

## Prerequisites

  [gcc-11.3.0](https://mirrorservice.org/sites/sourceware.org/pub/gcc/releases/gcc-11.3.0/gcc-11.3.0.tar.gz)
  
  [binutils-2.38](https://ftp.gnu.org/gnu/binutils/binutils-2.38.tar.gz)
  
## Setup
  
 1. Retrieve and unpack the above source code and insert the following lines into `~/.bashrc`
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

To build..

an EV1:
    ```
      make -j TYPE=EV1
    ```
    
an EV2:
    ```
      make -j TYPE=EV2
    ```
    
an EV3:
    ```
      make -j TYPE=EV3
    ```
    
## Development

There are a few limitations and unresolved issues which still require some work. 

  * the examples and SDK code currently uses hard-coded function offsets which means it only supports the build i am currently working on. we can change this to use the event function table and using only indexes for that table, which will give us compatibility with all known Shenmue 2 Dreamcast builds.
  * absolutely no support for tasks with parameters and completely missing any heap space memory management functions. this is useful for sharing data between tasks etc.
  * the function calls in the simple example are probably 90% not required/useful, so tracking down the function responsible for relinquishing control back to the user and ultimately removing the loading screen needs to be identified.
  * the location of `start` (the entrypoint) needs to be fixed at 0x0. this can be done thru linker flags. for now, any pure functions defined by our code must be explicitly forward declared and must be placed after `start` to ensure that it is always at 0x0 in the resulting binary.
  * ... and likely countless more, except these are the most important for now.