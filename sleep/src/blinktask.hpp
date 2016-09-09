#ifndef BLINKTASK_HPP_
#define BLINKTASK_HPP_

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/arduinotask.hpp>
#include <xXx/utils/singleton.hpp>

class BlinkTask : public Singleton<BlinkTask>, public ArduinoTask {
    friend class Singleton<BlinkTask>;

   public:
    void setup();
    void loop();

   private:
    BlinkTask() = default;
    ~BlinkTask() = default;

    TickType_t xLastWakeTime = 0;
};

#endif /* BLINKTASK_HPP_ */
