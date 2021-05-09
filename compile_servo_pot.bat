
sdcc -mmcs51  --iram-size 256 --xram-size 0 --code-size 4088 --verbose servo_pot.c -o servo_pot.ihx
packihx servo_pot.ihx > servo_pot.hex

pause
