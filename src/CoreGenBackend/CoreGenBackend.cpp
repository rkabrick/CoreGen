//
// _CoreGenBackend_cpp_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/CoreGenBackend/CoreGenBackend.h"

CoreGenBackend::CoreGenBackend() :
  Errno(new CoreGenErrno()),
  Proj(nullptr),
  Env(new CoreGenEnv(Errno)),
  PluginMgr(new CoreGenPluginMgr(Errno)),
  PassMgr(nullptr),
  Top(new CoreGenNode(CGTop,Errno)),
  DAG(nullptr){
}

CoreGenBackend::CoreGenBackend(std::string ProjName,
                               std::string ProjRoot,
                               std::string ArchRoot ) :
  Errno(new CoreGenErrno()),
  Proj(new CoreGenProj(Errno,ProjName,ProjRoot)),
  Env(new CoreGenEnv(ArchRoot,Errno)),
  PluginMgr(new CoreGenPluginMgr(Errno)),
  PassMgr(nullptr),
  Top(new CoreGenNode(CGTop,Errno)),
  DAG(nullptr){
}

CoreGenBackend::CoreGenBackend(std::string ProjName,
                               std::string ProjRoot,
                               std::string ArchRoot,
                               CGProjType Type) :
  Errno(new CoreGenErrno()),
  Proj(new CoreGenProj(Errno,ProjName,ProjRoot,Type)),
  Env(new CoreGenEnv(ArchRoot,Errno)),
  PluginMgr(new CoreGenPluginMgr(Errno)),
  PassMgr(nullptr),
  Top(new CoreGenNode(CGTop,Errno)),
  DAG(nullptr) {
}

CoreGenBackend::~CoreGenBackend(){
  for( unsigned i=0; i<Caches.size(); i++ ){
    delete Caches[i];
  }
  for( unsigned i=0; i<Cores.size(); i++ ){
    delete Cores[i];
  }
  for( unsigned i=0; i<Exts.size(); i++ ){
    delete Exts[i];
  }
  for( unsigned i=0; i<Insts.size(); i++ ){
    delete Insts[i];
  }
  for( unsigned i=0; i<PInsts.size(); i++ ){
    delete PInsts[i];
  }
  for( unsigned i=0; i<Formats.size(); i++ ){
    delete Formats[i];
  }
  for( unsigned i=0; i<Regs.size(); i++ ){
    delete Regs[i];
  }
  for( unsigned i=0; i<RegClasses.size(); i++ ){
    delete RegClasses[i];
  }
  for( unsigned i=0; i<Socs.size(); i++ ){
    delete Socs[i];
  }
  for( unsigned i=0; i<ISAs.size(); i++ ){
    delete ISAs[i];
  }
  for( unsigned i=0; i<Comms.size(); i++ ){
    delete Comms[i];
  }
  for( unsigned i=0; i<Spads.size(); i++ ){
    delete Spads[i];
  }
  for( unsigned i=0; i<MCtrls.size(); i++ ){
    delete MCtrls[i];
  }
  for( unsigned i=0; i<VTPs.size(); i++ ){
    delete VTPs[i];
  }
  for( unsigned i=0; i<Plugins.size(); i++ ){
    delete Plugins[i];
  }


  delete Top;
  delete PluginMgr;
  if( PassMgr != nullptr ){
    delete PassMgr;
  }
  if( DAG != nullptr ){
    delete DAG;
  }
  if( Proj != nullptr ){
    delete Proj;
  }
  if( Env != nullptr ){
    delete Env;
  }
  delete Errno;
}

bool CoreGenBackend::ExecuteLLVMCodegen(){
  // Create the codegen object
  CoreGenCodegen *CG = new CoreGenCodegen(Top,
                                          Proj,
                                          Errno);

  if( CG == nullptr ){
    Errno->SetError(CGERR_ERROR, "Could not create codegen object");
    return false;
  }

  // Execute it
  bool rtn = CG->ExecuteLLVMCodegen();

  // delete and clean everything up
  delete CG;
  return rtn;
}

bool CoreGenBackend::ExecuteChiselCodegen(){
  // Create the codegen object
  CoreGenCodegen *CG = new CoreGenCodegen(Top,
                                          Proj,
                                          Errno);

  if( CG == nullptr ){
    Errno->SetError(CGERR_ERROR, "Could not create codegen object");
    return false;
  }

  // Execute it
  bool rtn = CG->ExecuteChiselCodegen();

  // delete and clean everything up
  delete CG;
  return rtn;
}

bool CoreGenBackend::ExecuteCodegen(){
  // Create the codegen object
  CoreGenCodegen *CG = new CoreGenCodegen(Top,
                                          Proj,
                                          Errno);

  if( CG == nullptr ){
    Errno->SetError(CGERR_ERROR, "Could not create codegen object");
    return false;
  }

  // Execute it
  bool rtn = CG->Execute();

  // delete and clean everything up
  delete CG;
  return rtn;
}

bool CoreGenBackend::ExecutePasses(){
  if( PassMgr == nullptr ){
    Errno->SetError(CGERR_ERROR, "PassMgr has not been enabled");
    return false;
  }
  return PassMgr->Execute();
}

bool CoreGenBackend::ExecutePass( std::string str ){
  if( PassMgr == nullptr ){
    Errno->SetError(CGERR_ERROR, "PassMgr has not been enabled");
    return false;
  }
  return PassMgr->Execute(str);
}

bool CoreGenBackend::ExecuteSysPass( std::string str ){
  if( PassMgr == nullptr ){
    Errno->SetError(CGERR_ERROR, "PassMgr has not been enabled");
    return false;
  }
  return PassMgr->ExecuteSys(str);
}

bool CoreGenBackend::SetPassOutputPath( std::string Pass, std::string Path ){
  if( PassMgr == nullptr ){
    Errno->SetError(CGERR_ERROR, "PassMgr has not been enabled");
    return false;
  }
  return PassMgr->SetPassOutputPath(Pass,Path);
}

bool CoreGenBackend::SetPassInputStr( std::string Pass, std::string Str ){
  if( PassMgr == nullptr ){
    Errno->SetError(CGERR_ERROR, "PassMgr has not been enabled");
    return false;
  }
  return PassMgr->SetPassInputStr(Pass,Str);
}

bool CoreGenBackend::ExecutePassType(CGPassType T ){
  if( PassMgr == nullptr ){
    Errno->SetError(CGERR_ERROR, "PassMgr has not been enabled");
    return false;
  }
  return PassMgr->Execute(T);
}

void CoreGenBackend::CoreGenVersion( int *major, int *minor ){
  *major = CoreGenBackend_VERSION_MAJOR;
  *minor = CoreGenBackend_VERSION_MINOR;
}

bool CoreGenBackend::WriteIR( std::string FileName ){
  if( FileName.length() == 0 ){
    Errno->SetError( CGERR_ERROR, "FileName is empty" );
    return false;
  }

  CoreGenYaml *IR = new CoreGenYaml( FileName, PluginMgr, Env, Proj, Errno );
  if( !IR ){
    Errno->SetError( CGERR_ERROR, "Failed to create Yaml IR object" );
    return false;
  }

  if( !IR->WriteYaml( Socs, Cores, Caches, ISAs, Formats, Insts,
                      PInsts, RegClasses, Regs, Comms, Spads,
                      MCtrls, VTPs, Exts, Plugins) ){
    delete IR;
    return false;
  }

  delete IR;

  return true;
}

bool CoreGenBackend::ReadIR( std::string FileName ){
  if( FileName.length() == 0 ){
    Errno->SetError( CGERR_ERROR, "FileName is empty" );
    return false;
  }

  if( Proj == nullptr ){
    Proj = new CoreGenProj(Errno);
  }

  CoreGenYaml *IR = new CoreGenYaml( FileName, PluginMgr, Env, Proj, Errno );
  if( !IR ){
    Errno->SetError( CGERR_ERROR, "Failed to create Yaml IR object" );
    return false;
  }

  if( !IR->ReadYaml( Socs, Cores, Caches, ISAs, Formats, Insts,
                      PInsts, RegClasses, Regs, Comms, Spads,
                      MCtrls, VTPs, Exts, Plugins) ){
    delete IR;
    return false;
  }

  delete IR;

  return true;
}

bool CoreGenBackend::LoadPlugin( std::string Path ){
  if( !PluginMgr ){
    return false;
  }
  return PluginMgr->LoadPlugin( Path );
}

bool CoreGenBackend::ReleasePlugin( unsigned Idx ){
  if( !PluginMgr ){
    return false;
  }
  return PluginMgr->ReleasePlugin(Idx);
}

bool CoreGenBackend::ReleasePlugin( std::string Plugin ){
  if( !PluginMgr ){
    return false;
  }
  return PluginMgr->ReleasePlugin(Plugin);
}

unsigned CoreGenBackend::GetNumPlugins(){
  if( !PluginMgr ){
    return 0;
  }
  return PluginMgr->GetNumPlugins();
}

std::string CoreGenBackend::GetErrStr(){
  if( !Errno ){
    return "Error in utilizing Errno";
  }
  return Errno->GetErrStr();
}

bool CoreGenBackend::ExportDOT( std::string FName ){
  if( DAG == nullptr ){
    return false;
  }
  return DAG->ExportDOT(FName);
}

std::vector<std::string> CoreGenBackend::GetPasses(){
  std::vector<std::string> dummy;
  if( PassMgr == nullptr ){
    Errno->SetError( CGERR_ERROR, "Pass manager is null" );
    return dummy;
  }
  return PassMgr->GetPassNames();
}

std::vector<std::string> CoreGenBackend::GetPassDescriptions(){
  std::vector<std::string> dummy;
  if( PassMgr == nullptr ){
    Errno->SetError( CGERR_ERROR, "Pass manager is null" );
    return dummy;
  }
  return PassMgr->GetPassDescriptions();
}

bool CoreGenBackend::PrintPassInfo(){
  if( PassMgr == nullptr ){
    Errno->SetError( CGERR_ERROR, "Pass manager is null" );
    return false;
  }
  return PassMgr->PrintPassInfo();
}

bool CoreGenBackend::PrintSysPassInfo(){
  if( PassMgr == nullptr ){
    Errno->SetError( CGERR_ERROR, "Pass manager is null" );
    return false;
  }
  return PassMgr->PrintSysPassInfo();
}

bool CoreGenBackend::IsPassMgr(){
  if( PassMgr != nullptr ){
    return true;
  }else{
    return false;
  }
}

bool CoreGenBackend::InitPassMgr(std::ostream *O){
  if( DAG == nullptr ){
    Errno->SetError( CGERR_ERROR, "IR DAG has not been constructed" );
    return false;
  }
  if( Proj == nullptr ){
    Errno->SetError( CGERR_ERROR, "The project info is missing" );
    return false;
  }
  if( PassMgr ){
    return true;
  }
  PassMgr = new CoreGenPassMgr(O,Errno, DAG, Proj);
  if( PassMgr == nullptr ){
    return false;
  }
  return true;
}

bool CoreGenBackend::InitPassMgr(){
  if( DAG == nullptr ){
    Errno->SetError( CGERR_ERROR, "IR DAG has not been constructed" );
    return false;
  }
  if( Proj == nullptr ){
    Errno->SetError( CGERR_ERROR, "The project info is missing" );
    return false;
  }
  std::ostream *o = &std::cout;
  PassMgr = new CoreGenPassMgr(o,Errno, DAG, Proj);
  if( PassMgr == nullptr ){
    return false;
  }
  return true;
}

bool CoreGenBackend::PurgeDAG(){
  for( unsigned i=0; i<Top->GetNumChild(); i++ ){
    if( !Top->DeleteChild(Top->GetChild(i)) ){
      Errno->SetError( CGERR_ERROR, "Error purging top-level nodes" );
      return false;
    }
  }
  return true;
}

bool CoreGenBackend::BuildDAG(){
  if( DAG != nullptr ){
    // delete the old DAG
    this->PurgeDAG();
    delete DAG;
  }

  DAG = new CoreGenDAG(Errno);
  if( DAG == nullptr ){
    Errno->SetError( CGERR_ERROR, "Error allocating new top-level DAG" );
    return false;
  }

  // add all the subnodes
  for( unsigned i=0; i<Caches.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Caches[i]));
  }
  for( unsigned i=0; i<Cores.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Cores[i]));
  }
  for( unsigned i=0; i<Insts.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Insts[i]));
  }
  for( unsigned i=0; i<PInsts.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(PInsts[i]));
  }
  for( unsigned i=0; i<Formats.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Formats[i]));
  }
  for( unsigned i=0; i<Regs.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Regs[i]));
  }
  for( unsigned i=0; i<RegClasses.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(RegClasses[i]));
  }
  for( unsigned i=0; i<Socs.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Socs[i]));
  }
  for( unsigned i=0; i<ISAs.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(ISAs[i]));
  }
  for( unsigned i=0; i<Exts.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Exts[i]));
  }
  for( unsigned i=0; i<Comms.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Comms[i]));
  }
  for( unsigned i=0; i<Spads.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Spads[i]));
  }
  for( unsigned i=0; i<MCtrls.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(MCtrls[i]));
  }
  for( unsigned i=0; i<VTPs.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(VTPs[i]));
  }
  for( unsigned i=0; i<Plugins.size(); i++ ){
    Top->InsertChild(static_cast<CoreGenNode *>(Plugins[i]));
    Plugins[i]->BuildDAG();
  }

  // build the L0 DAG
  if( !DAG->BuildDAG(Top) ){
    Errno->SetError( CGERR_ERROR, "Error building L0 DAG" );
    return false;
  }

  // Lower everything
  return DAG->LowerAll();
}

bool CoreGenBackend::DeleteCacheNode(CoreGenCache *C){
  return true;
}

bool CoreGenBackend::DeleteCoreNode(CoreGenCore *C){
  return true;
}

bool CoreGenBackend::DeleteInstNode(CoreGenInst *I){
  return true;
}

bool CoreGenBackend::DeletePInstNode(CoreGenPseudoInst *P){
  return true;
}

bool CoreGenBackend::DeleteInstFormatNode(CoreGenInstFormat *I){
  return true;
}

bool CoreGenBackend::DeleteRegNode(CoreGenReg *R){
  return true;
}

bool CoreGenBackend::DeleteRegClassNode(CoreGenRegClass *RC){
  return true;
}

bool CoreGenBackend::DeleteSoCNode(CoreGenSoC *S){
  return true;
}

bool CoreGenBackend::DeleteISANode(CoreGenISA *I){
  return true;
}

bool CoreGenBackend::DeleteExtNode(CoreGenExt *E){
  return true;
}

bool CoreGenBackend::DeleteCommNode(CoreGenComm *C){
  return true;
}

bool CoreGenBackend::DeleteSpadNode(CoreGenSpad *S){
  return true;
}

bool CoreGenBackend::DeleteMCtrlNode(CoreGenMCtrl *M){
  return true;
}

bool CoreGenBackend::DeleteVTPNode(CoreGenVTP *V){
  return true;
}

bool CoreGenBackend::DeletePluginNode(CoreGenPlugin *P){
  return true;
}

bool CoreGenBackend::DeleteNode( CoreGenNode *N ){
  if( !N )
    return false;

  // stage 1: Determine what type of node this is
  //          Certain nodes will require deleting
  //          child nodes that are encodings.
  //          Further, we must remove the necessary
  //          nodes from the Top-level DAG lists
  switch(N->GetType()){
  case CGSoc:
    return DeleteSoCNode(static_cast<CoreGenSoC *>(N));
    break;
  case CGCore:
    return DeleteCoreNode(static_cast<CoreGenCore *>(N));
    break;
  case CGInstF:
    return DeleteInstFormatNode(static_cast<CoreGenInstFormat *>(N));
    break;
  case CGInst:
    return DeleteInstNode(static_cast<CoreGenInst *>(N));
    break;
  case CGPInst:
    return DeletePInstNode(static_cast<CoreGenPseudoInst *>(N));
    break;
  case CGRegC:
    return DeleteRegClassNode(static_cast<CoreGenRegClass *>(N));
    break;
  case CGReg:
    return DeleteRegNode(static_cast<CoreGenReg *>(N));
    break;
  case CGISA:
    return DeleteISANode(static_cast<CoreGenISA *>(N));
    break;
  case CGCache:
    return DeleteCacheNode(static_cast<CoreGenCache *>(N));
    break;
  case CGEnc:
    Errno->SetError( CGERR_ERROR, "Cannot delete individual encodings" );
    return false;
    break;
  case CGExt:
    return DeleteExtNode(static_cast<CoreGenExt *>(N));
    break;
  case CGComm:
    return DeleteCommNode(static_cast<CoreGenComm *>(N));
    break;
  case CGSpad:
    return DeleteSpadNode(static_cast<CoreGenSpad *>(N));
    break;
  case CGMCtrl:
    return DeleteMCtrlNode(static_cast<CoreGenMCtrl *>(N));
    break;
  case CGVTP:
    return DeleteVTPNode(static_cast<CoreGenVTP *>(N));
    break;
  case CGPlugin:
    Errno->SetError( CGERR_WARN, "Deleting a plugin will remove all its children" );
    return DeletePluginNode(static_cast<CoreGenPlugin *>(N));
    break;
  case CGTop:
    Errno->SetError( CGERR_ERROR, "Top-level DAG nodes cannot be deleted" );
    return false;
    break;
  default:
    // something went wrong
    Errno->SetError( CGERR_ERROR, "Unrecognized node type for deletion" );
    delete N;
    return false;
    break;
  }

  // if we get here, something went wrong
  return false;
}

CoreGenCache *CoreGenBackend::InsertCache(std::string Name,
                                          unsigned Sets,
                                          unsigned Ways){
  CoreGenCache *C = new CoreGenCache(Name,Sets,Ways,Errno);
  Caches.push_back(C);
  return C;
}

CoreGenCore *CoreGenBackend::InsertCore(std::string Name,
                                        CoreGenISA *ISA ){
  CoreGenCore *C = new CoreGenCore(Name, ISA, Errno);
  Cores.push_back(C);
  return C;
}

CoreGenExt *CoreGenBackend::InsertExt(std::string Name){
  CoreGenExt *E = new CoreGenExt(Name,Errno);
  Exts.push_back(E);
  return E;
}

CoreGenInst *CoreGenBackend::InsertInst(std::string Name, CoreGenISA *ISA,
                                        CoreGenInstFormat *Format ){
  CoreGenInst *I = new CoreGenInst(Name,ISA,Format,Errno);
  Insts.push_back(I);
  return I;
}

CoreGenPseudoInst *CoreGenBackend::InsertPseudoInst(std::string Name,
                                                    CoreGenInst *Inst ){
  CoreGenPseudoInst *P = new CoreGenPseudoInst(Name,Inst,Errno);
  PInsts.push_back(P);
  return P;
}

CoreGenInstFormat *CoreGenBackend::InsertInstFormat(std::string Name,
                                                    CoreGenISA *ISA){
  CoreGenInstFormat *IF = new CoreGenInstFormat(Name,ISA,Errno);
  Formats.push_back(IF);
  return IF;
}

CoreGenReg *CoreGenBackend::InsertReg(std::string Name,
                                      int RegIndex,
                                      int RegWidth ){
  CoreGenReg *R = new CoreGenReg(Name,RegIndex,RegWidth,Errno);
  Regs.push_back(R);
  return R;
}

CoreGenRegClass *CoreGenBackend::InsertRegClass(std::string Name){
  CoreGenRegClass *RC = new CoreGenRegClass(Name,Errno);
  RegClasses.push_back(RC);
  return RC;
}

CoreGenSoC *CoreGenBackend::InsertSoC(std::string Name){
  CoreGenSoC *S = new CoreGenSoC(Name,Errno);
  Socs.push_back(S);
  return S;
}

CoreGenISA *CoreGenBackend::InsertISA(std::string Name){
  CoreGenISA *I = new CoreGenISA(Name,Errno);
  ISAs.push_back(I);
  return I;
}

CoreGenComm *CoreGenBackend::InsertComm(std::string Name){
  CoreGenComm *C = new CoreGenComm(Name,Errno);
  Comms.push_back(C);
  return C;
}

CoreGenSpad *CoreGenBackend::InsertSpad(std::string Name,
                                        unsigned MemSize,
                                        unsigned RqstPorts,
                                        unsigned RspPorts){
  CoreGenSpad *S = new CoreGenSpad(Name,Errno,MemSize,RqstPorts,RspPorts);
  Spads.push_back(S);
  return S;
}

CoreGenMCtrl *CoreGenBackend::InsertMCtrl(std::string Name,
                                          unsigned Ports){
  CoreGenMCtrl *M = new CoreGenMCtrl(Name,Errno,Ports);
  MCtrls.push_back(M);
  return M;
}

CoreGenVTP *CoreGenBackend::InsertVTP(std::string Name){
  CoreGenVTP *V = new CoreGenVTP(Name,Errno);
  VTPs.push_back(V);
  return V;
}

bool CoreGenBackend::InsertPlugin( CoreGenPlugin *Plugin ){
  if( !Plugin ){
    return false;
  }
  Plugins.push_back(Plugin);
  return true;
}

CoreGenPlugin *CoreGenBackend::GetPlugin( unsigned P ){
  if( !PluginMgr ){
    return nullptr;
  }
  return PluginMgr->GetPlugin(P);
}

CoreGenPlugin *CoreGenBackend::GetPlugin( std::string Plugin ){
  if( !PluginMgr ){
    return nullptr;
  }
  return PluginMgr->GetPlugin(Plugin);
}

void CoreGenBackend::SetASPFiles(std::vector<std::string> Files){
  PassMgr->SetASPFiles(Files);
}

// EOF
