#include <LiquidCrystal_I2C.h>;
#include <Wire.h>;

/*-- -- -( Declare Constants )-- -- -*/
/*-- -- -( Declare objects )-- -- -*/

//LiquidCrystal_I2C lcd(#ofAddr,#ofColumns,#ofRows)
LiquidCrystal_I2C lcd(0x3F,20,4); //Set the LCD I2C address-- &gt;no fourth line when addressed as (0,3)

int ledPin1 = 8;
int ledPin2 = 9;
int ledPin3 = 10;
int ledPin4 = 11;


int speakerPin = 12;
int pitch = 0;
int note = 0;

int Tumbler_1 = 0;
int Tumbler_2 = 0;
int Tumbler_3 = 0;
int Tumbler_4 = 0;

int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor

/*-- -- -( Declare Variables )-- -- -*/

void setup() /*-- -- ( SETUP: RUNS ONCE )-- -- */
{
  //setup outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  //make certain they are off before we begin
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
          

  //setup lcd
  Wire.begin ();
  lcd.begin(20,4); //initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.init();
  lcd.backlight(); //finish with backlight on
  lcd.clear();
  lcd.setCursor(0,0);

}/*-- (end setup )-- -*/

void loop() /*-- -- ( LOOP: RUNS CONSTANTLY )-- -- */
{
  lcd.clear();
  GetNote();
  tone(speakerPin, note);


  if ((note == 384) && Tumbler_1 < 4)  //G4
  {
      Tumbler_1 += 1;
  }  
  else if ((Tumbler_1 == 4) && (note == 457) && (Tumbler_2 < 4))  //Bb4
  {
      digitalWrite(ledPin1, HIGH);
      Tumbler_2 += 1;
  }
  else if ((Tumbler_2 == 4) && (note == 432) && (Tumbler_3 < 4))  //A4
  {

    digitalWrite(ledPin2, HIGH);
    Tumbler_3 += 1;
  }
  else if ((Tumbler_3 == 4) && (note == 288) && Tumbler_4 < 4)  //D4
  {
   
    digitalWrite(ledPin3, HIGH);
    Tumbler_4 += 1;
  }  
  
 if(Tumbler_4 == 4)
 {   
    
    digitalWrite(ledPin4, HIGH);
    delay(250);
    PlayKatniss();
    delay(750);
    PlayRue();
    delay(750);
    blinkLEDs();
    blinkLEDs();
    blinkLEDs();
    
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Congratulations!  ");
    lcd.setCursor(0,1);
    lcd.print(" j794.1 Kid ");
    delay(15000);    //you have 15 seconds to write down the clue
    resetPuzzle();   //clear the screen and reset the tumblers for the next round
  }

 lcd.setCursor(0,2);
 lcd.print(Tumbler_1);
 lcd.setCursor(10,2);
 lcd.print(Tumbler_2);
 lcd.setCursor(0,3);
 lcd.print(Tumbler_3);
 lcd.setCursor(10,3);
 lcd.print(Tumbler_4);
   
 delay(250);

}/* -- (end main loop )-- */

void PlayKatniss()
{
  tone(speakerPin, 384);//G4
    delay(500);
  tone(speakerPin, 457);//Bb4
    delay(500);
  tone(speakerPin, 432);//A4
    delay(500);
  tone(speakerPin, 288);//D4
    delay(750);
  tone(speakerPin, 0);  //for the love of all that is sane, please stop that infernal racquette 
   
}// end GetKatniss()

void PlayRue()
{
  tone(speakerPin, 272);//Db4
    delay(500);
  tone(speakerPin, 342);//F4
    delay(500);
  tone(speakerPin, 305);//Eb4
    delay(500);
  tone(speakerPin, 363);//Gb4
    delay(750);
  tone(speakerPin, 0);
   
}//end void PlayRue()

void GetNote()
{
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  pitch = 200 + sensorValue / 4;
      lcd.setCursor(0,0);
      lcd.print("Frequency ");
      //lcd.print(sensorValue);
      lcd.setCursor(10,0);
      lcd.print("   Note   ");
      //lcd.print(pitch);
  
   //set the frequency to a "note" and return
     if (pitch <= 221) 
    {
      note = 216; //A3
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    A3    ");
    }
    else if ((pitch >= 222) && (pitch <= 235))
    {
      note = 228;  //A33/Bb3
      lcd.setCursor(0,1);
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("  A#3/Bb3 ");
    }
    else if ((pitch >= 236) && (pitch <= 249))
    {
      note = 242;  //B3
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    B3    ");
    }
    else if ((pitch >= 250) && (pitch <= 264))
    {
      note = 256;  //C4 --> middle C right?
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    C4    ");
    }
    else if ((pitch >= 265) && (pitch <= 279))
    {
      note = 272;  //C#4/Db4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("  C#4/Db4 ");
    }
    else if ((pitch >= 280) && (pitch <= 296))
    {
      note = 288;  //D4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    D4    ");
    }
    else if ((pitch >= 297) && (pitch <= 314))
    {
      note = 305;  //D#4/Eb4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("  D#4/Eb4 ");
    }
    else if ((pitch >= 315) && (pitch <= 332))
    {
      note = 323;  //E4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    E4    ");
    }
    else if ((pitch >= 333) && (pitch <= 352))
    {
      note = 342;  //F4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    F4    ");
    }
    else if ((pitch >= 353) && (pitch <= 373))
    {
      note = 363;  //#F4/Ab4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("  F#4/Gb4 ");
    }
    else if ((pitch >= 374) && (pitch <= 395))
    {
      note = 384;  //G4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    G4    ");
    }
    else if ((pitch >= 396) && (pitch <= 419))
    {
      note = 407;  //#G4/Ab4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("  G#4/Ab4 ");
    }
    else if ((pitch >= 420) && (pitch <= 444))
    {
      note = 432;  //A4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("    A4    ");
    }
        else if (pitch >= 445)
    {
      note = 457;  //A4
      lcd.setCursor(0,1);
      lcd.print("   ");
      lcd.print(note);
      lcd.setCursor(10,1);
      lcd.print("  A#4/Bb4 ");
    }
  return;
}//end void GetNote()

void blinkLEDs()
{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  delay(250);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(250);
}

void resetPuzzle()
{
 Tumbler_1 = 0;
 Tumbler_2 = 0;
 Tumbler_3 = 0;
 Tumbler_4 = 0; 
 lcd.clear();
 return;
}
