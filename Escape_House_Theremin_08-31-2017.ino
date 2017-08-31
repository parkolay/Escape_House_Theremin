#include <LiquidCrystal_I2C.h>;
#include <Wire.h>;

/*-- -- -( Declare Constants )-- -- -*/
/*-- -- -( Declare objects )-- -- -*/

//LiquidCrystal_I2C lcd(#ofAddr,#ofColumns,#ofRows)
LiquidCrystal_I2C lcd(0x3F,20,4); //Set the LCD I2C address-- &gt;no fourth line when addressed as (0,3)

int speakerPin = 12;
int pitch = 0;
int note = 0;
int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor

/*-- -- -( Declare Variables )-- -- -*/

void setup() /*-- -- ( SETUP: RUNS ONCE )-- -- */
{
  Wire.begin ();
  lcd.begin(20,4); //initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.init();
  lcd.backlight(); //finish with backlight on
  
  //-- -- -- -- Write characters on the display -- -- -- -- -- -- -- -- --
  
  lcd.clear();
  lcd.setCursor(0,0);

  PlayKatniss();
  delay(1000);
  PlayRue();
  delay(1000);

}/*-- (end setup )-- -*/

void loop() /*-- -- ( LOOP: RUNS CONSTANTLY )-- -- */
{
  lcd.clear();
  GetNote();
  tone(speakerPin, note);
  delay(250);

}/* -- (end main loop )-- */

void PlayKatniss()
{
  tone(speakerPin, 392);
    delay(500);
  tone(speakerPin, 233);
    delay(500);
  tone(speakerPin, 440);
    delay(500);
  tone(speakerPin, 293);
    delay(750);
   
}// end GetKatniss()

void PlayRue()
{
  tone(speakerPin, 277);
    delay(500);
  tone(speakerPin, 349);
    delay(500);
  tone(speakerPin, 311);
    delay(500);
  tone(speakerPin, 369);
    delay(750);
   
}//end void PlayRue()

void GetNote()
{
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  pitch = 200 + sensorValue / 4;
      lcd.setCursor(0,0);
      lcd.print(sensorValue);
      lcd.setCursor(10,0);
      lcd.print(pitch);
  
   //set the frequency to a "note" and return
   if (pitch <= 225) 
    {
      note = 220; //A3
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("A");
    }
    else if ((pitch >= 225) && (pitch <= 239))
    {
      note = 233;  //A33/Bb3
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("A#");
    }
    else if ((pitch >= 240) && (pitch <= 253))
    {
      note = 246;  //B3
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("B");
    }
    else if ((pitch >= 254) && (pitch <= 268))
    {
      note = 261;  //C4 --> middle C right?
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("C");
    }
    else if ((pitch >= 269) && (pitch <= 284))
    {
      note = 277;  //C#4/Db4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("C#");
    }
    else if ((pitch >= 285) && (pitch <= 301))
    {
      note = 293;  //D4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("D");
    }
    else if ((pitch >= 302) && (pitch <= 319))
    {
      note = 311;  //D#4/Eb4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("D#");
    }
    else if ((pitch >= 320) && (pitch <= 338))
    {
      note = 329;  //E4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("E");
    }
    else if ((pitch >= 339) && (pitch <= 359))
    {
      note = 349;  //F4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("F");
    }
    else if ((pitch >= 360) && (pitch <= 380))
    {
      note = 369;  //#F4/Ab4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("F#");
    }
    else if ((pitch >= 381) && (pitch <= 403))
    {
      note = 392;  //G4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("G");
    }
    else if ((pitch >= 404) && (pitch <= 426))
    {
      note = 415;  //#G4/Ab4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("G#");
    }
    else if (pitch >= 427)
    {
      note = 440;  //A4
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("A");
    }
  return;
}//end void GetNote()
