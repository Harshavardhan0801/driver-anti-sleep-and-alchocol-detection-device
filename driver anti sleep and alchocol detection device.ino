#define LEDRED 2
#define LEDGREEN 3
#define BUZZER 12
#define ALCLDIG 5
#define ALCLANA A1
#define TILT 6
#define IR 7
void setup()
{
  
  pinMode(LEDRED,OUTPUT);
  pinMode(LEDGREEN,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(ALCLDIG,INPUT);
  pinMode(TILT,INPUT);
  pinMode(IR,INPUT);
  pinMode(ALCLANA,INPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(LEDGREEN, HIGH);
   bool digital = digitalRead(ALCLDIG);
  int analog = analogRead(ALCLANA);
 
  Serial.print("Analog value : ");
  Serial.print(analog);
  Serial.print("t");
  Serial.print("Digital value :");
  Serial.println(digital);
 
  if (digital == 0) {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LEDRED, LOW);
  } 
else 
{
   // digitalWrite(3, HIGH);
    digitalWrite(LEDRED, HIGH);
    digitalWrite(BUZZER, LOW);
tilt();
    }
  }
void tilt()
{
  int TILT_VALUE = digitalRead(TILT);
  if (TILT_VALUE == LOW){
   // digitalWrite(3,HIGH);
    digitalWrite(LEDRED,HIGH);
    digitalWrite(BUZZER, HIGH);
    ir();
    delay(1000);
  }
  else {
  //  digitalWrite(3,HIGH);
    digitalWrite(LEDRED,LOW);
    digitalWrite(BUZZER, LOW);
    
  }
}
void ir()
{
  if (digitalRead(7)== HIGH)
  {
    //digitalWrite(LEDGREEN,HIGH);
digitalWrite(LEDRED,HIGH);
digitalWrite(BUZZER,HIGH);
    delay(100);
  }
  else 
  {
    //digitalWrite(LEDGREEN,HIGH);
digitalWrite(LEDRED,LOW);
digitalWrite(BUZZER,LOW);
    delay(100);
    }
  
} 
