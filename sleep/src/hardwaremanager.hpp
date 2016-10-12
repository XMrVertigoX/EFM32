#ifndef HARDWAREMANAGER_HPP_
#define HARDWAREMANAGER_HPP_

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class HardwareManager : public Singleton<HardwareManager> {
    friend class Singleton<HardwareManager>;

  public:
    void init();
    void switchClocks();

  private:
    HardwareManager()  = default;
    ~HardwareManager() = default;
};

#endif /* HARDWAREMANAGER_HPP_ */
