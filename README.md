<div align="center">

### BCA188 · LABORATORY ACTIVITY 09

# ESP32 Wi-Fi Manager

### Wi-Fi Configuration Without Reprogramming
### Rebecca Lyn R. Antonio
Student ID: 2024-2015

**ESP32 · Arduino IDE · WiFiManager · Laboratory Documentation**

</div>

## Overview

This activity uses the WiFiManager library to connect an ESP32 to Wi-Fi without editing and uploading the sketch for each network. When no saved network connects, the board starts a configuration access point and web portal. After credentials are entered, WiFiManager saves them for later connections.

## Materials

- ESP32 board and USB cable
- Arduino IDE with ESP32 board support
- WiFiManager library by tzapu
- Phone and 2.4 GHz Wi-Fi access

## Setup and use

1. Install ESP32 board support and WiFiManager in Arduino IDE.
2. Select the correct ESP32 board and serial port.
3. Set the access point name in the sketch and add `wm.setConfigPortalTimeout(180);` before `wm.autoConnect(...)`.
4. Upload the sketch. If no saved network connects, join the ESP32 access point on your phone and open `192.168.4.1`.
5. Select a Wi-Fi network and enter its password. The connected IP address appears in the Serial Monitor.

The 180-second portal timeout causes the sketch to restart if setup is not completed in time. Holding BOOT for three seconds clears saved Wi-Fi settings in this sketch.

## Project Information

| Item | Details |
| --- | --- |
| Student name | **Rebecca Lyn R. Antonio** |
| Assigned number | **2024-2015** |
| Board | DOIT ESP32 DEVKIT V1 |
| Development environment | Arduino IDE 2.3.10 |
| Library | WiFiManager by tzapu |
| Serial Monitor | 115200 baud |
| Configuration portal | `192.168.4.1` |
| Access point name used | `BCA188-ESP32-2024-2015` (renamed during testing to `BCA188-ESP32-2024-2015-TESTING`)

## Evidence

### 1. Wi-FiManager Setup Portal
The ESP32 setup portal is open at `192.168.4.1` and displays the access point name `BCA188-ESP32-2024-2015`.
<div align="center">
<img width="828" height="1792" alt="9e28a41f-f761-48f5-8c0a-486888caa675" src="https://github.com/user-attachments/assets/a4627727-9b39-4ee8-8e87-64f701e1582d" />

  *Figure 1. WiFiManager portal on the phone*

</div>

### 2. Successful Wifi Connection
The portal lists nearby Wi-Fi networks and provides fields to enter the selected network name and password.
<div align="center">
<img width="1917" height="1018" alt="Screenshot 2026-11-09 105240" src="https://github.com/user-attachments/assets/f168b927-d863-4238-8d9c-7c65b781383b" />

*Figure 2. Available networks and credential form*

</div>

## Task 1
### Wrong Password
The Serial Monitor reports that connecting to the newly entered access point failed.
<div align="center">
<img width="1917" height="1020" alt="Screenshot 2026-11-09 110008" src="https://github.com/user-attachments/assets/3fd31c60-5335-4ae7-83b1-24956c02f992" />

*Figure 3. Wrong-password connection attempt*

</div>

## Task 2
### Reset Setting
After saved Wi-Fi settings are cleared, the Serial Monitor shows the ESP32 starting its setup access point at `192.168.4.1`.
<div align="center">
<img width="1917" height="1017" alt="Screenshot 2026-11-09 110637" src="https://github.com/user-attachments/assets/fc7e547e-c1c0-4b97-addf-5af7a7087ace" />

*Figure 4. Reset settings and configuration portal startup*

</div>

## Task 3
### Change the Name
The portal header shows the updated access point name `BCA188-ESP32-2024-2015-TESTING`.
<div align="center">
<img width="828" height="1792" alt="8b25a432-de9d-4b2d-9ba5-3dfadc9cc56d" src="https://github.com/user-attachments/assets/145737f2-e03c-4849-9cff-dfb8b0a38f5e" />

*Figure 5. Portal after changing the access point name*

</div>

The phone detects the ESP32 access point under its updated name
<div align="center">
<img width="1917" height="1020" alt="Screenshot 2026-11-09 112504" src="https://github.com/user-attachments/assets/62c285de-ad68-4d14-adff-e5cb723c05da" />

*Figure 6. Renamed access point in phone Wi-Fi settings*

</div>

## Task 4

### Different Network
The Serial Monitor shows another successful connection, with IP address `10.11.33.44`.
<div align="center">
<img width="1917" height="1017" alt="Screenshot 2026-11-09 111738" src="https://github.com/user-attachments/assets/3367eec8-ab0f-453e-9cab-b307f537c8f4" />

*Figure 7. Successful connection on another network*

</div>

## Results and Observation

Task | Result observed |
| --- | --- |
| Wrong password | The Serial Monitor reports `Connect to new AP Failed`; the board does not connect to that network. |
| Reset settings | After clearing saved Wi-Fi, the board starts the configuration access point at `192.168.4.1`. The phone reaches the WiFiManager portal. |
| Change the name | The access point appears first as `BCA188-ESP32-2024-2015` and later as `BCA188-ESP32-2024-2015-TESTING` in the portal and phone Wi-Fi list. |
| Different network | The portal lists available networks, and the ESP32 subsequently connected successfully with IP `192.168.160.156`; another successful connection shows `10.11.33.44`.

## Why it connects to another network without a code change
WiFiManager saves the Wi-Fi credentials entered through its configuration portal in the ESP32, so the board can use those saved credentials on later boots without changing or uploading the sketch.

## Conclusion
In this activity, I learned how to use WiFiManager to connect my ESP32 to Wi-Fi through a phone setup page. I also tested changing the access point name and connecting to different networks. This made it easier to change Wi-Fi networks without editing and uploading the code again.




















