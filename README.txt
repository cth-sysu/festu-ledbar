------------------
Terminologi
------------------
ledbarsprogram - Fil innehållandes det som ska visas på baren

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

/var/ledbar/res/current.ledbar är det ledbarsprogram som körs vid uppstart

------------------
Stoppa autostartat program
------------------
När programmet körs används mycket resurser vilket gör raspberry pi:en långsam.
För att avsluta process som körs
sudo pkill ledbar

------------------
Manuell körning av programmet
------------------
Programet läggs i /var/ledbar/bin/ av installationsskriptet
ledbar [ledbarsprogram]
    Pixelinformationen i filen som pekas ut av ledbarsprogram skrivs till baren.
    Om ingen fil anges är standard ../res/default.ledbar
ledbar white
    Testläge alla dioder sätts till vitt ljus. Antal pixlar antas vara 128 * 8.
ledbar white width height
    Testläge alla dioder sätts till vitt ljus. width och height anger antal pxlar.

------------------
Filformat ledbarsprogramfil
------------------
första byten anger antal pixlar i bredd på baren
andra byten anger antal pixlar i höjd på baren
därefter följer den pixeldata som ska skickas till baren frame för frame