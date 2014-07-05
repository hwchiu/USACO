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
ID: your_id_here\n\
PROG: "+sys.argv[2]+"\n\
LANG: C++\n\
*/\n\
#include <iostream>\n\
#include <fstream>\n\
#include <string>\n\
using namespace std;\n\
int main() {\n\
    ofstream fout (\""+sys.argv[2]+"\");\n\
    ifstream fin (\""+sys.argv[2]+"\");\n\
    return 0;\n\
}"
cppFile.write(content)
cppFile.close()
inputFile = open(newpath+"/"+sys.argv[2]+".in",'w')
inputFile.close()
