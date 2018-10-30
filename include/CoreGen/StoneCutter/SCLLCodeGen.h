//
// _SCLLCodeGen_h_
//
// Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#ifndef _STONECUTTER_SCLLCODEGEN_H_
#define _STONECUTTER_SCLLCODEGEN_H_

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "CoreGen/StoneCutter/SCParser.h"
#include "CoreGen/StoneCutter/SCMsg.h"

using namespace llvm;

class SCLLCodeGen{
private:
  SCParser *Parser;                           ///< SC Parser object
  SCMsg *Msgs;                                ///< SC Messages object
  std::string OutputFile;                     ///< Output file

  // private functions

public:

  /// Default constructor
  SCLLCodeGen(SCParser *, SCMsg *, std::string);

  /// Default desctrutor
  ~SCLLCodeGen();

  /// Generate the LLVM IR output
  bool GenerateLL();
};

#endif

// EOF
