#! /usr/bin/bash

current_directory=$(pwd)/../

echo $current_directory

build_executable() {
    cd $current_directory/builds
    echo $pwd
    cmake ../
    make
}

if [ -d "$current_directory/builds" ] && echo "Build Directory exists!"
then 
    build_executable
else
    mkdir $current_directory/builds
    build_executable
fi