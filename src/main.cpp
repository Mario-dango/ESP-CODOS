#include <Arduino.h>

const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10;       //Resistencia calibracion en KΩ
const int LDR = A0;   //Pin del LDR

int V;
int ilum;

void LDRRead() {
	V = analogRead(LDR);
	ilum = ((long)V * A * 10) / ((long)B * Rc * (1024 - V));

	//Envio de datos por WiFi

	Serial.print("Iluminación: ");
	Serial.print(ilum);
	Serial.println(" Lux");

	return;
}

void setup() {
	// put your setup code here, to run once:

	Serial.begin(115200);


}

void loop() {
	// put your main code here, to run repeatedly:

	delay(2000);
	LDRRead();

}