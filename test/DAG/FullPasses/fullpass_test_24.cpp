//
// _FULLPASS_TEST24_CPP_
//
// Copyright (C) 2017-2020 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
// 
//

#include <iostream>
#include "CoreGen/CoreGenBackend/CoreGenBackend.h"

std::string PROJNAME = "TEST24";
std::string PROJROOT = "./";
std::string ARCHROOT = "./";
std::string PROJYAML = "TEST24.yaml";

unsigned ITER=16;

int main( int argc, char **argv ){
  CoreGenBackend *CG = new CoreGenBackend(PROJNAME,
                                          PROJROOT,
                                          ARCHROOT,CGSocProj);
  if( !CG ){
    std::cout << "ERROR : FAILED TO CREATE COREGEN OBJECT" << std::endl;
    return -1;
  }

  // add an SoC
  CoreGenSoC *SoC = CG->InsertSoC( PROJNAME + ".soc" );

  // add an ISA
  CoreGenISA *ISA = CG->InsertISA( PROJNAME + ".isa" );

  // add a core
  CoreGenCore *Core = CG->InsertCore( PROJNAME + ".core", ISA );

  // add a register class
  CoreGenRegClass *RC = CG->InsertRegClass( PROJNAME + ".regclass" );
  CoreGenRegClass *RCC = CG->InsertRegClass( PROJNAME + ".csrregclass" );

  // insert the regclass into the core
  if( !Core->InsertRegClass( RC ) ){
    std::cout << "ERROR : FAILED TO INSERT REGCLASS INTO CORE:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }
  if( !Core->InsertRegClass( RCC ) ){
    std::cout << "ERROR : FAILED TO INSERT REGCLASS INTO CORE:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }


  // add a register
  CoreGenReg *Reg[ITER];
  for(unsigned i=0; i<ITER; i++ ){
    Reg[i] = CG->InsertReg( PROJNAME + "." + std::to_string(i) + ".reg", i, 64 );
    Reg[i]->SetPseudoName( "PSEUDOREG."+std::to_string(i) );
    Reg[i]->SetAttrs(CoreGenReg::CGRegRW);

    // insert the reg into the reg class
    if( !RC->InsertReg( Reg[i] ) ){
      std::cout << "ERROR : FAILED TO INSERT REG INTO REGCLASS:" <<
        CG->GetErrStr() << std::endl;
      delete CG;
      return -1;
    }
  }

  CoreGenReg *CSR = CG->InsertReg( PROJNAME + ".csr", 0, 64 );
  CSR->SetPseudoName( "CSR.0" );
  CSR->SetAttrs(CoreGenReg::CGRegRW|CoreGenReg::CGRegCSR);
  if( !RCC->InsertReg(CSR) ){
    std::cout << "ERROR : FAILED TO INSERT REG INTO REGCLASS:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  // insert the core in the SoC
  if( !SoC->InsertCore( Core ) ){
    std::cout << "ERROR : FAILED TO INSERT CORE INTO SOC:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  // create new instruction format
  CoreGenInstFormat *IF = CG->InsertInstFormat( PROJNAME + ".if", ISA );

  // insert some instruction fields
  //  RT     RA     RB   OPC
  // [31-24][23-16][15-8][7-0]
  if( !IF->InsertField( "opcode", 0, 7, CoreGenInstFormat::CGInstCode, true ) ){
    std::cout << "ERROR : FAILED TO INSERT opcode FIELD INTO FORMAT:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }
  if( !IF->InsertField( "RB", 8, 15, CoreGenInstFormat::CGInstReg, false ) ){
    std::cout << "ERROR : FAILED TO INSERT rb FIELD INTO FORMAT:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }
  if( !IF->InsertField( "RA", 16, 23, CoreGenInstFormat::CGInstReg, false ) ){
    std::cout << "ERROR : FAILED TO INSERT ra FIELD INTO FORMAT:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }
  if( !IF->InsertField( "RT", 24, 31, CoreGenInstFormat::CGInstReg, false ) ){
    std::cout << "ERROR : FAILED TO INSERT rt FIELD INTO FORMAT:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  if( !IF->InsertRegFieldMap("RB", RC) ){
    std::cout << "ERROR : FAILED TO SET rb FIELD REGISTER CLASS:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }
  if( !IF->InsertRegFieldMap("RA", RC) ){
    std::cout << "ERROR : FAILED TO SET ra FIELD REGISTER CLASS:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }
  if( !IF->InsertRegFieldMap("RT", RCC) ){
    std::cout << "ERROR : FAILED TO SET rt FIELD REGISTER CLASS:" <<
      CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  // write the yaml
  if( !CG->WriteIR( PROJYAML ) ){
    std::cout << "ERROR : FAILED TO WRITE YAML IR:" << CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  // build the dag
  if( !CG->BuildDAG() ){
    std::cout << "ERROR : FAILED TO BUILD THE DAG:" << CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  // init the pass manager
  if( !CG->InitPassMgr() ){
    std::cout << "ERROR : FAILED TO INIT THE PASS MANAGER:" << CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  // execute the passes
  if( !CG->ExecutePasses() ){
    std::cout << "ERROR : FAILED TO EXECUTE DAG PASSES:" << CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  // export the DOT file
  if( !CG->ExportDOT(PROJNAME+".dot") ){
    std::cout << "ERROR : FAILED TO EXPORT THE DOT OUTPUT" << CG->GetErrStr() << std::endl;
    delete CG;
    return -1;
  }

  delete CG;
  return 0;
}
