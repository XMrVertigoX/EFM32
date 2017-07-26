#ifndef BLINKTASK_HPP_
#define BLINKTASK_HPP_

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <xXx/os/simpletask.hpp>

using namespace xXx;

class BlinkTask : public SimpleTask {
   public:
    BlinkTask();
    virtual ~BlinkTask();

    void setup();
    void loop();

   private:
    TickType_t _LastWakeTime;
};

#endif /* BLINKTASK_HPP_ */
