#!/bin/bash

CGCLI_PATH=$1
FILE=$2

if [ ! -f $CGCLI_PATH/cgcli ]; then
  echo "COULD NOT FIND $CGCLI_PATH/cgcli"
  exit -1
fi

$CGCLI_PATH/cgcli --ir $FILE --pass --enable-pass "DanglingRegionPass"
retVal=$?
if [[  "$retVal" -ne 0 ]]; then
  echo "$CGCLI_PATH/cgcli --ir $FILE --pass --enable-pass \"DanglingRegionPass\" FAILED with return code $retVal"
  exit $retVal
fi

exit 0
