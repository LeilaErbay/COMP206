#!/bin/bash

#NewProject.sh file given by professor

#assigns the variables acording to the number of arguments passed
NewProject=$0
if [ $# = 2 ]
then
	path=$1
	project_name=$2
else
	project_name=$1
	path=""
fi

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

#creates a file named compile in source and makes it executable
touch compile
chmod +x compile

echo "#!/bin/bash
#check if the input is in the correct format 

if [ "'"$1"'" = "'"-o"'" ]
then
   switch="'"$1"'"
   exename="'"$2"'"
   filenames="'"${@:3}"'"
   echo "'"$filenames"'"
else
   filenames="'"${@:1}"'"
fi

if [ "'"$filenames"'" = "'"null"'" ];
then
   echo "'"You are missing file names. Type in: compile -o executable_name file_names"'"
   exit
fi

#copy everything in the backup dir
cp -r * ../backup/

if [ "'"$1"'" = "'"-o"'" ]
then
   gcc -o "'"$exename"'" "'"$filenames"'" 2> error.txt
else
   gcc "'"$filenames"'" 2> error.txt
fi

more error.txt
" > compile

exit



