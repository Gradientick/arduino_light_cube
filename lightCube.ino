#define LAYER_COUNT 8
#define LAYER_PIN_START 2
#define LED_PIN_START 10
#define LED_PER_LAYER 64

void setup() {
  // Initialize all the layer and LED pins as OUTPUT
  for (int i = 0; i < LAYER_COUNT; i++) {
    pinMode(LAYER_PIN_START + i, OUTPUT);
  }
  for (int i = 0; i < LED_PER_LAYER; i++) {
    pinMode(LED_PIN_START + i, OUTPUT);
  }
}

void loop() {
  // Pattern 1: Turn on each layer one by one
  for (int layer = 0; layer < LAYER_COUNT; layer++) {
    setLayer(layer);
    delay(500);
  }

  // Pattern 2: Flashing random LEDs
  for (int i = 0; i < 50; i++) {
    int randomLayer = random(LAYER_COUNT);
    int randomLED = random(LED_PER_LAYER);
    setLayer(randomLayer);
    digitalWrite(LED_PIN_START + randomLED, HIGH);
    delay(100);
    digitalWrite(LED_PIN_START + randomLED, LOW);
  }

  // Pattern 3: Create a wave pattern
  for (int i = 0; i < LAYER_COUNT; i++) {
    setLayer(i);
    delay(200);
  }
  for (int i = LAYER_COUNT - 2; i >= 0; i--) {
    setLayer(i);
    delay(200);
  }
}

void setLayer(int layer) {
  // Turn off all layers
  for (int i = 0; i < LAYER_COUNT; i++) {
    digitalWrite(LAYER_PIN_START + i, LOW);
  }
  // Turn on the specified layer
  digitalWrite(LAYER_PIN_START + layer, HIGH);
}
