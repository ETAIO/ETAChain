#pragma once

#include <ETAiolib/ETAio.hpp>

namespace ETAio {

   class sudo : public contract {
      public:
         sudo( account_name self ):contract(self){}

         void exec();

   };

} /// namespace ETAio
