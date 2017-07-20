# มารู้จัก Clonefleur กันเถอะ

Clonefleur เป็นโปรเจคที่ใช้ในการตรวจสอบความชื้นในดิน ความเข้มแสง อุหณภูมิ ซึ่งสามารถนำมาใช้ประโยชน์ได้หลายอย่างทั้ง วัดความชื้นในดิน การตรวจสภาพแวดล้อมภายในโรงเรือน หรือแม้กระทั่งการดูแลรักษาต้นไม้ที่คุณรัก ซึ่งสามารถทำตามได้ง่าย

### อุปกรณ์ที่ใช้ในการทำ Clonefleur

  1.DHT11

  2.Soil Moisture Sensor

  3.NodeWiFi

  4.Wire jumper


### วิธีการต่อ SEnsor ต่างๆ ดังนี้

## DHT11
  
  - ขาVVC ลงไฟ 5V(+)
  - ขาGND ลง Ground(-)
  - ขาDATA ลงพอร์ทที่ 9 ของnodewifi
    
## Soil Moisture Sensor
  
  - ขาVVC ลงไฟ 5V(+)
  - ขาGND ลงไฟ Ground(-)
  - ขาA0  ลงพอร์ท A0 ของnodewifi
    
## Node Wifi
  
  - 3V3 ลงไฟ 5v(+)
  - GND ลง Ground(-)


### CODE ARDUINO

```markdown
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

