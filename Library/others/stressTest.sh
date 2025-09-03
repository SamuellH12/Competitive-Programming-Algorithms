P=code   #mude pro filename do codigo
Q=brute  #mude pro filename do brute [correto]
g++ ${P}.cpp -o sol -O2 || exit 1
g++ ${Q}.cpp -o ans -O2 || exit 1
g++ gen.cpp  -o gen -O2 || exit 1
for ((i = 1; ; i++)) do
	echo $i
	./gen $i > in
	./sol < in > out
	./ans < in > out2
	if (! cmp -s out out2) then
		echo "--> entrada:"
		cat in
		echo "--> saida sol:"
		cat out
		echo "--> saida ans:"
		cat out2
		break;
	fi
done