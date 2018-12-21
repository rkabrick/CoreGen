#!/bin/bash

SCCOMP_PATH=$1

if [ ! -f $SCCOMP_PATH/sccomp ]; then
  echo "COULD NOT FIND $SCCOMP_PATH/sccomp"
  exit -1
fi

FILE=test.OPT.sc
touch $FILE
echo "# this is a stonecutter source file" >> $FILE 2>&1

$SCCOMP_PATH/sccomp -c $FILE
retVal=$?
if [[ "$retval" -ne 0 ]]; then
  echo "$SCCOMP_PATH/sccomp -c $FILE failed with return code = $retVal"
  rm -Rf $FILE
  exit $retVal
fi

$SCCOMP_PATH/sccomp -chisel $FILE
retVal=$?
if [[ "$retval" -ne 0 ]]; then
  echo "$SCCOMP_PATH/sccomp -chisel $FILE failed with return code = $retVal"
  rm -Rf $FILE
  exit $retVal
fi

$SCCOMP_PATH/sccomp --chisel $FILE
retVal=$?
if [[ "$retval" -ne 0 ]]; then
  echo "$SCCOMP_PATH/sccomp --chisel $FILE failed with return code = $retVal"
  rm -Rf $FILE
  exit $retVal
fi

rm -Rf $FILE

exit 0