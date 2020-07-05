import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish
import time
import serial
import json

serialPort = serial.Serial(port = "/dev/cu.usbmodem1411", baudrate = 9600)


Broker = "192.168.0.196" #JT-BlackBox
#sub_topic = "homeIoT/lock/test"
sub_topic = "homeIoT/test"

time.sleep(2)

############################## MQTT Connection ###############################

#when connecting to mqtt:
def on_connect(client, usrData, flags, rc):
    client.subscribe(sub_topic)
    print("Connected with result code" + str(rc))
    
    ser.write(str(100).encode('ascii'))

#when receiving a message:
def on_message(client, usrData, msg):
    message=str(msg.payload)
    print(msg.topic+" "+message)
    
    
client=mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(Broker)
client.loop_start()

while True:
    if (ser.in_waiting >0):
        output = ser.read()
        //client.publish("output obtained",output.decode('utf-8'))
        
        client.publish(pub_topic, "test from homeIoT") #data need to be something
        time.sleep(60)