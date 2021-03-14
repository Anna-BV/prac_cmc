set terminal jpeg size 1024, 768 background "#ffffff"
set output "Result_ y1_2_3.jpg"
set encoding utf8
set title "Модель Пыха" font "Times New Roman, 14" 
set xlabel "t - время"
set ylabel "Y_i"
set grid
set xrange [0:200]
set yrange [*:*]
plot "file.txt" using 1:2 title "Y_1" lc rgb "red" with lines , \
"file.txt" using 1:3 title "Y_2" lc rgb "green" with lines , \
"file.txt" using 1:4 title "Y_3" lc rgb "blue" with lines