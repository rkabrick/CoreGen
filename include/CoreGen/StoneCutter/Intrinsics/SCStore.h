//
// _SCStore_h_
//
// Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#ifndef _STONECUTTER_SCINTRIN_SCSTORE_H_
#define _STONECUTTER_SCINTRIN_SCSTORE_H_

#include "CoreGen/StoneCutter/SCIntrin.h"

class SCStore : public SCIntrin {
private:
public:
  /// Default cosntructor
  SCStore();

  /// Overloaded Constructor
  SCStore( unsigned NI, std::string K );

  /// Default destructor
  ~SCStore();

  /// Execute the codegen
  virtual Value *codegen();
};

#endif

// EOF
