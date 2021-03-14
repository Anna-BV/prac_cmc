set terminal jpeg size 1024, 768 background "#ffffff"
set output "Result_ y3_2.jpg"
set encoding utf8
set title "Модель Пыха" font "Times New Roman, 14" 
set xlabel "Y2"
set ylabel "Y3"
set grid
set xrange [0:5]
set yrange [*:*]
plot "file.txt" using 3:4 title "Y_3-Y_2" lc rgb "green" with lines 
