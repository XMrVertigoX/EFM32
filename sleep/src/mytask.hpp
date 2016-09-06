#ifndef MYTASK_HPP_
#define MYTASK_HPP_

#include <xXx/utils/arduinotask.hpp>
#include <xXx/utils/singleton.hpp>

class MyTask : public ArduinoTask, public Singleton<MyTask> {
    friend class Singleton<MyTask>;

   public:
    void setup();
    void loop();

   private:
    MyTask() = default;
    ~MyTask() = default;
};

#endif /* MYTASK_HPP_ */
