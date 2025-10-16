# Portable Health Monitor for Community Health Workers

This project is an embedded systems solution designed to provide community health workers in remote areas with a low-cost, portable device for capturing and logging essential patient vitals. The device is built around an STM32 "Black Pill" microcontroller and integrates several sensors to monitor key health metrics without requiring an internet connection.

---

##  Features

* **Vital Signs Monitoring**: Measures Heart Rate, SpO2 (blood oxygen saturation), and body temperature.
* **Fall Detection**: An integrated gyroscope and accelerometer will be used to detect patient falls and trigger alerts.
* **Local Data Logging**: A microSD card reader stores patient history, including time-stamped vitals and significant events, for later review.
* **User Interface**: A 20x4 LCD screen provides real-time feedback and displays patient data clearly.
* **Offline First**: Designed to operate entirely without internet access, making it suitable for remote and rural environments.

---

##  Hardware Components

* **Main Controller**: STM32F411CEU6 "Black Pill"
* **Display**: 20x4 I²C LCD Display
* **Heart Rate & SpO2 Sensor**: MAX30102
* **Temperature Sensor**: LM35 Analog Temperature Sensor
* **Fall Detection**: Gyroscope/Accelerometer (e.g., MPU-6050)
* **Storage**: MicroSD Card Reader Module

---

##  How to Use

1.  Power on the device.
2.  Place a finger gently on the MAX30102 sensor to begin heart rate and SpO2 readings.
3.  Hold the LM35 sensor to record body temperature.
4.  All data is continuously updated on the LCD and logged to the microSD card for future reference.

---
