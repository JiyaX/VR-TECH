#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Aisha(11, 12); // TX, RX
int ledpin=13; // led on D13 will show blink on / off
int hall_1=9;
int hall_2=10;
int BluetoothData; // the data given from Computer
int HallState_1,HallState_2;
int change;
int Phs1,Phs2;
 
 void setup()
 {
   Aisha.begin(9600); //Bluetooth Module works at 9600 baudrate
   pinMode(ledpin,OUTPUT); //led pin as output
   pinMode(hall_1,INPUT); //hall sensor 1 as input
   pinMode(hall_2,INPUT); //hall snesor 2 is also input
 }
 
 void loop()
 {
   if (Aisha.available()) //if data is sent from laptop
   BluetoothData=Aisha.read(); //read it and store it in BluetoothData

 Phs1=HallState_1;
 Phs2=HallState_2;
 HallState_1 = digitalRead(hall_1);
 HallState_2 = digitalRead(hall_2);
 
 
 if (Phs1!=HallState_1 || Phs2!=HallState_2) //Check if new keys are pressed
 {
if (HallState_1==LOW && HallState_2==LOW)
Aisha.write(1);

if (HallState_1==HIGH && HallState_2==LOW)
Aisha.write(2);

if (HallState_1==LOW && HallState_2==HIGH)
Aisha.write(3);

if (HallState_1==HIGH && HallState_2==HIGH)
Aisha.write(4);
 }

if (BluetoothData=='y')
digitalWrite(ledpin,HIGH);
if (BluetoothData=='n')
digitalWrite(ledpin,LOW);

 
 }