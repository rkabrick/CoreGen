//
// _RegClassCG_cpp_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/CoreGenCodegen/NodeCodegen/RegClassCG.h"

RegClassCG::RegClassCG( CoreGenNode *N, CoreGenProj *P,
                        std::string Pack, std::string Path,
                        bool Comm, CoreGenErrno *E )
  : CoreGenNodeCodegen(N,P,Pack,Path,Comm,E) {
}

RegClassCG::~RegClassCG(){
}

bool RegClassCG::WriteRegClass(std::ofstream &O ){
  // write the comment
  O << "//-- " << Node->GetName() << " Register Class " << std::endl;
  O << "class " << CGRemoveDot(Node->GetName()) << "RFileIO(implicit val conf: "
    << CGRemoveDot(Proj->GetProjName()) << "Configuration) extends Bundle()" << std::endl
    << "{" << std::endl
    << "\tval rs1_addr = Input(UInt(5.W))" << std::endl
    << "\tval rs1_data = Output(UInt(conf.xprlen.W))" << std::endl
    << "\tval rs2_addr = Input(UInt(5.W))" << std::endl
    << "\tval rs2_data = Output(UInt(conf.xprlen.W))" << std::endl
    << "\tval dm_addr = Input(UInt(5.W))" << std::endl
    << "\tval dm_rdata = Output(UInt(conf.xprlen.W))" << std::endl
    << "\tval dm_wdata = Input(UInt(conf.xprlen.W))" << std::endl
    << "\tval dm_en = Input(Bool())" << std::endl
    << "\tval waddr    = Input(UInt(5.W))" << std::endl
    << "\tval wdata    = Input(UInt(conf.xprlen.W))" << std::endl
    << "\tval wen      = Input(Bool())" << std::endl
    << "}" << std::endl << std::endl;

  O << "class " << CGRemoveDot(Node->GetName()) << "(implicit val conf: "
    << CGRemoveDot(Proj->GetProjName()) << "Configuration) extends Module" << std::endl
    << "{" << std::endl
    << "\tval io = IO(new " << CGRemoveDot(Node->GetName()) << "RFileIO())" << std::endl
    << "\tval regfile = Mem( UInt(conf." << CGRemoveDot(Node->GetName())
    << "_numregs.W), UInt(conf." << CGRemoveDot(Node->GetName()) << "_maxwidth.W))" << std::endl
    << "\twhen (io.wen && (io.waddr =/= 0.U))" << std::endl
    << "\t{" << std::endl
    << "\t\tregfile(io.waddr) := io.wdata" << std::endl
    << "\t}" << std::endl << std::endl
    << "\twhen (io.dm_en && (io.dm_addr =/= 0.U))" << std::endl
    << "\t{" << std::endl
    << "\t\tregfile(io.dm_addr) := io.dm_wdata" << std::endl
    << "\t}" << std::endl << std::endl
    << "\tio.rs1_data := Mux((io.rs1_addr =/= 0.U), regfile(io.rs1_addr), 0.U)" << std::endl
    << "\tio.rs2_data := Mux((io.rs2_addr =/= 0.U), regfile(io.rs2_addr), 0.U)" << std::endl
    << "\tio.dm_rdata := Mux((io.dm_addr =/= 0.U), regfile(io.dm_addr), 0.U)" << std::endl
    << "}" << std::endl << std::endl;
  return true;
}

bool RegClassCG::Execute(){

  // already generated this register file type
  if( CGFileExists(Path) )
    return true;

  // open the output file
  std::ofstream OutFile;
  OutFile.open(Path,std::ios::trunc);
  if(!OutFile.is_open()){
    Errno->SetError(CGERR_ERROR, "Could not open chisel file for register class:" +
                    Path );
    return false;
  }

  // write the header
  OutFile << "// -- " << Node->GetName()
          << " Chisel Output" << std::endl << std::endl;

  // write the package info
  if( !WritePackageInfo(OutFile) ){
    Errno->SetError(CGERR_ERROR, "Could not write standard package info to file : " +
                    Path );
    OutFile.close();
    return false;
  }

  // import the chisel imports
  if( !WriteChiselImports(OutFile) ){
    Errno->SetError(CGERR_ERROR, "Could not write standard Chisel header to file : " + 
                    Path );
    OutFile.close();
    return false;
  }

  // write out the package block
  if( !WriteRegClass(OutFile) ){
    Errno->SetError(CGERR_ERROR, "Could not write register class block to file : " +
                    Path );
    OutFile.close();
    return false;
  }

  if( !WriteStdFooter(OutFile) ){
    Errno->SetError(CGERR_ERROR, "Could not write standard Chisel footer to file : " + 
                    Path );
    OutFile.close();
    return false;
  }

  // close the output file
  OutFile.close();

  return true;
}

// EOF
