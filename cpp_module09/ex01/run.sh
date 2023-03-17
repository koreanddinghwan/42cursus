#!/bin/bash

programName="./RPN"
argNum=$1

MINT="\033[38;2;152;255;152m"
RED="\033[38;2;255;0;0m"

EXECUTESTRING="$RED Executing program with $MINT"

VAR1=" 8 9 * 9 - 9 - 9 - 4 - 1 +"

VAR2=" 7 7 * 7 -"

VAR3="1 2 * 2 / 2 * 2 4 - +"

VAR4="(1 + 1)"

VAR5="1 + 1"

# 입력된 숫자에 따라 변수 선택하여 프로그램 실행
case $argNum in
    1)
        echo -e "$EXECUTESTRING" "$VAR1"
        $programName "$VAR1"
        ;;
    2)
        echo -e "$EXECUTESTRING" "$VAR2"
        $programName "$VAR2"
        ;;
    3)
        echo -e "$EXECUTESTRING" "$VAR3"
        $programName "$VAR3"
        ;;
	4)
        echo -e "$EXECUTESTRING" "$VAR4"
        $programName "$VAR4"
        ;;
	5)
        echo -e "$EXECUTESTRING" "$VAR5"
        $programName "$VAR5"
        ;;
    *)
        echo "Invalid input. Please enter a number between 1 and 5."
        ;;
esac
