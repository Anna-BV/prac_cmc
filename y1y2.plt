set terminal jpeg size 1024, 768 background "#ffffff"
set output "Result_ y2_1.jpg"
set encoding utf8
set title "Модель Пыха" font "Times New Roman, 14" 
set xlabel "Y1"
set ylabel "Y2"
set grid
set xrange [*:*]
set yrange [*:*]
plot "file.txt" using 2:3 title "Y_2-Y_1" lc rgb "red" with lines 
