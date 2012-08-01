/*
  This is a sample test to interface with
  the touch of the ITDB02 2.8" TFT Shield.
  Wich uses the TSC204 touch driver.
  Datasheets can be found here:
  http://imall.iteadstudio.com/im120417020.html
  */


void setup(){
  Serial.begin(9600);
  while(!Serial) {};
  Serial.println("Starting SPI");
  initSPI();
}

#define SCK A1
#define MO A0
#define MI 8
#define SS 9
#define BM MSBFIRST
void loop(){
  
  digitalWrite(SS,LOW);
  shiftOut(MO,SCK,BM,0b11001001);
  byte i1= shiftIn(MI,SCK,BM);
  byte i2= shiftIn(MI,SCK,BM);


  Serial.println(i1<<8|i2);
  delay(100);
}

void initSPI(){
  pinMode(SCK,OUTPUT);
  pinMode(MO,OUTPUT);
  pinMode(SS,OUTPUT);
  pinMode(MI,INPUT);
  digitalWrite(SCK,LOW);
  digitalWrite(MO,LOW);
  //digitalWrite(SS,HIGH);
}
