
sdcc -mmcs51  --iram-size 256 --xram-size 0 --code-size 4088 --verbose read_pot.c -o read_pot.ihx
packihx read_pot.ihx > read_pot.hex

pause
