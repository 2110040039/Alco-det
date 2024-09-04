# Alcodet

Alcodet is a project designed to monitor alcohol levels and environmental conditions like temperature and humidity using an ESP8266 microcontroller. The system alerts users when alcohol concentration reaches unsafe levels by triggering an alarm and sending notifications through Blynk.

## Features

- **Alcohol Detection**: Monitors alcohol concentration using a MQ3 gas sensor and triggers a warning if levels exceed the safe threshold.
- **Environmental Monitoring**: Reads temperature and humidity using the DHT11 sensor.
- **Real-time Alerts**: Sends notifications through the Blynk app when high alcohol levels are detected.
- **Visual Indicators**: LED indicators show the status of the environment (safe or warning).
- **Auditory Alert**: A buzzer sounds when unsafe alcohol levels are detected.

## Components Used

- **ESP8266**: WiFi-enabled microcontroller for data processing and communication.
- **DHT11 Sensor**: Measures temperature and humidity.
- **MQ3 Sensor**: Detects alcohol concentration in the environment.
- **Buzzer**: Provides an auditory alert when unsafe alcohol levels are detected.
- **LEDs**: Visual indicators for safe (green) and warning (red) statuses.
## Block Diagram
![block diagram](https://github.com/user-attachments/assets/e4cbb115-d58d-4bd0-ab05-8a2bd5b10530)
## Operation

### Safe Condition

- **LED Indicators**: 
  - Green LED (LED1) glows to indicate a safe environment.
  - Red LED (LED2) remains off.
- **Buzzer**: 
  - The buzzer is off.

![safe](https://github.com/user-attachments/assets/f00243a8-6bbe-47c7-84f2-d1a8055d99e5)

### Unsafe Condition

- **LED Indicators**:
  - Red LED (LED2) glows to indicate an unsafe environment.
  - Green LED (LED1) remains off.
- **Buzzer**:
  - The buzzer sounds to alert users of the unsafe condition.


- **Blynk Notifications**:
  - A Blynk notification is sent to the user’s mobile app indicating "High Alcohol Level Detected."


- **Email Alerts** (Future Improvement):
  - An email alert can be sent to notify users of high alcohol levels. This feature is not included in the current code but can be added using an SMTP server or services like IFTTT.

![alert](https://github.com/user-attachments/assets/cd0e2eb8-c6dc-4377-9d27-ecab60b331f9) ![blynk notification](https://github.com/user-attachments/assets/1e2eb0a8-16c2-4af8-a633-344becdf4b96) ![blynk mail](https://github.com/user-attachments/assets/0ca4612f-850c-475f-a1c0-63d8ab90527c)


## Future Improvements

- Integrate more sensors for comprehensive environmental monitoring.
- Add a more sophisticated notification system (e.g., email or SMS alerts).
- Enhance the user interface on the Blynk app for better data visualization.
