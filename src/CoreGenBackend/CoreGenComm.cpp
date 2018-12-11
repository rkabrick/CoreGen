//
// _CoreGenComm_cpp_
//
// Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGen/CoreGenBackend/CoreGenComm.h"

CoreGenComm::CoreGenComm(std::string N, CoreGenErrno *E)
  : CoreGenNode(CGComm,N,E), Type(CGCommUnk), Width(0) {
}

CoreGenComm::CoreGenComm(std::string N, CGCommType T,
                         unsigned W, CoreGenErrno *E)
  : CoreGenNode(CGComm,N,E), Type(T), Width(W) {
}

CoreGenComm::~CoreGenComm(){
}

bool CoreGenComm::InsertEndpoint( CoreGenNode *N ){
  if( N == nullptr ){
    Errno->SetError( CGERR_ERROR, "InsertEndpoint: Node pointer is null" );
    return false;
  }
  if( N->GetType() == CGComm ){
    Errno->SetError( CGERR_ERROR,
                     "InsertEndpoint: Cannot connect communication channel to communication channel" );
    return false;
  }

  // insert it into the endpoint vector and make it an official child
  EndPoints.push_back( N );
  return this->InsertChild(N);
}

bool CoreGenComm::DeleteEndpoint( CoreGenNode *N ){
  if( N == nullptr ){
    Errno->SetError( CGERR_ERROR, "DeleteEndpoint: Node pointer is null" );
    return false;
  }

  // make sure the node is an official endpoint, then delete it from
  // the vector and the child list
  std::vector<CoreGenNode *>::iterator it;
  it = find(EndPoints.begin(), EndPoints.end(), N);
  if( it == EndPoints.end() ){
    Errno->SetError( CGERR_ERROR,
                     "DeleteEndpoint: Cannot find target endpoint in communication channel" );
    return false;
  }
  EndPoints.erase(it);
  this->DeleteChild( N );
  return true;
}

bool CoreGenComm::SetCommType( CGCommType T ){
  Type = T;
  return true;
}

bool CoreGenComm::SetWidth( unsigned W ){
  if( W == 0 ){
    Errno->SetError( CGERR_ERROR, "SetWidth: Channel width is zero" );
    return false;
  }

  Width = W;

  return true;
}

CoreGenNode *CoreGenComm::GetEndpoint( unsigned Idx ){
  if( Idx > (EndPoints.size()+1) ){
    return nullptr;
  }
  return EndPoints[Idx];
}

CoreGenNode *CoreGenComm::GetEndpoint( std::string N ){
  for( unsigned i=0; i<EndPoints.size(); i++ ){
    if( EndPoints[i]->GetName() == N ){
      return EndPoints[i];
    }
  }
  return nullptr;
}
