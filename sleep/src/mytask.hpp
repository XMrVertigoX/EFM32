#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <FreeRTOS.h>
#include <task.h>

#include <xXx/utils/arduinotask.hpp>
#include <xXx/utils/singleton.hpp>

class MyTask : public Singleton<MyTask>, public ArduinoTask {
    friend class Singleton<MyTask>;

   public:
    void setup();
    void loop();

   private:
    MyTask() = default;
    ~MyTask() = default;

    TickType_t xLastWakeTime;
};

#endif /* MYTASK_HPP_ */
