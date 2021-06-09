echo "Enter two numbers"
read a;
read b;
echo "Enter the operator"
read op
case $op in
'+') echo "$a + $b = $((a + b))"
	;;
'-') echo "$a - $b = $((a - b))"
	;;
'*') echo "$a * $b = $((a * b))"
	;;
'/') echo "$a / $b = $((a / b))"
	;;
esac
