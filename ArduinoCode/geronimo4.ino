/* carte beetle compatible leonardo*/

#include "Keyboard.h" 
#include "Mouse.h"
#include "PeakDetection.h" // import lib

const int LED = 9; //LED connected to pin D9
const int PIEZO_PIN = A1; // Piezo input
const int POT_PIN = A0; // Potentiometer output
const int DISPLAY_LIMIT = 1000;
const int DISPLAY_ZOOM = 10000;

const double tolerance = 0.1;
double potADC_OLD = 0;
int LAG = 64;
double THRESHOLD = 1;
double THRESHOLD_MAX = 10;
double INFLUENCE = 0.1;

long previousMillis = 0;
long interval = 300;           // interval at detection is paused after a detection
int peak2 = 0;


PeakDetection peakDetection; // create PeakDetection object

void setup() {
  pinMode (LED, OUTPUT); //LED pin is Output
  Keyboard.begin();
  Serial.begin(9600);
  peakDetection.begin(LAG, THRESHOLD, INFLUENCE); // sets the lag, threshold and influence
 // analogReference(INTERNAL);  
 //initiate the Mouse library
  Mouse.begin();
 }

void loop() {
  int piezoADC = analogRead(PIEZO_PIN);;
  double potADC = analogRead(POT_PIN)/1023.0; // entre 0 et 1
  double diff = abs(potADC-potADC_OLD);
  if (diff > tolerance ){
    potADC_OLD = potADC;
    THRESHOLD = THRESHOLD_MAX*potADC; // entre 0 et 1
    peakDetection.update(LAG , THRESHOLD, INFLUENCE); // sets the lag, threshold and influence
    delay(50);
  }

//  double potV = potADC*2/1023.0; // reads the value of pot sensor and converts it to a range between 0 ad 100

  double data = (double)(piezoADC)/512-1; // reads the value of the sensor and converts to a range between -1 and 1
  peakDetection.add(data); // adds a new data point
  int peak = peakDetection.getPeak(); // returns 0, 1 or -1
  double filtered = peakDetection.getFilt(); // moving average

unsigned long time = millis();
if (time > 3000)  { //delay at startup for staring detection Output
  
//  Serial.print(piezoADC); // print data
//  Serial.print(",");
//  Serial.print(1024); // print data
//  Serial.print(",");

    
  Serial.print(DISPLAY_ZOOM*(data - filtered)); // print data
  Serial.print(",");
  Serial.print(-1*DISPLAY_LIMIT* peak); // print peak status
  Serial.print(",");
  Serial.print(-0.5*DISPLAY_LIMIT* peak2); // print peak status
  Serial.print(",");
//  Serial.print(DISPLAY_ZOOM*filtered); // print moving average
//  Serial.print(",");
//  Serial.print(potADC); // print peak status
//  Serial.print(",");
  double pd = peakDetection.showStd();
  Serial.print(DISPLAY_ZOOM* pd ); //
  Serial.print(",");
  Serial.print(-DISPLAY_ZOOM*pd ); // 
  Serial.print(",");
  Serial.print(DISPLAY_ZOOM*THRESHOLD*pd ); // 
  Serial.print(",");
  Serial.print(-DISPLAY_ZOOM*THRESHOLD*pd ); // 
  Serial.print(",");
  
  Serial.print(DISPLAY_LIMIT*potADC); // 
  Serial.print(",");

  Serial.print(-DISPLAY_LIMIT ); 
  Serial.print(",");
  Serial.print(DISPLAY_LIMIT ); 
  Serial.print(",");
//
  Serial.println();
  delay(10);

  if( (millis() - previousMillis) > 1000 ) {
    if (abs(peak) == 1 ) { // Detection triggered
    peak2 = 1;
    digitalWrite(LED, HIGH); //LED ON
    //Keyboard.press(205); //EMULATE F12 on keyboard
    Mouse.click();
    //delay(250);
    previousMillis = millis();
          }
        else {
    digitalWrite(LED, LOW); //LED OFF
    Keyboard.releaseAll();
    Mouse.release();
    peak2 = 0;}
    }

}

  
}
