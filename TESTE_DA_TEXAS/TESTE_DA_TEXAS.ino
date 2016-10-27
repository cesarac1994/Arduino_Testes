#include <Time.h>

//CONSTANTES
const int n=9, inicia=3,tempo = 5;
unsigned  int pino_Sinal = 2;     // the number of the pushbutton pin
unsigned  int ledPin =  13;      // the number of the LED pin


//VARIAVEIS GLOBAIS         // variable for reading the pushbutton status
int contador[n];
unsigned int flag=0,segundos;
unsigned int proximo_Sinal = HIGH;
unsigned int sinal_anterior = LOW;
int i;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(pino_Sinal, INPUT);     
  Serial.begin(9600);      // open the serial port at 9600 bps:    
  
}



void loop(){
  // read the state of the pushbutton value:
  sinal_anterior = digitalRead(pino_Sinal);
  
  //Serial.print(" sa: ");
  //Serial.print(sinal_anterior);
  //Serial.print(" ps: ");
  //Serial.println(proximo_Sinal);
  if(sinal_anterior != proximo_Sinal){
      flag++;
      for(i=0;i<n;i++){
        Serial.print(" c");
        Serial.print(i);
        Serial.print(":");
        Serial.print(contador[i]);
      }
      delay(tempo*188);
      for(i=0;i<n;i++)
        contador[i]=0;
      setTime(0);
      Serial.print(" f: ");
      Serial.println(flag);
  }
      
  if(flag>=inicia){
    //Serial.print("s:");
    segundos=second();
    //Serial.println(segundos);
    for(i=0;i<n;i++)
      if(segundos==i)
        contador[i]++;
 }
  proximo_Sinal = digitalRead(pino_Sinal);
  delay(1);
    
}