#include <Arduino.h>

// Add your Mysensors Settings here

// #define MY_RADIO_NRF24
// #define MY_RF24_CHANNEL 22
// #define MY_SIGNING_SIMPLE_PASSWD "verySecure"

//////////////////////////////////////

#include <MySensors.h>

#define PRODUCT_NAME "IR Sender"
#define SENSOR_ID_IR_SENDER 0

#include <IRLibAll.h>

IRsend irsend;

void presentation()
{
    sendSketchInfo(PRODUCT_NAME, "2.1.1");
    present(SENSOR_ID_IR_SENDER, S_IR, PRODUCT_NAME);
}

void receive(const MyMessage &message)
{
    char *message_copy = strdup(message.data);
    if (message_copy != NULL)
    {
        unsigned int type = atoi(strtok(message_copy, ","));
        unsigned long ir_data = strtoul(strtok(NULL, ","), NULL, 16);
        unsigned char len = atoi(strtok(NULL, ","));
        free(message_copy);

        irsend.send(type, ir_data, len);
    }
}
