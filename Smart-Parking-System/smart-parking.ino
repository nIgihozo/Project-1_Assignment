/*Smart Parking*/

/*Pin Definition*/
const int TRIG_PIN = 9;
const int ECHO_PIN = 8;
const int GREEN_LED = 2;
const int RED_LED = 3;
const int BUZZER = 4;

const int MAX_THRESHOLD = 50; // Maximum distance to consider (in cm)


void setup()
{
    /*Initialize Monitor Serials*/
    Serial.begin(9600);
     
    /*Configure Pin Modes*/
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop()
{
    long duration;
    float distance;

    /*Trigger the ultrasonic sensor*/
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    /*Read the echo signal*/
    duration = pulseIn(ECHO_PIN, HIGH);

    /*Calculate the distance*/
    distance = duration * 0.0343 / 2;

    /*Display the distance on the serial monitor*/
    Serial.print("Mesured Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    /*Distance Logics*/
    if(distance < MAX_THRESHOLD && distance > 0)
    {
        /*Update LED and Buzzer states*/
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
        tone(BUZZER, 1000); /* 1KHz Alarm tone*/
    }
    else
    {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        noTone(BUZZER);
    }

    delay(200); /*Delay for 2 seconds for stability*/
}