#define BUTTON_PIN 0

int attack_mode = 0;
bool last_btn = HIGH;
unsigned long last_debounce = 0;
unsigned long last_frame = 0;

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    // Button debounce
    bool btn = digitalRead(BUTTON_PIN);
    if (btn == LOW && last_btn == HIGH && millis() - last_debounce > 200) {
        attack_mode = (attack_mode + 1) % 5;
        last_debounce = millis();
    }
    last_btn = btn;

    // Send frame every 2ms
    if (millis() - last_frame >= 2) {
        last_frame = millis();

        if (attack_mode == 0) {
            // Normal
            Serial.println("N,0316,8,05,21,68,09,21,21,00,6F");
        } else if (attack_mode == 1) {
            // DoS
            Serial.println("D,0000,8,00,00,00,00,00,00,00,00");
        } else if (attack_mode == 2) {
            // Fuzzy
            Serial.println("F,03AB,8,A3,2F,11,CC,00,FF,12,44");
        } else if (attack_mode == 3) {
            // Gear
            Serial.println("G,0350,8,03,00,00,00,00,00,00,00");
        } else {
            // RPM
            Serial.println("R,0316,8,FF,FF,00,00,00,00,00,00");
        }
    }
}