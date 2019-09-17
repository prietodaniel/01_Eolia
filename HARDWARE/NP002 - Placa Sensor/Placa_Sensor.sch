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
LIBS:lmp91000
LIBS:microchip_pic16mcu
LIBS:sensors
LIBS:electrochemical_sensors
LIBS:gas_sensors
LIBS:user
LIBS:dk_Gas-Sensors
LIBS:Placa_Sensor-cache
EELAYER 25 0
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
Text GLabel 5700 5000 0    60   Input ~ 0
SDA2
Text GLabel 5400 4900 0    60   Input ~ 0
SCL2
$Comp
L LMP91000 U1
U 1 1 5CB0066C
P 6350 5000
F 0 "U1" H 6350 5450 60  0000 C CNN
F 1 "LMP91000" H 6350 4550 60  0000 C CNN
F 2 "Housings_SON:WSON-14_1EP_4.0x4.0mm_Pitch0.5mm" H 6450 5050 60  0001 C CNN
F 3 "" H 6450 5050 60  0001 C CNN
	1    6350 5000
	1    0    0    -1  
$EndComp
Text GLabel 5400 5300 0    60   Input ~ 0
GND
Text GLabel 5400 4700 0    60   Input ~ 0
GND
Text GLabel 5650 5200 0    60   Input ~ 0
VDD
Text GLabel 5700 4800 0    60   Input ~ 0
MENB
Text GLabel 7000 4900 2    60   Input ~ 0
WE
Text GLabel 7450 4550 2    60   Input ~ 0
CE
Text GLabel 7200 4800 2    60   Input ~ 0
RE
Text GLabel 9900 5000 2    60   Input ~ 0
WE
Text GLabel 8700 5100 0    60   Input ~ 0
CE
Text GLabel 8900 5000 0    60   Input ~ 0
RE
$Comp
L PIC16(L)F1829-I/SO U2
U 1 1 5CB00BA3
P 6650 3150
F 0 "U2" H 5700 4050 50  0000 L CNN
F 1 "PIC16(L)F1829-I/SO" H 5700 3950 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-20W_7.5x12.8mm_Pitch1.27mm" H 6650 2600 50  0001 C CNN
F 3 "" H 6650 2600 50  0001 C CNN
	1    6650 3150
	1    0    0    -1  
$EndComp
Text GLabel 6800 4050 2    60   Input ~ 0
GND
Text GLabel 6750 2150 2    60   Input ~ 0
VDD
$Comp
L Conn_01x05 J1
U 1 1 5CB00CF6
P 5150 1950
F 0 "J1" V 5150 2250 50  0000 C CNN
F 1 "Conn_01x05" V 5250 1950 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 5150 1950 50  0001 C CNN
F 3 "" H 5150 1950 50  0001 C CNN
	1    5150 1950
	0    -1   -1   0   
$EndComp
Text GLabel 5150 2200 3    60   Input ~ 0
GND
Text GLabel 5050 2650 3    60   Input ~ 0
VDD
Text GLabel 4400 3550 0    60   Input ~ 0
SCL1
Text GLabel 4400 3350 0    60   Input ~ 0
SDA1
Text GLabel 8300 3450 2    60   Input ~ 0
V_gas
Text GLabel 7200 5300 2    60   Input ~ 0
V_gas
Text GLabel 7400 5000 2    60   Input ~ 0
Vref
NoConn ~ 5550 2850
NoConn ~ 5550 3050
NoConn ~ 5550 3150
NoConn ~ 7750 3250
NoConn ~ 7750 3150
NoConn ~ 7750 3050
NoConn ~ 7750 2950
NoConn ~ 7750 2850
Text GLabel 8300 2750 2    60   Input ~ 0
MENB
$Comp
L R R7
U 1 1 5CB36133
P 8050 2500
F 0 "R7" V 8130 2500 50  0000 C CNN
F 1 "4.7K" V 8050 2500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7980 2500 50  0001 C CNN
F 3 "" H 8050 2500 50  0001 C CNN
	1    8050 2500
	-1   0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5CB3633C
P 7000 5550
F 0 "C1" H 7025 5650 50  0000 L CNN
F 1 "1u" H 7025 5450 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 7038 5400 50  0001 C CNN
F 3 "" H 7000 5550 50  0001 C CNN
	1    7000 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5CB36463
P 7000 5800
F 0 "#PWR01" H 7000 5550 50  0001 C CNN
F 1 "GND" H 7000 5650 50  0000 C CNN
F 2 "" H 7000 5800 50  0001 C CNN
F 3 "" H 7000 5800 50  0001 C CNN
	1    7000 5800
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5CB365C9
P 7900 5150
F 0 "R6" V 7980 5150 50  0000 C CNN
F 1 "500K" V 7900 5150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7830 5150 50  0001 C CNN
F 3 "" H 7900 5150 50  0001 C CNN
	1    7900 5150
	1    0    0    -1  
$EndComp
Text GLabel 3600 3650 0    60   Input ~ 0
SCL2
Text GLabel 3600 3450 0    60   Input ~ 0
SDA2
NoConn ~ 7750 3350
Text Notes 7250 5900 1    60   ~ 0
Opcional
$Comp
L R R8
U 1 1 5CE08C20
P 9450 3550
F 0 "R8" V 9530 3550 50  0000 C CNN
F 1 "820" V 9450 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 9380 3550 50  0001 C CNN
F 3 "" H 9450 3550 50  0001 C CNN
	1    9450 3550
	1    0    0    -1  
$EndComp
$Comp
L REFERENCE_VOLTAGE D1
U 1 1 5CE09077
P 9450 4000
F 0 "D1" V 9550 4100 50  0000 C CNN
F 1 "LM336-25" V 9350 4000 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" V 9450 4000 50  0001 C CNN
F 3 "" V 9450 4000 50  0000 C CNN
	1    9450 4000
	1    0    0    -1  
$EndComp
Text GLabel 9600 3300 2    60   Input ~ 0
VDD
Text GLabel 9600 3750 2    60   Input ~ 0
Vref
$Comp
L GND #PWR02
U 1 1 5CE09E81
P 9450 4300
F 0 "#PWR02" H 9450 4050 50  0001 C CNN
F 1 "GND" H 9450 4150 50  0000 C CNN
F 2 "" H 9450 4300 50  0001 C CNN
F 3 "" H 9450 4300 50  0001 C CNN
	1    9450 4300
	1    0    0    -1  
$EndComp
NoConn ~ 9650 4000
$Comp
L R R4
U 1 1 5CE0A1A8
P 7150 4550
F 0 "R4" V 7230 4550 50  0000 C CNN
F 1 "49.9" V 7150 4550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7080 4550 50  0001 C CNN
F 3 "" H 7150 4550 50  0001 C CNN
	1    7150 4550
	0    1    1    0   
$EndComp
Text Notes 6950 4400 0    60   ~ 0
Opcional
$Comp
L R R3
U 1 1 5CE0A65B
P 4950 2400
F 0 "R3" V 5030 2400 50  0000 C CNN
F 1 "4K7" V 4950 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4880 2400 50  0001 C CNN
F 3 "" H 4950 2400 50  0001 C CNN
	1    4950 2400
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5CE0AB43
P 8150 5150
F 0 "C2" H 8175 5250 50  0000 L CNN
F 1 "0.1u" H 8175 5050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8188 5000 50  0001 C CNN
F 3 "" H 8150 5150 50  0001 C CNN
	1    8150 5150
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x08 J6
U 1 1 5CE1D052
P 9900 2650
F 0 "J6" H 9900 3050 50  0000 C CNN
F 1 "Conn_01x08" H 9900 2150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 9900 2650 50  0001 C CNN
F 3 "" H 9900 2650 50  0001 C CNN
	1    9900 2650
	1    0    0    1   
$EndComp
$Comp
L TEST_1P J5
U 1 1 5CE1D365
P 9200 3750
F 0 "J5" H 9200 4020 50  0000 C CNN
F 1 "VREF_Test" H 9200 3950 50  0000 C CNN
F 2 "Connectors:PINTST" H 9400 3750 50  0001 C CNN
F 3 "" H 9400 3750 50  0001 C CNN
	1    9200 3750
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P J2
U 1 1 5CE1D52E
P 8100 3250
F 0 "J2" H 8100 3520 50  0000 C CNN
F 1 "VGAS_Test" H 8100 3450 50  0000 C CNN
F 2 "Connectors:PINTST" H 8300 3250 50  0001 C CNN
F 3 "" H 8300 3250 50  0001 C CNN
	1    8100 3250
	1    0    0    -1  
$EndComp
Text GLabel 9200 2450 0    60   Input ~ 0
GND
Text GLabel 9500 2750 0    60   Input ~ 0
VDD
Text GLabel 9200 2650 0    60   Input ~ 0
SDA1
Text GLabel 9500 2550 0    60   Input ~ 0
SCL1
$Comp
L TEST_1P J4
U 1 1 5CE1DD92
P 9150 3050
F 0 "J4" H 9150 3320 50  0000 C CNN
F 1 "VDD_Test" H 9150 3250 50  0000 C CNN
F 2 "Connectors:PINTST" H 9350 3050 50  0001 C CNN
F 3 "" H 9350 3050 50  0001 C CNN
	1    9150 3050
	-1   0    0    -1  
$EndComp
$Comp
L TEST_1P J3
U 1 1 5CE1DE2E
P 9150 2200
F 0 "J3" H 9150 2470 50  0000 C CNN
F 1 "GND_Test" H 9150 2400 50  0000 C CNN
F 2 "Connectors:PINTST" H 9350 2200 50  0001 C CNN
F 3 "" H 9350 2200 50  0001 C CNN
	1    9150 2200
	-1   0    0    -1  
$EndComp
NoConn ~ 9700 2950
NoConn ~ 9700 2850
NoConn ~ 9700 2350
NoConn ~ 9700 2250
$Comp
L PWR_FLAG #FLG03
U 1 1 5CE1E048
P 9400 3050
F 0 "#FLG03" H 9400 3125 50  0001 C CNN
F 1 "PWR_FLAG" H 9400 3200 50  0000 C CNN
F 2 "" H 9400 3050 50  0001 C CNN
F 3 "" H 9400 3050 50  0001 C CNN
	1    9400 3050
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5CE1E51B
P 9400 2200
F 0 "#PWR04" H 9400 1950 50  0001 C CNN
F 1 "GND" H 9400 2050 50  0000 C CNN
F 2 "" H 9400 2200 50  0001 C CNN
F 3 "" H 9400 2200 50  0001 C CNN
	1    9400 2200
	-1   0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5CE1ED86
P 4000 3150
F 0 "R2" V 4080 3150 50  0000 C CNN
F 1 "4.7K" V 4000 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3930 3150 50  0001 C CNN
F 3 "" H 4000 3150 50  0001 C CNN
	1    4000 3150
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5CE1EEB5
P 3800 3150
F 0 "R1" V 3880 3150 50  0000 C CNN
F 1 "4.7K" V 3800 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3730 3150 50  0001 C CNN
F 3 "" H 3800 3150 50  0001 C CNN
	1    3800 3150
	1    0    0    -1  
$EndComp
Text GLabel 3900 2850 1    60   Input ~ 0
VDD
$Comp
L 110-109 U3
U 1 1 5CE2C3A4
P 9550 5300
F 0 "U3" H 9050 5800 60  0000 C CNN
F 1 "CO gas sensor" H 9050 5000 60  0000 L CNN
F 2 "gas_sensors:SPEC_Gas_Sensor_C_Package_THT_4pins" H 9750 5500 60  0001 L CNN
F 3 "http://www.spec-sensors.com/wp-content/uploads/2016/04/3SP_CO_1000-C-Package-110-109.pdf" H 9750 5600 60  0001 L CNN
F 4 "1684-1001-ND" H 9750 5700 60  0001 L CNN "Digi-Key_PN"
F 5 "110-109" H 9750 5800 60  0001 L CNN "MPN"
F 6 "Sensors, Transducers" H 9750 5900 60  0001 L CNN "Category"
F 7 "Gas Sensors" H 9750 6000 60  0001 L CNN "Family"
F 8 "http://www.spec-sensors.com/wp-content/uploads/2016/04/3SP_CO_1000-C-Package-110-109.pdf" H 9750 6100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/spec-sensors-llc/110-109/1684-1001-ND/6136364" H 9750 6200 60  0001 L CNN "DK_Detail_Page"
F 10 "SENSOR GAS CO ANALOG CUR MOD" H 9750 6300 60  0001 L CNN "Description"
F 11 "SPEC Sensors, LLC" H 9750 6400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9750 6500 60  0001 L CNN "Status"
	1    9550 5300
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5CE2E112
P 7200 5000
F 0 "R5" V 7280 5000 50  0000 C CNN
F 1 "0" V 7200 5000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7130 5000 50  0001 C CNN
F 3 "" H 7200 5000 50  0001 C CNN
	1    7200 5000
	0    1    1    0   
$EndComp
Text GLabel 8050 2200 1    60   Input ~ 0
VDD
Text GLabel 9900 5900 2    60   Input ~ 0
WE
Text GLabel 8700 6000 0    60   Input ~ 0
CE
Text GLabel 8900 5900 0    60   Input ~ 0
RE
$Comp
L Jumper JP1
U 1 1 5D3121F1
P 6000 1550
F 0 "JP1" H 6000 1700 50  0000 C CNN
F 1 "Jumper" H 6000 1470 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6000 1550 50  0001 C CNN
F 3 "" H 6000 1550 50  0001 C CNN
	1    6000 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 5300 5800 5300
Wire Wire Line
	5400 4700 5800 4700
Wire Wire Line
	5400 4900 5800 4900
Wire Wire Line
	5650 5200 5800 5200
Wire Wire Line
	5700 4800 5800 4800
Wire Wire Line
	6900 4900 7000 4900
Wire Wire Line
	6900 4800 7200 4800
Wire Wire Line
	7000 4700 6900 4700
Wire Wire Line
	6800 4050 6650 4050
Wire Wire Line
	6650 4050 6650 3950
Wire Wire Line
	6650 2150 6650 2250
Wire Wire Line
	4850 2950 5550 2950
Wire Wire Line
	5250 2650 5550 2650
Wire Wire Line
	5150 2200 5150 2150
Wire Wire Line
	6650 2150 6750 2150
Wire Wire Line
	5050 2150 5050 2650
Wire Wire Line
	4400 3350 5550 3350
Wire Wire Line
	4400 3550 5550 3550
Wire Wire Line
	6900 5300 7200 5300
Wire Wire Line
	7750 2750 8300 2750
Connection ~ 8050 2750
Wire Wire Line
	7000 5400 7000 5300
Connection ~ 7000 5300
Wire Wire Line
	7000 5800 7000 5700
Wire Wire Line
	7900 5000 7900 4900
Wire Wire Line
	7900 5300 7900 5400
Wire Wire Line
	6900 5100 7700 5100
Wire Wire Line
	7700 5100 7700 4900
Connection ~ 7900 4900
Wire Wire Line
	6900 5200 7700 5200
Wire Wire Line
	7700 5200 7700 5400
Connection ~ 7900 5400
Wire Wire Line
	3600 3450 5550 3450
Wire Wire Line
	3600 3650 5550 3650
Wire Wire Line
	8050 2650 8050 2750
Wire Wire Line
	8050 2200 8050 2350
Wire Wire Line
	7700 4900 8150 4900
Wire Wire Line
	7700 5400 8150 5400
Wire Wire Line
	5700 5000 5800 5000
Wire Wire Line
	9600 3300 9450 3300
Wire Wire Line
	9450 3300 9450 3400
Wire Wire Line
	9450 3700 9450 3800
Wire Wire Line
	9200 3750 9600 3750
Connection ~ 9450 3750
Wire Wire Line
	9450 4200 9450 4300
Wire Wire Line
	7300 4550 7450 4550
Wire Wire Line
	7000 4550 7000 4700
Wire Wire Line
	4850 2950 4850 2200
Wire Wire Line
	4850 2200 4950 2200
Wire Wire Line
	4950 2150 4950 2250
Connection ~ 4950 2200
Wire Wire Line
	4950 2550 4950 2600
Wire Wire Line
	4950 2600 5050 2600
Connection ~ 5050 2600
Wire Wire Line
	8150 4900 8150 5000
Wire Wire Line
	8150 5400 8150 5300
Wire Wire Line
	8100 3250 8100 3450
Connection ~ 8100 3450
Wire Wire Line
	9500 2750 9700 2750
Wire Wire Line
	9200 2650 9700 2650
Wire Wire Line
	9500 2550 9700 2550
Wire Wire Line
	9200 2450 9700 2450
Connection ~ 9600 2750
Connection ~ 9600 2450
Wire Wire Line
	9150 2200 9600 2200
Wire Wire Line
	7750 3450 8300 3450
Wire Wire Line
	3900 2850 3900 2950
Wire Wire Line
	3800 2950 4000 2950
Wire Wire Line
	3800 2950 3800 3000
Wire Wire Line
	4000 2950 4000 3000
Connection ~ 3900 2950
Wire Wire Line
	4000 3300 4000 3450
Connection ~ 4000 3450
Wire Wire Line
	3800 3300 3800 3650
Connection ~ 3800 3650
Connection ~ 6650 3950
Wire Wire Line
	9050 5000 8900 5000
Wire Wire Line
	9050 5100 8700 5100
Wire Wire Line
	9600 2200 9600 2450
Connection ~ 9400 2200
Wire Wire Line
	9600 3150 9600 2750
Wire Wire Line
	9150 3150 9600 3150
Wire Wire Line
	9150 3150 9150 3050
Wire Wire Line
	9400 3050 9400 3150
Connection ~ 9400 3150
Wire Wire Line
	7400 5000 7350 5000
Wire Wire Line
	7050 5000 6900 5000
Wire Wire Line
	9750 5000 9900 5000
Wire Wire Line
	9750 5100 9800 5100
Wire Wire Line
	9800 5100 9800 5000
Connection ~ 9800 5000
Wire Wire Line
	5250 2150 5250 2650
Wire Wire Line
	5350 2750 5550 2750
Wire Wire Line
	5350 2150 5350 2750
Wire Wire Line
	9050 5900 8900 5900
Wire Wire Line
	9050 6000 8700 6000
Wire Wire Line
	9750 5900 9900 5900
Wire Wire Line
	9750 6000 9900 6000
Wire Wire Line
	9800 6000 9800 5900
Connection ~ 9800 5900
$Comp
L GND #PWR05
U 1 1 5D31240F
P 6300 1550
F 0 "#PWR05" H 6300 1300 50  0001 C CNN
F 1 "GND" H 6300 1400 50  0000 C CNN
F 2 "" H 6300 1550 50  0001 C CNN
F 3 "" H 6300 1550 50  0001 C CNN
	1    6300 1550
	-1   0    0    -1  
$EndComp
$Comp
L Jumper JP2
U 1 1 5D3124B4
P 6000 1950
F 0 "JP2" H 6000 2100 50  0000 C CNN
F 1 "Jumper" H 6000 1870 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6000 1950 50  0001 C CNN
F 3 "" H 6000 1950 50  0001 C CNN
	1    6000 1950
	-1   0    0    1   
$EndComp
Text GLabel 7100 1950 2    60   Input ~ 0
VDD
$Comp
L R R9
U 1 1 5D312718
P 6700 1950
F 0 "R9" V 6780 1950 50  0000 C CNN
F 1 "4.7K" V 6700 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6630 1950 50  0001 C CNN
F 3 "" H 6700 1950 50  0001 C CNN
	1    6700 1950
	0    1    1    0   
$EndComp
Wire Wire Line
	6850 1950 7100 1950
Wire Wire Line
	6300 1950 6550 1950
$Comp
L R R10
U 1 1 5D312893
P 6700 1800
F 0 "R10" V 6800 1800 50  0000 C CNN
F 1 "4.7K" V 6700 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6630 1800 50  0001 C CNN
F 3 "" H 6700 1800 50  0001 C CNN
	1    6700 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6450 1800 6450 1950
Connection ~ 6450 1950
$Comp
L GND #PWR06
U 1 1 5D312C05
P 7100 1800
F 0 "#PWR06" H 7100 1550 50  0001 C CNN
F 1 "GND" H 7100 1650 50  0000 C CNN
F 2 "" H 7100 1800 50  0001 C CNN
F 3 "" H 7100 1800 50  0001 C CNN
	1    7100 1800
	0    -1   1    0   
$EndComp
Wire Wire Line
	6450 1800 6550 1800
Wire Wire Line
	7100 1800 6850 1800
Wire Wire Line
	5700 1950 5650 1950
Wire Wire Line
	5650 1950 5650 2500
Wire Wire Line
	5650 2500 5350 2500
Connection ~ 5350 2500
Wire Wire Line
	5600 1550 5600 2300
Wire Wire Line
	5600 2300 5250 2300
Connection ~ 5250 2300
Wire Wire Line
	5600 1550 5700 1550
Wire Wire Line
	6900 5450 6900 5750
Wire Wire Line
	6900 5750 7000 5750
Connection ~ 7000 5750
$Comp
L 110-109 U4
U 1 1 5D3116EB
P 9550 6200
F 0 "U4" H 9050 6700 60  0000 C CNN
F 1 "CO gas sensor" H 9050 5900 60  0000 L CNN
F 2 "gas_sensors:SPEC_Gas_Sensor_P_Package" H 9750 6400 60  0001 L CNN
F 3 "http://www.spec-sensors.com/wp-content/uploads/2016/04/3SP_CO_1000-C-Package-110-109.pdf" H 9750 6500 60  0001 L CNN
F 4 "1684-1001-ND" H 9750 6600 60  0001 L CNN "Digi-Key_PN"
F 5 "110-109" H 9750 6700 60  0001 L CNN "MPN"
F 6 "Sensors, Transducers" H 9750 6800 60  0001 L CNN "Category"
F 7 "Gas Sensors" H 9750 6900 60  0001 L CNN "Family"
F 8 "http://www.spec-sensors.com/wp-content/uploads/2016/04/3SP_CO_1000-C-Package-110-109.pdf" H 9750 7000 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/spec-sensors-llc/110-109/1684-1001-ND/6136364" H 9750 7100 60  0001 L CNN "DK_Detail_Page"
F 10 "SENSOR GAS CO ANALOG CUR MOD" H 9750 7200 60  0001 L CNN "Description"
F 11 "SPEC Sensors, LLC" H 9750 7300 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9750 7400 60  0001 L CNN "Status"
	1    9550 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 6300 9050 6450
Wire Wire Line
	9050 6450 9900 6450
Wire Wire Line
	9900 6450 9900 6000
Connection ~ 9800 6000
$EndSCHEMATC
