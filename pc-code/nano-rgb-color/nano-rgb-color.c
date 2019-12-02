/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * This program creates led devices with the uleds kernel module and
 * sends the changes to the nano-rgb over serial.
 * 
 * Usage: nano-rgb-color -a <device> -1 <color> -2 <color>
 * 
 */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <poll.h>
#include <getopt.h>
#include <termios.h>
#include <stdlib.h>

// macro to print help message
#define PRINT_HELP() \
	printf("nano-rgb-color usage:\n"); \
	printf("-h --help\tshow this message\n"); \
	printf("-a=path --arduino=path\t"); \
	printf("select the device to open (e.g. /dev/ttyUSB0)\n"); \
	printf("-1=color --ch1=color\tthe color of channel 1\n"); \
	printf("select the device to open (e.g. /dev/ttyUSB0)\n"); 

// maximum length of arduino_path
#define MAX_PATH_LEN 64

int main(int argc, char **argv)
{
	//check if correct number commandline options
	if(argc == 1){
		PRINT_HELP();
		return 0;
	}
	
	//command line options
	static struct option long_options[] = {
		{"help", no_argument, 0, 'h'},
		{"arduino", required_argument, 0, 'a'},
		{"ch1", required_argument, 0, '1'},
		{"ch2", required_argument, 0, '2'},
		{0, 0, 0, 0}
	};
	
	//parse command line options
	int c, option_index = 0;
	char arduino_path[MAX_PATH_LEN];
	char ch1_color[6];
	char ch2_color[6];
	int ch1_flag = 0, ch2_flag = 0;
	while( (c = getopt_long( argc, argv, "ha:1:2:",	long_options, 
	&option_index ) ) != -1 ){
		
		switch(c){
			case 'h':
				PRINT_HELP();
				return 0;
				break;
			case 'a':
				strncpy(arduino_path, optarg, MAX_PATH_LEN);
				break;
			case '1':
				strncpy(ch1_color, optarg, 6);
				ch1_flag = 1;
				break;
			case '2':
				strncpy(ch2_color, optarg, 6);
				ch2_flag = 1;
				break;
			default:
				break;
		}
	}
	
	//open arduino
	int arduino_fd;
	arduino_fd = open(arduino_path, O_RDWR);
	if (arduino_fd == -1) {
		perror("Failed to open Arduino");
		return 1;
	}
	
	//verify opened file is a tty
	if( !isatty(arduino_fd) ){
		perror("Device is not a tty");
		return 1;
	}
	
	//struct termios arduino_config;
	
	//sleep 3 seconds to wait for arduino initialization after reset
	sleep(3);
	
	//send data
	char code[4];
	if( ch1_flag == 1 ){
		//null terminated substrings for each component
		char ch1_red[3];
		char ch1_green[3];
		char ch1_blue[3];
		ch1_red[0] = ch1_color[0];
		ch1_red[1] = ch1_color[1];
		ch1_red[2] = 0;
		ch1_green[0] = ch1_color[2];
		ch1_green[1] = ch1_color[3];
		ch1_green[2] = 0;
		ch1_blue[0] = ch1_color[4];
		ch1_blue[1] = ch1_color[5];
		ch1_blue[2] = 0;
		//assemble full code and write
		code[0] = '1';
		code[1] = (int)strtol(ch1_red, NULL, 16);
		code[2] = (int)strtol(ch1_green, NULL, 16);
		code[3] = (int)strtol(ch1_blue, NULL, 16);
		write(arduino_fd, &code, sizeof(code));
	}
	if( ch2_flag == 1 ){
		//null terminated substrings for each component
		char ch2_red[3];
		char ch2_green[3];
		char ch2_blue[3];
		ch2_red[0] = ch2_color[0];
		ch2_red[1] = ch2_color[1];
		ch2_red[2] = 0;
		ch2_green[0] = ch2_color[2];
		ch2_green[1] = ch2_color[3];
		ch2_green[2] = 0;
		ch2_blue[0] = ch2_color[4];
		ch2_blue[1] = ch2_color[5];
		ch2_blue[2] = 0;
		//assemble full code and write
		code[0] = '2';
		code[1] = (int)strtol(ch2_red, NULL, 16);
		code[2] = (int)strtol(ch2_green, NULL, 16);
		code[3] = (int)strtol(ch2_blue, NULL, 16);
		write(arduino_fd, &code, sizeof(code));
	}
	
	// close arduino
	close(arduino_fd);
	return 0;
}
