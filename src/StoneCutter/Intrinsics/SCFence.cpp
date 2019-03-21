//
// _SCFence_cpp_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/StoneCutter/Intrinsics/SCFence.h"

SCFence::SCFence() : SCIntrin(0,"FENCE") {
}

SCFence::SCFence(unsigned NI, std::string K) : SCIntrin(NI,K) {
}

SCFence::~SCFence(){
}

Value *SCFence::codegen(){
  return nullptr;
}

// EOF