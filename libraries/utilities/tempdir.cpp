/**
 *  @file
 *  @copyright defined in ETA/LICENSE.txt
 */

#include <ETAio/utilities/tempdir.hpp>

#include <cstdlib>

namespace ETAio { namespace utilities {

fc::path temp_directory_path()
{
   const char* ETA_tempdir = getenv("ETA_TEMPDIR");
   if( ETA_tempdir != nullptr )
      return fc::path( ETA_tempdir );
   return fc::temp_directory_path() / "ETA-tmp";
}

} } // ETAio::utilities
