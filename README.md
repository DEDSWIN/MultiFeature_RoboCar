# Multi-Functional Bluetooth Controlled Robo-Car Using Arduino UNO

This project showcases a Bluetooth-controlled Robo-Car model built using Arduino UNO and the HC-05 Bluetooth module. The Robo-Car is controlled via an Android app and includes key functionalities like crash avoidance, LED control, motor speed regulation, and obstacle distance measurement.

## Features
- **Bluetooth Control**: Control the car remotely using an Android app via Bluetooth (HC-05 module).
- **Crash Avoidance**: Detects obstacles and stops the car to prevent collisions.
- **Motor Speed Control**: Adjust the motor speed with three levels (low, medium, high) using the Android app.
- **LED Control**: Green LED turns on when the car is moving, and the red LED turns on when the car stops.
- **Obstacle Distance Measurement**: Continuously measures the distance to nearby obstacles and displays it in the app.

## Repository Contents
- **`code.ino`**: Arduino code for Bluetooth communication, motor control, and sensor input.
- **`project_report.pdf`**: Detailed project report covering design, implementation, and components.
- **`controller.aia`**: Android app controller file built using MIT App Inventor, for controlling the Robo-Car via Bluetooth.

## Demonstration
[![Watch the video](https://drive.google.com/uc?export=view&id=1ezU4QvT5Lc15uDKhd4Crv6d6d_9uq7k3)](https://cciitpatna-my.sharepoint.com/:v:/g/personal/2201cs92_harshvardhan_iitp_ac_in/EXDtFqT_glxHuRX2Dwxa0y8B--jgEfnO_B976JUtaVy1DQ?e=XVXOUN)

## Components Used
- Arduino UNO
- HC-05 Bluetooth Module
- Motor Driver (L298N)
- Ultrasonic Sensor (for obstacle detection)
- LEDs
- 12V LiPo Battery
- Android smartphone with custom-built app

## Conclusion
This hands-on project helped us gain experience in Arduino programming, app development, and real-world debugging. We learned how to integrate hardware and software components, adapt to unexpected challenges, and ensure smooth project execution.

Special thanks to **Prof. Jimson Mathew** for allowing us to work on such an exciting project.

## License
This project is licensed under the MIT License. See the LICENSE file for details.
