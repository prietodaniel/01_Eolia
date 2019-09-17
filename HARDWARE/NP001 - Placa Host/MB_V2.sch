EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:microchip_pic24mcu
LIBS:microchip_pic16mcu
LIBS:PrototipoMB-cache
LIBS:LT1054
LIBS:SamacSys_Parts
LIBS:MB_V2-cache
EELAYER 25 0
EELAYER END
$Descr A2 23386 16535
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
L R R11
U 1 1 5C849848
P 17150 4950
F 0 "R11" V 17230 4950 50  0000 C CNN
F 1 "4.7K" V 17150 4950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 17080 4950 50  0001 C CNN
F 3 "" H 17150 4950 50  0001 C CNN
	1    17150 4950
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 5C849849
P 17350 4950
F 0 "R12" V 17430 4950 50  0000 C CNN
F 1 "4.7K" V 17350 4950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 17280 4950 50  0001 C CNN
F 3 "" H 17350 4950 50  0001 C CNN
	1    17350 4950
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5C84984A
P 17550 4950
F 0 "R13" V 17630 4950 50  0000 C CNN
F 1 "4.7K" V 17550 4950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 17480 4950 50  0001 C CNN
F 3 "" H 17550 4950 50  0001 C CNN
	1    17550 4950
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 5C84984B
P 17750 4950
F 0 "R14" V 17830 4950 50  0000 C CNN
F 1 "4.7K" V 17750 4950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 17680 4950 50  0001 C CNN
F 3 "" H 17750 4950 50  0001 C CNN
	1    17750 4950
	1    0    0    -1  
$EndComp
$Comp
L CP C9
U 1 1 5C849850
P 17050 7250
F 0 "C9" H 16850 7350 50  0000 L CNN
F 1 "10uF" H 16850 7150 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Hand" H 17088 7100 50  0001 C CNN
F 3 "" H 17050 7250 50  0001 C CNN
	1    17050 7250
	0    -1   -1   0   
$EndComp
$Comp
L R R10
U 1 1 5C849851
P 14100 4900
F 0 "R10" V 14180 4900 50  0000 C CNN
F 1 "4k7" V 14100 4900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 14030 4900 50  0001 C CNN
F 3 "" H 14100 4900 50  0001 C CNN
	1    14100 4900
	0    1    1    0   
$EndComp
$Comp
L CP C5
U 1 1 5C849857
P 10300 4900
F 0 "C5" H 10350 5000 50  0000 L CNN
F 1 "1uF" H 10350 4800 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Hand" H 10338 4750 50  0001 C CNN
F 3 "" H 10300 4900 50  0001 C CNN
	1    10300 4900
	1    0    0    -1  
$EndComp
Text GLabel 10750 4600 2    60   Input ~ 0
VDD1
$Comp
L +3.3V #PWR01
U 1 1 5C849859
P 10300 4450
F 0 "#PWR01" H 10300 4300 50  0001 C CNN
F 1 "+3.3V" H 10300 4600 50  0000 C CNN
F 2 "" H 10300 4450 50  0001 C CNN
F 3 "" H 10300 4450 50  0001 C CNN
	1    10300 4450
	1    0    0    -1  
$EndComp
Text GLabel 8150 4150 0    60   Input ~ 0
VDD2
Text GLabel 5800 4850 0    60   Input ~ 0
VDD2
Text GLabel 5750 5550 0    60   Input ~ 0
GND
Text GLabel 18200 4750 2    60   Input ~ 0
VDD1
Text GLabel 15500 7750 3    60   Input ~ 0
VSS1
Text GLabel 21000 5900 2    60   Input ~ 0
VSS1
$Comp
L Conn_01x05 J7
U 1 1 5C84985A
P 13750 4650
F 0 "J7" H 13750 4950 50  0000 C CNN
F 1 "PICKIT3" V 13850 4650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 13750 4650 50  0001 C CNN
F 3 "" H 13750 4650 50  0001 C CNN
	1    13750 4650
	0    1    -1   0   
$EndComp
Text GLabel 14400 5300 2    60   Input ~ 0
VSS1
Text GLabel 14400 5100 2    60   Input ~ 0
VDD1
$Comp
L Conn_01x05 J10
U 1 1 5C84985B
P 15550 3150
F 0 "J10" H 15550 3450 50  0000 C CNN
F 1 "GPS/GPRS" V 15650 3150 50  0000 C CNN
F 2 "Connectors_JST:JST_PH_B5B-PH-SM4-TB_05x2.00mm_Straight" H 15550 3150 50  0001 C CNN
F 3 "" H 15550 3150 50  0001 C CNN
	1    15550 3150
	0    1    -1   0   
$EndComp
Text GLabel 15850 3600 2    60   Input ~ 0
VDD2
$Comp
L R R6
U 1 1 5C84985C
P 13100 7150
F 0 "R6" V 13180 7150 50  0000 C CNN
F 1 "4.7K" V 13100 7150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 13030 7150 50  0001 C CNN
F 3 "" H 13100 7150 50  0001 C CNN
	1    13100 7150
	0    1    -1   0   
$EndComp
$Comp
L R R7
U 1 1 5C84985D
P 13100 7350
F 0 "R7" V 13180 7350 50  0000 C CNN
F 1 "4.7K" V 13100 7350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 13030 7350 50  0001 C CNN
F 3 "" H 13100 7350 50  0001 C CNN
	1    13100 7350
	0    1    -1   0   
$EndComp
Text GLabel 12700 7150 0    60   Input ~ 0
VDD1
$Comp
L Conn_01x02 J5
U 1 1 5C84985E
P 8600 4400
F 0 "J5" H 8600 4600 50  0000 C CNN
F 1 "POWER_MB" V 8750 4400 50  0000 C CNN
F 2 "Connectors_JST:JST_PH_B2B-PH-SM4-TB_02x2.00mm_Straight" H 8600 4400 50  0001 C CNN
F 3 "" H 8600 4400 50  0001 C CNN
	1    8600 4400
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5C84985F
P 9700 5150
F 0 "#PWR02" H 9700 4900 50  0001 C CNN
F 1 "GND" H 9700 5000 50  0000 C CNN
F 2 "" H 9700 5150 50  0001 C CNN
F 3 "" H 9700 5150 50  0001 C CNN
	1    9700 5150
	1    0    0    -1  
$EndComp
Text GLabel 15500 5250 1    60   Input ~ 0
VDD1
$Comp
L PIC24FJ64GB002-I/P U3
U 1 1 5C849861
P 15450 6450
F 0 "U3" H 16000 7550 50  0000 L CNN
F 1 "PIC24FJ64GB002-I/P" H 16000 7450 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-28W_7.5x17.9mm_Pitch1.27mm" H 15450 6450 50  0001 C CIN
F 3 "" H 15450 6250 50  0001 C CNN
	1    15450 6450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5C849862
P 15350 3600
F 0 "#PWR03" H 15350 3350 50  0001 C CNN
F 1 "GND" H 15350 3450 50  0000 C CNN
F 2 "" H 15350 3600 50  0001 C CNN
F 3 "" H 15350 3600 50  0001 C CNN
	1    15350 3600
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 5C84986F
P 12850 5550
F 0 "D1" H 12850 5650 50  0000 C CNN
F 1 "LED" H 12850 5450 50  0000 C CNN
F 2 "LEDs:LED_0805_HandSoldering" H 12850 5550 50  0001 C CNN
F 3 "" H 12850 5550 50  0001 C CNN
	1    12850 5550
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5C849870
P 13300 5550
F 0 "R8" V 13380 5550 50  0000 C CNN
F 1 "220" V 13300 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 13230 5550 50  0001 C CNN
F 3 "" H 13300 5550 50  0001 C CNN
	1    13300 5550
	0    1    1    0   
$EndComp
Text GLabel 12550 5550 0    60   Input ~ 0
VSS1
$Comp
L LED D2
U 1 1 5C849871
P 12850 5850
F 0 "D2" H 12850 5950 50  0000 C CNN
F 1 "LED" H 12850 5750 50  0000 C CNN
F 2 "LEDs:LED_0805_HandSoldering" H 12850 5850 50  0001 C CNN
F 3 "" H 12850 5850 50  0001 C CNN
	1    12850 5850
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5C849872
P 13300 5850
F 0 "R9" V 13380 5850 50  0000 C CNN
F 1 "220" V 13300 5850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 13230 5850 50  0001 C CNN
F 3 "" H 13300 5850 50  0001 C CNN
	1    13300 5850
	0    1    1    0   
$EndComp
Text GLabel 12550 5850 0    60   Input ~ 0
VSS1
NoConn ~ 16750 5850
NoConn ~ 14150 6750
NoConn ~ 14150 6850
NoConn ~ 14150 6950
$Comp
L +5V #PWR04
U 1 1 5C849873
P 9100 4450
F 0 "#PWR04" H 9100 4300 50  0001 C CNN
F 1 "+5V" H 9100 4600 50  0000 C CNN
F 2 "" H 9100 4450 50  0001 C CNN
F 3 "" H 9100 4450 50  0001 C CNN
	1    9100 4450
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 5C849875
P 8350 3950
F 0 "#FLG05" H 8350 4025 50  0001 C CNN
F 1 "PWR_FLAG" H 8350 4100 50  0000 C CNN
F 2 "" H 8350 3950 50  0001 C CNN
F 3 "" H 8350 3950 50  0001 C CNN
	1    8350 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5C849878
P 8400 3500
F 0 "#PWR06" H 8400 3250 50  0001 C CNN
F 1 "GND" H 8400 3350 50  0000 C CNN
F 2 "" H 8400 3500 50  0001 C CNN
F 3 "" H 8400 3500 50  0001 C CNN
	1    8400 3500
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P J6
U 1 1 5C84987B
P 13400 6900
F 0 "J6" H 13400 7170 50  0000 C CNN
F 1 "TP_SCL" H 13400 7100 50  0000 C CNN
F 2 "Connectors:PINTST" H 13600 6900 50  0001 C CNN
F 3 "" H 13600 6900 50  0001 C CNN
	1    13400 6900
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P J8
U 1 1 5C84987C
P 13750 6900
F 0 "J8" H 13750 7170 50  0000 C CNN
F 1 "TP_SDA" H 13750 7100 50  0000 C CNN
F 2 "Connectors:PINTST" H 13950 6900 50  0001 C CNN
F 3 "" H 13950 6900 50  0001 C CNN
	1    13750 6900
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P J9
U 1 1 5C84987F
P 15350 3800
F 0 "J9" H 15350 4070 50  0000 C CNN
F 1 "TP_TX_PIC" H 15350 4000 50  0000 C CNN
F 2 "Connectors:PINTST" H 15550 3800 50  0001 C CNN
F 3 "" H 15550 3800 50  0001 C CNN
	1    15350 3800
	-1   0    0    1   
$EndComp
$Comp
L TEST_1P J11
U 1 1 5C849880
P 15800 3800
F 0 "J11" H 15800 4070 50  0000 C CNN
F 1 "TP_RX_PIC" H 15800 4000 50  0000 C CNN
F 2 "Connectors:PINTST" H 16000 3800 50  0001 C CNN
F 3 "" H 16000 3800 50  0001 C CNN
	1    15800 3800
	-1   0    0    1   
$EndComp
$Comp
L TEST_1P J12
U 1 1 5C849881
P 18050 5150
F 0 "J12" V 17950 5250 50  0000 C CNN
F 1 "TP_SDO" V 18050 5500 50  0000 C CNN
F 2 "Connectors:PINTST" H 18250 5150 50  0001 C CNN
F 3 "" H 18250 5150 50  0001 C CNN
	1    18050 5150
	0    1    1    0   
$EndComp
$Comp
L TEST_1P J13
U 1 1 5C849882
P 18050 5300
F 0 "J13" V 17950 5400 50  0000 C CNN
F 1 "TP_SCK" V 18050 5650 50  0000 C CNN
F 2 "Connectors:PINTST" H 18250 5300 50  0001 C CNN
F 3 "" H 18250 5300 50  0001 C CNN
	1    18050 5300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR07
U 1 1 5C849883
P 17350 7400
F 0 "#PWR07" H 17350 7150 50  0001 C CNN
F 1 "GND" H 17350 7250 50  0000 C CNN
F 2 "" H 17350 7400 50  0001 C CNN
F 3 "" H 17350 7400 50  0001 C CNN
	1    17350 7400
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5C84B875
P 17050 6800
F 0 "Y1" H 17050 6950 50  0000 C CNN
F 1 "8MHz" H 17050 6650 50  0000 C CNN
F 2 "Crystals:Crystal_SMD_HC49-SD_HandSoldering" H 17050 6800 50  0001 C CNN
F 3 "" H 17050 6800 50  0001 C CNN
	1    17050 6800
	0    1    1    0   
$EndComp
$Comp
L C C10
U 1 1 5C84BB6A
P 17500 6550
F 0 "C10" H 17525 6650 50  0000 L CNN
F 1 "33pF" H 17525 6450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 17538 6400 50  0001 C CNN
F 3 "" H 17500 6550 50  0001 C CNN
	1    17500 6550
	0    1    1    0   
$EndComp
$Comp
L C C11
U 1 1 5C84D0BD
P 17500 7050
F 0 "C11" H 17350 7150 50  0000 L CNN
F 1 "33pF" H 17300 6950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 17538 6900 50  0001 C CNN
F 3 "" H 17500 7050 50  0001 C CNN
	1    17500 7050
	0    1    1    0   
$EndComp
$Comp
L GNDPWR #PWR08
U 1 1 5C849877
P 8800 3500
F 0 "#PWR08" H 8800 3300 50  0001 C CNN
F 1 "GNDPWR" H 8800 3370 50  0000 C CNN
F 2 "" H 8800 3450 50  0001 C CNN
F 3 "" H 8800 3450 50  0001 C CNN
	1    8800 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 4600 10750 4600
Wire Wire Line
	10300 4450 10300 4750
Wire Wire Line
	9700 4900 9700 5150
Wire Wire Line
	9100 5050 9100 5150
Wire Wire Line
	9100 5150 10300 5150
Connection ~ 9700 5150
Wire Wire Line
	10300 5150 10300 5050
Connection ~ 10300 4600
Wire Wire Line
	15450 5350 15550 5350
Wire Wire Line
	17750 4750 17750 4800
Wire Wire Line
	17150 4800 17150 4750
Connection ~ 17150 4750
Wire Wire Line
	17350 4800 17350 4750
Connection ~ 17350 4750
Wire Wire Line
	17550 4750 17550 4800
Connection ~ 17550 4750
Wire Wire Line
	17350 6050 16750 6050
Connection ~ 17750 4750
Wire Wire Line
	16750 5950 18400 5950
Wire Wire Line
	17150 5100 17150 6150
Connection ~ 17150 5700
Wire Wire Line
	17350 5100 17350 6050
Connection ~ 17350 5800
Wire Wire Line
	17550 5100 17550 5950
Wire Wire Line
	17750 5100 17750 6300
Connection ~ 17750 6300
Wire Wire Line
	16750 7250 16900 7250
Wire Wire Line
	16750 7150 17350 7150
Wire Wire Line
	12700 7150 12950 7150
Wire Wire Line
	12950 7350 12850 7350
Wire Wire Line
	12850 7350 12850 7150
Connection ~ 12850 7150
Wire Wire Line
	13250 7150 14150 7150
Wire Wire Line
	13250 7350 14100 7350
Wire Wire Line
	8150 4150 8500 4150
Wire Wire Line
	8500 4150 8500 4200
Connection ~ 9100 4600
Wire Wire Line
	8600 3150 8600 4200
Wire Wire Line
	8350 3950 8350 4600
Wire Wire Line
	17000 6300 17000 5750
Wire Wire Line
	17000 5750 16750 5750
Wire Wire Line
	17150 6150 16750 6150
Connection ~ 17550 5950
Wire Wire Line
	17150 4750 18200 4750
Connection ~ 17850 4750
Wire Wire Line
	17200 7250 17850 7250
Connection ~ 17350 7250
Wire Wire Line
	13950 4850 13950 5650
Wire Wire Line
	13950 5650 14150 5650
Wire Wire Line
	13850 5100 14400 5100
Wire Wire Line
	13850 5100 13850 4850
Wire Wire Line
	14400 5300 13750 5300
Wire Wire Line
	13750 5300 13750 4850
Wire Wire Line
	14250 4900 14250 5100
Connection ~ 14250 5100
Wire Wire Line
	15550 3350 15550 3500
Wire Wire Line
	15550 3500 15350 3500
Connection ~ 15350 3500
Wire Wire Line
	15750 3350 15750 3600
Wire Wire Line
	15750 3600 15850 3600
Wire Wire Line
	15500 5350 15500 5250
Connection ~ 15500 5350
Connection ~ 15500 7600
Wire Wire Line
	15500 7600 15500 7750
Wire Wire Line
	14100 7250 14150 7250
Wire Wire Line
	13150 5550 13000 5550
Wire Wire Line
	12700 5550 12550 5550
Wire Wire Line
	13150 5850 13000 5850
Wire Wire Line
	12700 5850 12550 5850
Connection ~ 13950 4900
Wire Wire Line
	8350 4600 9400 4600
Connection ~ 8350 4150
Wire Wire Line
	9100 4450 9100 4750
Wire Wire Line
	8400 3450 8800 3450
Wire Wire Line
	8800 3450 8800 3500
Wire Wire Line
	8400 3500 8400 3450
Connection ~ 8600 3450
Wire Wire Line
	14150 5750 13900 5750
Wire Wire Line
	13900 5750 13900 5350
Wire Wire Line
	13900 5350 13650 5350
Wire Wire Line
	13650 5350 13650 4850
Wire Wire Line
	14150 5850 13850 5850
Wire Wire Line
	13850 5850 13850 5400
Wire Wire Line
	13850 5400 13550 5400
Wire Wire Line
	13550 5400 13550 4850
Wire Wire Line
	13450 5550 13750 5550
Wire Wire Line
	13750 5550 13750 5950
Wire Wire Line
	13750 5950 14150 5950
Wire Wire Line
	13450 5850 13650 5850
Wire Wire Line
	13650 5850 13650 6050
Wire Wire Line
	13650 6050 14150 6050
Wire Wire Line
	13400 6900 13400 7150
Connection ~ 13400 7150
Wire Wire Line
	13750 6900 13750 7350
Connection ~ 13750 7350
Wire Wire Line
	18050 5300 17550 5300
Connection ~ 17550 5300
Wire Wire Line
	18050 5150 17750 5150
Connection ~ 17750 5150
Wire Wire Line
	15350 3800 15450 3800
Connection ~ 15450 3800
Wire Wire Line
	15800 3800 15650 3800
Connection ~ 15650 3800
Wire Wire Line
	16750 5650 16900 5650
Wire Wire Line
	16900 5650 16900 4250
Wire Wire Line
	16900 4250 15650 4250
Wire Wire Line
	15650 4250 15650 3350
Wire Wire Line
	15450 3350 15450 4250
Wire Wire Line
	15450 4250 12100 4250
Wire Wire Line
	12100 4250 12100 6250
Wire Wire Line
	12100 6250 14150 6250
Wire Wire Line
	14100 7350 14100 7250
Wire Wire Line
	16750 7050 17350 7050
Wire Wire Line
	17050 7050 17050 6950
Wire Wire Line
	16750 6950 16800 6950
Wire Wire Line
	16800 6950 16800 6550
Wire Wire Line
	16800 6550 17350 6550
Wire Wire Line
	17050 6550 17050 6650
Connection ~ 17050 6550
Connection ~ 17050 7050
Wire Wire Line
	17750 6550 17750 7050
Wire Wire Line
	17750 6550 17650 6550
Wire Wire Line
	17750 6850 17850 6850
Wire Wire Line
	17850 6850 17850 7250
Connection ~ 17750 6850
Text GLabel 12550 6150 0    60   Input ~ 0
Bomba
Wire Wire Line
	12550 6150 14150 6150
$Comp
L Conn_01x03 J2
U 1 1 5C9AD40D
P 6450 3400
F 0 "J2" H 6450 3600 50  0000 C CNN
F 1 "Datos_LORA" V 6600 3300 50  0000 C CNN
F 2 "Connectors_JST:JST_PH_B3B-PH-SM4-TB_03x2.00mm_Straight" H 6450 3400 50  0001 C CNN
F 3 "" H 6450 3400 50  0001 C CNN
	1    6450 3400
	1    0    0    -1  
$EndComp
Text GLabel 5950 3600 0    60   Input ~ 0
LORA_UART_RX
Text GLabel 5950 3400 0    60   Input ~ 0
LORA_UART_TX
Wire Wire Line
	5950 3400 6250 3400
Wire Wire Line
	5950 3600 6050 3600
Wire Wire Line
	6050 3600 6050 3500
Wire Wire Line
	6050 3500 6250 3500
$Comp
L BC807 Q1
U 1 1 5C9AEA3C
P 9100 7450
F 0 "Q1" H 9300 7525 50  0000 L CNN
F 1 "BC807" H 9300 7450 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 9300 7375 50  0001 L CIN
F 3 "" H 9100 7450 50  0001 L CNN
	1    9100 7450
	-1   0    0    1   
$EndComp
Text GLabel 9800 7450 2    60   Input ~ 0
Bomba
$Comp
L R R4
U 1 1 5C9AF271
P 9550 7450
F 0 "R4" V 9630 7450 50  0000 C CNN
F 1 "4.7K" V 9550 7450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 9480 7450 50  0001 C CNN
F 3 "" H 9550 7450 50  0001 C CNN
	1    9550 7450
	0    1    -1   0   
$EndComp
Wire Wire Line
	9700 7450 9800 7450
Wire Wire Line
	9400 7450 9300 7450
Text GLabel 8900 6950 0    60   Input ~ 0
VDD2
Wire Wire Line
	8900 6950 9000 6950
Wire Wire Line
	9000 6950 9000 7250
$Comp
L Conn_01x02 J3
U 1 1 5C9B06F9
P 6450 4150
F 0 "J3" H 6450 4250 50  0000 C CNN
F 1 "Salida_Bomba" V 6600 4050 50  0000 C CNN
F 2 "Connectors_JST:JST_PH_B2B-PH-SM4-TB_02x2.00mm_Straight" H 6450 4150 50  0001 C CNN
F 3 "" H 6450 4150 50  0001 C CNN
	1    6450 4150
	1    0    0    -1  
$EndComp
Text GLabel 5950 4350 0    60   Input ~ 0
GND
Text GLabel 5950 4150 0    60   Input ~ 0
V_Bomba
Wire Wire Line
	5950 4150 6250 4150
Wire Wire Line
	5950 4350 6050 4350
Wire Wire Line
	6050 4350 6050 4250
Wire Wire Line
	6050 4250 6250 4250
Text GLabel 8900 8000 0    60   Input ~ 0
V_Bomba
Wire Wire Line
	8900 8000 9000 8000
Wire Wire Line
	9000 8000 9000 7650
Text GLabel 12850 6350 0    60   Input ~ 0
LORA_UART_TX
Text GLabel 12850 6500 0    60   Input ~ 0
LORA_UART_RX
Wire Wire Line
	12850 6350 14050 6350
Wire Wire Line
	14050 6350 14050 6650
Wire Wire Line
	14050 6650 14150 6650
Wire Wire Line
	14150 7050 13950 7050
Wire Wire Line
	13950 7050 13950 6500
Wire Wire Line
	13950 6500 12850 6500
Wire Wire Line
	15350 3350 15350 3600
Wire Wire Line
	15450 7600 15550 7600
Wire Wire Line
	15550 7600 15550 7550
Wire Wire Line
	15450 7600 15450 7550
Wire Wire Line
	17350 7150 17350 7400
Text GLabel 8750 3300 2    60   Input ~ 0
VSS1
Wire Wire Line
	8750 3300 8600 3300
$Comp
L PWR_FLAG #FLG09
U 1 1 5C9BA44A
P 8600 3150
F 0 "#FLG09" H 8600 3225 50  0001 C CNN
F 1 "PWR_FLAG" H 8600 3300 50  0000 C CNN
F 2 "" H 8600 3150 50  0001 C CNN
F 3 "" H 8600 3150 50  0001 C CNN
	1    8600 3150
	1    0    0    -1  
$EndComp
Connection ~ 8600 3300
Text GLabel 5750 5300 0    60   Input ~ 0
SCL
Text GLabel 5750 5100 0    60   Input ~ 0
SDA
Text GLabel 13200 7850 0    60   Input ~ 0
SCL
Text GLabel 13200 7650 0    60   Input ~ 0
SDA
Wire Wire Line
	13200 7650 13400 7650
Wire Wire Line
	13200 7850 13600 7850
Text GLabel 13200 7650 0    60   Input ~ 0
SDA
Wire Wire Line
	13400 7650 13400 7350
Connection ~ 13400 7350
Wire Wire Line
	13600 7850 13600 7150
Connection ~ 13600 7150
Wire Wire Line
	17750 7050 17650 7050
$Comp
L Conn_01x08_Female J4
U 1 1 5CAAD172
P 6450 5150
F 0 "J4" H 6450 5650 50  0000 C CNN
F 1 "Sensor_CO" V 6600 5150 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x08_Pitch2.54mm" H 6450 5150 50  0001 C CNN
F 3 "" H 6450 5150 50  0001 C CNN
	1    6450 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 5050 6050 5050
Wire Wire Line
	6050 5050 6050 4850
Wire Wire Line
	6050 4850 5800 4850
Wire Wire Line
	6000 5150 6250 5150
Wire Wire Line
	6000 5150 6000 5100
Wire Wire Line
	6000 5100 5750 5100
Wire Wire Line
	6250 5350 6050 5350
Wire Wire Line
	6050 5350 6050 5550
Wire Wire Line
	6050 5550 5750 5550
Wire Wire Line
	5750 5300 6000 5300
Wire Wire Line
	6000 5300 6000 5250
Wire Wire Line
	6000 5250 6250 5250
NoConn ~ 6250 4850
NoConn ~ 6250 4950
NoConn ~ 6250 5450
NoConn ~ 6250 5550
Text GLabel 5800 5950 0    60   Input ~ 0
VDD2
Text GLabel 5750 6650 0    60   Input ~ 0
GND
Text GLabel 5750 6400 0    60   Input ~ 0
SCL
Text GLabel 5750 6200 0    60   Input ~ 0
SDA
$Comp
L Conn_01x08_Female J15
U 1 1 5D0EF08B
P 6450 6250
F 0 "J15" H 6450 6750 50  0000 C CNN
F 1 "Sensor_SO2" V 6600 6250 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x08_Pitch2.54mm" H 6450 6250 50  0001 C CNN
F 3 "" H 6450 6250 50  0001 C CNN
	1    6450 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 6150 6050 6150
Wire Wire Line
	6050 6150 6050 5950
Wire Wire Line
	6050 5950 5800 5950
Wire Wire Line
	6000 6250 6250 6250
Wire Wire Line
	6000 6250 6000 6200
Wire Wire Line
	6000 6200 5750 6200
Wire Wire Line
	6250 6450 6050 6450
Wire Wire Line
	6050 6450 6050 6650
Wire Wire Line
	6050 6650 5750 6650
Wire Wire Line
	5750 6400 6000 6400
Wire Wire Line
	6000 6400 6000 6350
Wire Wire Line
	6000 6350 6250 6350
NoConn ~ 6250 5950
NoConn ~ 6250 6050
NoConn ~ 6250 6550
NoConn ~ 6250 6650
Text GLabel 5800 7100 0    60   Input ~ 0
VDD2
Text GLabel 5750 7800 0    60   Input ~ 0
GND
Text GLabel 5750 7550 0    60   Input ~ 0
SCL
Text GLabel 5750 7350 0    60   Input ~ 0
SDA
$Comp
L Conn_01x08_Female J16
U 1 1 5D0EF55D
P 6450 7400
F 0 "J16" H 6450 7900 50  0000 C CNN
F 1 "Sensor_O3" V 6600 7400 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x08_Pitch2.54mm" H 6450 7400 50  0001 C CNN
F 3 "" H 6450 7400 50  0001 C CNN
	1    6450 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 7300 6050 7300
Wire Wire Line
	6050 7300 6050 7100
Wire Wire Line
	6050 7100 5800 7100
Wire Wire Line
	6000 7400 6250 7400
Wire Wire Line
	6000 7400 6000 7350
Wire Wire Line
	6000 7350 5750 7350
Wire Wire Line
	6250 7600 6050 7600
Wire Wire Line
	6050 7600 6050 7800
Wire Wire Line
	6050 7800 5750 7800
Wire Wire Line
	5750 7550 6000 7550
Wire Wire Line
	6000 7550 6000 7500
Wire Wire Line
	6000 7500 6250 7500
NoConn ~ 6250 7100
NoConn ~ 6250 7200
NoConn ~ 6250 7700
NoConn ~ 6250 7800
Text GLabel 5800 8250 0    60   Input ~ 0
VDD2
Text GLabel 5750 8950 0    60   Input ~ 0
GND
Text GLabel 5750 8700 0    60   Input ~ 0
SCL
Text GLabel 5750 8500 0    60   Input ~ 0
SDA
$Comp
L Conn_01x08_Female J17
U 1 1 5D0EF81D
P 6450 8550
F 0 "J17" H 6450 9050 50  0000 C CNN
F 1 "Sensor_NO2" V 6600 8550 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x08_Pitch2.54mm" H 6450 8550 50  0001 C CNN
F 3 "" H 6450 8550 50  0001 C CNN
	1    6450 8550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 8450 6050 8450
Wire Wire Line
	6050 8450 6050 8250
Wire Wire Line
	6050 8250 5800 8250
Wire Wire Line
	6000 8550 6250 8550
Wire Wire Line
	6000 8550 6000 8500
Wire Wire Line
	6000 8500 5750 8500
Wire Wire Line
	6250 8750 6050 8750
Wire Wire Line
	6050 8750 6050 8950
Wire Wire Line
	6050 8950 5750 8950
Wire Wire Line
	5750 8700 6000 8700
Wire Wire Line
	6000 8700 6000 8650
Wire Wire Line
	6000 8650 6250 8650
NoConn ~ 6250 8250
NoConn ~ 6250 8350
NoConn ~ 6250 8850
NoConn ~ 6250 8950
Text GLabel 5800 9450 0    60   Input ~ 0
VDD2
Text GLabel 5750 10150 0    60   Input ~ 0
GND
Text GLabel 5750 9900 0    60   Input ~ 0
SCL
Text GLabel 5750 9700 0    60   Input ~ 0
SDA
$Comp
L Conn_01x08_Female J18
U 1 1 5D0EFBFD
P 6450 9750
F 0 "J18" H 6450 10250 50  0000 C CNN
F 1 "Sensor_PM10" V 6600 9750 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x08_Pitch2.54mm" H 6450 9750 50  0001 C CNN
F 3 "" H 6450 9750 50  0001 C CNN
	1    6450 9750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 9650 6050 9650
Wire Wire Line
	6050 9650 6050 9450
Wire Wire Line
	6050 9450 5800 9450
Wire Wire Line
	6000 9750 6250 9750
Wire Wire Line
	6000 9750 6000 9700
Wire Wire Line
	6000 9700 5750 9700
Wire Wire Line
	6250 9950 6050 9950
Wire Wire Line
	6050 9950 6050 10150
Wire Wire Line
	6050 10150 5750 10150
Wire Wire Line
	5750 9900 6000 9900
Wire Wire Line
	6000 9900 6000 9850
Wire Wire Line
	6000 9850 6250 9850
NoConn ~ 6250 9450
NoConn ~ 6250 9550
NoConn ~ 6250 10050
NoConn ~ 6250 10150
$Comp
L DM3CS-SF J14
U 1 1 5D1450E3
P 18600 5700
F 0 "J14" H 20450 6000 50  0000 L CNN
F 1 "DM3CS-SF" H 20450 5900 50  0000 L CNN
F 2 "SD_CARD_DP:SD_CARD_DP" H 20450 5800 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/1/DM3CS-SF.pdf" H 20450 5700 50  0001 L CNN
F 4 "MicroSD card connector, push-pull type MicroSD card connector, push-pull type" H 20450 5600 50  0001 L CNN "Description"
F 5 "" H 20450 5500 50  0001 L CNN "Height"
F 6 "798-DM3CSSF" H 20450 5400 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.com/Search/Refine.aspx?Keyword=798-DM3CSSF" H 20450 5300 50  0001 L CNN "Mouser Price/Stock"
F 8 "Hirose" H 20450 5200 50  0001 L CNN "Manufacturer_Name"
F 9 "DM3CS-SF" H 20450 5100 50  0001 L CNN "Manufacturer_Part_Number"
	1    18600 5700
	1    0    0    -1  
$EndComp
NoConn ~ 18600 5700
NoConn ~ 20600 6200
Wire Wire Line
	17350 5400 18400 5400
Wire Wire Line
	18400 5400 18400 5800
Wire Wire Line
	18400 5800 18600 5800
Connection ~ 17350 5400
Wire Wire Line
	18400 5950 18400 5900
Wire Wire Line
	18400 5900 18600 5900
Wire Wire Line
	17000 6300 18500 6300
Wire Wire Line
	18500 6300 18500 6000
Wire Wire Line
	18500 6000 18600 6000
Connection ~ 18000 6300
Wire Wire Line
	20600 5900 21000 5900
Connection ~ 21000 5900
NoConn ~ 20600 6000
Wire Wire Line
	17150 5450 21100 5450
Wire Wire Line
	21100 5450 21100 5700
Wire Wire Line
	21100 5700 20600 5700
Connection ~ 17150 5450
Wire Wire Line
	20600 5800 21300 5800
Wire Wire Line
	21300 5800 21300 4900
Wire Wire Line
	21300 4900 18100 4900
Wire Wire Line
	18100 4900 18100 4750
Connection ~ 18100 4750
Connection ~ 20700 5900
NoConn ~ 20600 6100
NoConn ~ 18600 6200
NoConn ~ 18600 6100
NoConn ~ 18600 6300
$Comp
L AP1117-33 U1
U 1 1 5D2E70FF
P 9700 4600
F 0 "U1" H 9550 4725 50  0000 C CNN
F 1 "AP1117-33" H 9700 4725 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-223-3_TabPin2" H 9700 4800 50  0001 C CNN
F 3 "" H 9800 4350 50  0001 C CNN
	1    9700 4600
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5D2E7D78
P 9100 4900
F 0 "C1" H 9125 5000 50  0000 L CNN
F 1 "0.1uF" H 9125 4800 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Hand" H 9138 4750 50  0001 C CNN
F 3 "" H 9100 4900 50  0001 C CNN
	1    9100 4900
	1    0    0    -1  
$EndComp
Text GLabel 5950 3200 0    60   Input ~ 0
GND
Wire Wire Line
	5950 3200 6150 3200
Wire Wire Line
	6150 3200 6150 3300
Wire Wire Line
	6150 3300 6250 3300
$EndSCHEMATC
