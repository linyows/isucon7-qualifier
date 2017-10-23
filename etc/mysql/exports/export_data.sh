#!/bin/bash

MYSQL="mysql -u root isubata --skip-column-names -e"

for file in $($MYSQL 'select name from image' | sort | uniq); do
  $MYSQL "select data from image where name = \"$file\"" >> data/$file
done
