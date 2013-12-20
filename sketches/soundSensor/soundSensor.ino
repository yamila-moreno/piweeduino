void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    pinMode(SOUND_SENSOR, INPUT);
}

void loop()
{
	int sensorValue = analogRead(SOUND_SENSOR);//use A0 to read the electrical signal
	Serial.print("sensorValue ");
    Serial.println(sensorValue);
    delay(1000);
}

