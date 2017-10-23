#!/bin/sh

echo 'Downloading release file.......'
cd /tmp
export GITHUB_TOKEN=
github-release download -n isubata -u monochromegane -r isucon7 -l

echo 'Moving release file.......'
cd ~/isubata/webapp/go
mv /tmp/isubata isubata
chmod u+x isubata
chown isucon:isucon isubata

echo 'Clear nginx log file.......'
echo '' > /var/log/nginx/access.log

echo 'Restarting isubata and nginx.......'
systemctl restart isubata.golang.service
systemctl restart nginx

