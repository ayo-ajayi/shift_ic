

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    switch(i){
      case 1:
      case 5:
        bitClear(leds, i);
        break;
      default:  
        bitSet(leds, i);
        break;
     }
    updateShiftRegister(); 
/*I cannot use the shiftOut() function outside of the the forloop,
because it shifts out a byte of data ONE BIT AT A TIME */

    delay(500);
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);

   /*digitalWrite(clockPin, LOW);..this line is optional,
 * it assures that the clock is operating on a falling edge trigger
   */

   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
