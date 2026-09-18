# Change the Slide For Me

[![Platform](https://img.shields.io/badge/Platform-ESP32-E7352C?logo=espressif&logoColor=white)](https://github.com/Prakhar1808/change-the-slide-for-me)
[![Framework](https://img.shields.io/badge/Framework-Arduino-00979D?logo=arduino&logoColor=white)](https://github.com/Prakhar1808/change-the-slide-for-me)
[![IDE](https://img.shields.io/badge/IDE-Arduino_IDE-00979D?logo=arduino&logoColor=white)](https://github.com/Prakhar1808/change-the-slide-for-me)
[![Comms](https://img.shields.io/badge/Comms-Bluetooth_HID-0082FC?logo=bluetooth&logoColor=white)](https://github.com/Prakhar1808/change-the-slide-for-me)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=cplusplus&logoColor=white)](https://github.com/Prakhar1808/change-the-slide-for-me)
[![License](https://img.shields.io/badge/License-GPL--3.0-blue.svg)](https://github.com/Prakhar1808/change-the-slide-for-me/blob/main/LICENSE)

A hands-on presentation remote built on an ESP32. It pairs over Bluetooth as a
keyboard and changes your slides using the board's built-in capacitive touch pad.

- **Tap**  = next slide (`Page Down`)
- **Hold** (~700 ms) = previous slide (`Page Up`)

## Hardware

- ESP32 dev board (WROOM / WROVER)
- No extra components required — it uses the onboard capacitive touch sensor `T0`

## Required library

The sketch needs the **BleKeyboard** library.

- Install it in **Arduino IDE: Tools → Manage Libraries…** and search for
  “BleKeyboard” by T-vK, or grab it from
  `https://github.com/T-vK/ESP32-BLE-Keyboard`.

## Flashing (Arduino IDE)

1. Install the ESP32 core: **Tools → Board → Boards Manager…** → search "esp32" → install
   **esp32 by Espressif Systems**.
2. Open the `change-the-slide-for-me/` folder as a sketch (the `.ino` name must
   match the folder name).
3. Select your board under **Tools → Board → ESP32 Arduino** (e.g. **ESP32 Dev Module**).
4. Click **Upload**.
5. Open the **Serial Monitor** (115200 baud) — you should see:

   ```
   ESP32 PPT Clicker
   Tap  = Page Down
   Hold = Page Up
   ```

## Usage

1. Power the device and pair it with your computer (it shows up as
   **ESP32 PPT Clicker**).
2. Open a slide deck in full-screen presentation mode.
3. Tap to go forward, hold to go back.

## Tuning

Per-board touch values vary, so you may need to adjust these in
`change-the-slide-for-me.ino`:

| Constant           | Default | Meaning                                        |
| ------------------ | ------- | ---------------------------------------------- |
| `TOUCH_PIN`        | `T0`    | Capacitive touch pin to read                   |
| `TOUCH_THRESHOLD`  | `400`   | Touch is detected when the raw value falls below this |
| `HOLD_TIME`        | `700`   | Milliseconds held before it counts as a "hold" |

A good way to calibrate is to watch the raw `touchRead()` value in the Serial
Monitor when touching/not touching the pad, then pick a threshold between the two.
> A very big shout-out to my friend kubo for helping me prepare this on a short notice

## License

[GPL-3.0](LICENSE)
