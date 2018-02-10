#!/bin/bash

#if data file is empty then remove file  use randomNumGenerator function to create 10 numbersin Data.pg file
if [ -s Data.pg ]
then
	rm Data.pg
	touch Data.pg
	echo "file is empty and newly created"
	randomNumGenerator () {
	i=0
	while [ $i -lt 10 ]
 	do
		 x=$(( $RANDOM % 50 +1 ))
 		echo -e "$x"
 		let i=i+1
	done
	}
	randomNumGenerator >> Data.pg
#condition if Data.pg file is a regular file
elif [ -f Data.pg ]
then
	touch Data.pg
	echo "file created"
	randomNumGenerator () {
	i=0
	while [ $i -lt 10 ]
	do
		x=$(( $RANDOM % 50 +1 ))
		let i=i+1
	done
	}
	randomNumGenerator >> Data.pg
fi 

counter=0
#keeps track of number of people playing
echo "enter number of people playing please, no more than 10"
read numPlayers

while [ $counter -lt $numPlayers ]
do
	#each person gets three tries
	tries=0
	while [ $tries -lt 3 ]
 	do
 		echo "player $counter enter a guess"
 		read guess
		#echo error if guess is not between range of 1 and 50
 		if [ $guess -gt 50 ] || [ $guess -lt 1 ]
 		then
 			echo "guesses must not be less than 1 or greater than 50" 
 		else
		#else remove first element of data and remove blank space of data
 			sed -i '1d' Data.pg && sed '/./!d' Data.pg
 			#append guess to Data
			echo "$guess" >> Data.pg
 		fi
		sum=0 
		i=0 
	 	while [ $i -lt 10 ] 
 		do
		#loop through numbers in Data and generate a sum
 			read num < Data.pg
 			sum=`expr $sum + $num`
 			let i=i+1
 		done 
		
		#create an average of the sum 
		ave=`echo "$sum/10" | bc` 
 		
		#determine 2/3 of the average	
		winAve=$(echo "scale=2;$ave * (2/3)" | bc)
		
		#determine upper and lower bound of the correct ave
		lowRange=$(echo "scale=2;$winAve*(.95)" | bc) 

		highRange=$(echo "scale=2;$winAve*(1.1)" | bc)	

		guess=$(echo "$guess*1.0" | bc)

		triesToCorrect=0
		
		#create an array of tries to store the number of tries per person
	 	declare -a arrayTries 
		if [ ! $(bc <<< "$guess >= $lowRange") ] && [ ! $(bc <<< "$guess <= $highRange") ]
		then 
			#update the number of tries
  			echo "you've guessed it right"  
  			triesToCorrect=`expr $triesToCorrect + $triesToCorrect`
  			arrayTries[$counter]=$triesToCorrect 
  			echo "Well done. You took $triesToCorrect" 
  			break
		# if player takes the max tries then he didn't guess correctly and thus took 3 tries
 		elif [ $tries -eq 2 ]
 		then 
 			echo "you took the max tries and didn't answer the correct answer"
 			triesToCorrect=3
			arrayTries[$counter]=$triesToCorrect
		else
  			echo "Incorrect guess. Continue guessing and Try again"
		fi
	let tries=tries+1 
	done
let counter=counter+1
done 


sumTries=0
echo "$numPlayers players took tries: " 
#loop through the number of tries
for i in "${arrayTries[@]}"
do
	echo "$i"
	sumTries=`expr $sumTries + $i`
done

#tell user the ave number of tries of all the players
aveTries=`echo "$sumTries/$numPlayers" | bc`
echo "So average number of tries: $aveTries"

