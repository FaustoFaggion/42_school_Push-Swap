make re
clear
printf "\n"
echo "3"
echo "===max 3 moves"
count=50
for i in $(seq $count); do
        ./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
done
printf "\n"
echo "100"
echo "===max 700 moves"
count=50
for i in $(seq $count); do
        ./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"` | wc -l
done
printf "\n"
echo "500"
echo "===5500 moves"
count=50
for i in $(seq $count); do
        ./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"` | wc -l
done
printf "\n"