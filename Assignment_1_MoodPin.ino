int pot = A0;     // potentiometer input pin
long Ain;         // mapped analog value from potentiometer (0–83 range)
int R,G,B;        //initial 
int pinred = 6;   // red LED pin (PWM)
int pinblue = 5;  // blue LED pin (PWM)
int pingreen = 3; // green LED pin (PWM)

void setup(){
 pinMode(pot, INPUT); 
 pinMode(pinred, OUTPUT);
 pinMode(pinblue, OUTPUT);
 pinMode(pingreen, OUTPUT);
 Serial.begin(9600);  // initialize Serial Monitor
}


void loop(){
// Read potentiometer value and map to angle range 0–83 (equivalent to 0°–300°)
Ain = (map(analogRead(pot), 0, 1023, 0, 83));

if(Ain <= 16.6){                     // 0 to 60°
  R = 100;                           // red on.
  G = Ain * 6;                       // green fading up.
  B = 0;                             // blue off.
  analogWrite(pinred, map(R, 0, 100, 0, 255));
  analogWrite(pinblue, map(B, 0, 100, 0, 255));
  analogWrite(pingreen, map(G, 0, 100, 0, 255));
}
if((Ain > 16.6) && (Ain <= 33.3)){    // 60° to 120°
  R = 100 - (Ain - 16.6) * 6;        // red fading down.
  G = 100;                           // green on.
  B = 0;                             // blue off.
  analogWrite(pinred, map(R, 0, 100, 0, 255));
  analogWrite(pinblue, map(B, 0, 100, 0, 255));
  analogWrite(pingreen, map(G, 0, 100, 0, 255));
}
if((Ain > 33.3) && (Ain <= 50)){      // 120° to 180°
  R = 0;                             // red off.
  G = 100;                           // green on.
  B = (Ain - 33.3) * 6;              // blue fading up.
  analogWrite(pinred, map(R, 0, 100, 0, 255));
  analogWrite(pinblue, map(B, 0, 100, 0, 255));
  analogWrite(pingreen, map(G, 0, 100, 0, 255));
}
if((Ain > 50) && (Ain <= 62.3)){      // 180° to 240°
  R = 0;                             // red off.
  G = 100 - (Ain - 50) * 6;          // green fading down.
  B = 100;                           // blue on.
  analogWrite(pinred, map(R, 0, 100, 0, 255));
  analogWrite(pinblue, map(B, 0, 100, 0, 255));
  analogWrite(pingreen, map(G, 0, 100, 0, 255));
}
if((Ain > 66.6) && (Ain <= 83.3)){    // 240° to 300°
  R = (Ain - 66.6) * 6;              // red fading up.
  G = 0;                             // green off.
  B = 100;                           // blue on.
  analogWrite(pinred, map(R, 0, 100, 0, 255));
  analogWrite(pinblue, map(B, 0, 100, 0, 255));
  analogWrite(pingreen, map(G, 0, 100, 0, 255));
}
   delay(100); // delay for smooth color transitions
}