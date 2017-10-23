ls -la
curl -s https://getcomposer.org/installer | /home/isucon/local/php/bin/php --help
curl -s https://getcomposer.org/installer | /home/isucon/local/php/bin/php -- --help
curl -s https://getcomposer.org/installer | /home/isucon/local/php/bin/php -- --filename=composer --install-dir=/home/isucon/local/php/bin/
cd local/php/bin/
ll
cd
mkdir isubata
ls -l
ls -la isubata/
ls -la isubata/webapp/
cd isubata/webapp/
ls -la
cd python/
/home/isucon/local/python/bin/pip install -r requirements.txt 
cd ../go
GOPATH=$(pwd) /home/isucon/local/go/bin/go build -v isubata
cd ../php
ls -la
/home/isucon/local/php/bin/composer install
/home/isucon/local/php/bin/php /home/isucon/local/php/bin/composer install
cd ./
cd ../
ll
cd ../
rm webapp/ -rf
ll
cd webapp/
ll
cd go
GOPATH=$(pwd) /home/isucon/local/go/bin/go build -v isubata
cd ../python/
/home/isucon/local/python/bin/pip install -r requirements.txt
cd ../php
/home/isucon/local/php/bin/php /home/isucon/local/php/bin/composer install
cd ../../
ll
cd ../
ll
cd local/php/etc/
ll
cd ~/isubata/webapp/nodejs/
ll
export PATH=/home/isucon/local/node/bin:$PATH
which npm
npm install
cd ../perl
/home/isucon/local/perl/bin/carton install
cd ../ruby
/home/isucon/local/ruby/bin/bundle install --path vendor/bundle
cd
exit
ls
cd isuda
cd isubata/
ls
md5sum src/isubata/app.go
pwd
cd webapp/
ls
cd go/
ls
md5sum src/isubata/app.go
pwd
ls
ping db
mysql -uroot isubata
exit
ll
ll release.sh 
sudo ./release.sh 
cat /var/log/nginx/access.log | ~/kataribe 
ll isubata/webapp/public/icons/
cat /var/log/nginx/access.log | ~/kataribe 
kls
sudo -s
crontab -e
crontab -l
ping db
sudo su
echo 'ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAqUJvs1vKgHRMH1dpxYcBBV687njS2YrJ+oeIKvbAbg6yL4QsJMeElcPOlmfWEYsp8vbRLXQCTvv14XJfKmgp8V9es5P/l8r5Came3X1S/muqRMONUTdygCpfyo+BJGIMVKtH8fSsBCWfJJ1EYEesyzxqc2u44yIiczM2b461tRwW+7cHNrQ6bKEY9sRMV0p/zkOdPwle30qQml+AlS1SvbrMiiJLEW75dSSENr5M+P4ciJHYXhsrgLE95+ThFPqbznZYWixxATWEYMLiK6OrSy5aYss4o9mvEBJozyrVdKyKz11zSK2D4Z/JTh8eP+NxAw5otqBmfNx+HhKRH3MhJQ== tomohisa@tomohisa-iMac.local' >> .ssh/authorized_keys
pwd
ls -las
ls -las .ssh
ssh-keygen
echo 'ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAqUJvs1vKgHRMH1dpxYcBBV687njS2YrJ+oeIKvbAbg6yL4QsJMeElcPOlmfWEYsp8vbRLXQCTvv14XJfKmgp8V9es5P/l8r5Came3X1S/muqRMONUTdygCpfyo+BJGIMVKtH8fSsBCWfJJ1EYEesyzxqc2u44yIiczM2b461tRwW+7cHNrQ6bKEY9sRMV0p/zkOdPwle30qQml+AlS1SvbrMiiJLEW75dSSENr5M+P4ciJHYXhsrgLE95+ThFPqbznZYWixxATWEYMLiK6OrSy5aYss4o9mvEBJozyrVdKyKz11zSK2D4Z/JTh8eP+NxAw5otqBmfNx+HhKRH3MhJQ== tomohisa@tomohisa-iMac.local' >> .ssh/authorized_keys
sudo su
ll
cd isubata/
ll
cd webapp/
ll
cd public/
ll
chown -R isucon:isucon .
ll
sudo su
cat ~/.ssh/id_rsa.pub 
ssh app0951
rsync -av -e "ssh ~/isubata/webapp/public/icons^Csucon@app0951:~/isubata/webapp/public/icons"
rsync -av /home/isucon/isubata/webapp/public/icons rsync://isucon@app0951:/home/isucon/isubata/webapp/public/icons
rsync -av -e ssh ~/isubata/webapp/public/icons^Csucon@app0951:~/isubata/webapp/public/icons
rsync -av -e ssh ~/isubata/webapp/public/icons isucon@app0951:~/isubata/webapp/public/icons
crontab -e
sudo su
crontab -e
ll
cd icons/
ll
touch foo
ll
rm foo
sudo su
echo 'ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAACAQCnzpR1gnRCfNTpvMGWiXLqjFxqgMN23hy2Q55ac9KJJXMTf1q1ZOKrt0EC6Bt/r7M7bo3EzmaIbOrTDxPtVpKgqHNpS31n6beVy/pukhcdWq0C6KI1miXpySZoWf2j05foDKMhvO2t15NddU9qmQn7fWwvCEwUKv13lAETSQ6ZKR1A7hFfNAFBxLACCyhvNpvVcVD1pbCymygENBOjtpIFSHFSdCBpm3FpVrH4sFbQZZyTicJW0sLMnHjdqlrM9F/GF+eGRdejSPpjZh6rNX54QMIR+oEyBqatFD6LH0lgWvw+VDwCHFaXQVbdLlRCQDxAH0ocMPHH4ZurYf69oDah73xfh3fCb9v+B+gp+4zN7MqcYZy15zw/PIKHySWitST1hi+uLwa3FXGIgHdMtFFrkR9hrpSqRwPduUanzU01jl1gmq237SKy0fuzmvUKdZPRkrLz4cNfdD++S6v4nrb8JHryp0Hp6NJ02XDtylKQJJX9ZL7lsxE/PCdMiG0CngdSe1MY2TV0tCt3TNvDfmk7zB4pe3GuOdGazIdlv2aukEAnSNmoVUflym08J4Oz676PI0onFUExEfok21AQNtt6WsUbi7Jd84Xx09HLjMFDPYyZQZWn9+u5ZIaAVPwg26T3w8FU/OJmKK+Autdm3VBc2UHTmDlL2qdrtLjcQZAMqw== dev.kuro.obi@gmail.com' >> ~/.ssh/authorized_keys 
ll
crontab -l
ll
ls -las | wc -l
crontab -l
sudo su
crontab -l
crontab -e
sudo su
crontab -e
sudo su
exit
ls
ls isubata/
ls isubata/webapp/
ls isubata/webapp/go/
ls isubata/webapp/go/isubata 
ll isubata/webapp/go/
ll isubata/webapp/go/isubata 
ps aux | grep nginx
wget https://github.com/aktau/github-release/releases/download/v0.7.2/linux-amd64-github-release.tar.bz2
tar xf linux-amd64-github-release.tar.bz2
ls
cp bin/linux/amd64/github-release /usr/local/bin/.
sudo cp bin/linux/amd64/github-release /usr/local/bin/.
ls
rm -rf linux-amd64-github-release.tar.bz2 bin
sudo apt-get install unzip
wget https://github.com/matsuu/kataribe/releases/download/v0.3.0/linux_amd64.zip
ls
unzip linux_amd64.zip 
ls
rm -rf linux_amd64.zip 
less /etc/nginx/nginx.conf 
sudo systemctl status mysql
sudo systemctl status mysqld
sudo systemctl status mysql
sudo cp /etc/nginx/nginx.conf{,org}
sudo vi /etc/nginx/nginx.conf
sudo systemctl restart nginx
sudo systemctl status nginx
cd /tmp/
github-release download -n isubata -u monochromegane -r isucon7 -l
export GITHUB_TOKEN=
github-release download -n isubata -u monochromegane -r isucon7 -l
mv isubata ~/isubata/webapp/go/.
sudo su -
sudo systemctl restart isubata.golang.service
ls
github-release download -n isubata -u monochromegane -r isucon7 -l
ll
cd
chmod u+x isubata/webapp/go/isubata 
sudo systemctl restart isubata.golang.service
sudo systemctl status isubata.golang.service
vi release.sh
chmod u+x release.sh 
sudo ./release.sh 
ls isubata/webapp/public/icons/ | wc -l
ls isubata/webapp/public/icons/
ls -ltr isubata/webapp/public/icons/
sudo ./release.sh 
ll isubata/webapp/public/icons/
ll isubata/webapp/public/icons/ | wc -l
ll isubata/webapp/public/icons/
ll -h isubata/webapp/public/icons/
top
cat /proc/cpuinfo 
sudo ./release.sh 
sudo vi /etc/nginx/nginx.conf
sudo ./release.sh 
sudo systemctl status isubata.golang.service
sudo vi /etc/nginx/nginx.conf
sudo systectl restart nginx
sudo systemctl restart nginx
ps aux | grep nginx
sudo ./release.sh 
exit
ls
less .ssh/id_rsa.pub 
exit
ll
cd isubata/
ll
cd db/
ll
cd ..
ll
cd webapp/
ll
cd /etc/
ll
exit
