if [ $# = 0 ]
then 
	param=`cat ~/.vrc`
else
	param=$*
	echo $* > ~/.vrc
fi
vi $param
