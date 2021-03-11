#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPin D8

DHT dht(DHTPin, DHTTYPE);

float hum;
float tHum;
float temp;
float tTemp;

int DHTerror = 0;



void setup() {
    // put your setup code here, to run once:

    Serial.begin(115200);

    dht.begin();

}

void loop() {

    // put your main code here, to run repeatedly:
    delay(2000);

    tHum = dht.readHumidity();
    tTemp = dht.readTemperature();

    if (isnan(tHum) || isnan(tTemp)) {

        //Ignorar la lectura fallida y mantenemos la lectura anterior
        DHTerror++;
    }
    else {

        DHTerror = 0;

        hum = tHum;
        temp = tTemp;

        // Envío de datos por WiFi
        //Test de lectura por serial

        Serial.print("Humedad: ");
        Serial.print(hum);
        Serial.print("%     Temperatura: ");
        Serial.print(temp);
        Serial.println("°C");

        
    }


}