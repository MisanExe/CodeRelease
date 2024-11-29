#!/bin/bash

SyslocalBin_dir="/usr/local/bin"
SysInstalled_dir="/usr/local/bin/CodeRelease"
bin="build/CodeRelease"

#move executable to local
if [ ! -f $bin ]; then 
    echo "unable to find '$bin' in current folder"
    exit 1
else
    echo "Installing CodeRelease Version ----"
fi

#copy to the local bin directory | 1) check if already installed, then replace
if [ -f $SysInstalled_dir ]; then 
    echo "A verison of this program already exists, updating program"
    cp -u $bin $SyslocalBin_dir
else
    cp $bin $SyslocalBin_dir
fi

if [ $? -eq 0 ]; then 
    source ~/.bashrc
    if [ $? -eq 0 ]; then 
        echo "installation complete"
        exit 0
    fi

    echo "installation failed"
    exit 1
else
    echo "installation failed"
    exit 1
fi
