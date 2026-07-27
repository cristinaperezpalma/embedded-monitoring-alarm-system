# 03 - Hardware and Implementation

## Overview

This document describes the hardware components, physical implementation, and software environment used to develop the embedded monitoring and alarm system. The prototype integrates multiple Modulino devices connected through an I²C bus, allowing the Arduino UNO R4 to continuously acquire sensor data, process measurements, and control visual and acoustic alarms in real time.

---

## Hardware Components

The embedded system was implemented using a modular hardware platform composed of the following devices.

### Master Controller

The **Arduino UNO R4** acts as the central processing unit of the system. It executes the firmware, coordinates communication with every peripheral through the I²C bus, processes sensor measurements, and controls all output devices.

### Sensor Modules

The monitoring system acquires environmental information through two sensing modules:

- **Modulino Thermo** – Digital temperature sensor used to continuously monitor ambient temperature.
- **Modulino Distance** – Distance sensor used to detect nearby objects and identify proximity-based alarm conditions.

### User Interface Modules

The operator interacts with the system through dedicated input devices:

- **Modulino Buttons** – Three programmable push buttons used to mute alarms, stop the system, and restart the monitoring cycle.
- **Modulino Knob** – Rotary encoder used to modify internal operating parameters without reprogramming the microcontroller.

### Output Modules

Alarm conditions are communicated using two actuator modules:

- **Modulino Pixels** – Addressable RGB LED bar used to represent the current alarm level visually.
- **Modulino Buzzer** – Acoustic alarm activated whenever predefined safety thresholds are exceeded.

---

## Physical Assembly

The prototype integrates temperature monitoring and proximity detection into a single modular embedded system.

All Modulino devices are connected using the **I²C daisy-chain architecture**, allowing both communication and power distribution through standardized cables.

The assembly process consists of:

1. Connecting the Arduino UNO R4 to the first Modulino module.
2. Linking the remaining modules sequentially through the I²C connectors.
3. Uploading the firmware from the Arduino IDE.
4. Powering the complete system through the USB interface.

Because every Modulino board contains its own electronics, no breadboards or additional wiring are required, resulting in a clean and highly modular hardware implementation.

<p align="center">
<img src="../screenshots/montaje-completo.png" width="250">
</p>

The modular assembly greatly simplifies installation while allowing new peripherals to be incorporated without redesigning the existing hardware.

---

## Hardware Connections

Although the Modulino platform hides the low-level electrical implementation, every module communicates through the shared I²C bus.

| Device | Connection | Category | Function |
|----------|------------|----------|----------|
| Arduino UNO R4 | SDA / SCL | Master Controller | Executes the firmware and manages communication |
| Modulino Thermo | I²C Bus | Sensor | Ambient temperature measurement |
| Modulino Distance | I²C Bus | Sensor | Distance and proximity detection |
| Modulino Knob | I²C Bus | User Input | Parameter adjustment |
| Modulino Buttons | I²C Bus | User Input | System control |
| Modulino Pixels | I²C Bus | Actuator | Visual alarm indication |
| Modulino Buzzer | I²C Bus | Actuator | Acoustic alarm generation |

This shared communication architecture reduces wiring complexity while improving maintainability and scalability.

---

## Software Environment

The firmware was developed using the Arduino ecosystem and official Modulino libraries.

The software environment includes:

- Arduino IDE
- C++
- Official Modulino Library
- Wire Library (I²C communication)

The Modulino library provides high-level interfaces for every module, allowing the firmware to interact with sensors and actuators without directly handling low-level communication details.

---

## Firmware Implementation

The embedded software continuously executes a monitoring loop in which sensor data is periodically acquired, processed, and evaluated against predefined safety thresholds.

Depending on the measured conditions, the firmware performs the following actions:

- Reads temperature and distance measurements.
- Updates the LED bar according to the detected temperature level.
- Activates the buzzer whenever an alarm condition is detected.
- Processes user input from the push buttons.
- Restarts or stops the monitoring cycle when requested.

This continuous execution model enables real-time environmental monitoring while maintaining a simple and responsive firmware architecture.

---

## Design Decisions

Several engineering decisions guided the implementation of the hardware platform:

- Selection of the Arduino UNO R4 as the master controller.
- Adoption of the Modulino ecosystem for modular expansion.
- Use of the I²C protocol to minimize wiring complexity.
- Separation of sensing, user interaction, and alarm modules.
- Development in C++ using the Arduino IDE and official libraries.

---

## Summary

This document describes the complete implementation of the embedded monitoring and alarm system, from hardware selection and physical assembly to firmware development. By combining the Arduino UNO R4 with modular I²C peripherals, the project demonstrates a scalable embedded architecture capable of monitoring environmental conditions and generating real-time visual and acoustic alarms.
