# 04 - Testing and Results

## Overview

This document presents the validation process and experimental results obtained during the development of the embedded monitoring and alarm system. The prototype was evaluated under different operating conditions to verify the correct interaction between sensors, actuators, and user controls while assessing the overall stability of both the hardware and firmware.

<p align="center">
<img src="../screenshots/montaje-completo.png" width="400">
</p>

The performed tests demonstrate that the system is capable of continuously monitoring environmental conditions while providing reliable visual and acoustic responses whenever predefined alarm thresholds are exceeded.

---

## Firmware Execution

The embedded software runs on the **Arduino UNO R4**, which acts as the master controller of the I²C communication bus and coordinates every connected Modulino device.

The firmware is organized into two main execution stages:

### System Initialization (`setup()`)

During startup, the firmware performs the following tasks:

- Initializes I²C communication.
- Configures every Modulino module.
- Initializes sensors and actuators.
- Verifies hardware availability.
- Prepares the monitoring system for continuous operation.

Once initialization is complete, the system enters the main monitoring cycle.

### Continuous Monitoring (`loop()`)

The main execution loop continuously performs the following operations:

1. Reads temperature measurements.
2. Reads distance measurements.
3. Detects user interactions through the buttons and rotary knob.
4. Evaluates alarm conditions.
5. Updates the LED bar.
6. Activates or deactivates the buzzer.
7. Sends diagnostic information through the serial interface.

The sequential execution model keeps the firmware simple, deterministic, and easy to maintain while providing real-time system responses.

---

## Experimental Validation

Several functional tests were carried out to verify the behavior of both the hardware platform and the embedded software.

### Temperature Monitoring

The Modulino Temperature Sensor produced stable and consistent measurements throughout the testing period.

Temperature changes were immediately reflected by the LED bar, confirming the correct acquisition and processing of sensor data.

### Proximity Detection

The Modulino Distance Sensor successfully detected nearby objects and triggered alarm conditions whenever the configured safety threshold was exceeded.

The response was immediate and repeatable across multiple test cycles.

### User Interface

The user interface operated correctly during all experiments.

The three push buttons successfully performed their assigned functions:

- Alarm muting.
- Complete system shutdown.
- Monitoring cycle restart.

The rotary knob also provided smooth parameter adjustments without unstable readings or unexpected jumps.

### Alarm System

The alarm subsystem responded correctly to every simulated event.

The LED bar continuously represented the current monitoring state, while the buzzer generated acoustic warnings only when alarm conditions were detected.

No false alarms or delayed activations were observed during testing.

---

## System Performance

The prototype demonstrated stable behavior throughout the experimental evaluation.

The following observations were made:

- Reliable I²C communication during continuous operation.
- No communication errors between Modulino devices.
- Stable sensor measurements.
- Immediate actuator response.
- Predictable firmware execution.
- Continuous monitoring without interruptions.

The modular architecture proved suitable for long-term embedded monitoring applications.

---

## Design Validation

The experimental results validate the main engineering decisions adopted during the project.

The I²C-based architecture significantly reduced wiring complexity while allowing all modules to communicate through a shared bus.

The Arduino UNO R4 successfully coordinated every peripheral, demonstrating sufficient processing capability for real-time monitoring tasks.

Likewise, the use of the official Modulino libraries simplified firmware development while maintaining reliable communication with all connected devices.

---

## Conclusions

The developed prototype successfully demonstrates the implementation of a modular embedded monitoring and alarm system capable of continuously supervising environmental conditions and reacting immediately to hazardous situations.

Both the hardware platform and the embedded firmware operated reliably throughout the experimental evaluation, confirming the effectiveness of the selected architecture.

The combination of modular I²C hardware, real-time sensing, user interaction, and visual and acoustic alarms provides a flexible solution suitable for educational projects and future IoT-oriented monitoring applications.

---

## Summary

This project validates the complete development cycle of an embedded monitoring system, including hardware integration, firmware implementation, communication through the I²C protocol, experimental testing, and performance evaluation. The obtained results demonstrate a stable, scalable, and reliable embedded platform capable of monitoring environmental conditions and generating real-time safety alerts.
