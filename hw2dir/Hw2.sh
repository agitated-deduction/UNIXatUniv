#!/bin/bash
:<<'END'
파일: HW2.sh
기능: 입력 된 학생 성적 정보를 학과별로, 과목별로 log에 기록한다.
개발자: 201521672 박소연
날짜: 1차 개발: 2018-03-16
END
argc=$#
argv1=$1
argv2=$2
argv3=$3
argv4=$4
if [ ${argc} -eq 0 ] && [ -d ./log ]
then
	echo "log 디렉토리가 이미 존재합니다."
	exit${1}
elif [ ! -d ./log ]
then
	mkdir ./log
fi

if [ ${argc} -eq 4 ]
then
	if [ -e ./log/${argv2}.txt ]
	then
		echo ${argv1}" "${argv3}" "${argv4} >> ./log/${argv2}.txt 
	else
		echo ${argv1}" "${argv3}" "${argv4} > ./log/${argv2}.txt 
	fi

	if [ -e ./log/${argv3}.txt ]
	then
		echo ${argv1}" "${argv2}" "${argv4} >> ./log/${argv3}.txt 
	else
		echo ${argv1}" "${argv2}" "${argv4} > ./log/${argv3}.txt 
	fi

else
	echo "[이름] [학과] [과목] [성적]을 넣어주세요."
fi
