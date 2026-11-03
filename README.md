# BCA188-Laboratory9

# BCA188 Lab: WiFiManager on ESP32

**Name:** Marie June Lomo
**Assigned number:** 2024-1006

## Results

| Task | What to do | What you observe |
|---|---|---|
| 1. Wrong password | Enter a wrong password on the setup page. | The setup page said it was saving the credentials and trying to connect. The Serial Monitor showed "Connect to new AP Failed", the board did not connect, and the setup network came back so I could try again. |
| 2. Reset settings | Hold the BOOT button for 3 seconds while the board is running. | The Serial Monitor showed "Resetting Wi-Fi settings...", the board restarted with "No wifi saved", and the setup network BCA188-ESP32-2024-1006 appeared again. |
| 3. Change the name | Change the network name, upload, and check your phone's Wi-Fi list. | After uploading, my phone's Wi-Fi list showed the new setup network BCA188-ESP32-2024-1006-TEST. |
| 4. Different network | Reset the board, then connect to your phone hotspot. | The board connected to my phone hotspot and got a new IP address, 172.20.10.2, different from the home network IP 192.168.254.143. |

## Screenshots

Setup page on my phone:

<img width="828" height="1792" alt="dba31ff0-0dc1-44da-a522-f87eb735deb7 (1)" src="https://github.com/user-attachments/assets/d3d2e49e-6780-42e4-b003-fd67a08288f0" />

Serial Monitor showing the connected state with an IP address:

<img width="1920" height="1080" alt="6af14918-ea90-4621-a9e2-28d3d504ab28" src="https://github.com/user-attachments/assets/ec373021-58a2-49f8-a6c8-71930ca676ce" />

## Why did the board connect to a different network without a code change?

WiFiManager saves the Wi-Fi name and password in the ESP32's memory and lets me enter new ones through the setup page, so the network is stored data and not part of the code.
