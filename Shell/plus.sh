n=`ls -l | grep "$1" | wc -l`
>$1.$n
echo "Created!"
