#!/bin/bash


if [ "$#" -ne 4 ]; then
    echo "Usage: $0 <file> <softLink> <hardLink> <fifo>"
    exit 1
fi

source="$1"

if [ ! -f "$source" ]; then
    echo "Creating original file: $source"
    touch "$source"
fi

ln -s "$source" "$2"
ln "$source" "$3"   
mkfifo "$4"       
exit 0