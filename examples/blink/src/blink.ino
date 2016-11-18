//Bruno Scherer

//Esse código é um exemplo de controle de estado dos GPIO do MCU ESP8266, 
//por ser um exemplo bem simples seu funcionamento ele funciona em todos os modelos de ESP, 
//apenas em alguns casos sendo necessario mudar o gpio que deseja ser controlado.

//Vamos controlar o GPIO 2 e mudar seu estado em um determinado periodo de tempo.

#define LED 4 //Define qual o led que estaremos mudando o estatus de alto para baixo e de baixo para alto
#define tempo 1000 //Define o tempo do intervalo da mudança 

//A função setup é chamada uma vez e serve para inicializar estados, variaveis...
void setup(){

pinMode(LED, OUTPUT); //Define o LED como sendo OUTPUT ou seja do tipo saída

}

//A função loop é uma função que literalmente está em loop infinito por default, quando chega ao fim retorna ao inicio
void loop(){
	digitalWrite(LED, HIGH); //Muda o estado do pino para alto
	delay(tempo); //Atraso em milisengundos

	digitalWrite(LED, LOW); //Muda o estado do pino para baixo
	delay(tempo);
}