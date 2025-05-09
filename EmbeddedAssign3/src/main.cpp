#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  
  // 初始化OLED显示屏
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306显示屏初始化失败"));
    for(;;);
  }

  // 清屏
  display.clearDisplay();
  
  // 设置文本样式
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello, OLED!");
  display.display();
}

void loop() {
  delay(1000);
  
  display.clearDisplay();
  
  display.setCursor(0, 0);
  display.println("OLED Display Test");
  display.setCursor(0, 20);
  display.print("Time: ");
  display.print(millis()/1000);
  display.println("s");
  
  display.display();
  
  delay(1000);
}