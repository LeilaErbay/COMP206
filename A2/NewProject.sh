#!/bin/bash

#conditions to check if there is a project name
if [ $# -le 1 ] || ([ $# -lt 2 ] && [ -d $2 ])
then
	echo "Project name is missing. Type in: NewProject path project_name"
	echo "script has terminated"
	exit 1
fi

# conditions to see if the path provided is valid
while [ ! -d $1 ] && [ $# -le 3 ]
do
	echo "Your path name is malformed. Type in: NewProject path project_name"
	echo "script has terminated"
	exit 1
done 

#conditions to check if project name is one word
if [ $# -gt 2 ]
then
	echo "Your project name must be one word"
	exit 1
fi

# if path is given, create subdirectory in path
if [ $# -eq 2 ] && [ -d $1 ] 
	then 
	cd $1 && mkdir $2
	echo "a new directory has been made in the given path"
	cd $2
	mkdir docs
	mkdir source
 	mkdir backup
 	mkdir archive
	cd source

#creating compile script
	echo '#!/bin/bash' >> compile
       #if no inputs than error
	echo 'if [ "$#" -eq 0 ] ' >> compile
        echo 'then' >> compile
        echo 'echo "you are missing file names. Type in: compile -o executable_name file_name(s)"' >> compile
        echo 'fi' >> compile
	#if first input is a -o then there will be an error
        echo 'if [ "$1" == "-o" ]' >> compile
        echo 'then' >> compile
        echo 'execFile="$2".out' >> compile
	#create an array of the positional params
        echo 'params=("$@")' >> compile
        echo 'shift' >> compile
        echo 'shift' >> compile
        echo 'while [ $# -ne 0 ]' >> compile
        echo 'do' >> compile
	#loop through positional params (ie c files)
	echo 'params+=($1)' >> compile
        echo 'shift' >> compile
        echo 'done' >> compile
        echo 'cp ${params[*]} ../backup' >> compile
	#gcc
        echo 'echo `gcc -o "$execFile" ${params[*]}` >& "errors.txt"' >> compile
        echo 'more "errors.txt"' >> compile
        #if no -o is provided then a.out will be used 
	echo 'else' >> compile
        echo 'execFile=a.out' >> compile
        echo 'params=("$@")' >> compile
        echo 'shift' >> compile
        echo 'while [ $# -ne 0 ]' >> compile
        echo 'do' >> compile
        echo 'params+=($1)' >> compile
        echo 'shift' >> compile
        echo 'done' >> compile
	#copy .c files to backup
        echo 'cp ${params[*]} ../backup' >> compile
        #execute gcc
	echo 'echo `gcc -o "$execFile" ${params[*]}` >& "errors.txt"' >> compile
        echo 'more "errors.txt"' >> compile
        echo 'fi' >> compile
	chmod a+x compile 
fi

if [ $# -eq 1 ]
 then
	mkdir $1
	echo " new directory has been made in the current directory"
	cd $1
	mkdir  docs
	mkdir source
	mkdir backup
	mkdir archive
	cd source
	echo '#!/bin/bash' >> compile	
	#if no positional params -- error is shown
	echo 'if [ "$#" -eq 0 ] ' >> compile
        echo 'then' >> compile
	echo 'echo "you are missing file names. Type in: compile -o executable_name file_name(s)"' >> compile
        echo 'fi' >> compile
	#if positional param 1 is -o then executable file name
        echo 'if [ "$1" == "-o" ]' >> compile
        echo 'then' >> compile
        #executable file is given
	echo 'execFile="$2".out' >> compile
	echo 'params=("$@")' >> compile
        echo 'shift' >> compile
        echo 'shift' >> compile
	#looping through positional params
	echo 'while [ $# -ne 0 ]' >> compile
	echo 'do' >> compile
	echo 'params+=($1)' >> compile
	echo 'shift' >> compile
	echo 'done' >> compile
	#copy all .c files to backup
	echo 'cp ${params[*]} ../backup' >> compile
	#show error message
	echo 'echo `gcc -o "$execFile" ${params[*]}` >& "errors.txt"' >> compile
	echo 'more "errors.txt"' >> compile
	#if exec file is not given then a.out will be provided
	echo 'else' >> compile
	echo 'execFile=a.out' >> compile
	echo 'array=("$@")' >> compile
        echo 'shift' >> compile
	#loop through positional params
	echo 'while [ $# -ne 0 ]' >> compile
        echo 'do' >> compile
        echo 'params+=($1)' >> compile
        echo 'shift' >> compile
        echo 'done' >> compile
	#copy .c files to backup
        echo 'cp ${params[*]} ../backup' >> compile
        #execute gcc
	echo 'echo `gcc -o "$execFile" ${params[*]}` >& "errors.txt"' >> compile
        echo 'more "errors.txt"' >> compile
        echo 'fi' >> compile
        chmod a+x compile
fi

