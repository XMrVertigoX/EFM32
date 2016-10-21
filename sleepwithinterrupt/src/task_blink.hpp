#ifndef TASK_BLINK_HPP_
#define TASK_BLINK_HPP_

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <xXx/os/arduinotask.hpp>

using namespace xXx;

class Task_Blink : public ArduinoTask {
  public:
    Task_Blink();
    virtual ~Task_Blink();

    void setup();
    void loop();

  private:
    TickType_t _LastWakeTime;
};

#endif /* TASK_BLINK_HPP_ */
