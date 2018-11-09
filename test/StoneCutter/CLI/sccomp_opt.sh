#!/bin/bash

CGCLI_PATH=$1

FILE=test.OPT.sc
touch $FILE
echo "# this is a stonecutter source file" >> $FILE 2>&1

$CGCLI_PATH/cgcli -O $FILE
retVal=$?
if [ ! $? -eq 0 ]; then
  echo "$CGCLI_PATH/sccomp -O $FILE failed with return code = $retVal"
  rm -Rf $FILE
  exit $retVal
fi

$CGCLI_PATH/cgcli -optimize $FILE
retVal=$?
if [ ! $? -eq 0 ]; then
  echo "$CGCLI_PATH/sccomp -optimize $FILE failed with return code = $retVal"
  rm -Rf $FILE
  exit $retVal
fi

$CGCLI_PATH/cgcli --optimize $FILE
retVal=$?
if [ ! $? -eq 0 ]; then
  echo "$CGCLI_PATH/sccomp --optimize $FILE failed with return code = $retVal"
  rm -Rf $FILE
  exit $retVal
fi

rm -Rf $FILE

exit 0
