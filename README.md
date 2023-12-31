# Automated + Bluetooth Controlled Advanced Vacuum Cleaner Robot

The Automated + Bluetooth Controlled Advanced Vacuum Cleaner Robot is an advanced robotic system designed to autonomously navigate and perform efficient vacuuming tasks. It incorporates various components and technologies, including Arduino IDE, C++ programming, and the following hardware components:

## Model Demonstration
- **Robot Controls:** https://user-images.githubusercontent.com/91270314/182155628-186eaac0-3d37-453c-880e-a5f46e72c51e.mp4
- **Floor Detection:** https://user-images.githubusercontent.com/91270314/182156538-22d26949-394a-494e-aba2-0008b6ddee99.mp4
- **Images:** https://drive.google.com/drive/folders/14bqA24ZzzlCEzcGs8VBObAG6jPHldgs9?usp=share_link
- 
## Components Used
- **Arduino UNO R3:** The microcontroller board used as the brain of the robot.
- **Ultrasonic Sensor:** Used for obstacle detection.
- **L293d Motor Driver:** Controls the DC geared motors.
- **HC05 Bluetooth Module:** Enables wireless communication with the robot.
- **DC Geared Motor:** Provides motion for the robot.
- **Infrared Sensor:** Detects objects or walls in close proximity.
- **Sucker Fan:** Collects dust and debris effectively.
- **LM7805 Voltage Regulator:** Provides stable power supply.
- **Lithium-ion Battery:** Powers the robot.
- **Servo Motor:** Controls additional mechanisms or accessories.
- **Jumper Wires:** Establishes electrical connections.
- **Ballpoint Wheel:** Enables smooth movement.

## Features
- **Autonomous Navigation:** Utilizes ultrasonic and infrared sensors for obstacle detection and avoidance.
- **Bluetooth Control:** Allows wireless control from a Bluetooth-enabled device.
- **Efficient Vacuuming:** Equipped with a powerful sucker fan for effective cleaning.

## Installation
1. **Assemble the Robot:** Construct the robot chassis and place the components accordingly.
2. **Upload the Arduino Code:** Use Arduino IDE to upload the provided code (`vacuum_cleaner_robot_code.ino`) to the Arduino UNO R3.
3. **Power Management:** Connect the lithium-ion battery to the LM7805 voltage regulator to safeguard the HC05 bluetooth module.
4. **Bluetooth Connection:** Pair your device with the HC05 Bluetooth module.
5. **Control the Robot:** Use a dedicated mobile app or Bluetooth control app to control the robot's movement and cleaning functions.

## Usage
1. Ensure the robot is charged and all components are functioning correctly.
2. Connect your device to the HC05 Bluetooth module.
3. Open the dedicated mobile app or compatible Bluetooth control app.
4. Establish a Bluetooth connection with the robot.
5. Use the app to control the robot's movement, start/stop the vacuum function, and monitor cleaning progress.

## Contributing
Contributions are welcome! Fork the repository, create a new branch, make desired changes, test thoroughly, and submit a pull request.

## Contact
For any questions or inquiries, please contact Vimal Grace M at vimalgracerobotics@gmail.com.
