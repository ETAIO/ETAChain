/**
 *  @file
 *  @copyright defined in ETA/LICENSE.txt
 */

#include <ETAio/chain/chain_id_type.hpp>
#include <ETAio/chain/exceptions.hpp>

namespace ETAio { namespace chain {

   void chain_id_type::reflector_verify()const {
      ETA_ASSERT( *reinterpret_cast<const fc::sha256*>(this) != fc::sha256(), chain_id_type_exception, "chain_id_type cannot be zero" );
   }

} }  // namespace ETAio::chain

namespace fc {

   void to_variant(const ETAio::chain::chain_id_type& cid, fc::variant& v) {
      to_variant( static_cast<const fc::sha256&>(cid), v);
   }

   void from_variant(const fc::variant& v, ETAio::chain::chain_id_type& cid) {
      from_variant( v, static_cast<fc::sha256&>(cid) );
   }

} // fc
