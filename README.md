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

<img src="https://drive.google.com/uc?export=view&id=1b1D1LkOerLarXumQ3n4ixMCyxNUzzZ0J" width="400px" />

Click [here](https://drive.google.com/file/d/1SEgj6lMiopXzHhbrF1fHBNEulSB35EfG/view?usp=sharing) to watch the full video.


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
