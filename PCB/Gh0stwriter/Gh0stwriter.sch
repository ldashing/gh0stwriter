EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A1
U 1 1 5ECE574D
P 5650 3750
F 0 "A1" H 5700 4631 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 5700 4540 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 5925 3000 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 5750 3450 50  0001 C CNN
	1    5650 3750
	1    0    0    -1  
$EndComp
$Comp
L YAAJ_STM32:BluePill_1 BP?1
U 1 1 5ECE59A4
P 2600 4700
F 0 "BP?1" H 3175 4875 50  0000 C CNN
F 1 "BluePill_1" H 3175 4784 50  0000 C CNN
F 2 "bluepill:YAAJ_BluePill" H 3850 2750 50  0001 C CNN
F 3 "" H 3850 2750 50  0001 C CNN
	1    2600 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 4750 5650 4750
Wire Wire Line
	5650 4750 5650 4550
$EndSCHEMATC
