# 🌿 AquaHyel – Water Hyacinth Remover Robot

**AquaHyel** is an automated **Water Hyacinth Remover Robot** developed as part of an academic **Robotics Application Development** project.  
The system is designed to address the growing environmental challenge caused by invasive water hyacinth in rivers, canals, and other water bodies.

This repository contains the **robot control code, hardware design concepts, and project documentation** related to the AquaHyel prototype.

AquaHyel focuses on **automation, cost-effectiveness, portability, and environmental sustainability**, reducing the need for manual labor in aquatic weed removal.

---

## 📌 Project Overview

Water hyacinth (*Eichhornia crassipes*) is a rapidly spreading invasive aquatic plant that blocks sunlight, reduces oxygen levels, and disrupts aquatic ecosystems.

The **AquaHyel robot** provides a practical robotic solution by:

- Detecting water hyacinth on the water surface  
- Collecting plants using a conveyor-based mechanism  
- Measuring collected weight in real time  
- Automatically returning when capacity is reached  
- Operating with minimal human intervention  

The system is designed for **small to medium water bodies**, with future scalability in mind.

---

## 🎓 Academic Context

- **Programme:** Higher National Diploma in Software Engineering  
- **Module:** Robotics Application Development  
- **Institution:** National Institute of Business Management (NIBM)  
- **Assessment Type:** Final Academic Project  
- **Project Domain:** Robotics, Embedded Systems & Environmental Engineering  

This project was developed under academic supervision and evaluated as part of institutional coursework requirements. :contentReference[oaicite:0]{index=0}

---

## 🛠️ Core Features

The AquaHyel robot provides the following key functionalities:

- 🌊 Automated surface-level water hyacinth detection  
- 🛞 Motor-driven navigation (forward, backward, turning)  
- 🧲 Conveyor belt–based plant collection mechanism  
- ⚖️ Load cell–based weight measurement system  
- 🚨 LED & buzzer alerts on maximum load  
- ↩️ Automated return mechanism after capacity is reached  
- 🧭 Edge detection using physical push-button sensors  
- 🔋 Battery-powered, low-energy embedded design  

---

## 🏗️ System Architecture (High-Level)

The robot follows a **modular embedded system architecture**:

```text
Power Supply
↓
Arduino Uno (Control Unit)
↓
Sensors & Actuators
↓
Mechanical Collection System
```
### Main Subsystems

- **Control Unit:** Arduino Uno  
- **Navigation System:** DC gear motors + motor driver  
- **Detection System:** Ultrasonic sensor & push buttons  
- **Collection System:** Conveyor belt + servo-assisted bucket  
- **Measurement System:** Load cell with HX711 module  
- **User Feedback:** LCD display, LED, buzzer  

---

## 🔩 Hardware Components

| Component | Purpose |
|---------|--------|
| Arduino Uno | Central control unit |
| DC Gear Motors | Movement & conveyor control |
| L298N Motor Driver | Motor direction & speed control |
| Ultrasonic Sensor | Object & plant detection |
| Load Cell (HX711) | Weight measurement |
| SG90 Servo Motor | Bucket lifting mechanism |
| Relay Module | Power control for conveyor |
| Buck Converters | Voltage regulation |
| LCD Display | System status output |
| LEDs & Buzzer | Alerts and indications |

---

## 🧠 Control Logic (Overview)

- Robot moves forward scanning for plants  
- Ultrasonic sensor detects surface obstacles  
- Conveyor belt activates to collect plants  
- Load cell continuously monitors weight  
- When maximum weight is reached:
  - LED & buzzer activate  
  - Robot automatically returns to start point  
- Push buttons detect hard edges and correct navigation  

---

## 🧩 Technology Stack

### 🔌 Embedded & Hardware
- Arduino Uno  
- Embedded C / Arduino IDE  
- DC & Servo motors  
- Sensors & relay modules  

### 🛠️ Tools & Platforms
- Arduino IDE  
- Tinkercad (design simulation)  
- Breadboard-based prototyping  
- PVC & EPS-based floating structure  

---

## 📁 Repository Structure (High-Level)

```text
AquaHyel-Water-Hyacinth-Remover/
│
├── arduino-code
├── project-report
├── project-presentation
└── README.md
```

--

## 🚀 How to Run the System

### Prerequisites

- Arduino Uno board  
- Arduino IDE installed  
- Required sensors & motors connected  
- External battery power supply  

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/AquaHyel-Water-Hyacinth-Remover
   ```
1. Open the `.ino` file in **Arduino IDE**
2. Connect **Arduino Uno** via USB
3. Upload the code to the board
4. Power the robot using **external batteries**
5. Test the system in a **controlled water environment**

---

## 🎯 Target Use Cases

- River & canal maintenance  
- Environmental robotics projects  
- Academic robotics & IoT research  
- Sustainable water body management  
- Portfolio-ready robotics systems  

---

## 🔮 Future Enhancements

- 📷 Computer vision–based plant identification  
- 🛰️ GPS-based navigation & tracking  
- ☀️ Solar-powered energy system  
- 🤖 Fully automated unloading mechanism  
- ✂️ Integrated cutting blades for dense plants  

---

## 📄 Project Documentation

The complete academic documentation includes:

- Problem analysis & literature review  
- System architecture & circuit diagrams  
- Component selection and justification  
- Testing and evaluation results  
- Future enhancement proposals  

📄 **Project Report:** Included in this repository  
🎥 **Video Demonstration:** Linked in the report appendix  

---

## 📜 License

This project is released **strictly for educational and academic purposes**.  
Commercial use requires prior authorization.