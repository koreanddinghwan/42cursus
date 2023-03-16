#!/bin/bash

programName="./RPN"
argNum=$1

VAR1="8 9 * 9 - 9 - 9 - 4 - 1 +"

VAR2="7 7 * 7 -"

VAR3="1 2 * 2 / 2 * 2 4 - +"

VAR4="(1 + 1)"

# 입력된 숫자에 따라 변수 선택하여 프로그램 실행
case $argNum in
    1)
        echo "Executing program with $VAR1"
        $programName "$VAR1"
        ;;
    2)
        echo "Executing program with $VAR2"
        $programName "$VAR2"
        ;;
    3)
        echo "Executing program with $VAR3"
        $programName "$VAR3"
        ;;
	4)
        echo "Executing program with $VAR4"
        $programName "$VAR4"
        ;;
    *)
        echo "Invalid input. Please enter a number between 1 and 4."
        ;;
esac
