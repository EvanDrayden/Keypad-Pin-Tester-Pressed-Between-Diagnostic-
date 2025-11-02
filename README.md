This Arduino sketch is designed to detect which pins on your keypad connect when a key is pressed.
It’s ideal for identifying unknown or mislabeled keypad wiring and works reliably with any Arduino-compatible board (Nano, Uno, Mega, ESP32, etc.).
Keypads often come with no documentation or inconsistent pin labeling. This tool eliminates guesswork by automatically identifying which two pins short together when each button is pressed.
It prints the detected pin pairs in the Serial Monitor, so you can map your keypad correctly before using it with the Keypad.h library or any custom logic.
Paste the results from serial monitor to any AI model and ask it to correct the keypad code.
Check code for connections.
You can use any set of 8 digital pins.
Update the pins[] array in the code if your wiring is different.
The sketch cycles through each pin, sets it LOW one at a time, and checks the others for a signal.
When a key is pressed, two pins get connected internally inside the keypad, and the program prints out which pins they are.
Example
Pressed between 8 & 3
Pressed between 9 & 4
How to Use
	1.	Wire your keypad to any 8 digital pins on your Arduino.
	2.	Upload the provided .ino sketch.
	3.	Open Serial Monitor at 9600 baud.
	4.	Press each key one by one.
	5.	Note the pin pairs displayed.
	6.	Use those pin pairs to define your rows and columns in your main keypad program.

💡 Tip: If your keypad output looks confusing, take a photo of your notes or wiring diagram and upload it to an AI model (like ChatGPT with image analysis) to automatically generate your correct hexaKeys, rowPins, and colPins mappings.
Developed for makers, students, and hardware testers who are done guessing keypad pinouts.
Tested on Arduino Nano, Uno, Mega, and ESP32 — but works on any board with at least 8 digital pins.
