    //Node WIFI
    #include <Arduino.h>
    #include <ESP8266WiFi.h>
    #include <ESP8266WebServer.h>
    #include <ESP8266mDNS.h>
    #include <EEPROM.h>
    
    // DHT11
    #include <DHT.h>
    #include <DHT_U.h>
    DHT dht(9, DHT11);
    
    // Soil mpisture Sensor
    int S = A0;

    
    void setup() 
    {
         
        dht.begin();
        Serial.begin(115200);
        Serial.println("Clone Fleur");
        
    }
    
    void loop() 
    {
             
           // for DHT11
          int Temp = dht.readTemperature();
          int Humidity = dht.readHumidity();
           Serial.print(" Temperature: ");
           Serial.print(Temp);
           Serial.print(" C ");
           Serial.print(" Humidity: ");
           Serial.print(Humidity);
           Serial.print(" RH ");
            
            // for Soil moisture Sensor
          int soil= analogRead(S);
           soil = map(soil,0,1024,100,0);
           Serial.print(" Moisture: ");
           Serial.print(soil);
           Serial.println(" %");
        delay(500);
    } 
