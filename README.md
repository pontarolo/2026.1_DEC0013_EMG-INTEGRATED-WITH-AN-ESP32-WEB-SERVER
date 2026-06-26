<div align="center">
    <img  src="images/banner.png" />

<h4 align="center">Electromyograph integrated with an ESP32 Web Server (⚠️ Under Construction!!)</h4>

![UFSC](https://img.shields.io/badge/UFSC-Ararangu%C3%A1-003366)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Language: C++](https://img.shields.io/badge/Language-C++-purple.svg)
</div>

<p align="center">
  <a href="#materials">Materials</a> •
  <a href="#diagrams">Diagrams</a> •
  <a href="software/README.md">Software</a> •
  <a href="LICENSE">License</a>
</p>

---

## Basic Overview

This project consists of an implementation of a circuit to measure specific muscle activity. The project emerges as a way to detect muscular issues and restraints in a low-cost and reliable manner. The general architecture of this project is a connection between the electromyograph PCB and the ESP32 microcontroller, where the ESP32 acts as a web server with an WebSocket to handle the data plotting.

## Description</div>

This section explains the details of the project, including the materials and tools used, communication and electrical diagrams and examples of its functionality.

### <a id="materials"></a> Materials

<table>
  <tr>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/220res.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Resistor</strong><br>
      <font color="#666" size="2">2x 220Ω • THT</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/100kres.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Resistor</strong><br>
      <font color="#666" size="2">4x 100KΩ • THT</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/220kres.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Resistor</strong><br>
      <font color="#666" size="2">4x 220KΩ • THT</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/trimpot.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Trimpot</strong><br>
      <font color="#666" size="2">1x 10KΩ • THT</font>
    </td>
  </tr>
  <tr>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/capacitor100u.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Capacitor</strong><br>
      <font color="#666" size="2">2x 100μF • Electrolytic • THT</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/capacitor220n.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Capacitor</strong><br>
      <font color="#666" size="2">2x 220nF • Ceramic • THT</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/battery.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Battery</strong><br>
      <font color="#666" size="2">1x Lithium-Ion • 3.7V • 18650 • With Wires</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/mt3608.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>MT3608</strong><br>
      <font color="#666" size="2">1x Module</font>
    </td>
  </tr>
  <tr>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/tp4056.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>TP4056</strong><br>
      <font color="#666" size="2">1x Module</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/lm324n.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>LM324N</strong><br>
      <font color="#666" size="2">1x Integrated Circuit</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/breakout.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>TRRS Breakout</strong><br>
      <font color="#666" size="2">1x Module</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/esp32.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>ESP32</strong><br>
      <font color="#666" size="2">1x ESP-WROOM-32</font>
    </td>
  </tr>
  <tr>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/dip14.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>IC Socket</strong><br>
      <font color="#666" size="2">1x DIP-14</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/cell_holder.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Cell Holder</strong><br>
      <font color="#666" size="2">1x Lithium-Ion • 18650 • Single</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/battery_2.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Battery</strong><br>
      <font color="#666" size="2">1x Lithium-Ion • 3.7V • 18650</font>
    </td>
    <td align="center" valign="top" width="150" style="border: none;">
      <img src="/images/flux.png" width="80" height="80" style="object-fit: contain;"><br>
      <strong>Solder Flux</strong><br>
      <font color="#666" size="2">1x Lead-Free</font>
    </td>
  </tr>
</table>

### <a id="diagrams"></a> Communication Diagram

In this subsection we will discuss the communication diagram of the project to give a general view of the signal path and a clearer understanding of the circuit itself.

<p align="center">
    <img src="images/communication.png" />
</p>

The image above represents the communication diagram, which shows the signal path throughout the whole project. The user's noisy low-voltage signal is sent to the printed circuit board (PCB) through silver $Ag$ or silver chloride $AgCl$ electrodes, where it can be properly filtered and amplified. Then the clean signal is carried to the ESP32 microcontroller that acts as a WebSocket Server to handle mass data plotting, hosting an HTML page that displays the graph.

---

### Electrical Diagram


In this subsection we will discuss the communication diagram of the project to give a general view of the signal processing and a clearer understanding of the circuit itself.

<p align="center">
    <img src="images/electrical.png" />
</p>

The image above represents the electrical diagram, which shows the electrical connection between the components. As shown in the image, the circuit consists of:

| Component | Role in the circuit |
| :--- | :--- |
| **Resistors** | Set the gain stages, establish amplifier feedback loops, and stabilize signal lines. |
| **Trimpot** | Adjusts the virtual ground offset (reference voltage) to bias the EMG signal for the ESP32 ADC. |
| **Capacitors** | Filter out DC offsets (high-pass) and high-frequency noise (low-pass), and decouple power rails. |
| **Battery** | Provides clean, isolated 3.7V power to eliminate grid noise ($60\text{ Hz}$) and ensure user safety. |
| **MT3608** | Boosts the 3.7V battery to a stable 5V, ensuring full dynamic range for the op-amps. |
| **TP4056** | Handles safe Li-Ion battery charging and provides over-discharge protection. |
| **LM324N** | Handles differential amplification and active filtering of the microvolt-level muscle signals. |
| **TRRS Breakout** | Serves as the input jack for the 3-lead electrode cable (Signal +, Signal -, and Reference). |
| **ESP32** | Samples the analog processed signal and hosts the WebSocket server for real-time live plotting. |

<p align="center">
    <img src="images/internal.png" />
</p>

To secure the right voltage for the ESP32 ADC pins, a set of calculations were made, using the following equations:

- **Op-Amps:** By applying Kirchhoff's Laws, it is possible to obtain the expressions for Common and Differential Mode Gain:

| Name | Equation |
| :--- | :--- |
| **Common Mode Voltage** | $V_{cm} = \frac{V_{electrode(+)} + V_{electrode(-)}}{2}$ |
| **Common Mode Gain** | $A_{cm} = 1 - \frac{R_4}{Z_1}$ |
| **Differential Mode Voltage** | $V_{dif} = V_{electrode(+)} - V_{electrode(-)}$ |
| **Differential Mode Gain** | $A_{dif} = -\left(\frac{1}{2} + \frac{R_4}{R_5} + \frac{2R_4}{Z_3} + \frac{R_4}{2Z_1}\right)$ |

Where the complex impedances $Z_1$ and $Z_3$ are defined in the frequency domain ($s$-domain) as:

| Name | Equation |
| :--- | :--- |
| **Impedance $Z_1$** | $Z_1(s) = R_1 + \frac{1}{sC_1}$ |
| **Impedance $Z_3$** | $Z_3(s) = R_3 + \frac{1}{sC_2}$ |

By substituting the values, it follows that the circuit raises the muscle voltage by around $1000$ times.

<p align="center">
    <img src="images/voltage_divider.png" />
</p>

- **Voltage Divider:** To reach a desired reference voltage, the following equation can be used:

| Name | Equation |
| :--- | :--- |
| **Reference Voltage** | $V_{out} = \left(5V\right)\left(\frac{R_{variable}}{R_{total}}\right)$ |

---

## Prototype

A single-channel prototype was implemented on a breadboard to validate the circuit's functionality during the testing phase.

<p align="center">
    <img src="images/prototype.png" />
</p>

---

## Software Used

To install the software, click on the name and you will be redirected to the download page. 

<table>
  <tr>
    <td align="center" valign="top" width="120" style="border: none;">
      <img src="images/arduino_logo.png" alt="Arduino Logo" width="80" height="80"><br>
      <strong><a href="https://www.arduino.cc/en/software/">Arduino IDE</a></strong><br>
      <font color="#666" size="2">v2.3.8</font>
    </td>
        <td align="center" valign="top" width="120" style="border: none;">
      <img src="images/kicad_logo.png" alt="KiCad Logo" width="80" height="80"><br>
      <strong><a href="https://www.kicad.org/download/">KiCad</a></strong><br>
      <font color="#666" size="2">v10.0.2</font>
    </td>
  </tr>
</table>