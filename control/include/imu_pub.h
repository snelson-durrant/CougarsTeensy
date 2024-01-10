#ifndef IMU_PUB
#define IMU_PUB

#include "publisher.h"
#include <Adafruit_BNO08x.h>
#include <Wire.h>
#include <frost_interfaces/msg/imu.h>

class IMUPub : Publisher {

public:
  void setup(rcl_node_t node);
  void imu_setup();
  void imu_update();
  void publish();
  using Publisher::destroy;

private:
  frost_interfaces__msg__IMU msg;
};

#endif // IMU_PUB