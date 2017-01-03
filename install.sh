#!/bin/bash
printf "configuring static ip... "
cp config/dhcpcd.conf /etc/dhcpcd.conf
rc=$?; if [ $rc -eq 0 ]
  then echo "done"
  else exit $rc
fi

printf "disabling sysrq (http://lmgtfy.com/?q=sysrq)... "
echo "kernel.sysrq=0" >> /etc/sysctl.conf
rc=$?; if [ $rc -eq 0 ]
  then echo "done"
  else exit $rc
fi

echo "building executable... "
chown -R pi "$(pwd)"
cd src; make
rc=$?; if [ -f "bin/ledbar" ]
  then echo "done"; cd ..
  else exit $rc
fi

printf "configuring autostart... "
echo "sh $(pwd)/bin/ledbar $(pwd)/res/default.ledbar" > /etc/init.d/ledbar-service
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