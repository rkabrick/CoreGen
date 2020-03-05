//
// _CoreGenLLVMCodegen_cpp_
//
// Copyright (C) 2017-2020 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/CoreGenCodegen/CoreGenLLVMCodegen.h"

CoreGenLLVMCodegen::CoreGenLLVMCodegen( CoreGenNode *T,
                                        CoreGenProj *P,
                                        CoreGenArchEntry *EN,
                                        std::string R,
                                        CoreGenErrno *E,
                                        std::string Ver )
  : Top(T), Proj(P), Entry(EN), LLVMRoot(R), Errno(E), Version(Ver){
}

CoreGenLLVMCodegen::~CoreGenLLVMCodegen(){
}

std::string CoreGenLLVMCodegen::UpperCase(std::string Str){
  std::locale loc;
  std::string Tmp;
  for( unsigned i=0; i<Str.length(); i++ ){
    Tmp += std::toupper(Str[i],loc);
  }
  return Tmp;
}

bool CoreGenLLVMCodegen::GenerateSubtargets(){
  for( unsigned i=0; i<Top->GetNumChild(); i++ ){
    if( Top->GetChild(i)->GetType() == CGISA )
      Subtargets.push_back(Top->GetChild(i)->GetName());
  }
  return true;
}

bool CoreGenLLVMCodegen::GenerateInstFormats(){
  for( unsigned i=0; i<Top->GetNumChild(); i++ ){
    if( Top->GetChild(i)->GetType() == CGInstF )
      Formats.push_back(static_cast<CoreGenInstFormat *>(Top->GetChild(i)));
  }
  return true;
}

bool CoreGenLLVMCodegen::GenerateRegClasses(){
  for( unsigned i=0; i<Top->GetNumChild(); i++ ){
    if( Top->GetChild(i)->GetType() == CGRegC )
      RegClasses.push_back(static_cast<CoreGenRegClass *>(Top->GetChild(i)));
  }
  return true;
}

bool CoreGenLLVMCodegen::GenerateInsts(){
  for( unsigned i=0; i<Top->GetNumChild(); i++ ){
    if( Top->GetChild(i)->GetType() == CGInst )
      Insts.push_back(static_cast<CoreGenInst *>(Top->GetChild(i)));
  }
  return true;
}

bool CoreGenLLVMCodegen::GeneratePInsts(){
  for( unsigned i=0; i<Top->GetNumChild(); i++ ){
    if( Top->GetChild(i)->GetType() == CGPInst )
      PInsts.push_back(static_cast<CoreGenPseudoInst *>(Top->GetChild(i)));
  }
  return true;
}

bool CoreGenLLVMCodegen::ExecuteBackend(){

  // Stage 1: generate subtargets
  if( !GenerateSubtargets() )
    return false;

  /// Stage 2: generate the vector of instruction formats
  if( !GenerateInstFormats() )
    return false;

  /// Stage 3: generate the vector of register classes
  if( !GenerateRegClasses() )
    return false;

  /// Stage 4: generate the vector instructions
  if( !GenerateInsts() )
    return false;

  /// Stage 5: generate the vector pseudo instructions
  if( !GeneratePInsts() )
    return false;

  return true;
}

// EOF
