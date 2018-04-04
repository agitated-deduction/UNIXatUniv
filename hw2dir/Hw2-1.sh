#! /bin/bash
:<<'END'
파일: Hw2-1.c
기능: 원래 이름, 변경 이름을 입력받아서 원래 이름의 위치에 변경 이름을 적는다.
개발자: 201521672 박소연
날짜: 1차 개발 : 2018년 3월 16일
참고자료: jybaek.tistory.com/354
END
argc=$#
argv1=$1
argv2=$2
APPS_SCRIPT=./log/
if [ $argc -ne 2 ]
then
	echo "[원래 이름] [변경 이름] 을 적어주세요."
	exit ${1}
fi
if [ -e "$APPS_SCRIPT" ]
then
	SCRIPT_LIST=`ls $APPS_SCRIPT`

	for SCRIPT in $SCRIPT_LIST
	do
		PAT=./log/$SCRIPT
		if [ `grep -c $argv1 $PAT`  -gt 0 ]
		then
			chmod 744 $PAT
			sed s/$argv1/$argv2/g $PAT >> $PAT
		fi
	done
else
	echo "파일이 없습니다."
fi
