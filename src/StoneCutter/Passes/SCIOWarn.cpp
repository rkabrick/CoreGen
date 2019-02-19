//
// _SCIOWarn_cpp_
//
// Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/StoneCutter/Passes/SCIOWarn.h"

SCIOWarn::SCIOWarn(Module *TM,
                     SCOpts *O,
                     SCMsg *M)
  : SCPass("IOWarn",TM,O,M) {
}

SCIOWarn::~SCIOWarn(){
}

void SCIOWarn::CheckPrototypeIO( Function &F, Instruction &I ){
  std::string ArgName;
  if( I.getOpcode() == Instruction::Load ){
    // load operation
    ArgName = I.getOperand(0)->getName().str();
  }else{
    // store operation
    ArgName = I.getOperand(1)->getName().str();
  }

  if( this->IsGlobal( ArgName ) ){
    // This arg is a global, check the function prototype list
    // for this arg and make sure that we're not doing I/O
    // where we don't need to.
    // We do this by walking the fucntion's prototype list
    for( auto &Arg : F.args() ){
      // First test the basic arg list
      if( ArgName == Arg.getName().str() ){
        return ;
      }
    }

    // Argument does not appear in the basic argument list
    // Test the register classes
    if( this->HasGlobalAttribute( ArgName, "regclass" ) ){
      // this variable is a register within a register class
      // retrieve its register class and look at the argument list for it
      std::string RegClass = this->GetGlobalAttribute(ArgName,"regclass");
      for( auto &Arg : F.args() ){
        if( RegClass == Arg.getName().str() ){
          return ;
        }
      }
    }

    this->PrintMsg( L_WARN, "Detected rogue I/O operation to register file for variable=" +
                            ArgName + " in instruction=" + F.getName().str() );
  }
}

void SCIOWarn::CheckIOLayout(){
  // walk all the functions
  for( auto &Func : TheModule->getFunctionList() ){
    // walk all the basic blocks
    for( auto &BB : Func.getBasicBlockList() ){
      // walk all the instructions
      for( auto &Inst : BB.getInstList() ){
        if( (Inst.getOpcode() == Instruction::Load) ||
            (Inst.getOpcode() == Instruction::Store) ){
          // Evaluate the load/store instruction
          CheckPrototypeIO( Func, Inst );
        }
      }
    }
  }
}

bool SCIOWarn::Execute(){
  if( !TheModule ){
    this->PrintMsg( L_ERROR, "LLVM IR Module is null" );
    return false;
  }

  CheckIOLayout();

  return true;
}

// EOF
