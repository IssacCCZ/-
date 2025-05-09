#include <Arduino.h>
const int led1Pin = 12;  // 定义 LED1 引脚
const int led2Pin = 13;  // 定义 LED2 引脚

void setup() {
  pinMode(led1Pin, OUTPUT);  // 将 LED1 引脚设置为输出模式
  pinMode(led2Pin, OUTPUT);  // 将 LED2 引脚设置为输出模式
  Serial.begin(9600);  // 初始化串口通信，波特率设置为 9600
  Serial.println("1 for LED1 2 for LED2");  // 向串口发送提示信息
}

void loop() {
  if (Serial.available() > 0) {  // 检查串口是否有数据可读
    String command = Serial.readStringUntil('\n');  // 读取串口接收到的字符串，直到换行符
    if (command == "1") {  // 判断接收到的指令
      digitalWrite(led1Pin, HIGH);  // 点亮 LED1
      Serial.println("LED1 up");  // 向串口发送反馈信息
    } else if (command == "2") {
      digitalWrite(led2Pin, HIGH);  // 点亮 LED2
      Serial.println("LED2 up");  // 向串口发送反馈信息
    } else {
      Serial.println("no plz 1 or 2");  // 接收到无效指令时发送提示信息
    }
  }
}