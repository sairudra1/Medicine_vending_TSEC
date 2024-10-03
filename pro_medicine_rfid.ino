#include <Wire.h>
//#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
//#include <MFRC522.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int hour;
int minute;
int h;
int mini;
//RTClib myRTC;


#define SS_PIN 10
#define RST_PIN 9
//MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int saiflag;
int Atflag;
int eeflag;

void setup() {

  Serial.begin(57600);
  Wire.begin();
  SPI.begin();      // Initiate  SPI bus
 // mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Team SAI");
  lcd.setCursor (0, 1);
  lcd.print("From DJSCE");
  delay(1000);
  lcd.clear();

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Team SAI");
  lcd.setCursor (0, 1);
  lcd.print("PRESENTS  PROTOTYPE");
  delay(2500);
  lcd.clear();

  delay(750);  // put your setup code here, to run once:

}

void loop()
{
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);  //data for output for stepper

  /*analogWrite(A0, 255);
    analogWrite(A1, 255);
    analogWrite(A2, 255);
    analogWrite(A3, 255);  //data for output for stepper*/

  //analogWrite(analogOutPin, outputValue);
//  DateTime now = myRTC.now();
  hour = now.hour(), DEC;
  h = hour;
  minute = now.minute(), DEC;
  mini = minute;

  delay(1000);
  
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();

  content.toUpperCase();
  
    if (content.substring(1) == "29 BB 3A 71") //change here the UID of the card/cards that you want to give access
    {
    Serial.println("SAIRUDRA GUDUR is registered");
    delay(750);
    }
    else if (content.substring(1) == "60 CD 95 55") //change here the UID of the card/cards that you want to give access
    {
    Serial.println("EESHAAN DHURU is registered");
    delay(750);
    }
    else if (content.substring(1) == "79 5B 31 71") //change here the UID of the card/cards that you want to give access
    {
    Serial.println("ATHARVA WADEKAR is registered");
    delay(750);
    }
    else
    {
    delay(750);
    }
  

  if (h == 6 && mini == 30)
  {
    saiflag = 0;
    Atflag = 0;
    eeflag = 0;
  }
  if (h == 12 && mini == 30)
  {
    saiflag = 0;
    Atflag = 0;
    eeflag = 0;
  }
  if (h == 18 && mini == 30)
  {
    saiflag = 0;
    Atflag = 0;
    eeflag = 0;
  }

  if (h >= 7 && h <= 11 && content.substring(1) == "79 5B 31 71" && Atflag == 0)
  {
    Serial.println("79 5B 31 71 morning medication");
    Atflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("morning medication");
    delay(2500);
    lcd.clear();
  }
  else if (h >= 13 && h <= 17 && content.substring(1) == "79 5B 31 71" && Atflag == 0)
  {
    Serial.println("79 5B 31 71 afternoon medication");
    Atflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("Afternoon medication");
    delay(2500);
    lcd.clear();
  }
  else if (h >= 19 && h <= 23 && content.substring(1) == "79 5B 31 71" && Atflag == 0)
  {
    Serial.println("79 5B 31 71 night medication");
    Atflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("night medication");
    delay(2500);
    lcd.clear();
  }
  ////////////////////////////////

  if (h >= 7 && h <= 11 && content.substring(1) == "60 CD 95 55" && eeflag == 0)
  {
    Serial.println("60 CD 95 55 morning medication");
    eeflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("morning medication");
    delay(2500);
    lcd.clear();
  }
  else if (h >= 13 && h <= 17 && content.substring(1) == "60 CD 95 55" && eeflag == 0)
  {
    Serial.println("60 CD 95 55 afternoon medication");
    eeflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("afternoon medication");
    delay(2500);
    lcd.clear();
  }
  else if (h >= 19 && h <= 23 && content.substring(1) == "60 CD 95 55" && eeflag == 0)
  {
    Serial.println("60 CD 95 55 night medication");
    eeflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("night medication");
    delay(2500);
    lcd.clear();
  }
  ///////////////////////////////////

  if (h >= 7 && h <= 11 && content.substring(1) == "29 BB 3A 71" && saiflag == 0)
  {
    Serial.println("sairudra morning medication");
    saiflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("morning medication");
    delay(2500);
    lcd.clear();
  }
  else if (h >= 13 && h <= 17 && content.substring(1) == "29 BB 3A 71" && saiflag == 0)
  {
    Serial.println("sairudra afternoon medication");
    saiflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("afternoon medication");
    delay(2500);
    lcd.clear();
  }
  else if (h >= 19 && h <= 23 && content.substring(1) == "29 BB 3A 71" && saiflag == 0)
  {
    Serial.println("sairudra evening medication ");
    saiflag = 1;
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("PRESCRIPTION");
    lcd.setCursor (0, 1);
    lcd.print("night medication");
    delay(2500);
    lcd.clear();
  }
  delay(1000);
  ////////////////////////////////////////////
  if (content.substring(1) == "29 BB 3A 71" && saiflag == 1)
  {
    ///
    Serial.println("Already took medication");
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("You have already");
    lcd.setCursor (0, 1);
    lcd.print("recieved medication");
    delay(2500);
    lcd.clear();
  }
  else if (content.substring(1) == "60 CD 95 55" && eeflag == 1)
  {
    Serial.println("Already took medication");
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("You have already");
    lcd.setCursor (0, 1);
    lcd.print("recieved medication");
    delay(2500);
    lcd.clear();
  }
  else if (content.substring(1) == "79 5B 31 71" && Atflag == 1)
  {
    Serial.println("Already took medication");
    delay(100);
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("You have already");
    lcd.setCursor (0, 1);
    lcd.print("recieved medication");
    delay(2500);
    lcd.clear();
  }
  delay(750);

}
