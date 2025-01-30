# 🌱 Sensorial Node - STM32WL55JC

**Code for creating and developing a sensorial node for the STM32WL55JC board.**

The node is responsible for acquiring data relating to **soil humidity**, detected by:
- **Three analog sensors**: [SEN0308](https://wiki.dfrobot.com/Waterproof_Capacitive_Soil_Moisture_Sensor_SKU_SEN0308), [SOILWATCH](https://pino-tech.eu/wp-content/uploads/2017/08/SoilWatch10.pdf), [Teros10](https://metergroup.com/it/products/teros-10/)
- **One digital sensor**: [Teros12](https://metergroup.com/it/products/teros-12/)
<br><br>
## 📡 LoRaWAN Communication
This project is based on the **LoRaWAN End Node template** to communicate with a LoRaWAN gateway. After configuring the communication parameters, the node periodically sends the acquired sensor data.<br><br>
👉 *See the configuration variables inside the project for detailed settings.*
<br><br>
## 📊 Sensory Data Acquisition Methods

Data acquisition is handled in the **`EnvSensors_Read()`** function in **`sys_sensor.c`**). Here’s how it works:
- The **step** variable regulates the acquisition cycle.
- Each LoRaWAN sampling period includes **5 consecutive acquisitions per sensor**.
- At each new **step** value, the ADC is initialized via **`MX_ADC_Init()`** (found in **`adc.c`** file), which reads data from the respective sensor’s port.
- The sampled data is stored in the corresponding **`sensor_data`** structure and later used to construct the payload sent to the cloud.<br><br>
👉 *It is possible to consult the pins that were used to connect the analog sensors in the sys_sensor.c file.*
<br><br>
## ⚙️ How to Properly Run the Project

1. **Download** the project and **import it into your IDE**.
2. **Modify** the LoRaWAN parameters to match your reference cloud application.
3. **Flash** the code onto the STM32WL55JC board.
4. **Verify** the correct operation.

🔔 **Note:** This repository has undergone various modifications and sensor experiments. The latest commits focus on integrating the **[SDI-12 library](https://github.com/DaddaRev/SDI-12)**. Check the commit history to find the most suitable version for your needs.


---
## Author
📌 [Davide Reverberi](https://github.com/DaddaRev)

📝 **Repository:** [SDI-12 Library](https://github.com/DaddaRev/SDI-12) *(for Teros12 integration)*

---
✨ *Feel free to contribute and improve the project!*

