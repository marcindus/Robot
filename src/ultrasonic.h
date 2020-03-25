const int trigPin = D6;
const int echoPin = D7;

void startUltrasonicSensor()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int getDistance()
{
    long duration;
    int distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
}
