// The constants
const int GreenArrow1 = 12;
const int GreenLight1 = 13;
const int YellowLight1 = 2;
const int RedLight1 = 3;
const int GreenArrow2 = 4;
const int GreenLight2 = 5;
const int YellowLight2 = 6;
const int RedLight2 = 7;
const int RedWalking1 = 8;
const int WhiteWalking1 = 9;
const int WhiteWalking2 = 10;
const int RedWalking2 = 11;
const int Blinking = 1;

//Statements  
#define STATE_OFF 0
#define STATE_EW_Turning 1
#define STATE_EW_Straight 2
#define STATE_Yellow1 3
#define STATE_Yellow2 6
#define STATE_NS_Straight 4
#define STATE_NS_Turning 5
#define NS_Walking 7
#define EW_Walking 8
#define EMERGENCY1 9
#define EMERGENCY2 10
#define SERVO_PIN A0
#define SWITCH_PIN A1
#define Switch A4
#include <Servo.h>
// #include "pitches.h"

Servo myservo;


int State = STATE_OFF;
int StateTime = 0;

int WalkingButtonState = LOW;
  int SwitchState1 = 0;
int SwitchState2 = 0;

int melody[] = {

  // notes in the melody:
 // NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

// The Output and Inputs
void setup() {
  // Red Lights
  pinMode(RedLight1, OUTPUT);
  pinMode(RedLight2, OUTPUT);
  pinMode(RedWalking1, OUTPUT);
  pinMode(RedWalking2, OUTPUT);
  // Green Lights
  pinMode(GreenArrow1, OUTPUT);
  pinMode(GreenArrow2, OUTPUT);
  pinMode(GreenLight1, OUTPUT);
  pinMode(GreenLight2, OUTPUT);
  // Yellow Lights
  pinMode(YellowLight1, OUTPUT);
  pinMode(YellowLight2, OUTPUT);
  // White Lights
  pinMode(WhiteWalking1, OUTPUT);
  pinMode(WhiteWalking2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(Switch, INPUT);
  digitalWrite(GreenLight1,LOW);
  // Servos
  pinMode(SWITCH_PIN, INPUT);
  myservo.attach(SERVO_PIN);
  Serial.begin(9600);
}

// iterate over the notes of the melody:

//  for (int thisNote = 0; thisNote A3 < ; thisNote++) {
  
void setStateTimeToNow() {
  StateTime = millis();
}
    
  // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

 //   int noteDuration = 1000 / noteDurations[thisNote];

 //   tone(8, melody[thisNote], noteDuration);
    
    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

//    int pauseBetweenNotes = noteDuration * 1.30;

 //   delay(pauseBetweenNotes);

    // stop the tone playing:

//    noTone(8);

//  }
// }
    
// Group of a function
void Emergency1() {
    digitalWrite(RedLight1,LOW);
    digitalWrite(RedLight2,LOW);
    digitalWrite(RedWalking1,HIGH);
    digitalWrite(RedWalking2,HIGH);
    digitalWrite(GreenArrow1,LOW);
    digitalWrite(GreenArrow2,LOW);
    digitalWrite(GreenLight1,LOW);
    digitalWrite(GreenLight2,LOW);
    digitalWrite(YellowLight1,LOW);
    digitalWrite(YellowLight2,LOW);
    digitalWrite(WhiteWalking1,LOW);
    digitalWrite(WhiteWalking2,LOW);
}

// Group of a function
void Emergency2() {
  digitalWrite(RedLight1,HIGH);
  digitalWrite(RedLight2,HIGH);
      digitalWrite(RedWalking1,HIGH);
    digitalWrite(RedWalking2,HIGH);
    digitalWrite(GreenArrow1,LOW);
    digitalWrite(GreenArrow2,LOW);
    digitalWrite(GreenLight1,LOW);
    digitalWrite(GreenLight2,LOW);
    digitalWrite(YellowLight1,LOW);
    digitalWrite(YellowLight2,LOW);
    digitalWrite(WhiteWalking1,LOW);
    digitalWrite(WhiteWalking2,LOW);
}

// Group of a function
void TurnONEmergency() {
  if (State == EMERGENCY1) {
  // Light Stuff
      Emergency1();
  // check for time to transition
   int now = millis();
   if (now - StateTime >= 500) {
     (State = EMERGENCY2);
     setStateTimeToNow();
    }
    }
      else  {
  // Light Stuff
      Emergency2();
  // check for time to transition
   int now = millis();
    if (now - StateTime >= 500) {
      (State = EMERGENCY1);
     setStateTimeToNow();
}
      }
}
        
// Group of a function for EW Advanced Arrow
void EWTurning() {
   digitalWrite(WhiteWalking1,LOW);
  digitalWrite(WhiteWalking2,LOW);
  digitalWrite(RedWalking1,HIGH);
  digitalWrite(RedWalking2,HIGH);
digitalWrite(YellowLight1,LOW);
    digitalWrite(YellowLight2,LOW);
  digitalWrite(GreenLight2,LOW);
    digitalWrite(RedLight1, HIGH);
  digitalWrite(RedLight2,LOW);
    digitalWrite(GreenArrow2, HIGH);
}

// Group of a function for EW Green Light
void EWStraight() {
  digitalWrite(RedWalking1,HIGH);
  digitalWrite(RedWalking2,LOW);
   digitalWrite(WhiteWalking2,HIGH);
  digitalWrite(WhiteWalking1,LOW);
  digitalWrite(RedLight1,HIGH);
  digitalWrite(RedLight2,LOW);
  digitalWrite(YellowLight1,LOW);
    digitalWrite(YellowLight2,LOW);
    digitalWrite(GreenArrow2,LOW);
    digitalWrite(GreenLight2,HIGH);
}

// Group of a function for NS Yellow Light
void YellowNS() {
  digitalWrite(WhiteWalking1,LOW);
  digitalWrite(WhiteWalking2,LOW);
  digitalWrite(YellowLight1,HIGH);
  digitalWrite(YellowLight2,LOW);
   digitalWrite(RedLight1,LOW);
    digitalWrite(RedLight2,HIGH);
    digitalWrite(RedWalking1,HIGH);
    digitalWrite(RedWalking2,HIGH);
  digitalWrite(GreenArrow1,LOW);
    digitalWrite(GreenArrow2,LOW);
    digitalWrite(GreenLight1,LOW);
    digitalWrite(GreenLight2,LOW);
}

// Group of a function for EW Yellow Light
void YellowEW() {
    digitalWrite(WhiteWalking1,LOW);
  digitalWrite(WhiteWalking2,LOW);
  digitalWrite(YellowLight1,LOW);
  digitalWrite(YellowLight2,HIGH);
   digitalWrite(RedLight1,HIGH);
    digitalWrite(RedLight2,LOW);
    digitalWrite(RedWalking1,HIGH);
    digitalWrite(RedWalking2,HIGH);
  digitalWrite(GreenArrow1,LOW);
    digitalWrite(GreenArrow2,LOW);
    digitalWrite(GreenLight1,LOW);
    digitalWrite(GreenLight2,LOW);
}
  
// Group of a function for NS Green Light
void NSStraight() {
  digitalWrite(RedLight1,LOW);
digitalWrite(RedWalking2,HIGH);
  digitalWrite(RedWalking1,LOW);
  digitalWrite(WhiteWalking1,HIGH);
  digitalWrite(WhiteWalking2,LOW);
    digitalWrite(YellowLight1,LOW);
    digitalWrite(YellowLight2,LOW);
    digitalWrite(GreenLight1,HIGH);
    digitalWrite(RedLight2,HIGH);
  digitalWrite(GreenArrow1, LOW);
  digitalWrite(GreenArrow2, LOW);
}

// Group of a function for NS Advanced Arrow
void NSTurning() {
   digitalWrite(WhiteWalking1,LOW);
  digitalWrite(WhiteWalking2,LOW);
  digitalWrite(RedWalking1,HIGH);
  digitalWrite(RedWalking2,HIGH);
  digitalWrite(YellowLight1,LOW);
    digitalWrite(YellowLight2,LOW);
      digitalWrite(GreenLight1,LOW);
    digitalWrite(GreenArrow1,HIGH);
  digitalWrite(RedLight2,HIGH);
  digitalWrite(RedLight1,LOW);
}

// A whole operation to combine other function
void RunNormal() {
    if (State == STATE_OFF ||
       State == EMERGENCY1 || 
       State == EMERGENCY2) {
      State = STATE_EW_Straight;
    }

  if (State == STATE_EW_Straight) {
    // do lights stuff
    EWStraight();
    // check for time to transition
    int now = millis();
  if (now - StateTime >= 7000) {
      (State = STATE_Yellow1);
      setStateTimeToNow();
    }
  
  }
  else if (State == STATE_EW_Turning) {
  // Light Stuff
    EWTurning();
  // check for time to transition
   int now = millis();
    if (now - StateTime >= 6000) {
      (State = STATE_EW_Straight);
      setStateTimeToNow();
    }
    
  }
  else if (State == STATE_Yellow1) {
   // Light Stuff
    YellowEW();
  // check for time to transition
   int now = millis();
         if (now - StateTime >= 5000) {
      (State = STATE_NS_Turning);
      setStateTimeToNow();
    }
    
    
  }
  else if (State == STATE_NS_Straight) {
   // Light Stuff
    NSStraight();
  // check for time to transition
   int now = millis();
    if (now - StateTime >= 7000) {
      (State = STATE_Yellow2);
      setStateTimeToNow();
  }
  
  }
  else if (State == STATE_NS_Turning) {
    // Light Stuff
    NSTurning();
  // check for time to transition
   int now = millis();
    if (now - StateTime >= 6000) {
      (State = STATE_NS_Straight);
      setStateTimeToNow();
    }
  }
    else if (State == STATE_Yellow2){
      // Light Stuff
      YellowNS();
      // check for time to transition
     int now = millis();
      if (now - StateTime >= 5000) {
      (State = STATE_EW_Turning);
       setStateTimeToNow();
}
}
  }

// Turns servo to 0 degrees
void Servo0(){
   myservo.write(0);
}

// Turns servo to 90 degrees
void Servo90(){
    myservo.write(90);
  digitalWrite(Blinking, HIGH);
delay (500);
    digitalWrite(Blinking, LOW);
delay (500);
}
  
// Function loops
void loop() {

  int Luminosity1 = analogRead(SWITCH_PIN);
  Serial.println(SwitchState2);
  
  if (Luminosity1 < 15) {  
    Servo90();
  } else if (Luminosity1 >= 0) {
    Servo0();
  }
 
 int Luminosity2 = analogRead(Switch);
   Serial.println(Luminosity2);
  
  if (Luminosity2 < 15) {
    RunNormal();
  } else if (Luminosity2 >= 0) {
	TurnONEmergency();
 }
}

// All for new tab/new folder 

// #define NOTE_B0  31
// #define NOTE_C1  33
// #define NOTE_CS1 35
// #define NOTE_D1  37
// #define NOTE_DS1 39
// #define NOTE_E1  41
// #define NOTE_F1  44
// #define NOTE_FS1 46
// #define NOTE_G1  49
// #define NOTE_GS1 52
// #define NOTE_A1  55
// #define NOTE_AS1 58
// #define NOTE_B1  62
// #define NOTE_C2  65
// #define NOTE_CS2 69
// #define NOTE_D2  73
// #define NOTE_DS2 78
// #define NOTE_E2  82
// #define NOTE_F2  87
// #define NOTE_FS2 93
// #define NOTE_G2  98
// #define NOTE_GS2 104
// #define NOTE_A2  110
// #define NOTE_AS2 117
// #define NOTE_B2  123
// #define NOTE_C3  131
// #define NOTE_CS3 139
// #define NOTE_D3  147
// #define NOTE_DS3 156
// #define NOTE_E3  165
// #define NOTE_F3  175
// #define NOTE_FS3 185
// #define NOTE_G3  196
// #define NOTE_GS3 208
// #define NOTE_A3  220
// #define NOTE_AS3 233
// #define NOTE_B3  247
// #define NOTE_C4  262
// #define NOTE_CS4 277
// #define NOTE_D4  294
// #define NOTE_DS4 311
// #define NOTE_E4  330
// #define NOTE_F4  349
// #define NOTE_FS4 370
// #define NOTE_G4  392
// #define NOTE_GS4 415
// #define NOTE_A4  440
// #define NOTE_AS4 466
// #define NOTE_B4  494
// #define NOTE_C5  523
// #define NOTE_CS5 554
// #define NOTE_D5  587
// #define NOTE_DS5 622
// #define NOTE_E5  659
// #define NOTE_F5  698
// #define NOTE_FS5 740
// #define NOTE_G5  784
// #define NOTE_GS5 831
// #define NOTE_A5  880
// #define NOTE_AS5 932
// #define NOTE_B5  988
// #define NOTE_C6  1047
// #define NOTE_CS6 1109
// #define NOTE_D6  1175
// #define NOTE_DS6 1245
// #define NOTE_E6  1319
// #define NOTE_F6  1397
// #define NOTE_FS6 1480
// #define NOTE_G6  1568
// #define NOTE_GS6 1661
// #define NOTE_A6  1760
// #define NOTE_AS6 1865
// #define NOTE_B6  1976
// #define NOTE_C7  2093
// #define NOTE_CS7 2217
// #define NOTE_D7  2349
// #define NOTE_DS7 2489
// #define NOTE_E7  2637
// #define NOTE_F7  2794
// #define NOTE_FS7 2960
// #define NOTE_G7  3136
// #define NOTE_GS7 3322
// #define NOTE_A7  3520
// #define NOTE_AS7 3729
// #define NOTE_B7  3951
// #define NOTE_C8  4186
// #define NOTE_CS8 4435
// #define NOTE_D8  4699
// #define NOTE_DS8 4978
