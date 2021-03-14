set terminal jpeg size 1024, 768 background "#ffffff"
set output "Result_ y3_1.jpg"
set encoding utf8
set title "Модель Пыха" font "Times New Roman, 14" 
set xlabel "Y1"
set ylabel "Y3"
set grid
set xrange [0:3]
set yrange [*:*]
plot "file.txt" using 2:4 title "Y_1-Y_3" lc rgb "blue" with lines 
