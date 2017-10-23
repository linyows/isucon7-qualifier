#!/bin/bash

MYSQL="mysql -u isucon -hdb --password=isucon isubata --skip-column-names -e"

for file in $($MYSQL 'select name from image' | sort | uniq); do
  curl -s -O http://localhost:5000/icons/$file
  sleep 0.5
done
