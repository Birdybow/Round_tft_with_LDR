
#include "Free_Fonts.h" // Include the header file attached to this sketch
#include <TFT_eSPI.h>
TFT_eSPI tft;


int tempLest = 25; //avlest fra temperatursensor
String temp;
int32_t x0temp = 80;

int LDRMax = 2000;
int LDRMin = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(12,INPUT);

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setFreeFont(&FreeSans9pt7b); 





//**************Temperatur nederst*********************************************************************************************
  tft.drawLine(0,185,240,185,TFT_GREEN);                             //drawLine(x0, y0, x1, y1, color);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  temp = String(tempLest);                //konverterer int til string, som er det eneste drawstring aksepterer
  tft.drawString(temp,x0temp,200);               //drawString(String,x0,y0)
  tft.drawCircle(x0temp + 47,205,5,TFT_GREEN);  //(x0,y0,radien,color)
  tft.drawString("C",x0temp + 55,200);
//******************************************************************************************************************************
    

}

void loop() {
tempLest = analogRead(14);
Serial.print("Temperaturen er: ");
tempLest = map(tempLest,LDRMin,LDRMax,0,60);
Serial.println(tempLest);


//**************Temperatur nederst*********************************************************************************************
   tft.fillRect(x0temp-10,200,150,60,TFT_BLACK); //fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
  tft.drawLine(0,185,240,185,TFT_GREEN);                             //drawLine(x0, y0, x1, y1, color);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  temp = String(tempLest);                //konverterer int til string, som er det eneste drawstring aksepterer
  tft.drawString(temp,x0temp,200);               //drawString(String,x0,y0)
  tft.drawCircle(x0temp + 47,205,5,TFT_GREEN);  //(x0,y0,radien,color)
  tft.drawString("C",x0temp + 55,200);
//******************************************************************************************************************************

  tft.setTextSize(0);
  tft.fillRect(95,0,55,185,TFT_BLACK); //fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
  tempLest = map(tempLest,0,60,0,165); // Mapper over til pixler ifra avlest verdi
  tft.fillRect(95,185-tempLest,55,tempLest,TFT_BLUE); //fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
  Serial.println(String("Xstartpunkt er : ")+String(185 - tempLest));
  Serial.println(String("Rektangellengde er : ")+String(tempLest));
  int yLine = 22;
  int verdi = 60;
  for(int i = 0 ; i < 6 ; i++ ){                                  
    tft.drawLine(80,yLine,90,yLine,TFT_WHITE);
    tft.drawString(String(verdi),50,yLine);
    yLine += 29;
    verdi -= 10;
  }
  delay(200);

//Serial.println(String("")+String());

}
