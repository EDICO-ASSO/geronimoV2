/* carte beetle compatible leonardo*/

#include "Keyboard.h" 
#include "PeakDetection.h" // import lib

const int LED = 9; //LED connected to pin D9
const int PIEZO_PIN = A1; // Piezo input
const int POT_PIN = A0; // Potentiometer output
const int DISPLAY_LIMIT = 1000;
const int DISPLAY_ZOOM = 10000;

const double tolerance = 0.1;
double potADC_OLD = 0;
int LAG = 128;
double THRESHOLD = 1;
double THRESHOLD_MAX = 5;
double INFLUENCE = 0.9;




PeakDetection peakDetection; // create PeakDetection object

void setup() {
  pinMode (LED, OUTPUT); //LED pin is Output
  Keyboard.begin();
  Serial.begin(9600);
  peakDetection.begin(LAG, THRESHOLD, INFLUENCE); // sets the lag, threshold and influence
 // analogReference(INTERNAL);
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


//  Serial.print(piezoADC); // print data
//  Serial.print(",");
//  Serial.print(1024); // print data
//  Serial.print(",");

  
  Serial.print(DISPLAY_ZOOM*(data - filtered)); // print data
  Serial.print(",");
  Serial.print(-1*DISPLAY_LIMIT* peak); // print peak status
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

unsigned long time = millis();

if (time > 1)  { //delay at startup for staring detection Output
  if (abs(peak) == 1 ) { // Detection triggered
    digitalWrite(LED, HIGH); //LED ON
    //Keyboard.press(205); //EMULATE F12 on keyboard
    delay(250);
    Keyboard.releaseAll();
    digitalWrite(LED, LOW); //LED OFF
  }
}

  
}
