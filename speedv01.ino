#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define pinIRexit D4
#define pinIRentry D3
#define sw1 D5
unsigned long pMillis = 0L;
unsigned long cMillis = 0L;
const long intervalDisplay = 100L;
const double distance = 0.118d;  //Distanz zwischen den Lichtshranken in Meter
const float factor120 = 4.32f;   //Faktor 36 * 1,2; cm/s -> km/h; Spur TT
const float factor87 = 3.132f;    //Faktor 36 * 0,87; cm/s -> km/h; Spur H0

unsigned long t0 = 0L;
unsigned long t1 = 0L;

double vReal = 0;
double vModel = 0;
void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(1000);
    
  pinMode(pinIRentry,INPUT);  // IR Sensor Input 0
  pinMode(pinIRexit,INPUT);   // IR Sensor Input 1
  pinMode(sw1,INPUT_PULLUP);  // switch input + builtin pullup resistor
}

void loop() {
  
  if(digitalRead(sw1) == 0){
    t0 = 0,
    t1 = 0;
    vReal = 0;
    vModel = 0;
  }
  
  if((t0 == digitalRead(pinIRentry))){
    t0 = millis();
  }

  if((t1 == digitalRead(pinIRexit))){
    t1 = millis();
    vModel =(distance/(t1-t0))*100000;
    vReal = vModel*factor120;
  }
  
  cMillis = millis();
  if(cMillis - pMillis >= intervalDisplay){
    pMillis = cMillis;
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0,0);
    display.println("Model");
    display.setCursor(0,8);
    display.println("cm/s");
    display.setCursor(0,16);
    display.println("Vorbild");
    display.setCursor(0,24);
    display.println("km/h");
    display.setTextSize(2);
    display.setCursor(48,0);
    display.println(vModel);
    display.setCursor(48,16);
    display.println(vReal);
    display.display();
  }
}
