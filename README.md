# Übersicht
Das Modellbahn Tachometer ist ein Hilfsmittel zur Bestimmung der Maßstabsgerechten Geschwindigkeit von Modelleisenbahnen. Folgender Prototyp wurde dafür entwickelt.

(Bild)
## Komponenten
- 1x WeMos D1 Mini
- 1x 128x32 SSD1306 0.91" I2C OLED Screen
- 2x TCRT5000 IR Sensor
- 1x Button
- Makerbeam 10x10

## Funktion

Die IR Sensoren haben einen bestimmten Abstand, welcher als Konstante in das Programm implementiert ist. 
Zur Bestimmung der Geschwindigkeit werden zwei Zeiten gemessen und diese mit dem Abstand verrechnet. v = s/Δt

Die Ausgabe erfolgt für die "Geschwindigkeit der Modelleisenbahn" in cm/s (vModel) und die Umrechnung über den Maßstab in eine Äquivalente 1:1 Geschwindigkeit in km/h (vReal).

Aktuell wird nur der Maßstab 1:120 (TT) umgerechnet. Der Faktor für H0 (1:87) ist implementiert, es gibt jedoch aktuell keinen Weg diesen direkt umzustellen.

Zur Validierung der Rechnung wurde folgendes Tool benutzt:

http://www.modell-bahner.net/rechner.php

## To-Do
- Zweiter Button zur Auswahl des Modellmaßstabs
- ???
