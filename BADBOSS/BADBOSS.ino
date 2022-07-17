#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define KEY_ROWS 4 
#define KEY_COLS 4 

char keymap[KEY_ROWS][KEY_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[KEY_ROWS]={9,10,11,12};
byte colPins[KEY_COLS]={2,3,4,5};

Keypad myKeypad =Keypad(makeKeymap(keymap),rowPins,colPins,KEY_ROWS,KEY_COLS);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int cursorColumn = 0;

void Menu(){
  lcd.clear();
  lcd.print("Hi BAD BOSS");
  lcd.setCursor(cursorColumn, 1);
  lcd.cursor();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Hi BAD BOSS");
  Wire.begin();
  lcd.init();
  lcd.backlight();
  Menu();
}

void loop() {
  char key = myKeypad.getKey();
  if(key){
    lcd.setCursor(cursorColumn,1);
    lcd.print(key);
    lcd.cursor();
    Serial.println(key);
    cursorColumn++;
    if(cursorColumn == 17){
      Menu();
      cursorColumn = 0;
    }
  }
}
