# FestU LED

## Terminologi
_ledbarsprogram_ - fil innehållandes det som ska visas på baren

## Inloggning
IP: `192.168.1.3`
User: `pi`
Password: `raspberry`

## Installation
Installera [Raspbian](https://www.raspberrypi.org/downloads/raspbian/) (t.ex. [Lite](https://downloads.raspberrypi.org/raspbian_lite_latest)) på sd-kortet.

Ladda ner och packa upp [repot](https://github.com/marcushultman/festu-ledbar/archive/master.zip), eller klona med `git`:
`git clone https://github.com/marcushultman/festu-ledbar.git`
Simpel installation med script:
`sudo festu-ledbar/install.sh` (`sudo` behövs för configurering av statisk ip samt autostart)

Föra att köra igång programmet manuellt:
`bin/ledbar` (läser `res/default.ledbar` som default ledbarsprogram)

## Stoppa autostartat program
När programmet körs används mycket resurser vilket gör raspberry pi:en långsam.
För att avsluta process som körs
`sudo pkill ledbar`

## Program `bin/ledbar`
`ledbar _ledbarsprogram_`
⋅⋅⋅Pixelinformationen i _ledbarsprogram_ skrivs till baren.
⋅⋅⋅Om ingen fil anges är standard `res/default.ledbar`
`ledbar white`
⋅⋅⋅Testläge alla dioder sätts till vitt ljus. Antal pixlar antas vara 128 * 8.
`ledbar white _width_ _height_`
⋅⋅⋅Testläge alla dioder sätts till vitt ljus. _width_ och _height_ anger antal pixlar.

## Filformat ledbarsprogramfil
Första byten anger antal pixlar i bredd på baren. Andra byten anger antal pixlar i höjd på baren. Därefter följer den pixeldata som ska skickas till baren frame för frame