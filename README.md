# Systems Programming & Embedded C Portfolio

A minimal C and Arduino codebase covering hardware control, stream processing, recursive algorithms, and automated test logic.

## Project Index & File Layout

├── q1_water_quality.c      # Sensor processing & status classifier
├── q2_mobile_money.c       # Transaction control-flow state machine
├── q3_distance_analysis.c  # Array analytics & recursive processing
└── smart_parking_system/   # Embedded Tinkercad smart parking system
    └── smart_parking_system.ino

## 1. Water Quality Sensor Monitor
- **Purpose:** Calculates Water Quality Index (WQI) using:$$\text{Index} = 100 - (\vert{}T - 25\vert{} + \frac{\text{Turbidity}}{2})$$
- Classification: Good ($\ge 80$), Warning ($60\text{--}79$), Critical ($< 60$).Real-World Application: Microcontroller ECUs in industrial water treatment.
- Compilation Pipeline: Preprocessing (.i) $\rightarrow$ Compilation (.s) $\rightarrow$ Assembly (.o) $\rightarrow$ Linking (.exe).

## 2. Mobile Money Processing System

**Purpose:** CLI state machine handling deposits, balance validation, and withdrawals.

**Control Flow:**

- *switch/case routes* operations (Deposit, Withdraw, Balance, Summary, Exit).

- *while(1)* handles infinite transaction loops until explicit exit (break).

- *continue* rejects negative inputs and overdraft attempts safely without resetting session state.

## 3. Delivery Route Analytics

**Purpose:** Performs route data analytics using procedural and recursive functions.
#### Functions:
- total_distance() & average_distance(): Sums and averages distances.
- longest_route() & count_above_limit(): Calculates bounds and filter metrics.
- recursive_sum(): Base case ($n \le 0$), decrementing step ($n - 1$).
- Trade-off: Recursion offers clean mathematical code but risks stack overflow on large arrays.

## 4. Arduino Smart Parking System

**Data Flow:** HC-SR04 Sensor → Arduino Uno → LED Indicators + Piezo Alarm

**Pin Map:**

- Trig: Pin 9 | Echo: Pin 8

- Green LED: Pin 2 | Red LED: Pin 3 | Buzzer: Pin 4

**State Behavior:**

- Occupied (<100 cm): Red LED ON, Green LED OFF, Buzzer ON (1000 Hz).   


- Vacant (≥100 cm): Green LED ON, Red LED OFF, Buzzer OFF (noTone).   
