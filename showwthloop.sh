
yes 2> /dev/null|grep -n '.'|head -n $1|cut -d':' -f1
