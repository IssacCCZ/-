#include <Arduino.h>
void setup() {
  // 设定主角（程序里的变量对应硬件的引脚），引脚功能/作用（输入/输出）
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(14,OUTPUT);
pinMode(15,OUTPUT);
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
}
 
void loop() {
  //来回for循环，设置好起止点
int a[6]={12,13,14,15,22,23};
for(int i = 0; i < 6; i++ )
  {
    digitalWrite(a[i] , HIGH);
    delay(500);
    digitalWrite(a[i] , LOW);
  }

}
