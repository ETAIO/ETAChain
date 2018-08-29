/**
 *  @file
 *  @copyright defined in ETA/LICENSE.txt
 */
#pragma once

#include <ETAio/chain/types.hpp>
#include <ETAio/chain/contract_types.hpp>

namespace ETAio { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_ETAio_newaccount(apply_context&);
   void apply_ETAio_updateauth(apply_context&);
   void apply_ETAio_deleteauth(apply_context&);
   void apply_ETAio_linkauth(apply_context&);
   void apply_ETAio_unlinkauth(apply_context&);

   /*
   void apply_ETAio_postrecovery(apply_context&);
   void apply_ETAio_passrecovery(apply_context&);
   void apply_ETAio_vetorecovery(apply_context&);
   */

   void apply_ETAio_setcode(apply_context&);
   void apply_ETAio_setabi(apply_context&);

   void apply_ETAio_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace ETAio::chain
