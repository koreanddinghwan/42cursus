#!/bin/bash

# 인자로 입력받은 숫자만큼 랜덤한 양수 생성
num=$1
args=""
for i in $(seq 1 $num); do
  rand=$((RANDOM % 1000000 + 1)) # 1에서 100 사이의 랜덤한 양수 생성
  args="$args $rand" # 인자 문자열에 추가
done

# 프로그램 실행
./a.out $args
