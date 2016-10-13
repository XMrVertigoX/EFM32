#ifndef TASK_TOGGLE_HPP_
#define TASK_TOGGLE_HPP_

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <xXx/os/arduinotask.hpp>

using namespace xXx;

class Task_Toggle : public ArduinoTask {
  public:
    Task_Toggle(SemaphoreHandle_t &semaphore);
    virtual ~Task_Toggle();

    void setup();
    void loop();

  private:
    SemaphoreHandle_t _semaphore;
};

#endif /* TASK_TOGGLE_HPP_ */
