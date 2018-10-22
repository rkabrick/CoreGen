//
// _CoreGenVTP_cpp_
//
// Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/CoreGenBackend/CoreGenVTP.h"

CoreGenVTP::CoreGenVTP(std::string N, CoreGenErrno *E)
  : CoreGenNode(CGVTP,N,E) {
}

CoreGenVTP::~CoreGenVTP(){
}
