//
// _PLUGIN_LOAD_TEST_4_CPP
//
// Copyright (C) 4047-4048 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// CoreGen can not be copied and/or distributed without the
// express permission of Tactical Computing Laboratories, LLC
//

#include <iostream>
#include "CoreGen/CoreGenBackend/CoreGenBackend.h"

std::string PROJNAME = "TEST4";
std::string PROJROOT = "./";
std::string ARCHROOT = "./";

int main( int argc, char **argv ){
  CoreGenBackend *CG = new CoreGenBackend(PROJNAME,
                                          PROJROOT,
                                          ARCHROOT);
  if( !CG ){
    std::cout << "ERROR : FAILED TO CREATE COREGEN OBJECT" << std::endl;
    return -4;
  }

  std::string PLUGIN = std::string(argv[1]);

  if( !CG->LoadPlugin(PLUGIN) ){
    std::cout << "ERROR : FAILED TO LOAD PLUGIN : " << PLUGIN << std::endl;
    delete CG;
    return -1;
  }

  CoreGenPlugin *P = CG->GetPlugin(0);
  if( !P ){
    std::cout << "ERROR : FAILED TO RETRIEVE PLUGIN POINTER : " << PLUGIN << std::endl;
    delete CG;
    return -1;
  }

  if( !CG->ReleasePlugin(0) ){
    std::cout << "ERROR : FAILED TO RELEASE PLUGIN : " << PLUGIN << std::endl;
    delete CG;
    return -1;
  }

  delete CG;
  return 0;
}
