void setup(){
	Serial.begin(9600);
	delay(500);

	Serial.println("Ola. estou funcionando");
}

void loop(){
	Serial.println("Eu vou...");
	delay(1000);

	Serial.println("Ou nao vou...");
	delay(1000);
}
