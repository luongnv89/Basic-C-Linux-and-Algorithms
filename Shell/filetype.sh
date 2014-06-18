if [ $# -lt 1 ]
then
	echo "$0: file name missing" >&2
	echo "Usage: $0"
	exit 1
fi

for i in $*
do
	if [ -e $i ]
	then 
		echo "$i is regular file"
	elif [ -d $i ]
	then
		echo "$i is a directory"
	else
		echo "$i exists, but I wonder what it is .."
	fi
	else
		echo "$i does not exist"
	fi
done
exit 0
