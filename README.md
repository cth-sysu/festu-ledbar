# FestU LED

## Terminologi
_ledbarsprogram_ - fil innehållandes det som ska visas på baren

## Inloggning
IP: `192.168.1.123`
User: `pi`
Password: `raspberry`

## Installation
Installera [Raspbian](https://www.raspberrypi.org/downloads/raspbian/) (t.ex. [Lite](https://downloads.raspberrypi.org/raspbian_lite_latest)) på SD-kortet.

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

## Skapa programfil med GlediatorToDisk
Hämta senaste versionen (GlediatorWithPatchRelease.zip) från https://github.com/HeffU/GlediatorToDisk/releases

Starta Glediator via run_patched.bat (eller .sh, otestat)

Välj File->Load Project och öppna GlediatorToDisk/settings/16x8_8panel_LEDBAR_Project

Säkerställ att pixeladressering är korrekt genom att gå in på Options->Output, klicka på "Patch ArtNet/TMP2.Net", välj Load och filen GlediatorToDisk/settings/16x8_8panel_LEDBAR_ArtNetPatchList

Skapa dina effekter i Glediator, tänk ut ett program och hur du vill byta mellan effekter. Bökigt men fungerande är att använda sliders för att byta mellan de olika kanalerna manuellt. Tips: Börja och avsluta på en liknande och/eller statisk effekt.

När du är nöjd, öppna Options->Output och välj "Open Socket" för att starta inspelning. Stäng Options->Output och utför ditt planerade program. För att avsluta inspelning öppna Options->Output och välj "Close Socket".

Programfilen sparas i GlediatorToDisk/output/ och är döpt efter datum/tid. (Exakt namn kan ses längst ned i Options->Output efter att du tryckt "Close Socket")

Byt eventuellt namn på filen till något passande, och för över den till baren.
