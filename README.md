# CAN-Bus-IDS-STM32
### Real-time Automotive CAN Bus Intrusion Detection with On-Device AI on STM32F446RE

![STM32](https://img.shields.io/badge/MCU-STM32F446RE-blue)
![AI](https://img.shields.io/badge/AI-X--CUBE--AI%2010.2-red)
![Accuracy](https://img.shields.io/badge/Accuracy-99.92%25-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

A real-time automotive **CAN Bus Intrusion Detection System (IDS)** running entirely on a resource-constrained ARM Cortex-M4 microcontroller. The system monitors CAN bus traffic, extracts features per frame, and classifies attacks using a quantized neural network — no cloud, no external compute, sub-millisecond inference.

---

## Demo
```
=== CAN IDS System Starting ===
[OK] CAN Driver Initialized
[OK] UART Frame Parser Ready
[OK] AI Network Initialized
=== System Ready - Monitoring CAN Bus ===

[INFO] Normal traffic - 1000 frames processed
[ALERT] *** DoS ATTACK *** | ID: 0x000 | Confidence: 99%
[ALERT] *** DoS ATTACK *** | ID: 0x000 | Confidence: 99%
[ALERT] *** FUZZY ATTACK *** | ID: 0x03AB | Confidence: 97%
[INFO] Normal traffic - 1000 frames processed


No Attack, Normal ECU traffic
<img width="640" height="321" alt="image" src="https://github.com/user-attachments/assets/33617821-ffee-4455-95d7-bdec6afdc5b9" />

Simulated Attack by injecting malicous frames
<img width="641" height="261" alt="image" src="https://github.com/user-attachments/assets/4646d1a5-39f5-493e-b159-9bd82309d378" />

<img width="675" height="242" alt="image" src="https://github.com/user-attachments/assets/bc9d58d7-0cb8-4fae-9272-52ed40ebed3f" />







```

---

## System Architecture
```
┌─────────────────────┐         CAN                    ┌──────────────────────────────┐
│     ESP8266 Node    │ ─────────────────────────────► │    STM32F446RE - IDS Node    │
│                     │                                 │                              │
│  • Simulates ECU    │                                 │  • Bare-metal bxCAN driver   │
│    CAN traffic      │                                 │  • Feature extraction (11)   │
│  • Injects attacks  │                                 │  • int8 MLP inference        │
│  • Button-triggered │                                 │  • UART alert logging        │
└─────────────────────┘                                 └──────────────────────────────┘
```

---

## Detection Results

| Attack Type    | Test Accuracy | Live Demo    | Description                       |
|---------------|--------------|--------------|-----------------------------------|
| Normal Traffic | 99.9%        | ✅ Working   | Legitimate ECU frames             |
| DoS Attack     | 100%         | ✅ Detected  | ID 0x000 flooding                 |
| Fuzzy Attack   | 99.7%        | ✅ Detected  | Random ID + payload injection     |
| Gear Spoofing  | 99.8%        | Dataset only | ECU impersonation (gear position) |
| RPM Spoofing   | 99.8%        | Dataset only | ECU impersonation (engine RPM)    |

**Overall accuracy: 99.92%** on 491,847 unseen test frames (HCRL Car Hacking Dataset)

---

## ML Pipeline

| Step | Detail |
|------|--------|
| Dataset | HCRL Car Hacking Dataset — real vehicle (KIA Soul), OBD-II capture |
| Frames | 3.3M total → balanced to 491,847 per class (5 classes) |
| Features | CAN ID, DLC, 8 payload bytes, inter-arrival time = 11 features |
| Model | MLP: Input(11) → Dense(64, ReLU) → Dense(32, ReLU) → Dense(5, Softmax) |
| Parameters | 3,013 total — 11.77 KB float32 |
| Quantization | Full int8 post-training quantization → 8.06 KB |
| Runtime | X-CUBE-AI 10.2 on STM32F446RE |
| On-device RAM | 2.62 KB total |



<img width="1267" height="101" alt="image" src="https://github.com/user-attachments/assets/9e517891-d104-4a39-9250-e43fce210141" />

<img width="1267" height="101" alt="image" src="https://github.com/user-attachments/assets/6c080fed-b79d-49e0-9913-f63478761163" />

---

## Firmware Architecture
```
Core/Src/
├── main.c                  ← Application entry, inference loop
├── can_driver.c            ← Bare-metal bxCAN — direct register access
│                              RCC, GPIO AF9, BTR timing, filter config
│                              Interrupt-driven RX ring buffer (32 frames)
├── feature_extractor.c     ← Hardcoded StandardScaler, 11-feature extraction
├── uart_frame_parser.c     ← Interrupt-driven UART parser (ESP8266 frames)
└── uart_log.c              ← UART logging with printf-style formatting

X-CUBE-AI/App/
├── network.c               ← Generated inference API
└── network_data.c          ← Quantized model weights in flash
```

### Key Design Decisions

- **No HAL for CAN** — bxCAN configured entirely via direct register manipulation. RCC clock enable, GPIO alternate function 9, BTR bit timing for 500 kbit/s at 45 MHz APB1, filter bank configuration, NVIC priority assignment.
- **Ring buffer ISR** — CAN RX interrupt stores frames in a 32-slot circular buffer. Main loop drains it independently. No blocking in ISR, no dropped frames during inference.
- **Hardcoded scaler** — StandardScaler parameters embedded as const float arrays in firmware. No dynamic memory allocation, no file I/O.
- **int8 quantization** — 4x memory reduction vs float32. Faster integer math on Cortex-M4. Quantization parameters applied per-frame before inference.

---

## Hardware

| Component | Purpose |
|-----------|---------|
| STM32F446RE (Nucleo-64) | Main IDS node — 180 MHz Cortex-M4, 512KB flash, 128KB RAM |
| ESP8266 (ESP-12S) | Sensor/attack simulation node |
| UART connection | Inter-board frame protocol @ 115200 baud |
| ST-Link V2 (on-board) | Flashing and SWD debugging |

---

## CAN Bit Timing
```
APB1 clock:  45 MHz
Prescaler:   9
BS1:         8 time quanta
BS2:         1 time quantum
Baud rate:   45,000,000 / (9 x (1 + 8 + 1)) = 500,000 bit/s
```

---

## Repository Structure
```
CAN-Bus-IDS-STM32/
├── Core/
│   ├── Inc/                    ← Header files
│   └── Src/                    ← Firmware source files
├── Drivers/                    ← STM32 HAL drivers (CubeMX generated)
├── X-CUBE-AI/                  ← ST AI runtime + generated network
├── Middlewares/                ← X-CUBE-AI library
├── ML_Pipeline/                ← Python notebooks and model files
│   ├── explore.ipynb
│   ├── can_ids_model.tflite
│   ├── can_ids_model.h
│   └── scaler_params.json
├── ESP8266/
│   └── can_simulator.ino       ← Arduino sketch for frame simulation
└── README.md
```

---

## Getting Started

### Prerequisites
- STM32CubeIDE 1.16+
- X-CUBE-AI 10.2 pack (install via CubeMX Software Packs)
- Arduino IDE with ESP8266 board package
- Python 3.x with TensorFlow, scikit-learn, pandas

### Flash STM32
1. Open project in STM32CubeIDE
2. Build project (Ctrl+B)
3. Flash via ST-Link (F11)
4. Open serial terminal at 115200 baud on Nucleo COM port

### Flash ESP8266
1. Open `ESP8266/can_simulator.ino` in Arduino IDE
2. Select Tools → Board → Generic ESP8266 Module
3. Hold FLASH button → press RESET → release FLASH → Upload
4. Press RESET to run — FLASH button cycles attack modes




---

## Industry Relevance

This project addresses real automotive cybersecurity requirements under **ISO 21434** and **UN R155**, which mandate intrusion detection for connected vehicles. The on-device inference approach is production-viable for ECU deployment where latency requirements rule out cloud processing, memory constraints demand quantized models, and real-time guarantees require deterministic bare-metal firmware.

---

## Tech Stack

**Embedded:** C · STM32CubeIDE · X-CUBE-AI 10.2 · Bare-metal bxCAN · UART ISR

**ML:** Python · TensorFlow/Keras · scikit-learn · TFLite · int8 Quantization

**Tools:** Jupyter Notebook · STM32CubeMX · Arduino IDE

---

## Author

**Laith Alarmouti** — Embedded AI and Real-Time Systems

M.Sc. Embedded AI · Seeking embedded/firmware roles in Germany (automotive, defence, aerospace)

[Portfolio](https://laithalarmouti.github.io) · [LinkedIn](https://linkedin.com/in/laithalarmouti)
