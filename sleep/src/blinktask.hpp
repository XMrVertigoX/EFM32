#ifndef BLINKTASK_HPP_
#define BLINKTASK_HPP_

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <xXx/templates/singleton.hpp>
#include <xXx/utils/arduinotask.hpp>

using namespace xXx;

class BlinkTask : public ArduinoTask {

  public:
    BlinkTask();
    ~BlinkTask();

    void setup();
    void loop();

  private:
    TickType_t _LastWakeTime;
};

#endif /* BLINKTASK_HPP_ */
