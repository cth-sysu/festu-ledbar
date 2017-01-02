------------------
Inloggning
------------------
IP: 192.168.1.3
User: pi
Password: raspberry

------------------
Installation
------------------
Installera raspbian (t.ex. lite/jessie) på sdkortet

sudo mkdir /var/ledbar
sudo git clone https://github.com/marcushultman/festu-ledbar.git /var/ledbar
sudo /var/ledbar/install.sh



Lägg in din ledbarsfil som /var/ledbar/bin/test.ledbar
/var/ledbar/res/current.ledbar är det ledbarsprogram som körs


