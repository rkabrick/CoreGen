//
// _SCExtractZ_cpp_
//
// Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/StoneCutter/Intrinsics/SCExtractZ.h"

SCExtractZ::SCExtractZ() : SCIntrin(3,"EXTRACTZ") {
}

SCExtractZ::SCExtractZ(unsigned NI, std::string K) : SCIntrin(NI,K) {
}

SCExtractZ::~SCExtractZ(){
}

Value *SCExtractZ::codegen(){
  return nullptr;
}

// EOF
