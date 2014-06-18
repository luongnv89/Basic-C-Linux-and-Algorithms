n=`find -name "$1"|wc -l`
if [ $n -ge 1 ]
then 
	m=`ls -l|grep "$1"|head -n 1|cut -c1`
	if [ $m = "-" ]
	then 
		echo "It is a regular file"
	elif [ $m = "d" ]
	then 
		echo "It is a directory"
	else
		echo "Undefined"
	fi
else
	echo "It doesn't exist"
fi
exit 0
