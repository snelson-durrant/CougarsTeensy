#include "imu_pub.h"

void IMUPub::setup(rcl_node_t node) { 

  RCCHECK(rclc_publisher_init_best_effort(
      &publisher, &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(frost_interfaces, msg, IMU), "imu_data"));
}

void IMUPub::update(float roll, float pitch, float yaw, float accel_x, float accel_y, float accel_z) {

    msg.gyro_x = roll * 180.0 / PI; // convert roll to degrees
    msg.gyro_y = pitch * 180.0 / PI; // convert pitch to degrees
    msg.gyro_z = yaw * 180.0 / PI; // convert yaw to degrees

    msg.accel_x = accel_x;
    msg.accel_y = accel_y;
    msg.accel_z = accel_z;
}

void IMUPub::publish() {

  msg.header.stamp.nanosec = rmw_uros_epoch_nanos();
  RCSOFTCHECK(rcl_publish(&publisher, &msg, NULL));
}