#ifndef __A89307_REGISTER_H__
#define __A89307_REGISTER_H__

#include "defines.hpp"

namespace A89307
{
  class Register
  {
  public:
    A89307::RegisterId id;
    uint8_t addr;
    int32_t value;
    uint8_t position;
    uint8_t size;
    uint8_t shadowAddr() const;
    uint32_t bitMask() const;
    static void fillAllRegsWithDefault(Register *allRegs);
    static uint32_t copyRegisterName(A89307::RegisterId id, char *name);

  private:
    static const Register DefaultRegs[RegisterId::Reg_No];
  };
}

#endif // __A89307_REGISTERS_H__
