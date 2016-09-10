#ifndef BLINKTASK_HPP_
#define BLINKTASK_HPP_

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/templates/singleton.hpp>
#include <xXx/utils/arduinotask.hpp>

class BlinkTask : public Singleton<BlinkTask>, public xXx::ArduinoTask {
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
