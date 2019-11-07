EESchema Schematic File Version 4
LIBS:RGB_Controller-cache
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
L Transistor_FET:2N7000 Q1
U 1 1 5DA5C36F
P 8650 1800
F 0 "Q1" H 8856 1846 50  0000 L CNN
F 1 "2N7000" H 8856 1755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-126-3_Vertical" H 8850 1725 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 8650 1800 50  0001 L CNN
	1    8650 1800
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q2
U 1 1 5DA5D12D
P 8650 2500
F 0 "Q2" H 8856 2546 50  0000 L CNN
F 1 "2N7000" H 8856 2455 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-126-3_Vertical" H 8850 2425 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 8650 2500 50  0001 L CNN
	1    8650 2500
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q3
U 1 1 5DA5D633
P 8650 3300
F 0 "Q3" H 8856 3346 50  0000 L CNN
F 1 "2N7000" H 8856 3255 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-126-3_Vertical" H 8850 3225 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 8650 3300 50  0001 L CNN
	1    8650 3300
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q4
U 1 1 5DA62A7E
P 8700 4650
F 0 "Q4" H 8906 4696 50  0000 L CNN
F 1 "2N7000" H 8906 4605 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-126-3_Vertical" H 8900 4575 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 8700 4650 50  0001 L CNN
	1    8700 4650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q5
U 1 1 5DA62FE2
P 8700 5400
F 0 "Q5" H 8906 5446 50  0000 L CNN
F 1 "2N7000" H 8906 5355 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-126-3_Vertical" H 8900 5325 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 8700 5400 50  0001 L CNN
	1    8700 5400
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q6
U 1 1 5DA63500
P 8700 6150
F 0 "Q6" H 8906 6196 50  0000 L CNN
F 1 "2N7000" H 8906 6105 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-126-3_Vertical" H 8900 6075 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 8700 6150 50  0001 L CNN
	1    8700 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 1600 8750 1600
Wire Wire Line
	9500 1700 9200 1700
Wire Wire Line
	9200 1700 9200 2300
Wire Wire Line
	9200 2300 8750 2300
Wire Wire Line
	9500 1800 9250 1800
Wire Wire Line
	9250 1800 9250 3100
Wire Wire Line
	9250 3100 8750 3100
Wire Wire Line
	8800 4450 9500 4450
Wire Wire Line
	9500 4550 9250 4550
Wire Wire Line
	9250 4550 9250 5200
Wire Wire Line
	9250 5200 8800 5200
Wire Wire Line
	9500 4650 9300 4650
Wire Wire Line
	9300 4650 9300 5950
Wire Wire Line
	9300 5950 8800 5950
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5DA776FC
P 9700 1250
F 0 "J1" H 9780 1242 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9780 1151 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 9700 1250 50  0001 C CNN
F 3 "~" H 9700 1250 50  0001 C CNN
	1    9700 1250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5DA788B5
P 9700 4100
F 0 "J3" H 9780 4092 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9780 4001 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 9700 4100 50  0001 C CNN
F 3 "~" H 9700 4100 50  0001 C CNN
	1    9700 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x04 J2
U 1 1 5DA85AD5
P 9700 1600
F 0 "J2" H 9780 1592 50  0000 L CNN
F 1 "Screw_Terminal_01x04" H 9780 1501 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-4_P5.00mm" H 9700 1600 50  0001 C CNN
F 3 "~" H 9700 1600 50  0001 C CNN
	1    9700 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x04 J4
U 1 1 5DA8641C
P 9700 4450
F 0 "J4" H 9780 4442 50  0000 L CNN
F 1 "Screw_Terminal_01x04" H 9780 4351 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-4_P5.00mm" H 9700 4450 50  0001 C CNN
F 3 "~" H 9700 4450 50  0001 C CNN
	1    9700 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 1350 9500 1500
Wire Wire Line
	9500 4200 9500 4350
Wire Wire Line
	7800 1250 9500 1250
$Comp
L Device:R R3
U 1 1 5DAAF040
P 8150 3300
F 0 "R3" V 7943 3300 50  0000 C CNN
F 1 "R" V 8034 3300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8080 3300 50  0001 C CNN
F 3 "~" H 8150 3300 50  0001 C CNN
	1    8150 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 3300 8450 3300
$Comp
L Device:R R2
U 1 1 5DAB0758
P 8150 2500
F 0 "R2" V 7943 2500 50  0000 C CNN
F 1 "R" V 8034 2500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8080 2500 50  0001 C CNN
F 3 "~" H 8150 2500 50  0001 C CNN
	1    8150 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 2500 8450 2500
$Comp
L Device:R R1
U 1 1 5DAB157C
P 8150 1800
F 0 "R1" V 7943 1800 50  0000 C CNN
F 1 "R" V 8034 1800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8080 1800 50  0001 C CNN
F 3 "~" H 8150 1800 50  0001 C CNN
	1    8150 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 1800 8450 1800
$Comp
L Device:R R4
U 1 1 5DAB443C
P 8150 4650
F 0 "R4" V 7943 4650 50  0000 C CNN
F 1 "R" V 8034 4650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8080 4650 50  0001 C CNN
F 3 "~" H 8150 4650 50  0001 C CNN
	1    8150 4650
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5DAB491A
P 8150 5400
F 0 "R5" V 7943 5400 50  0000 C CNN
F 1 "R" V 8034 5400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8080 5400 50  0001 C CNN
F 3 "~" H 8150 5400 50  0001 C CNN
	1    8150 5400
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5DAB4D6C
P 8150 6150
F 0 "R6" V 7943 6150 50  0000 C CNN
F 1 "R" V 8034 6150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8080 6150 50  0001 C CNN
F 3 "~" H 8150 6150 50  0001 C CNN
	1    8150 6150
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 6150 8500 6150
Wire Wire Line
	8500 5400 8300 5400
Wire Wire Line
	8300 4650 8500 4650
Wire Wire Line
	8000 6150 5050 6150
Wire Wire Line
	5050 6150 5050 4050
Wire Wire Line
	5150 4150 5150 5400
Wire Wire Line
	5150 5400 8000 5400
Wire Wire Line
	8000 4650 8000 5200
Wire Wire Line
	8000 5200 5250 5200
Wire Wire Line
	5250 5200 5250 4250
Wire Wire Line
	5300 3450 5300 2600
Wire Wire Line
	5300 2600 7650 2600
Wire Wire Line
	7650 2600 7650 3300
Wire Wire Line
	7650 3300 8000 3300
Wire Wire Line
	8000 2500 5200 2500
Wire Wire Line
	5200 2500 5200 3650
Wire Wire Line
	5100 3750 5100 1800
Wire Wire Line
	5100 1800 8000 1800
$Comp
L Jumper:Jumper_2_Open JP1
U 1 1 5DAC33D7
P 7100 3050
F 0 "JP1" H 7100 3285 50  0000 C CNN
F 1 "Jumper_2_Open" H 7100 3194 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 7100 3050 50  0001 C CNN
F 3 "~" H 7100 3050 50  0001 C CNN
	1    7100 3050
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_2_Open JP2
U 1 1 5DAC4436
P 7100 3350
F 0 "JP2" H 7100 3585 50  0000 C CNN
F 1 "Jumper_2_Open" H 7100 3494 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 7100 3350 50  0001 C CNN
F 3 "~" H 7100 3350 50  0001 C CNN
	1    7100 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3350 7500 3350
Wire Wire Line
	7500 3350 7500 4200
Wire Wire Line
	7500 4200 9500 4200
Connection ~ 9500 4200
Wire Wire Line
	6900 3350 6900 3050
Wire Wire Line
	7200 3050 7200 1350
Wire Wire Line
	7200 1350 9500 1350
Connection ~ 9500 1350
Wire Wire Line
	5900 2650 6900 2650
Wire Wire Line
	6900 2650 6900 3050
Connection ~ 6900 3050
$Comp
L Switch:SW_Push SW1
U 1 1 5DACBDA9
P 4500 2950
F 0 "SW1" H 4500 3235 50  0000 C CNN
F 1 "SW_Push" H 4500 3144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4500 3150 50  0001 C CNN
F 3 "~" H 4500 3150 50  0001 C CNN
	1    4500 2950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5DACCE06
P 4500 3350
F 0 "SW2" H 4500 3635 50  0000 C CNN
F 1 "SW_Push" H 4500 3544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4500 3550 50  0001 C CNN
F 3 "~" H 4500 3550 50  0001 C CNN
	1    4500 3350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5DACD236
P 4500 3750
F 0 "SW3" H 4500 4035 50  0000 C CNN
F 1 "SW_Push" H 4500 3944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4500 3950 50  0001 C CNN
F 3 "~" H 4500 3950 50  0001 C CNN
	1    4500 3750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5DACD64C
P 4500 4250
F 0 "SW4" H 4500 4535 50  0000 C CNN
F 1 "SW_Push" H 4500 4444 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4500 4450 50  0001 C CNN
F 3 "~" H 4500 4450 50  0001 C CNN
	1    4500 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 4250 4300 3750
Wire Wire Line
	4300 3750 4300 3350
Connection ~ 4300 3750
Wire Wire Line
	4300 3350 4300 2950
Connection ~ 4300 3350
Wire Wire Line
	4300 4250 4300 4750
Connection ~ 4300 4250
Wire Wire Line
	4900 3350 4900 2950
Wire Wire Line
	4900 2950 4700 2950
Wire Wire Line
	4700 3550 4700 3350
Wire Wire Line
	4700 3850 4700 3750
Wire Wire Line
	4700 4250 4700 3950
Wire Wire Line
	5500 3750 5100 3750
Wire Wire Line
	5200 3650 5500 3650
Wire Wire Line
	5500 3550 4700 3550
Wire Wire Line
	5500 3450 5300 3450
Wire Wire Line
	5500 3350 4900 3350
Wire Wire Line
	4300 4750 6000 4750
Wire Wire Line
	5900 2750 5900 2650
Wire Wire Line
	6100 4750 7800 4750
Wire Wire Line
	5250 4250 5500 4250
Wire Wire Line
	5500 4150 5150 4150
Wire Wire Line
	5050 4050 5500 4050
Wire Wire Line
	4700 3950 5500 3950
Wire Wire Line
	5500 3850 4700 3850
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5DA5AA0B
P 6000 3750
F 0 "A1" H 6000 2661 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 6000 2570 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 6150 2800 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 6000 2750 50  0001 C CNN
	1    6000 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 3050 7300 3050
Wire Wire Line
	8750 2000 8350 2000
Wire Wire Line
	8350 2000 8350 2700
Wire Wire Line
	8350 6350 8800 6350
Wire Wire Line
	8800 5600 8350 5600
Connection ~ 8350 5600
Wire Wire Line
	8350 5600 8350 6350
Wire Wire Line
	8800 4850 8350 4850
Connection ~ 8350 4850
Wire Wire Line
	8350 4850 8350 5600
Wire Wire Line
	8750 3500 8350 3500
Connection ~ 8350 3500
Wire Wire Line
	8350 3500 8350 4100
Wire Wire Line
	8750 2700 8350 2700
Connection ~ 8350 2700
Wire Wire Line
	8350 2700 8350 3500
Wire Wire Line
	7800 1250 7800 4100
Wire Wire Line
	9500 4100 8350 4100
Connection ~ 8350 4100
Wire Wire Line
	8350 4100 8350 4850
Wire Wire Line
	8350 4100 7800 4100
Connection ~ 7800 4100
Wire Wire Line
	7800 4100 7800 4750
Wire Wire Line
	6000 4750 6100 4750
Connection ~ 6000 4750
Connection ~ 6100 4750
$EndSCHEMATC
