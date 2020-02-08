#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "YOUR_SSID"; // Your Network SSID
const char* password = "YOUR_PASSWORD"; //Your Network Password

int aisle_a_pin=5;
int aisle_a=0;
int aisle_a_data=0;

int aisle_b_pin = 4;
int aisle_b = 0;
int aisle_b_data = 0;

int aisle_c_pin = 13;
int aisle_c = 0;
int aisle_c_data = 0;

/*---------- WiFi setup ---------- */
WiFiClient client;

/*---------- ThingSpeak setup ---------- */
unsigned long myChannelNumber = 932995; // Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "L6DS09UU84B2PG2U"; // Your Write API Key

/*---------- Setup Function ---------- */

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  delay(1000);
  pinMode(aisle_a_pin, INPUT);
  pinMode(aisle_b_pin, INPUT);
  pinMode(aisle_c_pin, INPUT);
  
  //if you come here you have connected to the WiFi
  Serial.println("connected...yeey :");
  ThingSpeak.begin(client);
  delay(1000);
}

/*---------- Loop Function ---------- */

void loop()
{
  /* ---------- AISLE_A Loop ----------*/ 
  
  if( digitalRead(aisle_a_pin)==LOW)
   { 
        aisle_a_data=1;
        Serial.println("--------------------------------------DETECTING PERSON ON AISLE_A----------------------------");
         
         while(digitalRead(aisle_a_pin)!=HIGH)
         {
            delay(500);
            Serial.println("----------------------------------AISLE_A: PERSON REGISTERED SUCCESSFULLY----------------------");
         }
         aisle_a=aisle_a+1;  
        
   }
   else
   {
       aisle_a_data=0;
   }

  /* ---------- AISLE_B Loop ----------*/ 
  
  if( digitalRead(aisle_b_pin)==LOW)
   { 
        aisle_b_data=1;
        Serial.println("--------------------------------------DETECTING PERSON ON AISLE_B----------------------------");
         
         while(digitalRead(aisle_b_pin)!=HIGH)
         {
            delay(500);
            Serial.println("----------------------------------AISLE_B: PERSON REGISTERED SUCCESSFULLY----------------------");
            
         }
         aisle_b=aisle_b+1;  
        
   }
   else
   {
       aisle_b_data=0;
   }

   /* ---------- AISLE_C Loop ----------*/ 
  
  if( digitalRead(aisle_c_pin)==LOW)
   { 
        aisle_c_data=1;
        Serial.println("--------------------------------------DETECTING PERSON ON AISLE_C----------------------------");
         
         while(digitalRead(aisle_c_pin)!=HIGH)
         {
            delay(500);
            Serial.println("----------------------------------AISLE_C: PERSON REGISTERED SUCCESSFULLY----------------------");
         }
         aisle_c=aisle_c+1;  
        
   }
   else
   {
       aisle_c_data=0;
   }
   
  
  ThingSpeak.writeField(myChannelNumber, 1, aisle_a, myWriteAPIKey); //Update in ThingSpeak
  ThingSpeak.writeField(myChannelNumber, 2, aisle_b, myWriteAPIKey); //Update in ThingSpeak
  ThingSpeak.writeField(myChannelNumber, 3, aisle_c, myWriteAPIKey); //Update in ThingSpeak
}
