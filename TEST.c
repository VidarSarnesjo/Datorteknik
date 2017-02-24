#include <IOShieldOled.h>
#include <stdint.h>
#include <pic32mx.h>

int z;
int Size;
byte* fillWhite;

const int xoffset = 90;
const int yoffset = 0;




void setup() {

IOShieldOled.begin();
IOShieldOled.displayOn();
IOShieldOled.clear();
IOShieldOled.setCursor(0,0);


  IOShieldOled.setDrawMode(modeAnd);

  fillWhite = IOShieldOled.getStdPattern(1);
  IOShieldOled.setFillPattern(fillWhite);

  z = 0;

  Size = 6;



}

void loop() {

  // Hello chipKIT World"
   IOShieldOled.setCursor(0,1);// sets the cursor to row 2
   IOShieldOled.putString("Hello");
   IOShieldOled.setCursor(0,2);// sets the cursor to row 3
   IOShieldOled.putString("chipKIT");
   IOShieldOled.setCursor(0,3);// sets the cursor to row 4
   IOShieldOled.putString("World");
  // square graphics





  int x = 8*(z % 4) + xoffset; //sets the column position for the rectangle
  int y = 8*(z/4) + yoffset;   //sets the row position for the rectangle
  IOShieldOled.moveTo(x,y);

  IOShieldOled.drawFillRect(x+ Size, y + Size);



  z++;
if (z == 16){
  z = 0;
}
  IOShieldOled.updateDisplay();// update the frame buffer



  delay(150);

}
