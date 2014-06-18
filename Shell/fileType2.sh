if [ $# -lt 1 ]
then
	echo "$0: file name missing" >&2
	echo "Usage: $0"
	exit 1
fi

for i in $*
do
	[ -e $i ] || echo "$i is regular file"
	[ -d $i ] && echo "$i is a directory"
	[ -f $i ] && echo "$i exists, but I wonder what it is .."
done
exit 0
