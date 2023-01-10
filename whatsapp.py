import serial
import os
import time
from twilio.rest import Client

arduino = serial.Serial(port='COM5', baudrate=9600, timeout=.1)
time.sleep(2)

count = 0
while(1):
        data = arduino.readline().decode()
        value = int(data)
        print(value)
        time.sleep(2)
        
        if value >= 35:
            account_sid = os.environ['TWILIO_ACCOUNT_SID']
            auth_token = os.environ['TWILIO_AUTH_TOKEN']
            client = Client(account_sid, auth_token)
            count += 1
            if count%5 == 0:
                message = client.messages.create(
                                            body='Fire has been detected 🔥🔥. Call 101 immediatly',
                                            from_='whatsapp:+14155238886',
                                            to='whatsapp:+918762126388'
                                        )
    
