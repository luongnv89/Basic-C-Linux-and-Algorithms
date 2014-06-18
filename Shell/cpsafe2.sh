if [ -e $2 ]
then 
	echo "$2 already exists. Do you really want to overwite it?"
	read answer
	if [ "$answer" = "no" ]
	then
		exit 0
	fi
fi
cp $1 $2

