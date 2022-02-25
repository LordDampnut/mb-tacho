# Übersicht
Das Modellbahn Tachometer ist ein Hilfsmittel zur Bestimmung der Maßstabsgerechten Geschwindigkeit von Modelleisenbahnen. Folgender Prototyp wurde dafür entwickelt.

Vorderseite:
![Front](https://i.imgur.com/20JKZne.jpg)

Rückseite:
![Back](https://i.imgur.com/RzJ2OmC.jpg)

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

Anschlussreihenfolge der Sensorkabel ("Oben nach Unten"):

* DATA - Grau
* GND - Schwarz
* 3V3 - Weiß

## Anleitung

Die Lokomotive muss sich von links nach rechts an den Sensoren vorbeibewegen. Der Messabstand beträgt maximal ca. 3cm. Grüne LEDs an den IR-Sensoren zeigen ob die Lichtschranke ausgelöst wurde. Direkt nach dem Passieren der zweiten Lichtschranke wird auf dem Bildschirm die Modell- und Realgeschwindigkeit ausgegeben. Um erneut eine Messug durchzuführen werden mit dem Button die Werte zurückgesetzt.

Beschleunigen der Lokomotive während der Messung kann das Ergebnis verfälschen. Es sollte darauf geachtet werden, dass der Zug die Lichtschranken mit konstanter Geshwindigkeit passiert.


## To-Do
- Zweiter Button zur Auswahl des Modellmaßstabs
- Durchschalten der Maßstäbe nach gebräuchlichen Nenngrößen: [Liste: Wikipedia](https://de.wikipedia.org/wiki/Ma%C3%9Fst%C3%A4be_der_Modelleisenbahn#Nenngr%C3%B6%C3%9Fen,_Ma%C3%9Fst%C3%A4be_und_Spurweiten)
- Fahrtrichtung Links > Rechts und Rechts > Links umschalten (Button / Buttonkombination oder Automatisch?)
