KEYFILE := ./key.txt
KEY = 0000000000000000
INTXT := ./test.txt # 输入的 txt 文件名
OUTTXT := ./out.txt # 输出的 txt 文件名
ENCMODE := enc -des-ecb

GCC := gcc
INC := ./des.c
OUTC := ./out
COUTFILE := ./cout.txt
STANDARDCFILE := ./main.c
STANDARDCOUT := ./main
STANDARDTXT := ./standard.txt

c:
	@${GCC} ${INC} -o ${OUTC}
	@${OUTC} < ${KEYFILE} > ${COUTFILE}
	@xxd ${COUTFILE}

stf:
	@openssl ${ENCMODE} -K ${KEY} -in ${INTXT} -out ${OUTTXT} 
	@xxd ${OUTTXT}

ssl:
	@openssl ${ENCMODE} -K ${KEY} -in ${INTXT}
	@echo ''

diff:
	@diff -y ${COUTFILE} ${OUTTXT} || exit 0
	@echo ''

clean:
	@rm ${OUTC}
	@rm ${STANDARDCOUT}

standard:
	@${GCC} ${STANDARDCFILE} -o ${STANDARDCOUT}
	@${STANDARDCOUT} > ${STANDARDTXT}
	@xxd ${STANDARDTXT}