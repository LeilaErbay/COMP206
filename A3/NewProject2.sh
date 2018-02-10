#!/bin/bash


#assigns the variables according to the number of arguments passed
NewProject=$0
total="$#"

#method used to determine if path is provided
touch textfile.txt
for s in $@
do
        echo "$s" >> textfile.txt
done

cfiles=`grep -c  "\.c" textfile.txt`

diff=$(($total-$cfiles))

#determine if a path is provided
if [ $diff -eq 1 ]
then
        project_name=$1
        path=""
else
        path=$1
        project_name=$2
fi
`rm -r textfile.txt`


#checks if the project name is missing
if [ "$project_name" = "" ]
then 
	echo 'Project name is missing. Type in: NewProject path project_name'
	exit
fi

#checks if the user has entered a path and if yes then it checks if it is of thecorrect form
if [ "$path" != "" ]
then 
	if [ -d "$path" ]
	then :
	else 
		echo 'Your path name is malformed. Type in: NewProject path project_name'
		exit
	fi
fi

#makes all the directories
if [ "$path" != "" ]
then
	mkdir "$path"/"$project_name"
	mkdir "$path"/"$project_name"/docs
	mkdir "$path"/"$project_name"/source
	mkdir "$path"/"$project_name"/backup
	mkdir "$path"/"$project_name"/archive
	  cd "$path"/"$project_name"/source
else
	mkdir "$project_name"
	mkdir "$project_name"/docs
	mkdir "$project_name"/source
	mkdir "$project_name"/backup
	mkdir "$project_name"/archive
	cd "$project_name"/source
fi 

#depending if path is provided or not, remove the .c extension of the source files and replace with .o using sed
if [ "$path" != "" ]
then

	declare -a sourceFiles 	
	j=0
	for i in "${@:3}"
        do
                sourceFiles[$j]=`echo $i| sed -r 's/.c$/.o/'`
		((j++))
		
	done
	
else
	declare -a sourceFiles	
	j=0
	for i in "${@:2}" 
	do
        	sourceFiles[$j]=`echo $i | sed -r 's/.c$/.o/'`
		((j++))  
	done
fi




#create a makefile and use make
touch makefile
chmod +x makefile

#set the compiler and target which will be a.out and check the condition for the corret files and compile 
echo "CC= gcc" >> makefile
echo "CFLAGS= -g -Wall">> makefile  
echo "TARGET= a.out" >> makefile
echo "FILES="${sourceFiles[@]}"" >> makefile


echo "\$(TARGET): \$(FILES) " >> makefile
echo "	\$(CC) \$(CFLAGS) \$^" >> makefile


	echo "%.o : %.c %.h" >> makefile
	echo "	\$(CC) -c \$^">> makefile
	((k++))

	echo "clean :" >> makefile
        echo "		rm -i -f *.o" >> makefile

exit
