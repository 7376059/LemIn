mkdir new
for i in {1..200}
do
	echo $i
	./generator --big-superposition > ./new/map_$i
	../tools/checker.sh ../LemIn/lem-in ./new/map_$i
done
#rm -rf new
