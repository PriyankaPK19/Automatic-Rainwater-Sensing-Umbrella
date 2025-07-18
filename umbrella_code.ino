 
// Define pins 
const int rainSensorPin = A0; // Rain sensor data pin 
const int motorIn1 = 8;       // Motor driver IN1 
const int motorIn2 = 9;       // Motor driver IN2 
const int motorEnable = 10;   // Motor driver ENA 
 // IR sensor pin for fully open position 
const int irsensorpinclose = 7; 
const int irsensorpinopen =5; // IR sensor pin for fully closed position 
 
void setup() { 
  Serial.begin(9600); // Initialize serial communication 
  // Set motor pins as outputs 
  pinMode(motorIn1, OUTPUT); 
  pinMode(motorIn2, OUTPUT); 
  pinMode(motorEnable, OUTPUT); 
  pinMode(irsensorpinopen, INPUT); 
  pinMode(irsensorpinclose, INPUT); 
  // Initially stop the motor 
  digitalWrite(motorIn1, LOW); 
  digitalWrite(motorIn2, LOW); 
  analogWrite(motorEnable, 0); 
} 
                     void loop() { 
  // Read rain sensor value 
  int rainValue = analogRead(rainSensorPin); 
  Serial.print("Rain Sensor Value: "); 
  Serial.println(rainValue); 
 
  // If it's raining and not fully open, open the umbrella 
      if (rainValue < 500 && (!digitalRead(irsensorpinopen)==LOW)) { 
    digitalWrite(motorIn1, HIGH); 
    digitalWrite(motorIn2, LOW); 
    analogWrite(motorEnable, 255); // Full speed 
  } 
  // If it's not raining and not fully closed, close the umbrella 
  else if (rainValue >= 500 && (!digitalRead(irsensorpinclose)==LOW)){ 
    digitalWrite(motorIn1, LOW); 
    digitalWrite(motorIn2, HIGH); 
    analogWrite(motorEnable, 255); // Full speed 
  } else { 
    // Stop the motor if fully open or fully closed 
    digitalWrite(motorIn1, LOW); 
    digitalWrite(motorIn2, LOW); 
    analogWrite(motorEnable, LOW); 
  } 
  // Small delay to avoid too many serial prints 
  delay(1000); 
                    }