#!/usr/local/bin/python3
import subprocess 
import os
fileStr =  subprocess.check_output(["find","src/","-name","*.cpp"]).decode("utf-8")
fileList = "".join(fileStr).split("\n")
name = "tabTemp"
for f in fileList:
    if not f:
        continue
    print ("Processing file {}".format(f))
    tmp = open(name,mode='w+')
    subprocess.call(["expand","-t","4",f],stdout=tmp) 
    tmp2 = open(f,mode="w+")
    subprocess.call(["cat",name],stdout=tmp2)
    tmp.close()
    tmp2.close()
	

os.remove(name)
