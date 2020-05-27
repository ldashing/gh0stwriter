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
L Driver_Motor:Pololu_Breakout_A4988 A3
U 1 1 5ECE574D
P 7600 4250
F 0 "A3" H 7650 5131 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 7650 5040 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 7875 3500 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 7700 3950 50  0001 C CNN
	1    7600 4250
	1    0    0    -1  
$EndComp
$Comp
L YAAJ_STM32:BluePill_1 BP?1
U 1 1 5ECE59A4
P 1350 3750
F 0 "BP?1" H 1925 3925 50  0000 C CNN
F 1 "BluePill_1" H 1925 3834 50  0000 C CNN
F 2 "bluepill:YAAJ_BluePill" H 2600 1800 50  0001 C CNN
F 3 "" H 2600 1800 50  0001 C CNN
	1    1350 3750
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A4
U 1 1 5ECF26AB
P 9400 4250
F 0 "A4" H 9450 5131 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 9450 5040 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 9675 3500 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 9500 3950 50  0001 C CNN
	1    9400 4250
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A1
U 1 1 5ECFA6A8
P 4100 4200
F 0 "A1" H 4150 5081 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 4150 4990 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4375 3450 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4200 3900 50  0001 C CNN
	1    4100 4200
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A2
U 1 1 5ECFA6AE
P 6250 4250
F 0 "A2" H 6300 5131 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 6300 5040 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 6525 3500 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 6350 3950 50  0001 C CNN
	1    6250 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_Darlington_ECB Q1
U 1 1 5ED142A8
P 6000 6350
F 0 "Q1" H 6190 6396 50  0000 L CNN
F 1 "Q_NPN_Darlington_ECB" H 6190 6305 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-126-3_Vertical" H 6200 6450 50  0001 C CNN
F 3 "~" H 6000 6350 50  0001 C CNN
	1    6000 6350
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4007 D1
U 1 1 5ED14C87
P 5900 6000
F 0 "D1" H 5900 6217 50  0000 C CNN
F 1 "1N4007" H 5900 6126 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp" H 5900 5825 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 5900 6000 50  0001 C CNN
	1    5900 6000
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5ED17FEE
P 6550 5950
F 0 "J4" H 6630 5942 50  0000 L CNN
F 1 "Conn_01x02" H 6630 5851 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B2B-XH-A_1x02_P2.50mm_Vertical" H 6550 5950 50  0001 C CNN
F 3 "~" H 6550 5950 50  0001 C CNN
	1    6550 5950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5ED1B6C9
P 4350 5700
F 0 "J2" H 4430 5692 50  0000 L CNN
F 1 "Conn_01x02" H 4430 5601 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B2B-XH-A_1x02_P2.50mm_Vertical" H 4350 5700 50  0001 C CNN
F 3 "~" H 4350 5700 50  0001 C CNN
	1    4350 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5ED1EAD0
P 2750 2550
F 0 "C2" H 2868 2596 50  0000 L CNN
F 1 "CP" H 2868 2505 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 2788 2400 50  0001 C CNN
F 3 "~" H 2750 2550 50  0001 C CNN
	1    2750 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5ED221E5
P 2400 2550
F 0 "C1" H 2518 2596 50  0000 L CNN
F 1 "CP" H 2518 2505 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 2438 2400 50  0001 C CNN
F 3 "~" H 2400 2550 50  0001 C CNN
	1    2400 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5ED2400A
P 3500 2550
F 0 "C4" H 3615 2596 50  0000 L CNN
F 1 "C" H 3615 2505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 3538 2400 50  0001 C CNN
F 3 "~" H 3500 2550 50  0001 C CNN
	1    3500 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5ED2C112
P 3150 2550
F 0 "C3" H 3265 2596 50  0000 L CNN
F 1 "C" H 3265 2505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 3188 2400 50  0001 C CNN
F 3 "~" H 3150 2550 50  0001 C CNN
	1    3150 2550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 SerialPort1
U 1 1 5ED3520C
P 2850 6700
F 0 "SerialPort1" H 2930 6692 50  0000 L CNN
F 1 "Conn_01x06" H 2930 6601 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 2850 6700 50  0001 C CNN
F 3 "~" H 2850 6700 50  0001 C CNN
	1    2850 6700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5ED48418
P 2700 3800
F 0 "#PWR0101" H 2700 3550 50  0001 C CNN
F 1 "GND" V 2705 3672 50  0000 R CNN
F 2 "" H 2700 3800 50  0001 C CNN
F 3 "" H 2700 3800 50  0001 C CNN
	1    2700 3800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5ED4AAB5
P 2700 3900
F 0 "#PWR0102" H 2700 3650 50  0001 C CNN
F 1 "GND" V 2705 3772 50  0000 R CNN
F 2 "" H 2700 3900 50  0001 C CNN
F 3 "" H 2700 3900 50  0001 C CNN
	1    2700 3900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5ED4C27A
P 1150 5600
F 0 "#PWR0103" H 1150 5350 50  0001 C CNN
F 1 "GND" V 1155 5472 50  0000 R CNN
F 2 "" H 1150 5600 50  0001 C CNN
F 3 "" H 1150 5600 50  0001 C CNN
	1    1150 5600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5ED4F987
P 2750 2700
F 0 "#PWR0104" H 2750 2450 50  0001 C CNN
F 1 "GND" V 2755 2572 50  0000 R CNN
F 2 "" H 2750 2700 50  0001 C CNN
F 3 "" H 2750 2700 50  0001 C CNN
	1    2750 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5ED4FD9E
P 3150 2700
F 0 "#PWR0105" H 3150 2450 50  0001 C CNN
F 1 "GND" V 3155 2572 50  0000 R CNN
F 2 "" H 3150 2700 50  0001 C CNN
F 3 "" H 3150 2700 50  0001 C CNN
	1    3150 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5ED50065
P 2400 2700
F 0 "#PWR0106" H 2400 2450 50  0001 C CNN
F 1 "GND" V 2405 2572 50  0000 R CNN
F 2 "" H 2400 2700 50  0001 C CNN
F 3 "" H 2400 2700 50  0001 C CNN
	1    2400 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5ED50348
P 3500 2700
F 0 "#PWR0107" H 3500 2450 50  0001 C CNN
F 1 "GND" V 3505 2572 50  0000 R CNN
F 2 "" H 3500 2700 50  0001 C CNN
F 3 "" H 3500 2700 50  0001 C CNN
	1    3500 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 5ED6DEAA
P 1150 5700
F 0 "#PWR0108" H 1150 5550 50  0001 C CNN
F 1 "+3V3" V 1165 5828 50  0000 L CNN
F 2 "" H 1150 5700 50  0001 C CNN
F 3 "" H 1150 5700 50  0001 C CNN
	1    1150 5700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5ED79C30
P 4100 5000
F 0 "#PWR0109" H 4100 4750 50  0001 C CNN
F 1 "GND" V 4105 4872 50  0000 R CNN
F 2 "" H 4100 5000 50  0001 C CNN
F 3 "" H 4100 5000 50  0001 C CNN
	1    4100 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5ED79EDD
P 4300 5000
F 0 "#PWR0110" H 4300 4750 50  0001 C CNN
F 1 "GND" V 4305 4872 50  0000 R CNN
F 2 "" H 4300 5000 50  0001 C CNN
F 3 "" H 4300 5000 50  0001 C CNN
	1    4300 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5ED7A1C8
P 6250 5050
F 0 "#PWR0111" H 6250 4800 50  0001 C CNN
F 1 "GND" V 6255 4922 50  0000 R CNN
F 2 "" H 6250 5050 50  0001 C CNN
F 3 "" H 6250 5050 50  0001 C CNN
	1    6250 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5ED7A4BD
P 6450 5050
F 0 "#PWR0112" H 6450 4800 50  0001 C CNN
F 1 "GND" V 6455 4922 50  0000 R CNN
F 2 "" H 6450 5050 50  0001 C CNN
F 3 "" H 6450 5050 50  0001 C CNN
	1    6450 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5ED7A825
P 7600 5050
F 0 "#PWR0113" H 7600 4800 50  0001 C CNN
F 1 "GND" V 7605 4922 50  0000 R CNN
F 2 "" H 7600 5050 50  0001 C CNN
F 3 "" H 7600 5050 50  0001 C CNN
	1    7600 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5ED7AA89
P 7800 5050
F 0 "#PWR0114" H 7800 4800 50  0001 C CNN
F 1 "GND" V 7805 4922 50  0000 R CNN
F 2 "" H 7800 5050 50  0001 C CNN
F 3 "" H 7800 5050 50  0001 C CNN
	1    7800 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5ED7CA89
P 9400 5050
F 0 "#PWR0115" H 9400 4800 50  0001 C CNN
F 1 "GND" V 9405 4922 50  0000 R CNN
F 2 "" H 9400 5050 50  0001 C CNN
F 3 "" H 9400 5050 50  0001 C CNN
	1    9400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5ED7CCB1
P 9600 5050
F 0 "#PWR0116" H 9600 4800 50  0001 C CNN
F 1 "GND" V 9605 4922 50  0000 R CNN
F 2 "" H 9600 5050 50  0001 C CNN
F 3 "" H 9600 5050 50  0001 C CNN
	1    9600 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0117
U 1 1 5ED85436
P 4100 3500
F 0 "#PWR0117" H 4100 3350 50  0001 C CNN
F 1 "+3V3" V 4115 3628 50  0000 L CNN
F 2 "" H 4100 3500 50  0001 C CNN
F 3 "" H 4100 3500 50  0001 C CNN
	1    4100 3500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0118
U 1 1 5ED85A0B
P 6250 3550
F 0 "#PWR0118" H 6250 3400 50  0001 C CNN
F 1 "+3V3" V 6265 3678 50  0000 L CNN
F 2 "" H 6250 3550 50  0001 C CNN
F 3 "" H 6250 3550 50  0001 C CNN
	1    6250 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0119
U 1 1 5ED86DA5
P 7600 3550
F 0 "#PWR0119" H 7600 3400 50  0001 C CNN
F 1 "+3V3" V 7615 3678 50  0000 L CNN
F 2 "" H 7600 3550 50  0001 C CNN
F 3 "" H 7600 3550 50  0001 C CNN
	1    7600 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0120
U 1 1 5ED87085
P 9400 3550
F 0 "#PWR0120" H 9400 3400 50  0001 C CNN
F 1 "+3V3" V 9415 3678 50  0000 L CNN
F 2 "" H 9400 3550 50  0001 C CNN
F 3 "" H 9400 3550 50  0001 C CNN
	1    9400 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0121
U 1 1 5EDA79ED
P 2400 2400
F 0 "#PWR0121" H 2400 2250 50  0001 C CNN
F 1 "+3V3" V 2415 2528 50  0000 L CNN
F 2 "" H 2400 2400 50  0001 C CNN
F 3 "" H 2400 2400 50  0001 C CNN
	1    2400 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0122
U 1 1 5EDA7C94
P 3150 2400
F 0 "#PWR0122" H 3150 2250 50  0001 C CNN
F 1 "+3V3" V 3165 2528 50  0000 L CNN
F 2 "" H 3150 2400 50  0001 C CNN
F 3 "" H 3150 2400 50  0001 C CNN
	1    3150 2400
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0123
U 1 1 5EDAC1D3
P 4300 3500
F 0 "#PWR0123" H 4100 3350 50  0001 C CNN
F 1 "Vdrive" H 4315 3673 50  0000 C CNN
F 2 "" H 4300 3500 50  0001 C CNN
F 3 "" H 4300 3500 50  0001 C CNN
	1    4300 3500
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0124
U 1 1 5EDBB3D5
P 6450 3550
F 0 "#PWR0124" H 6250 3400 50  0001 C CNN
F 1 "Vdrive" H 6465 3723 50  0000 C CNN
F 2 "" H 6450 3550 50  0001 C CNN
F 3 "" H 6450 3550 50  0001 C CNN
	1    6450 3550
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0125
U 1 1 5EDBC732
P 7800 3550
F 0 "#PWR0125" H 7600 3400 50  0001 C CNN
F 1 "Vdrive" H 7815 3723 50  0000 C CNN
F 2 "" H 7800 3550 50  0001 C CNN
F 3 "" H 7800 3550 50  0001 C CNN
	1    7800 3550
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0126
U 1 1 5EDBCBD1
P 9600 3550
F 0 "#PWR0126" H 9400 3400 50  0001 C CNN
F 1 "Vdrive" H 9615 3723 50  0000 C CNN
F 2 "" H 9600 3550 50  0001 C CNN
F 3 "" H 9600 3550 50  0001 C CNN
	1    9600 3550
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0127
U 1 1 5EDC054C
P 2750 2400
F 0 "#PWR0127" H 2550 2250 50  0001 C CNN
F 1 "Vdrive" H 2765 2573 50  0000 C CNN
F 2 "" H 2750 2400 50  0001 C CNN
F 3 "" H 2750 2400 50  0001 C CNN
	1    2750 2400
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0128
U 1 1 5EDC0874
P 3500 2400
F 0 "#PWR0128" H 3300 2250 50  0001 C CNN
F 1 "Vdrive" H 3515 2573 50  0000 C CNN
F 2 "" H 3500 2400 50  0001 C CNN
F 3 "" H 3500 2400 50  0001 C CNN
	1    3500 2400
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0129
U 1 1 5EDC7B2F
P 6350 5950
F 0 "#PWR0129" H 6150 5800 50  0001 C CNN
F 1 "Vdrive" H 6365 6123 50  0000 C CNN
F 2 "" H 6350 5950 50  0001 C CNN
F 3 "" H 6350 5950 50  0001 C CNN
	1    6350 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 5850 6200 5850
Wire Wire Line
	6200 5850 6200 5950
Wire Wire Line
	6200 5950 6350 5950
Connection ~ 6350 5950
Wire Wire Line
	6350 6050 6250 6050
Wire Wire Line
	6250 6050 6250 6150
Wire Wire Line
	6250 6150 6100 6150
Connection ~ 6100 6150
Wire Wire Line
	6100 6150 5900 6150
$Comp
L power:GND #PWR0130
U 1 1 5EDDA290
P 6100 6550
F 0 "#PWR0130" H 6100 6300 50  0001 C CNN
F 1 "GND" H 6105 6377 50  0000 C CNN
F 2 "" H 6100 6550 50  0001 C CNN
F 3 "" H 6100 6550 50  0001 C CNN
	1    6100 6550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0131
U 1 1 5EDEF778
P 4150 5800
F 0 "#PWR0131" H 4150 5550 50  0001 C CNN
F 1 "GND" H 4155 5627 50  0000 C CNN
F 2 "" H 4150 5800 50  0001 C CNN
F 3 "" H 4150 5800 50  0001 C CNN
	1    4150 5800
	1    0    0    -1  
$EndComp
Text GLabel 2650 6600 0    50   BiDi ~ 0
PA9
Text GLabel 1150 4300 0    50   BiDi ~ 0
PA9
Text GLabel 2650 6700 0    50   BiDi ~ 0
PA10
$Comp
L power:GND #PWR0132
U 1 1 5EDF829F
P 2650 7000
F 0 "#PWR0132" H 2650 6750 50  0001 C CNN
F 1 "GND" H 2655 6827 50  0000 C CNN
F 2 "" H 2650 7000 50  0001 C CNN
F 3 "" H 2650 7000 50  0001 C CNN
	1    2650 7000
	1    0    0    -1  
$EndComp
Text GLabel 1150 4400 0    50   BiDi ~ 0
PA10
Text GLabel 3700 3800 0    50   BiDi ~ 0
ICReset
Text GLabel 5850 3850 0    50   BiDi ~ 0
ICReset
Text GLabel 7200 3850 0    50   BiDi ~ 0
ICReset
Text GLabel 9000 3850 0    50   BiDi ~ 0
ICReset
Text GLabel 800  4200 0    50   BiDi ~ 0
ICReset
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 5EE5F861
P 6950 4150
F 0 "J3" H 7030 4142 50  0000 L CNN
F 1 "Conn_01x06" H 7030 4051 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B6B-XH-A_1x06_P2.50mm_Vertical" H 6950 4150 50  0001 C CNN
F 3 "~" H 6950 4150 50  0001 C CNN
	1    6950 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J5
U 1 1 5EE60300
P 8300 4150
F 0 "J5" H 8380 4142 50  0000 L CNN
F 1 "Conn_01x06" H 8380 4051 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B6B-XH-A_1x06_P2.50mm_Vertical" H 8300 4150 50  0001 C CNN
F 3 "~" H 8300 4150 50  0001 C CNN
	1    8300 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J6
U 1 1 5EE6112C
P 10100 4150
F 0 "J6" H 10180 4142 50  0000 L CNN
F 1 "Conn_01x06" H 10180 4051 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B6B-XH-A_1x06_P2.50mm_Vertical" H 10100 4150 50  0001 C CNN
F 3 "~" H 10100 4150 50  0001 C CNN
	1    10100 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J1
U 1 1 5EE5D6A5
P 4800 4100
F 0 "J1" H 4880 4092 50  0000 L CNN
F 1 "Conn_01x06" H 4880 4001 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B6B-XH-A_1x06_P2.50mm_Vertical" H 4800 4100 50  0001 C CNN
F 3 "~" H 4800 4100 50  0001 C CNN
	1    4800 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 5EEAEDB9
P 4400 2550
F 0 "J7" H 4480 2542 50  0000 L CNN
F 1 "Conn_01x02" H 4480 2451 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2_1x02_P5.00mm_Horizontal" H 4400 2550 50  0001 C CNN
F 3 "~" H 4400 2550 50  0001 C CNN
	1    4400 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0133
U 1 1 5EEB0595
P 4200 2650
F 0 "#PWR0133" H 4200 2400 50  0001 C CNN
F 1 "GND" H 4205 2477 50  0000 C CNN
F 2 "" H 4200 2650 50  0001 C CNN
F 3 "" H 4200 2650 50  0001 C CNN
	1    4200 2650
	1    0    0    -1  
$EndComp
$Comp
L power:Vdrive #PWR0134
U 1 1 5EEB1E7D
P 4200 2550
F 0 "#PWR0134" H 4000 2400 50  0001 C CNN
F 1 "Vdrive" H 4215 2723 50  0000 C CNN
F 2 "" H 4200 2550 50  0001 C CNN
F 3 "" H 4200 2550 50  0001 C CNN
	1    4200 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5EEC46BA
P 5650 6350
F 0 "R1" V 5443 6350 50  0000 C CNN
F 1 "R" V 5534 6350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5580 6350 50  0001 C CNN
F 3 "~" H 5650 6350 50  0001 C CNN
	1    5650 6350
	0    1    1    0   
$EndComp
Text GLabel 1150 3800 0    50   BiDi ~ 0
Hammer
Text GLabel 5500 6350 0    50   BiDi ~ 0
Hammer
Text GLabel 4150 5700 0    50   BiDi ~ 0
Endstop
Text GLabel 1150 3900 0    50   BiDi ~ 0
Endstop
$EndSCHEMATC
