/*
 * Sketch to control the pins of Arduino via serial interface
 * Developed for piweek dec 2013
 *
 */


char operation; // Holds operation (R, W, ...)
char mode; // Holds the mode (D, A)
int pin_number; // Holds the pin number
int digital_value; // Holds the digital value


void digital_read(int pin_number){
        /*
         * Performs a digital read on pin_number and returns the value read to serial
         * in this format: P{pin_number}:{value}\n where value can be 0 or 1     
         */

        pinMode(pin_number, INPUT);
        digital_value = digitalRead(pin_number);
        Serial.print('P');
        Serial.print(pin_number);
        Serial.print(':'); 
        Serial.println(digital_value); // Adds a trailing \n 
} 

void setup() {
        Serial.begin(9600); // Serial Port at 9600 baud
}


void loop() {
        
        // Check if characters available in the buffer
        if (Serial.available() > 0) {
                operation = Serial.read();
                switch (operation){
                        case 'R': // Read operation 
                		mode = Serial.read();
                                if (mode == 'D'){ // Digital read 
                                        pin_number = int(Serial.read()); 
                                        digital_read(pin_number); 
                                } else if (mode == 'A'){ // Analog read
                                        pin_number = int(Serial.read()); 
                                        //analog_read(pin_number)
				} else {
					break; // Unexpected mode
				}
                                break; 
                                 
                        case 'W':
                                break; 
                                 
                        default: // Unexpected char
                                break;
		}
	}
}
