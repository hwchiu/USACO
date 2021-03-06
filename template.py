#!/usr/local/bin/python
import sys
import os
if len(sys.argv) <=2:
	print "Usage: DirectoryName progName"
	sys.exit(0)
#Create directory
newpath = r'src/'+sys.argv[1] 
if not os.path.exists(newpath): 
	os.makedirs(newpath)
#Create c++ file
cppFile = open(newpath+"/"+sys.argv[2]+".cpp",'w')
content="\
/*\n\
ID: hwchiu1\n\
PROG: "+sys.argv[2]+"\n\
LANG: C++\n\
*/\n\
#include <iostream>\n\
#include <fstream>\n\
#include <string>\n\
using namespace std;\n\
int main() {\n\
    ofstream fout (\""+sys.argv[2]+".out\");\n\
    ifstream fin (\""+sys.argv[2]+".in\");\n\
    return 0;\n\
}"
cppFile.write(content)
cppFile.close()
#Create input file
inputFile = open(newpath+"/"+sys.argv[2]+".in",'w')
inputFile.close()
#Create MakeFile
makeFile  = open(newpath+"/Makefile",'w')
content="\
NAME := "+sys.argv[2]+"\n\
SRC := ${NAME}.cpp\n\
OUTPUT := ${NAME}.out\n\
CXX := clang++\n\
RM := /bin/rm\n\
\n\
all: install\n\
\n\
install: ${src}\n\
\t@${CXX} -o ${NAME} -O2 ${SRC}\n\
\n\
clean:\n\
\t@${RM} -f ${OUTPUT} ${NAME}\n\
"
makeFile.write(content)
makeFile.close();
