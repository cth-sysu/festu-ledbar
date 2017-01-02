#!/bin/bash
printf "configuring static ip... "
ifconfig eth0 down
ifconfig eth0 192.168.1.3
ifconfig eth0 up
echo "done"

printf "disabling sysrq... "
echo "kernel.sysrq=0" >> /etc/sysctl.conf
rc=$?; if [ $rc -eq 0 ]
  then echo "done"
  else exit $rc
fi

printf "copying ledbar file "
if [ -f "$1" ]
  then
    printf "($1)... "
    mkdir -p bin && cp $1 bin
  else
    printf "(default.ledbar)... "
    mkdir -p bin && cp default.ledbar bin
fi
echo "done"

echo "building executable... "
cd src; make
rc=$?; if [ -f "bin/ledbar" ]
  then echo "done"; cd ..
  else exit $rc
fi

printf "configuring autostart... "
echo "sh $(pwd)/bin/ledbar" > /etc/init.d/ledbar-service
chmod 755 /etc/init.d/ledbar-service
update-rc.d ledbar-service defaults
echo "done"

echo; printf "restart now (y/n)?"
read a
if [ $a  == "y" ]
  then
    shutdown -r -t 3
    echo "restarting in 3s..."
fi