#ifndef BLINKTASK_HPP_
#define BLINKTASK_HPP_

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <xXx/os/arduinotask.hpp>

using namespace xXx;

class BlinkTask : public ArduinoTask {
  public:
    BlinkTask(uint16_t stack, UBaseType_t priority);
    virtual ~BlinkTask();

    void setup();
    void loop();

  private:
    TickType_t _LastWakeTime;
};

#endif /* BLINKTASK_HPP_ */
