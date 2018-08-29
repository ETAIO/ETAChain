/**
 *  @file
 *  @copyright defined in ETA/LICENSE.txt
 */

#include <ETAiolib/ETAio.hpp>

namespace asserter {
   struct assertdef {
      int8_t      condition;
      std::string message;

      ETALIB_SERIALIZE( assertdef, (condition)(message) )
   };
}
