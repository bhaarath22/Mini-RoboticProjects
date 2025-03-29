# **Dust Bin Collector Rover**

## **Project Timeline:** July 2023 - December 2023  

### **Project Overview**
During my **3rd semester**, I intended to design a **street dustbin collector vehicle**. I achieved this by designing a **4-wheel rover** with a **2-axis manipulator** at the front. The manipulator picks up the dustbins through a **magnetic docking system**. When it holds a dustbin, the magnet is **turned on** to hold it. The dust is emptied into the truck of the rover. Upon completion, the manipulator deposits the dustbin, and the magnet is **turned off**.

---

## **Components Used**

1. **Arduino Uno** - (x1)
2. **Servo Motors** - (x3) (For 2-axis manipulator: 1 for base, 2 for shoulder movement)
3. **DC Motors** - (x4) (For rover movement)
4. **Motor Driver Module** - (x1)
5. **Joystick Modules** - (x2) (1 for manipulator control, 1 for rover control)
6. **Magnetic Docking System** - (x1)

---

## **Joystick & Movement Control**

### 🎮 **Manipulator (Servo) Movement** (Joystick A0, A1)
| **Joystick X (A0)**  | **Joystick Y (A1)** | **Servo Movement** |
|-----------------|----------------|----------------------|
| **0 → 1023**   | -              | **Base rotates (Left ↔ Right)** |
| -              | **0 → 1023**   | **Up-Left & Up-Right servos move Up/Down** |

- **Base Servo:** Moves left/right based on X-axis joystick values.  
- **Arm Servos:** Move up/down together based on Y-axis joystick values.  

---

### 🚗 **Rover Movement** (Joystick A2, A3)
| **Joystick X (A2)**  | **Joystick Y (A3)** | **Rover Action** |
|-----------------|----------------|----------------------|
| **< 400 (Left)**  | -              | **Move Left**  |
| **> 600 (Right)** | -              | **Move Right** |
| -                | **< 400 (Up)**  | **Move Forward** |
| -                | **> 600 (Down)**| **Move Backward** |
| **400 - 600**    | **400 - 600**   | **Stop (Neutral Position)** |

---

## **Key Learnings**
- **Understanding Joystick Input:** How to manipulate X, Y-axis values for controlling movement.
- **Analog & Digital Pins of Microcontroller:** Processing sensor data efficiently.
- **Combining a Mobile Robot & Manipulator:** Coordinating movements for an autonomous task.

---

## **Conclusion**
This project helped me explore the integration of **robotics, automation, and embedded programming**. It was an exciting journey to combine a **rover and a manipulator**, making them work together for an efficient dustbin collection system.
