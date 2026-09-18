#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 PPT Clicker", "ESP32", 100);

#define TOUCH_PIN T0
#define TOUCH_THRESHOLD 400
#define HOLD_TIME 700

bool wasTouched = false;
bool holdTriggered = false;
unsigned long touchStartTime = 0;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();

  Serial.println("ESP32 PPT Clicker");
  Serial.println("Tap  = Page Down");
  Serial.println("Hold = Page Up");
}

void loop() {

  int value = touchRead(TOUCH_PIN);
  bool touched = value < TOUCH_THRESHOLD;


  if (touched && !wasTouched) {
    touchStartTime = millis();
    holdTriggered = false;
  }


  if (touched && wasTouched) {

    if (!holdTriggered &&
        millis() - touchStartTime >= HOLD_TIME) {

      if (bleKeyboard.isConnected()) {


        bleKeyboard.press(KEY_PAGE_UP);
        delay(50);
        bleKeyboard.release(KEY_PAGE_UP);

        Serial.println("<<< PAGE UP / PREVIOUS");

        holdTriggered = true;
      }
    }
  }


  if (!touched && wasTouched) {

    unsigned long duration =
      millis() - touchStartTime;


    if (duration < HOLD_TIME && !holdTriggered) {

      if (bleKeyboard.isConnected()) {


        bleKeyboard.press(KEY_PAGE_DOWN);
        delay(50);
        bleKeyboard.release(KEY_PAGE_DOWN);

        Serial.println(">>> PAGE DOWN / NEXT");
      }
    }
  }

  wasTouched = touched;

  delay(20);
}
