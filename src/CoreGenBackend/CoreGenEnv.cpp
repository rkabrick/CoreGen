//
// _CoreGenEnv_cpp_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/CoreGenBackend/CoreGenEnv.h"

CoreGenEnv::CoreGenEnv(CoreGenErrno *E)
  : Errno(E){
}

CoreGenEnv::CoreGenEnv(std::string A,
                       CoreGenErrno *E)
  : Errno(E), ArchRoot(A){
  if( ArchRoot.length() == 0 ){
    Errno->SetError(CGERR_WARN, "CoreGenEnv found a null archive root path");
  }
}

CoreGenEnv::~CoreGenEnv(){
}

// EOF
