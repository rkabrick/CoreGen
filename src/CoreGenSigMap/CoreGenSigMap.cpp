//
// _CoreGenSigMap_cpp_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include <iostream>
#include "CoreGen/CoreGenSigMap/CoreGenSigMap.h"

CoreGenSigMap::CoreGenSigMap() : TmpIdx(0) {
}

CoreGenSigMap::~CoreGenSigMap(){
  Signals.clear();
}

bool CoreGenSigMap::CheckValidNode(const YAML::Node Node,
                                   std::string Token){
  if( !Node[Token] || Node[Token].IsNull() )
    return false;
  return true;
}

bool CoreGenSigMap::InsertSignal( SCSig *S ){
  if( S == nullptr )
    return false;

  Signals.push_back( S );
  return true;
}

SCSig *CoreGenSigMap::GetSignal( unsigned Idx ){
  if( Idx > (Signals.size()-1) )
    return nullptr;

  return Signals[Idx];
}

unsigned CoreGenSigMap::GetMaxSignalWidth( unsigned Idx ){
  if( Idx > (Signals.size()-1) ){
    return 0;
  }

  SigType Type = Signals[Idx]->GetType();
  unsigned Max = Signals[Idx]->GetWidth();

  for( unsigned i=0; i<Signals.size(); i++ ){
    if( Signals[i]->GetType() == Type ){
      if( Signals[i]->GetWidth() > Max )
        Max = Signals[i]->GetWidth();
    }
  }

  return Max;
}

unsigned CoreGenSigMap::GetMinSignalWidth( unsigned Idx ){
  if( Idx > (Signals.size()-1) ){
    return 0;
  }

  SigType Type = Signals[Idx]->GetType();
  unsigned Min = Signals[Idx]->GetWidth();

  for( unsigned i=0; i<Signals.size(); i++ ){
    if( Signals[i]->GetType() == Type ){
      if( Signals[i]->GetWidth() < Min )
        Min = Signals[i]->GetWidth();
    }
  }

  return Min;
}

bool CoreGenSigMap::WriteSigMap( std::string File ){
  if( File.length() == 0 )
    return false;
  if( Signals.size() == 0 )
    return false;

  // open the file
  std::ofstream OutYaml(File.c_str());

  // open the yaml emitter
  YAML::Emitter out(OutYaml);

  // open the yaml stream
  out << YAML::BeginMap;

  // write the opt-level signals
  if( !WriteTopLevelSignals(&out) ){
    OutYaml.close();
    return false;
  }

  // write the individual instruction signals
  if( !WriteInstSignals(&out) ){
    OutYaml.close();
    return false;
  }

  // write all the tmp reg info
  if( !WriteTempRegs(&out) ){
    OutYaml.close();
    return false;
  }

  // end the YAML stream
  out << YAML::EndMap;

  // close the file
  OutYaml.close();

  return true;
}

FusedOpType CoreGenSigMap::StrToFusedOpType( std::string Fop ){
  if( Fop == "FOP_UNK" ){
    return FOP_UNK;
  }else if( Fop == "FOP_SEXT" ){
    return FOP_SEXT;
  }else if( Fop == "FOP_ZEXT" ){
    return FOP_ZEXT;
  }else if( Fop == "FOP_NOT" ){
    return FOP_NOT;
  }else if( Fop == "FOP_NEG" ){
    return FOP_NEG;
  }
  return FOP_UNK;
}

SigType CoreGenSigMap::StrToSigType( std::string Sig ){
  if( Sig == "SIGUNK" ){
    return SIGUNK;
  }else if( Sig == "SIGINSTF" ){
    return SIGINSTF;
  }else if( Sig == "ALU_ADD" ){
    return ALU_ADD;
  }else if( Sig == "ALU_SUB" ){
    return ALU_SUB;
  }else if( Sig == "ALU_SLL" ){
    return ALU_SLL;
  }else if( Sig == "ALU_SRL" ){
    return ALU_SRL;
  }else if( Sig == "ALU_SRA" ){
    return ALU_SRA;
  }else if( Sig == "ALU_AND" ){
    return ALU_AND;
  }else if( Sig == "ALU_OR" ){
    return ALU_OR;
  }else if( Sig == "ALU_XOR" ){
    return ALU_XOR;
  }else if( Sig == "ALU_SLT" ){
    return ALU_SLT;
  }else if( Sig == "ALU_SLTU" ){
    return ALU_SLTU;
  }else if( Sig == "ALU_COPY" ){
    return ALU_COPY;
  }else if( Sig == "ALU_MUL" ){
    return ALU_MUL;
  }else if( Sig == "ALU_DIV" ){
    return ALU_DIV;
  }else if( Sig == "ALU_REM" ){
    return ALU_REM;
  }else if( Sig == "ALU_FADD" ){
    return ALU_FADD;
  }else if( Sig == "ALU_FSUB" ){
    return ALU_FSUB;
  }else if( Sig == "ALU_FMUL" ){
    return ALU_FMUL;
  }else if( Sig == "ALU_FDIV" ){
    return ALU_FDIV;
  }else if( Sig == "ALU_FREM" ){
    return ALU_FREM;
  }else if( Sig == "PC_INCR" ){
    return PC_INCR;
  }else if( Sig == "PC_BRJMP" ){
    return PC_BRJMP;
  }else if( Sig == "PC_JALR" ){
    return PC_JALR;
  }else if( Sig == "BR_N" ){
    return BR_N;
  }else if( Sig == "BR_NE" ){
    return BR_NE;
  }else if( Sig == "BR_EQ" ){
    return BR_EQ;
  }else if( Sig == "BR_GE" ){
    return BR_GE;
  }else if( Sig == "BR_GEU" ){
    return BR_GEU;
  }else if( Sig == "BR_LT" ){
    return BR_LT;
  }else if( Sig == "BR_LTU" ){
    return BR_LTU;
  }else if( Sig == "BR_J" ){
    return BR_J;
  }else if( Sig == "BR_JR" ){
    return BR_JR;
  }else if( Sig == "MUX_NE" ){
    return MUX_NE;
  }else if( Sig == "MUX_EQ" ){
    return MUX_EQ;
  }else if( Sig == "MUX_GT" ){
    return MUX_GT;
  }else if( Sig == "MUX_GTU" ){
    return MUX_GTU;
  }else if( Sig == "MUX_GE" ){
    return MUX_GE;
  }else if( Sig == "MUX_GEU" ){
    return MUX_GEU;
  }else if( Sig == "MUX_LT" ){
    return MUX_LT;
  }else if( Sig == "MUX_LTU" ){
    return MUX_LTU;
  }else if( Sig == "MUX_LE" ){
    return MUX_LE;
  }else if( Sig == "MUX_LEU" ){
    return MUX_LEU;
  }else if( Sig == "MUX" ){
    return MUX;
  }else if( Sig == "REG_READ" ){
    return REG_READ;
  }else if( Sig == "REG_WRITE" ){
    return REG_WRITE;
  }else if( Sig == "AREG_READ" ){
    return AREG_READ;
  }else if( Sig == "AREG_WRITE" ){
    return AREG_WRITE;
  }else if( Sig == "MEM_READ" ){
    return MEM_READ;
  }else if( Sig == "MEM_WRITE" ){
    return MEM_WRITE;
  }else if( Sig == "FENCE" ){
    return FENCE;
  }
  return SIGUNK;
}

bool CoreGenSigMap::ReadTopLevelSignals(const YAML::Node& TopNodes){
  if( TopNodes.size() == 0 )
    return false;

  for( unsigned i=0; i<TopNodes.size(); i++ ){
    const YAML::Node& Node = TopNodes[i];
    if( !CheckValidNode(Node,"Signal") ){
      return false;
    }
    std::string LSig = Node["Signal"].as<std::string>();
    if( LSig.length() == 0 )
      return false;
    TopSigs.push_back(StrToSigType(LSig));
  }
  return true;
}

bool CoreGenSigMap::ReadInstSignals(const YAML::Node& InstNodes){
  if( InstNodes.size() == 0 )
    return false;

  for( unsigned i=0; i<InstNodes.size(); i++ ){
    const YAML::Node& Node = InstNodes[i];
    if( !CheckValidNode(Node,"Inst") )
      return false;
    std::string Name = Node["Inst"].as<std::string>();
    if( Node["Signals"] ){
      const YAML::Node& SNode = Node["Signals"];
      for( unsigned j=0; j<SNode.size(); j++ ){
        const YAML::Node& LSNode = SNode[j];
        if( !CheckValidNode(LSNode,"Signal") )
          return false;
        std::string SigName = LSNode["Signal"].as<std::string>();

        if( !CheckValidNode(LSNode,"Type") )
          return false;
        SigType Type = StrToSigType(LSNode["Type"].as<std::string>());

        if( !CheckValidNode(LSNode,"Width") )
          return false;
        unsigned Width = LSNode["Width"].as<unsigned>();

        std::string FusedOp;
        if( CheckValidNode(LSNode,"FusedOp") ){
          FusedOp = LSNode["FusedOp"].as<std::string>();
        }

        Signals.push_back(new SCSig(Type,Width,Name,SigName));
        if( FusedOp.length() > 0 ){
          // write the fused op to the latest signal
          FusedOpType FType = StrToFusedOpType(FusedOp);
          Signals[Signals.size()-1]->SetFusedType(FType);
        }
      }
    }
  }

  return true;
}

bool CoreGenSigMap::ReadTmpRegs(const YAML::Node& TmpNodes){

  for( unsigned i=0; i<TmpNodes.size(); i++ ){
    const YAML::Node& Node = TmpNodes[i];
    if( !CheckValidNode(Node,"Temp") )
      return false;
    std::string Name = Node["Temp"].as<std::string>();

    if( !CheckValidNode(Node,"Width") )
      return false;
    unsigned Width = Node["Width"].as<unsigned>();

    if( Node["Mappings"] ){
      const YAML::Node& MNode = Node["Mappings"];
      SCTmp *T = nullptr;
      for( unsigned j=0; j<MNode.size(); j++ ){
        const YAML::Node& MSNode = MNode[j];
        std::string Inst = MSNode["Map"].as<std::string>();
        std::string IRName = MSNode["IRName"].as<std::string>();

        if( j==0 ){
          // create a new object
          T = new SCTmp(Name,Width,Inst,IRName);
        }else{
          // insert a new pair into the object
          T->InsertTmpPair(Inst,IRName);
        }
      }
      // add the object to our vector of tmps
      TempRegs.push_back(T);
    }
  }

  return true;
}

bool CoreGenSigMap::ReadSigMap( std::string File ){
  if( File.length() == 0 )
    return false;

  // load the file
  YAML::Node IR;
  try{
    IR = YAML::LoadFile(File);
  }catch(YAML::ParserException& e){
    return false;
  }
  if( IR.IsNull() )
    return false;

  // the file is open and has nodes, read everything that is valid
  // read the top-level signals
  const YAML::Node& TopNodes = IR["SignalTop"];
  if( CheckValidNode(IR,"SignalTop") ){
    if( !ReadTopLevelSignals(TopNodes) )
      return false;
  }

  // read the instruction signals
  const YAML::Node& InstNodes = IR["Instructions"];
  if( CheckValidNode(IR,"Instructions") ){
    if( !ReadInstSignals(InstNodes) )
      return false;
  }

  // read the temporary register values
  const YAML::Node& TmpNodes = IR["Temps"];
  if( CheckValidNode(IR,"Temps") ){
    if( !ReadTmpRegs(TmpNodes) )
      return false;
  }

  return true;
}

bool CoreGenSigMap::WriteInstSignals(YAML::Emitter *out){
  if( out == nullptr )
    return false;

  *out << YAML::Key << "Instructions" << YAML::BeginSeq;

  // walk all the signals and derive the names
  std::vector<std::string> SigNames;
  for( unsigned i=0; i<Signals.size(); i++ ){
    if( SigNames.size() > 0 ){
      bool found = false;
      for( unsigned j=0; j<SigNames.size(); j++ ){
        if( Signals[i]->GetInst() == SigNames[j] )
          found = true;
      }
      if( !found )
        SigNames.push_back(Signals[i]->GetInst());
    }else{
      SigNames.push_back(Signals[i]->GetInst());
    }
  }

  // walk all the signal names, derive all the signals and write them out
  for( unsigned i=0; i<SigNames.size(); i++ ){
    std::vector<SCSig *> Sigs;

    // retrieve all the signals for the target instruction
    for( unsigned j=0; j<Signals.size(); j++ ){
      if( Signals[j]->GetInst() == SigNames[i] )
        Sigs.push_back(Signals[j]);
    }

    // make the vector unique
    std::vector<SCSig *> CSigs;

    // build a unique vector of all the local instruction signals
    for( unsigned j=0; j<Sigs.size(); j++ ){
      if( CSigs.size() > 0 ){
        bool found = false;
        for( unsigned k=0; k<CSigs.size(); k++ ){
          if( Sigs[j]->GetName() == CSigs[k]->GetName() )
            found = true;
        }
        if( !found )
          CSigs.push_back(Sigs[j]);
      }else{
        CSigs.push_back(Sigs[j]);
      }
    }

    // write out the instruction
    *out << YAML::BeginMap << YAML::Key << "Inst" << YAML::Value << SigNames[i];
    *out << YAML::Key << "Signals" << YAML::Value << YAML::BeginSeq;
    for( unsigned j=0; j<CSigs.size(); j++ ){
      *out << YAML::BeginMap;
      *out << YAML::Key << "Signal" << YAML::Value << CSigs[j]->GetName();
      *out << YAML::Key << "Type" << YAML::Value << CSigs[j]->SigTypeToStr();
      *out << YAML::Key << "Width" << YAML::Value << CSigs[j]->GetWidth();
      if( CSigs[j]->GetFusedType() != FOP_UNK )
        *out << YAML::Key << "FusedOp" << YAML::Value << CSigs[j]->FusedOpTypeToStr();
      *out << YAML::EndMap;
    }
    *out << YAML::EndSeq;
    *out << YAML::EndMap;
  }

  *out << YAML::EndSeq;

  return true;
}

bool CoreGenSigMap::WriteTempRegs(YAML::Emitter *out){
  if( out == nullptr )
    return false;

  *out << YAML::Key << "Temps" << YAML::BeginSeq;
  for( unsigned i=0; i<TempRegs.size(); i++ ){
    *out << YAML::BeginMap << YAML::Key << "Temp" << YAML::Value << TempRegs[i]->GetName();
    *out << YAML::Key << "Width" << YAML::Value << TempRegs[i]->GetWidth();
    *out << YAML::Key << "Mappings" << YAML::Value << YAML::BeginSeq;

    for( unsigned j=0; j<TempRegs[i]->GetNumMappings(); j++ ){
      *out << YAML::BeginMap;
      std::pair<std::string,std::string> Map = TempRegs[i]->GetMap(j);
      *out << YAML::Key << "Map" << YAML::Value << Map.first;
      *out << YAML::Key << "IRName" << YAML::Value << Map.second;
      *out << YAML::EndMap;
    }

    *out << YAML::EndSeq;
    *out << YAML::EndMap;
  }
  *out << YAML::EndSeq;

  return true;
}

bool CoreGenSigMap::WriteTopLevelSignals(YAML::Emitter *out){
  if( out == nullptr )
    return false;

  std::vector<std::string> Sigs;
  for( unsigned i=0; i<Signals.size(); i++ ){
    Sigs.push_back(Signals[i]->GetName());
  }

  std::sort(Sigs.begin(),Sigs.end());
  Sigs.erase( std::unique(Sigs.begin(),Sigs.end()), Sigs.end());

  *out << YAML::Key << "SignalTop" << YAML::BeginSeq;
  for( unsigned i=0; i<Sigs.size(); i++ ){
    *out << YAML::BeginMap << YAML::Key
         << "Signal" << YAML::Value << Sigs[i]
         << YAML::EndMap;
  }
  *out << YAML::EndSeq;

  return true;
}

std::string CoreGenSigMap::GetTempReg( std::string Inst, std::string IRName,
                                       unsigned width ){

  // Search the current set of temporaries.  If we find an existing match
  // on the IRName and the width, use it.  In LLVM SSA form, we should not
  // see duplicate temporaries within a target instruction
  for( unsigned i=0; i<TempRegs.size(); i++ ){
    if( TempRegs[i]->IsIRFound(IRName) && (TempRegs[i]->GetWidth() == width) ){
      TempRegs[i]->InsertTmpPair( Inst, IRName );
      return TempRegs[i]->GetName();
    }
  }

  // Could not find an existing temporary, return a new temp
  std::string TmpName = "ALUTMP" + std::to_string(TmpIdx) + "_" + std::to_string(width);
  TmpIdx++;
  TempRegs.push_back( new SCTmp(TmpName,width,Inst,IRName) );
  return TmpName;
}

std::string CoreGenSigMap::GetTempMap( std::string Inst, std::string IRName ){
  for( unsigned i=0; i<TempRegs.size(); i++ ){
    if( TempRegs[i]->IsPairFound(Inst,IRName) )
      return TempRegs[i]->GetName();
  }
  std::string NStr = "";
  return NStr;
}

// EOF
