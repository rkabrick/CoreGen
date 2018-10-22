//
// _YAML_READER_MISSINGDATA_15_CPP_
//
// Copyright (C) 2018-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// CoreGen can not be copied and/or distributed without the
// express permission of Tactical Computing Laboratories, LLC
//

#include <iostream>
#include "CoreGen/CoreGenBackend/CoreGenBackend.h"

std::string PROJNAME = "TEST15";
std::string PROJROOT = "./";
std::string ARCHROOT = "./";
std::string PROJYAML = "../TEST15.yaml";

int main( int argc, char **argv ){
  CoreGenBackend *CG = new CoreGenBackend(PROJNAME,
                                          PROJROOT,
                                          ARCHROOT);
  if( !CG ){
    std::cout << "ERROR : FAILED TO CREATE COREGEN OBJECT" << std::endl;
    return -15;
  }

  if( !CG->ReadIR( PROJYAML ) ){
    std::cout << "ERROR : FAILED TO READ YAML IR: " << CG->GetErrStr() << std::endl;
    delete CG;
    return -15;
  }

  delete CG;
  return 0;
}
