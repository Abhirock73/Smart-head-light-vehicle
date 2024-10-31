
void setup()
{
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(2,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop()
{
    int light = analogRead(A0);

    int rain=digitalRead(2);

    digitalWrite(9,HIGH);

    delay(10);

    digitalWrite(9,LOW);
    float time=pulseIn(8,HIGH);
    float distance=0.033*time/2;
    distance=(distance-500)/10;
    int swit=digitalRead(7);
    int speed =analogRead(A2);
    speed=speed/10;
    distance=abs(distance);

    if(swit==0)
    {

      Serial.println("vehivle is stop");

    }
    else{
              Serial.print("DISTANCE:-");
            Serial.print(distance);
          if(light>=300 && light <=600)
          {
            Serial.println("Evening");
            if(rain==0){
                 Serial.println("weather clear");
                 if(distance >35){
                     Serial.println("path is clear");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("LOW Intensity Mode Activated");
                        digitalWrite(5,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(4,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                }
                else{
                  Serial.println("vehicle is coming");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("LOW Intensity Mode Activated");
                        digitalWrite(5,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(4,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("LOW Intensity Mode Activated");
                        digitalWrite(5,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(4,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                }

            }
            else{
                 Serial.println("it's raining Now");
                 if(distance >35){
                     Serial.println("path is clear");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                }
                else{
                  Serial.println("vehicle is coming");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(5,LOW);
                        digitalWrite(4,LOW);
                     }
                }
            }
          }
          else if(light<300){
            Serial.println("Night");
            if(rain==0){
                 Serial.println("weather clear");
                 if(distance >35){
                     Serial.println("path is clear");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                }
                else{
                  Serial.println("vehicle is coming");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("LOW Intensity Mode Activated");
                        digitalWrite(5,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(4,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("LOW Intensity Mode Activated");
                        digitalWrite(5,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(4,LOW);
                     }
                }

            }
            else{
                 Serial.println("it's raining Now");
                 if(distance > 35){
                     Serial.println("path is clear");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("HIGh Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        digitalWrite(5,LOW);
                     }
                }
                else{
                  Serial.println("vehicle is coming");
                     if(speed<=30){
                        Serial.println("Vehicle is moving with normal speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else if(speed>30 && speed<60){
                        Serial.println("Vehicle is moving with Average speed");
                        Serial.println("MEDIUM Intensity Mode Activated");
                        digitalWrite(4,HIGH);
                        digitalWrite(3,LOW);
                        digitalWrite(5,LOW);
                     }
                     else{
                        Serial.println("Vehicle is moving with HIGH speed");
                        Serial.println("HIGH Intensity Mode Activated");
                        digitalWrite(3,HIGH);
                        digitalWrite(5,LOW);
                        digitalWrite(4,LOW);
                     }
                }
            }

          }
          else{
            Serial.println("Day");
              digitalWrite(5,LOW);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
          }
    }
    delay(1000);
}