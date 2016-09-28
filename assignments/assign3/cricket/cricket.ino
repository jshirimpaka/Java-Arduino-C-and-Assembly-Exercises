/* cricket
 *  
 *  CSE 132 - Assignment 3
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Jean Shirimpaka
 *  WUSTL Key:shirimpaka.jean
 *  
 *  and if two are partnered together
 *  
 *  Name:
 *  WUSTL Key:
 */
#define FILTER_COUNTS 6

float temperatures[FILTER_COUNTS];
unsigned long counts=0;
unsigned long currentTime=0;
bool LEDon=true;

float countTime=0;
float dt=0;
float BLINK_DURATION=200;


const int SENSOR_PIN = A1;
const int LED_PIN =10 ;




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
analogReference(INTERNAL);
pinMode(SENSOR_PIN, INPUT);
pinMode(LED_PIN, OUTPUT);
}


void loop() {
  if(millis()-currentTime>=250){
    readTemp();
    currentTime+=250;
    //digitalWrite(LED_PIN,HIGH);
  }
}

void readTemp(){
  int reading=analogRead(SENSOR_PIN);
  float sensormillVolts=(reading*1100.0)/1024.0;
  float temperature=sensormillVolts/10.0; //LM35 Spec Sheet
  temperatures[counts%FILTER_COUNTS]=temperature;
  counts+=1;
  
  float sum=0;
  for(int i=0; i<6;i++){
       
       sum+=temperatures[i];
       
  }
    
  float tempFiltered=sum/FILTER_COUNTS;
  float chirpsmin=Number60(tempFiltered);
  float dt=60000/chirpsmin;//period
  float blinkTime=0;
  
  

    if(LEDon){
      if(millis()>blinkTime){
        blinkTime+=BLINK_DURATION;
       digitalWrite(LED_PIN, HIGH); 
       LEDon=false;
      }
    }else{
        if(millis()>blinkTime){
          blinkTime+=dt-blinkTime;
          digitalWrite(LED_PIN, LOW);
         LEDon=true;
        }
    }
  
  
    Serial.print(temperature);
    Serial.print(" , ");
    Serial.println(tempFiltered);
  
}

float Number60(float temp){
  float ans=7*(temp-10)+40;
  return ans;
}



 
