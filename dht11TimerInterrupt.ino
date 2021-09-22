#include <DHT.h>  // 라이브러리에서 DHT 추가
#include <TimerOne.h>

#define DHTPIN 5     // DHT 센서 데이터선을 디지털핀에 연결
#define DHTTYPE DHT11 // DHT 센서 정의

#define DHTPIN2 4
#define DHTTYPE2 DHT11

#define DHTPIN3 3
#define DHTTYPE3 DHT11

#include <Wire.h>                     // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 2004 I2C용 라이브러리

LiquidCrystal_I2C lcd(0x27,16,2);
LiquidCrystal_I2C lcd2(0x26,16,2);
LiquidCrystal_I2C lcd3(0x25,16,2); 


int Count = 0;
int Count2 = 0;
int Count3 = 0;

void point1second(void);
void point2second(void);
void point3second(void);

DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE2);
DHT dht3(DHTPIN3, DHTTYPE3);

void setup() {
  Serial.begin(9600); 

  lcd.init();
  lcd2.init();
  lcd3.init();
  lcd.backlight();
  lcd2.backlight();
  lcd3.backlight();
  
  dht.begin();  // DHT 센서 연결
  dht2.begin();
  dht3.begin();

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  Timer1.initialize(10000); //타이머 간격 100000us = 100ms = 0.1 sec
  Timer1.attachInterrupt( timerIsr ); // 타이머 간격대로 timerIsr 함수 실행

}

void loop() {
  int h = dht.readHumidity(); // DHT 센서에서 습도데이터 읽기
  int t = dht.readTemperature();  // DHT 센서에서 온도데이터 읽기
  int h2 = dht2.readHumidity(); // DHT 센서에서 습도데이터 읽기
  int t2 = dht2.readTemperature();  // DHT 센서에서 온도데이터 읽기
  int h3 = dht3.readHumidity(); // DHT 센서에서 습도데이터 읽기
  int t3 = dht3.readTemperature();  // DHT 센서에서 온도데이터 읽기
  
  lcd.setCursor(0,0);
  lcd.print("temp : ");
  lcd.print(t);
  lcd.print("°C");
  
  lcd2.setCursor(0,0);
  lcd2.print("temp : ");
  lcd2.print(t2);
  lcd.print("°C");
  
  lcd3.setCursor(0,0);
  lcd3.print("temp : ");
  lcd3.print(t3);
  lcd.print("°C");
}

void timerIsr()
{
  Count++;
  Count2++;
  Count3++;
  if( Count == 100 ) // 10개 카운트 되면 point1second 로 감 ( 100ms ) 
  {
    Count = 0;
    point1second();
  }
  
  if( Count2 == 100 ) // 20개 카운트 되면 point2second 로 감 ( 200ms ) 
  {
    Count2 = 0;
    point2second();
  }

  if( Count3 == 100 ) // 30개 카운트 되면 point3second 로 감 ( 300ms ) 
  {
    Count3 = 0;
    point3second();
  }
}

void point1second()
{
  int t = dht.readTemperature();  // DHT 센서에서 온도데이터 읽기

  // 데이터가 없을 때 처리하는 방식 
  // 습도 혹은 온도 데이터가 nan 일때 출력되는 메시지
  if (isnan(t)) {              
    Serial.println(F("센서와 연결되지 않았습니다"));
    return;
  }

  if(t < 30){
    digitalWrite(13, HIGH);
    Serial.println("LED1 : on");
  }
  else if(t > 30){
    digitalWrite(13, LOW);
    Serial.println("LED1 : off");
  }

}

void point2second()
{
  int t2 = dht2.readTemperature();  // DHT 센서에서 온도데이터 읽기

  // 데이터가 없을 때 처리하는 방식 
  // 습도 혹은 온도 데이터가 nan 일때 출력되는 메시지
  if (isnan(t2)) {              
    Serial.println(F("센서와 연결되지 않았습니다"));
    return;
  }

  if(t2 < 30){
    digitalWrite(12, HIGH);
    Serial.println("LED2 : on");
  }
  else if(t2 > 30){
    digitalWrite(12, LOW);
    Serial.println("LED2 : off");
  }
}

void point3second()
{
  int t3 = dht3.readTemperature();  // DHT 센서에서 온도데이터 읽기

  // 데이터가 없을 때 처리하는 방식 
  // 습도 혹은 온도 데이터가 nan 일때 출력되는 메시지
  if (isnan(t3)) {              
    Serial.println(F("센서와 연결되지 않았습니다"));
    return;
  }

  if(t3 < 30){
    digitalWrite(11, HIGH);
    Serial.println("LED3 : on\n\n");
  }
  else if(t3 > 30){
    digitalWrite(11, LOW);
    Serial.println("LED3 : off\n\n");
  }
}
