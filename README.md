# Bew-sserungs-SYS
This project uses an **ESP32** to control a 12V pump via a **relay**. The pump activates every 12 hours for 5 seconds, managed by a **DS3231 RTC**. An **LED** indicates when the pump is running. The relay switches the 12V power to the pump, while the ESP32 and RTC ensure timely operation.
Importatnt: I actually messured MV not V in the Relay OUT i fixed this issue and now the output is 12V. (The first time is messured it i messured it while it was of and it gave out 12V i repeated the test with the Relay on at times with a new Script and it worked)
