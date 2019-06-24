#include <Adafruit_Sensor.h> 
#include <Adafruit_BMP280.h>
#include <HardwareSerial.h>
#include<Servo.h>  
int servoPin = PA0;
int alt=0;
int count=0;
Adafruit_BMP280 bmp;
extern struct usart_dev *USART3;
HardwareSerial Serial3(USART3,PB10,PB11); 
Servo servo;
void setup(){
  Serial.begin(9600); 
  Serial3.begin(9600); 
  if(!bmp.begin(0x76)){ 
    Serial.println(F("Sensor BMP280 não foi identificado! Verifique as conexões.")); 
    while(1);} 
      servo.attach(servoPin);
}
 
void loop(){
  int a,u,d,c,m,dm,ua,da,ca;
    servo.write(30);
    if(alt==5){
      delay(100);
      count++; 
    }
    if(count==5)
    servo.write(0); 
  //delay(1000);     
  Serial3.write((int)bmp.readTemperature()); // Escreve os dados no HC12
  Serial.println((int)bmp.readTemperature());
  Serial.println((int)bmp.readPressure());
  Serial.println((int)bmp.readAltitude(1013.25));
  alt =(int)bmp.readAltitude(1013.25);
    Serial3.flush();    
    delay(1000);// Aguarda os dados, depois limpa a memória
u=(int)bmp.readPressure() % 10;
d= (int)bmp.readPressure()/ 10 % 10;
c= (int)bmp.readPressure()/ 100 % 10;
m= (int)bmp.readPressure()/ 1000 % 10;
dm=(int)bmp.readPressure() / 10000 % 10;
 Serial3.write(dm); 
 Serial3.write(m);
 Serial3.write(c);
 Serial3.write(d);
 Serial3.write(u);
 Serial3.flush();   
 delay(1000);

ua=alt % 10;
da=alt/ 10 % 10;
ca= alt/ 100 % 10;
Serial3.write(ca); 
 Serial3.write(da);
 Serial3.write(ua);
  Serial3.flush();  
   delay(1000);
}
