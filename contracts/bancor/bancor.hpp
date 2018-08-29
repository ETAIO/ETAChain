/**
 *  @file
 *  @copyright defined in ETA/LICENSE.txt
 */
#pragma once

#include <ETAiolib/ETAio.hpp>
#include <ETAiolib/token.hpp>
#include <ETAiolib/reflect.hpp>
#include <ETAiolib/generic_currency.hpp>

#include <bancor/converter.hpp>
#include <currency/currency.hpp>

namespace bancor {
   typedef ETAio::generic_currency< ETAio::token<N(other),S(4,OTHER)> >  other_currency;
   typedef ETAio::generic_currency< ETAio::token<N(bancor),S(4,RELAY)> > relay_currency;
   typedef ETAio::generic_currency< ETAio::token<N(currency),S(4,CUR)> > cur_currency;

   typedef converter<relay_currency, other_currency, cur_currency > example_converter;
} /// bancor

