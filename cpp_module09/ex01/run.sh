#!/bin/bash

programName="./RPN"
argNum=$1

MINT="\033[38;2;152;255;152m"
RED="\033[38;2;255;0;0m"

EXECUTESTRING="$RED Executing program with $MINT"

VARS=(
	" 8 9 * 9 - 9 - 9 - 4 - 1 +"
	" 7 7 * 7 -"
	"1 2 * 2 / 2 * 2 4 - +"
	"(1 + 1)"
	"1 + 1"
	"0 / 1"
	'0 1 /'
	'0 0 /'
	'1 0 /'
)

# 입력된 숫자에 따라 변수 선택하여 프로그램 실행
if ((argNum >= 1 && argNum <= ${#VARS[@]})); then
  echo -e "$EXECUTESTRING" "${VARS[$argNum-1]}"
  $programName "${VARS[$argNum-1]}"
else
  echo "$RED Invalid input. Please enter a number between 1 and ${#VARS[@]}."
fi
