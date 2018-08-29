/**
 *  @file
 *  @copyright defined in ETA/LICENSE.txt
 */

#include <ETAiolib/ETAio.hpp>

namespace ETAio {

   class noop: public contract {
      public:
         noop( account_name self ): contract( self ) { }
         void anyaction( account_name from,
                         const std::string& /*type*/,
                         const std::string& /*data*/ )
         {
            require_auth( from );
         }
   };

   ETAIO_ABI( noop, ( anyaction ) )

} /// ETAio
