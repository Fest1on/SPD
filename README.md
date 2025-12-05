<!-- Red ASCII Logo -->
<pre>
<span style="color:red">
 /$$$$$$  /$$$$$$$  /$$$$$$$
 /$$__  $$| $$__  $$| $$__  $$
| $$  \__/| $$  \ $$| $$  \ $$
|  $$$$$$ | $$  | $$| $$$$$$$/
 \____  $$| $$  | $$| $$____/
 /$$  \ $$| $$  | $$| $$
|  $$$$$$/| $$$$$$$/| $$
 \______/ |_______/ |__/
</span>
</pre>



# SDP – Simple DOS Program
**Educational network load-simulation tool written in C++**

⚠️ **FOR LEGAL, ETHICAL, AND EDUCATIONAL USE ONLY**

SDP is a lightweight educational project that demonstrates how network traffic generation works at a low level.  
It is intended **only for learning**, building defensive tools, and testing your own hardware or isolated lab environments.

---

## 🎯 Purpose
SDP is designed for:

- Learning the basics of socket programming and network protocols  
- Investigating how systems behave under increased traffic load  
- Building and testing defensive techniques (rate limiting, anomaly detection, firewall rules)  
- Simulating network activity in controlled, private lab environments  
- Experimenting with packet-handling logic in a safe way

> **SDP is not an attack tool.**  
> It is a teaching and research project focused on transparency and defensive analysis.

---

## ⚖️ Legal & Ethical Notice

By using this software, you agree that:

- You may run SDP **only on networks and devices that you own** or where you have **explicit written permission**.  
- Generating traffic toward systems without authorization is illegal in most countries worldwide.  
- The author assumes **no responsibility** for any misuse, damage, or violations of law.  

SDP exists to **help people understand networks and improve security**, not to harm others.

---

## ✨ Features

- Clean and minimalistic C++ code — great for educational purposes  
- Cross-platform (Linux / Windows)  
- No heavy dependencies  
- Very easy to modify, extend, or integrate into learning environments  
- Useful example for courses related to networks, systems, and cybersecurity fundamentals  

---

## 📦 Build & Run (in a safe, controlled environment)

```bash
# Example compilation command
g++ SPD.cpp start_dos.cpp wifi_scanner.cpp IP_info.cpp -o sdp
