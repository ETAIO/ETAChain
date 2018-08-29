#include <ETAiolib/ETAio.hpp>
using namespace ETAio;

class hello : public ETAio::contract {
  public:
      using contract::contract;

      /// @abi action 
      void hi( account_name user ) {
         print( "Hello, ", name{user} );
      }
};

ETAIO_ABI( hello, (hi) )
