/*
   Sistema de Irrigação 
   AUTOR:   Lucas Alexandre Mortale
   SKETCH:  Irrigação
   DATA:    14/09/2024
*/
// Código de Funcionamento para Sistema de Monitoramento e Irrigação com Arduino
 
#define pinoAnalog A0 // Define o pino A0 como "pinoAnalog"
#define pinoRele 8 // Define o pino 8 como "pinoRele"
#define pino5V 7 // Define o pino 7 como "pino5V"
#define Vermelho 4
#define Amarelo 5
#define Verde 6
 
int ValAnalogIn; // Introduz o valor analógico ao código
 
void setup() {
Serial.begin(9600); // Declara o BaundRate em 9600
Serial.println("Sistema de Irrigação"); // Imprime a frase no monitor serial
pinMode(pinoRele, OUTPUT); // Declara o pinoRele como Saída
pinMode(pino5V, OUTPUT); // Declara o pino5V como Saída
digitalWrite(pino5V, HIGH); // Põem o pino5V em estado Alto = 5V
//LEDs
  pinMode(Vermelho, OUTPUT);  //vermelho
  pinMode(Amarelo, OUTPUT);  //amarelo
  pinMode(Verde, OUTPUT);  //verde
}
 
void loop() {
ValAnalogIn = analogRead(pinoAnalog); // Relaciona o valor analógico com o recebido do sensor
int Porcento = map(ValAnalogIn, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem
 
Serial.print(Porcento); // Imprime o valor em Porcento no monitor Serial
Serial.println("%"); // Imprime o símbolo junto ao valor encontrado
 
if (Porcento >= 45) { // Se a porcentagem for menor ou igual à
Serial.println("Irrigando a planta ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, HIGH); // Altera o estado do pinoRele para nível Alto
digitalWrite(Vermelho, LOW);  //vermelho
digitalWrite(Amarelo, LOW);
digitalWrite(Verde, HIGH);   //verde

}
 
else { // Se não ...
Serial.println("Planta Irrigada ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, LOW); // Altera o estado do pinoRele para nível Baixo
digitalWrite(Amarelo, HIGH);
delay (1000);
digitalWrite(Vermelho, HIGH);  //vermelho
digitalWrite(Verde, LOW);   //verde

}
delay (1000); // Estabelece o tempo de 1s para reinicializar a leitura
}
