# 01 - Project Overview

## Overview

This project presents the design and implementation of a modular embedded monitoring and alarm system based on the Arduino UNO R4 platform. The system continuously monitors environmental conditions using I2C-connected sensors and activates visual and acoustic alarms whenever predefined safety thresholds are exceeded.

The project combines embedded programming, sensor integration, real-time monitoring, modular hardware design and embedded software development to demonstrate the implementation of an intelligent monitoring system suitable for IoT-oriented applications.

<p align="center">
<img src="../screenshots/montaje-completo.png" width="700">
</p>

---

## Hardware Platform

The prototype was implemented using the following hardware components:

- Arduino UNO R4
- Modulino Temperature Sensor
- Modulino Distance Sensor
- Modulino LED Bar
- Modulino Buzzer
- Push Buttons
- I2C Communication Bus

---

## Software Environment

The firmware was developed using:

- Arduino IDE
- C++
- Arduino Libraries
- I2C Communication Protocol

---

## System Architecture

The monitoring system follows a modular embedded architecture in which all peripherals communicate through the I2C bus. Sensor measurements are periodically acquired by the Arduino UNO R4, processed by the firmware and translated into visual and acoustic responses according to predefined safety thresholds.

<p align="center">
<img src="../screenshots/arquitectura-fisica.png" width="700">
</p>

---

## Functional Requirements

The firmware was designed to satisfy the following operational requirements:

- Continuously measure ambient temperature in real time.
- Detect nearby objects using the distance sensor.
- Display the current temperature level using a proportional LED bar.
- Activate an acoustic alarm whenever predefined temperature or distance thresholds are exceeded.
- Allow the operator to mute the alarm using Button A.
- Completely stop system operation using Button B.
- Restore normal monitoring using Button C.
- Continuously report sensor values and system status through the Serial Monitor for debugging and validation.

---

## Non-Functional Requirements

The prototype was developed considering several engineering constraints to ensure stable and reliable operation.

- Sensor measurements are updated every 150 ms to provide near real-time monitoring while avoiding unnecessary I2C bus saturation.
- The firmware is designed for continuous operation without blocking delays or memory overflow.
- The software is implemented in C++ using the Arduino IDE to ensure portability and maintainability.
- During startup, the system verifies communication with every I2C peripheral before entering the monitoring loop.
- The visual and acoustic interfaces provide intuitive feedback, allowing users to quickly identify the severity of an alarm condition without requiring technical knowledge.

---

## Design Decisions

Several engineering decisions were adopted during the implementation of the system:

- **Modular Hardware Design:** All peripherals communicate through the I2C bus, simplifying wiring and allowing new modules to be integrated with minimal hardware modifications.

- **Real-Time Monitoring:** A short acquisition interval was selected to provide fast response while maintaining stable communication between devices.

- **Dual Alarm Mechanism:** Visual and acoustic indicators operate simultaneously to improve usability and increase system reliability during emergency situations.

- **Embedded C++ Development:** Native Arduino programming was selected to maximize hardware compatibility, execution efficiency and future code maintenance.

- **Manual User Control:** Physical buttons provide immediate interaction with the system, allowing alarms to be muted, the monitoring process to be stopped, or normal operation to be restored without requiring external software.

---

## Summary

This project provides practical experience in embedded systems programming, modular hardware integration, I2C communication and real-time monitoring.

By combining Arduino UNO R4, multiple Modulino sensors and actuators, and embedded C++ firmware, the prototype demonstrates the implementation of a reliable monitoring and alarm system capable of detecting environmental risks and responding through both visual and acoustic notifications.

The project also reinforces fundamental concepts of embedded software design, hardware abstraction, sensor integration and modular IoT system development.
