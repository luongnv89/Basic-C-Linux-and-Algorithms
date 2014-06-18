# $1: the name of file
# $2: The destination
n=`find $2 -name "$1"|wc -l`
if [ $n -ge 1 ]
then
	echo "The file exist already. Do you really want to overwrite it? Yes/No"
	read choi
	case $choi in
		"Yes" | "yes" | "y" | "Y" )
			cp $1 $2
			echo "Copied!";;
		"No" | "no" | "N" | "n" )
			echo "Aborted!";;
		* )
			echo "Error"
	esac
else
	cp $1 $2
	echo "Copied!"
fi
exit 0

