# phyphox-Arduino-Workshops
## Vorbereitung
### Arduino IDE installieren
Zuerst muss die Arduino IDE installiert werden. Die Installationsdatei wird kostenfrei unter [arduino.cc](https://www.arduino.cc/)
 für Windows, MacOS und Linux zur Verfügung gestellt.
### ESP32 Boardtreiber installieren
Als nächstes wird in der Arduino IDE eine zusätzliche Quelle für neue Boardtreiber hinterlegt werden. Dazu auf _Datei_ &#8594; _Voreinstellungen_ klicken.
Anschließend muss folgende URL in das Feld neben _Zusätzliche Boardverwalter-URLs_ kopiert werden:
```
https://dl.espressif.com/dl/package_esp32_index.json
```
Nun kann der eigentliche Boardtreiber über den Boarverwalter installiert werden. Dazu auf _Werkzeuge_ &#8594; _Board_ &#8594; _Boardverwalter_ klicken. Oben rechts kann nun nach _ESP32_ gesucht, und die _esp32_ Bibliothek von _Espressif Systems_ installiert werden. <br />
Wenn die Installation erfolgreich war, sollte unter _Werkzeuge_ &#8594; _Port_ ein neuer Eintrag erscheinen sobald der ESP32 über ein USB-Kabel angeschlossen wird. Falls nicht gibt es hier eine Hilfestellung um das Problem zu lösen: [FAQ](#faq)

### phyphox Bibliothek installieren
Zuletzt muss noch die _phyphox BLE_ Bibliothek installiert werden. Diese Bibliothek übernimmt das einfache Übertragen der Daten per Bluetooth und enthält einige Beispiele. Dazu unter _Sketch_ &#8594; _Bibliothek einbinden_ &#8594; _Bibliothek verwalten_ nach _phyphox BLE_ suchen und Installieren.

## FAQ
### Warum wird mein ESP32 nicht von Windows erkannt?
Vermutlich fehlt ein Treiber um mit dem USB-Chip des ESP32 zu kommunizieren. In der Regel wird der Chip _CH340_ verwendet, um das zu überprüfen kannst du dir die Beschriftung auf dem IC in der nähe des USB-Ports ansehen. Der benötigte Treiber ist hier zu finden: [CH340 Treiber](https://sparks.gogo.co.nz/ch340.html)
### Ich erhalte eine Fehlermeldung beim Hochladen meines Sketches
Durch gedrückt halten des Reset-Buttons (RST) kann der ESP32 in den Flash-Mode gebracht werden. Während der Button gedrückt wird, auf _Sketch hochladen_  klicken und sobald in der Arduino IDE 
```
Connecting........_____....._____.....___
```
erscheint, den Button wieder loslassen.

