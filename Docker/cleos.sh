#!/bin/bash

# Usage:
# Go into cmd loop: sudo ./clETA.sh
# Run single cmd:  sudo ./clETA.sh <clETA paramers>

PREFIX="docker-compose exec nodETAd clETA"
if [ -z $1 ] ; then
  while :
  do
    read -e -p "clETA " cmd
    history -s "$cmd"
    $PREFIX $cmd
  done
else
  $PREFIX "$@"
fi
