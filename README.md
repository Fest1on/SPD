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



# SDP — Simple DOS Program

Low-level TCP/UDP traffic generation tool written in pure C++.

**Strictly for authorized security research, penetration testing, and educational purposes.**

---
## Purpose

SDP serves as a minimal, transparent reference implementation for:

- Studying raw socket programming and protocol behavior
- Stress-testing network stacks, firewalls, and intrusion detection systems
- Validating rate-limiting, QoS policies, and anomaly detection mechanisms
- Simulating high-volume traffic in isolated lab environments
- Red-team tool development and defensive research
- Integrated OSINT module for passive target reconnaissance

---
## Legal Notice

- Use **exclusively** on systems and networks you own or have explicit written authorization to test.
- Unauthorized traffic generation or scanning against third-party hosts constitutes a criminal offense in most jurisdictions.
- The author provides this code as-is and assumes **zero liability** for misuse, damages, or legal consequences.

You are responsible for compliance with all applicable laws.

---
## Features

- Minimal footprint, no external dependencies beyond standard C++ and system sockets
- Multi-threaded TCP/UDP flood capabilities
- Randomized source port / payload options
- Built-in OSINT reconnaissance module (ip-api)
- Single binary — one tool for recon + stress testing
- Easily extensible

---
## Build

```bash
# Linux
g++ -O2 -pthread *.cpp -o sdp

# Windows (MinGW/MSVC)
g++ -O2 -lws2_32 -pthread *.cpp -o sdp.exe
