#include <ETAiolib/ETAio.hpp>
#include <ETAiolib/print.hpp>
using namespace ETAio;

class payloadless : public ETAio::contract {
  public:
      using contract::contract;

      void doit() {
         print( "Im a payloadless action" );
      }
};

ETAIO_ABI( payloadless, (doit) )
