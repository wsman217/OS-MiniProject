#! /bin/bash
# make build

algorithm=0

if [ "$2" = "sjf" ]
then
  algorithm=1
fi

./scheduler.out "$1" "$algorithm"