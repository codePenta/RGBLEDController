#define RED_POTI_PIN A0
#define YELLOW_POTI_PIN A1
#define BLUE_POTI_PIN A2

#define RED_LED_PIN 9
#define YELLOW_LED_PIN 10
#define BLUE_LED_PIN 11

const int sendDelay = 25;
const int bright = 255;
const int dark = 0;

int redBrightness = 0;
int yellowBrightness = 0;
int blueBrightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  
  redBrightness = analogRead(RED_POTI_PIN) / 4;
  yellowBrightness = analogRead(YELLOW_POTI_PIN) / 4;
  blueBrightness = analogRead(BLUE_POTI_PIN) / 4;

  if (redBrightness >= dark &&
      redBrightness <= bright)
  {
    Serial.print("R:");
    Serial.print(redBrightness);
    analogWrite(RED_LED_PIN, redBrightness); 
  }

  if (yellowBrightness >= dark &&
      yellowBrightness <= bright)
  {
    Serial.print("G:");
    Serial.print(yellowBrightness);
    analogWrite(YELLOW_LED_PIN, yellowBrightness); 
  }

  if (blueBrightness >= dark &&
      blueBrightness <= bright)
  {
    Serial.print("B:");
    Serial.print(blueBrightness);
    analogWrite(BLUE_LED_PIN, blueBrightness); 
  }

  Serial.println();

  delay(sendDelay);

}
