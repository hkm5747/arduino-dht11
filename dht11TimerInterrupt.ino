#include <TimerOne.h>
#include "DHT.h"     // DHT.h 라이브러리를 포함한다

int count = 0;
int count2 = 0;
int count3 = 0;

#define DHTPIN 2      // DHT핀을 2번으로 정의한다(DATA핀)
#define DHTPIN2 3
#define DHTPIN3 4

#define DHTTYPE DHT11  // DHT타입을 DHT11로 정의한다

DHT dht(DHTPIN, DHTTYPE);  // DHT설정 - dht (디지털2, dht11)
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);

void setup() {

Serial.begin(9600);    // 9600 속도로 시리얼 통신을 시작한다
dht.begin(); //DHT 초기화
Timer1.initialize(100000); //타이머 간격 100000us = 100ms = 0.1 sec
Timer1.attachInterrupt( timerIsr ); // 타이머 간격대로 timerIsr 함수 실행

}

void loop() {

}

void timerIsr()
{
   if(count == 10)
  {
    count = 0;
    point1second();
  }
  
  if(count2 == 20)
  {
    count2 = 0;
    point2second();
  }
  
  if(count3 == 30)
  {
    count3 == 30;
    point3second();
  }
}

void point1second()
{
  int h = dht.readHumidity();  // 변수 h에 습도 값을 저장 

  int t = dht.readTemperature();  // 변수 t에 온도 값을 저장

  Serial.print("Humidity1: ");  // 문자열 Humidity: 를 출력한다.

  Serial.print(h);  // 변수 h(습도)를 출력한다.

  Serial.print("%\t");  // %를 출력한다

  Serial.print("Temperature1: ");  // 이하생략

  Serial.print(t);

  Serial.println(" C");
}

void point2second()
{
  int h2 = dht.readHumidity();  // 변수 h에 습도 값을 저장 

  int t2 = dht.readTemperature();  // 변수 t에 온도 값을 저장

  Serial.print("Humidity2: ");  // 문자열 Humidity: 를 출력한다.

  Serial.print(h2);  // 변수 h(습도)를 출력한다.

  Serial.print("%\t");  // %를 출력한다

  Serial.print("Temperature2: ");  // 이하생략

  Serial.print(t2);

  Serial.println(" C");
}

void point3second()
{
  int h3 = dht.readHumidity();  // 변수 h에 습도 값을 저장 

  int t3 = dht.readTemperature();  // 변수 t에 온도 값을 저장

  Serial.print("Humidity3: ");  // 문자열 Humidity: 를 출력한다.

  Serial.print(h3);  // 변수 h(습도)를 출력한다.

  Serial.print("%\t");  // %를 출력한다

  Serial.print("Temperature3: ");  // 이하생략

  Serial.print(t3);

  Serial.println(" C");
}
