# Systems Programming & Embedded C Portfolio

A minimal C and Arduino codebase covering hardware control, stream processing, recursive algorithms, and automated test logic.

---

## Project Index & File Layout

```text
.
├── q1_water_quality.c      # Sensor processing & status classifier
├── q2_mobile_money.c       # Transaction control-flow state machine
├── q3_distance_analysis.c  # Array analytics & recursive processing
└── smart_parking_system/   # Embedded Tinkercad smart parking system
    └── smart_parking_system.ino


## 2. Water Quality Sensor Monitor
**Purpose:** Calculates Water Quality Index (WQI) using:
Index = 100 - (|Temperature - 25| + (Turbidity / 2))

**Classification:**

- Good: Index >= 80

- Warning: 60 <= Index < 80

- Critical: Index < 60

**Real-World Application:** Embedded microcontrollers and Engine Control Units (ECUs) in industrial water treatment and environmental monitoring systems.

### Compilation Pipeline:

- Preprocessing (.c -> .i): Expands headers and macros.

- Compilation (.i -> .s): Translates C code to Assembly.

- Assembly (.s -> .o): Converts Assembly to object machine code.

- Linking (.o -> .exe / .out): Links library binaries to create the executable.

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
