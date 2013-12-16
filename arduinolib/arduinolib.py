"""
A library to interface Arduino through serial connection

Developed for the piweek, dec 2013
"""
import serial

class Arduino():
    """
    Represents an Arduino connection
    """

    def __init__(self, serial_port='/dev/ttyACM0', baud_rate=9600,
            read_timeout=5):
        """
        Initializes the serial connection to the Arduino board
        """
        self.conn = serial.Serial(serial_port, baud_rate) 
        self.conn.timeout = read_timeout # Timeout for readline() 

    def digital_read(self, pin_number):
        """
        Performs a digital read on pin_number and returns the value (1 or 0)
        Internally sends b'RD{pin_number}' over the serial connection
        """
        command = (''.join(('RD', str(pin_number)))).encode()
        self.conn.write(command) 
        line_received = self.conn.readline().decode().strip()
        header, value = line_received.split(':') # e.g. D13:1
        if header == ('D'+ str(pin_number)):
            # If header matches
            return value

if __name__ == '__main__':
    
    import time

    a = Arduino()
    time.sleep(5)
    print(a.digital_read(13))
