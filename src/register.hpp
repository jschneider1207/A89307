#ifndef __A89307_REGISTER_H__
#define __A89307_REGISTER_H__

#include "private\defines.hpp"

namespace A89307
{
  class Register
  {
  public:
    A89307::RegisterId id;
    uint8_t eepromAddress;
    uint8_t shadowAddress;
    uint32_t value;
    uint8_t position;
    uint8_t size;
    uint32_t bitMask() const;
    static void fillAllRegsWithDefault(Register *allRegs);
    static void copyRegisterName(A89307::RegisterId id, char *name);

  private:
    static const Register DefaultRegs[RegisterId::Reg_No];
  };
}

#endif // __A89307_REGISTERS_H__
