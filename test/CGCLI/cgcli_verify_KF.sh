#!/bin/bash

CGCLI_PATH=$1

$CGCLI_PATH/cgcli -i sample1.yaml
retVal=$?
if [ ! $retVal -eq 0 ]; then
  echo "$CGCLI_PATH/cgcli -i sample1.yaml erroneously passed with return code = $retVal"
  exit $retVal
fi

$CGCLI_PATH/cgcli -ir sample1.yaml
retVal=$?
if [ ! $retVal -eq 0 ]; then
  echo "$CGCLI_PATH/cgcli -ir sample1.yaml erroneously passed with return code = $retVal"
  exit $retVal
fi

$CGCLI_PATH/cgcli --ir sample1.yaml
retVal=$?
if [ ! $retVal -eq 0 ]; then
  echo "$CGCLI_PATH/cgcli --ir sample1.yaml erroneously passed with return code = $retVal"
  exit $retVal
fi

exit 0
