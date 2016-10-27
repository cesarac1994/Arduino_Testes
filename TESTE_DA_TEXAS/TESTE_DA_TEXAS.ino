#include <Time.h>

//CONSTANTES
const int n=9, inicia=3,tempo_espera=5*188;
const int pino_Sinal = 2;     
const int ledPin =  13;      


//VARIAVEIS GLOBAIS         
int contador[n];
unsigned int flag=0,segundos;
unsigned int proximo_Sinal = HIGH;
unsigned int sinal_anterior = LOW;
int i;

//CONFIGURAÇÃO DE PINOS E DA PORTA SERIAL
void setup() {
  //digitais (não analógicos)
  // inicializa o pino do led 13 como saída
  pinMode(ledPin, OUTPUT);      
  // inicializa o pino do Sinal, como entrada
  pinMode(pino_Sinal, INPUT);     
  Serial.begin(9600);      // para o serial monitor    
  
}

//ALGORITMO PARA AFERIÇÃO DO TEMPO
void loop(){
  //sinal lido para ser comparado
  sinal_anterior = digitalRead(pino_Sinal);
  
  if(sinal_anterior != proximo_Sinal){
      flag++;
      for(i=0;i<n;i++){
        Serial.print(" c");
        Serial.print(i);
        Serial.print(":");
        Serial.print(contador[i]);
      }
      delay(tempo_espera); //delay para dar tempo de olhar as informações coletadas
      for(i=0;i<n;i++)
        contador[i]=0;
      setTime(0); //zera o cronômetro
      Serial.print(" f: ");
      Serial.println(flag);
  }
      
  if(flag>=inicia){
    segundos=second(); //retorna o valor em segundos do cronômetro
    for(i=0;i<n;i++)
      if(segundos==i)
        contador[i]++;
 }
  proximo_Sinal = digitalRead(pino_Sinal); //sinal lido para ser comparado
  delay(1);
    
}