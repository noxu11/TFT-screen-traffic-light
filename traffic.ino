/*this is a traffic light thingy that is added with a TFT screen(specifically, a 1'77inch is what i used) and some lights using esp32
made by me, noxu11. 11/05/2024
*/
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip 
// REMEMBER TO CHECK YOUR PINS IN eSPI
#include <SPI.h>
#include "CountdownLib.h" //countdown
TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
Countdown countDown(10, []() {
  countDown.Reset();
 
}); //(10) is the amount of seconds, can be changed

#define LEDRED 25 //these are the pins that i used(in esp32) and it could be modified to suit your board(up to u).
#define LEDYELLOW 33
#define LEDGREEN 32
#define STOPBUTTON 12
//#define buzz 13 //optional 
 int stopbtn = digitalRead(HIGH);
#define DEBUG(A) tft.println(A);


//this is known as for-loop.

void setup() {
  tft.init();
  tft.setRotation(3);  // The rotation of the screen (1=180,2=360,3=540, and 4=180(max).)
   tft.fillScreen(TFT_BLACK);
   tft.setCursor(60, 50, 2);
   tft.setTextColor(TFT_RED);
   tft.setTextSize(1);
   tft.println("------");
   delay(1000);
 //-----------
  tft.fillScreen(TFT_BLACK); //the background
  tft.setCursor(20, 50, 2); // is the location of your text in the screen *can be modifed tho. The last num is the font type
  tft.setTextColor(TFT_CYAN);
  tft.setTextSize(1); // 4 is freakin large-owh yes it is the size of the text.
  tft.println("created by");

  tft.setCursor(90, 50, 2);
  tft.setTextColor(TFT_BLUE);
  tft.setTextSize(1);
  tft.print("noxu11");
  delay(5000);

  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  pinMode(STOPBUTTON, INPUT);
  digitalWrite(STOPBUTTON, HIGH);

 
  //-------------- the code above-between these lines can be deleted. pasikat yung gumawa HAHAHA
}
void flashing(size_t times=1) { // By default it will flash once, you can change this into your desire
        int delayPeriod = 900; //how fast the number will appear.

        for (size_t loop = 0; loop < (times*1); ++loop) {
      
        tft.fillScreen(TFT_BLACK);
        tft.setCursor(75, 50, 2);
        tft.setTextSize(2);
        DEBUG(countDown.Value);
        countDown.Tick(); 
        delay(delayPeriod);
        }
}
  void loop() {
  
  if (stopbtn == HIGH) {
  tft.fillScreen(TFT_BLACK); 
  delay(100);

  digitalWrite(LEDGREEN, HIGH);
  delay(2000);
  digitalWrite(LEDGREEN, LOW);
  tft.setCursor(42, 50, 2);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.print("WALK"); 
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(57, 50, 2);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.print("GO!");
  delay(2000);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);
  flashing(10);
  delay(2000);
  tft.fillScreen(TFT_BLACK);

  }

  if (stopbtn == LOW) {
  tft.fillScreen(TFT_BLACK); 
  delay(100);

  // *buzzer
  //digitalWrite(buzz, HIGH);
 // delay(2000);
  // optional
  digitalWrite(LEDRED, HIGH); 
  delay(2000); 
  digitalWrite(LEDRED, LOW);
  tft.setCursor(53, 50, 2);
  tft.setTextColor(TFT_RED);
  tft.setTextSize(2);
  tft.print("RED!"); 
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 50, 2);
  tft.setTextColor(TFT_RED);
  tft.setTextSize(2);
  tft.print("STOP NOW!");
  delay(2000);


tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED);
  flashing(10);
  tft.fillScreen(TFT_BLACK);
  delay(100);
  tft.setCursor(54, 50, 2);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.print("////");
  delay(2000);
  tft.fillScreen(TFT_BLACK);

  delay(0000);

  tft.fillScreen(TFT_BLACK); 
  delay(100);

  // *buzzer
  //digitalWrite(buzz, HIGH);
 // delay(2000);
  // optional
  digitalWrite(LEDGREEN, HIGH);
  delay(2000);
  digitalWrite(LEDGREEN, LOW);
  tft.setCursor(40, 50, 2);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.print("GREEN"); 
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(57, 50, 2);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.print("GO!");
  delay(2000);


tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);
  flashing(10);
  tft.fillScreen(TFT_BLACK);
  delay(100);
  tft.setCursor(54, 50, 2);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.print("////");
  delay(2000);
  tft.fillScreen(TFT_BLACK);

  delay(1000);

  tft.fillScreen(TFT_BLACK); 
  delay(100);

  // *buzzer
  //digitalWrite(buzz, HIGH);
 // delay(2000);
  // optional
  digitalWrite(LEDYELLOW, HIGH);
  delay(2000);
  digitalWrite(LEDYELLOW, LOW);
  tft.setCursor(37, 50, 2);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.print("YELLOW"); 
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(43, 50, 2);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.print("WAIT!");
  delay(2000);


  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW);
  flashing(10);
  tft.fillScreen(TFT_BLACK);
  delay(100);
  tft.setCursor(54, 50, 2);
  tft.setTextColor(TFT_RED);
  tft.setTextSize(2);
  tft.print("////");
  delay(2000);
  tft.fillScreen(TFT_BLACK);

  delay(1000);
  }
}




  