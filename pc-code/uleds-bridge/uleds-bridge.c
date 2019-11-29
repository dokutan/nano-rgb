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
 * Usage: uleds-bridge -a <device>
 * 
 */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <poll.h>
#include <linux/uleds.h>
#include <getopt.h>

// macro to close all file descriptors
#define CLOSE_ALL_FD() \
	close(fd_r1); \
	close(fd_g1); \
	close(fd_b1); \
	close(fd_r2); \
	close(fd_g2); \
	close(fd_b2); \
	close(arduino_fd);
	
// macro to print help message
#define PRINT_HELP() \
	printf("uleds-bridge usage:\n"); \
	printf("This program requires the uleds kernel module.\n"); \
	printf("-h --help\tshow this message\n"); \
	printf("-a=path --arduino=path\t"); \
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
		{0, 0, 0, 0}
	};
	
	//parse command line options
	int c, option_index = 0;
	char arduino_path[MAX_PATH_LEN];
	while( (c = getopt_long( argc, argv, "ha:",	long_options, 
	&option_index ) ) != -1 ){
		
		switch(c){
			case 'h':
				PRINT_HELP();
				return 0;
				break;
			case 'a':
				strncpy(arduino_path, optarg, MAX_PATH_LEN);
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
	
	// wait 5 seconds for the arduino to initialize after reset
	sleep(5);
	
	// uleds stuff
	struct uleds_user_dev dev_led_r1;
	struct uleds_user_dev dev_led_g1;
	struct uleds_user_dev dev_led_b1;
	struct uleds_user_dev dev_led_r2;
	struct uleds_user_dev dev_led_g2;
	struct uleds_user_dev dev_led_b2;
	int fd_r1, fd_g1, fd_b1;
	int fd_r2, fd_g2, fd_b2;
	int brightness_r1, brightness_g1, brightness_b1;
	int brightness_r2, brightness_g2, brightness_b2;
	int ret;
	
	// configure leds (max_brightness and name)
	strncpy(dev_led_r1.name, "nano-rgb:red:ch1", LED_MAX_NAME_SIZE);
	strncpy(dev_led_g1.name, "nano-rgb:green:ch1", LED_MAX_NAME_SIZE);
	strncpy(dev_led_b1.name, "nano-rgb:blue:ch1", LED_MAX_NAME_SIZE);
	strncpy(dev_led_r2.name, "nano-rgb:red:ch2", LED_MAX_NAME_SIZE);
	strncpy(dev_led_g2.name, "nano-rgb:green:ch2", LED_MAX_NAME_SIZE);
	strncpy(dev_led_b2.name, "nano-rgb:blue:ch2", LED_MAX_NAME_SIZE);
	dev_led_r1.max_brightness = 255;
	dev_led_g1.max_brightness = 255;
	dev_led_b1.max_brightness = 255;
	dev_led_r2.max_brightness = 255;
	dev_led_g2.max_brightness = 255;
	dev_led_b2.max_brightness = 255;
	
	// open /dev/uleds
	fd_r1 = open("/dev/uleds", O_RDWR);
	if (fd_r1 == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	fd_g1 = open("/dev/uleds", O_RDWR);
	if (fd_g1 == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	fd_b1 = open("/dev/uleds", O_RDWR);
	if (fd_b1 == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	fd_r2 = open("/dev/uleds", O_RDWR);
	if (fd_r2 == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	fd_g2 = open("/dev/uleds", O_RDWR);
	if (fd_g2 == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	fd_b2 = open("/dev/uleds", O_RDWR);
	if (fd_b2 == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	
	// create leds in /sys/class/leds
	ret = write(fd_r1, &dev_led_r1, sizeof(dev_led_r1));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		CLOSE_ALL_FD();
		return 1;
	}
	ret = write(fd_g1, &dev_led_g1, sizeof(dev_led_g1));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		CLOSE_ALL_FD();
		return 1;
	}
	ret = write(fd_b1, &dev_led_b1, sizeof(dev_led_b1));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		CLOSE_ALL_FD();
		return 1;
	}
	ret = write(fd_r2, &dev_led_r2, sizeof(dev_led_r2));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		CLOSE_ALL_FD();
		return 1;
	}
	ret = write(fd_g2, &dev_led_g2, sizeof(dev_led_g2));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		CLOSE_ALL_FD();
		return 1;
	}
	ret = write(fd_b2, &dev_led_b2, sizeof(dev_led_b2));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		CLOSE_ALL_FD();
		return 1;
	}
	
	// poll stuff (monitors file descriptors)
	struct pollfd fds[6];
	fds[0].fd = fd_r1;
	fds[1].fd = fd_g1;
	fds[2].fd = fd_b1;
	fds[3].fd = fd_r2;
	fds[4].fd = fd_g2;
	fds[5].fd = fd_b2;
	fds[0].events = POLLIN;
	fds[1].events = POLLIN;
	fds[2].events = POLLIN;
	fds[3].events = POLLIN;
	fds[4].events = POLLIN;
	fds[5].events = POLLIN;
	
	// bytes to send to the arduino
	char code[4];
	
	while(1){
		
		// monitor file descriptor: poll(fds, nfds, timeout)
		poll(fds,6,-1);
		//printf("poll returned\n");
		
		if(fds[0].revents & POLLIN){
			// read red led ch1 brightness
			ret = read(fd_r1, &brightness_r1, sizeof(brightness_r1));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				CLOSE_ALL_FD();
				return 1;
			}
			//printf("rr\n");
		}
		if(fds[1].revents & POLLIN){
			// read green led ch1 brightness
			ret = read(fd_g1, &brightness_g1, sizeof(brightness_g1));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				CLOSE_ALL_FD();
				return 1;
			}
			//printf("rg\n");
		}
		if(fds[2].revents & POLLIN){
			// read blue led ch1 brightness
			ret = read(fd_b1, &brightness_b1, sizeof(brightness_b1));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				CLOSE_ALL_FD();
				return 1;
			}
			//printf("rb\n");
		}
		if(fds[3].revents & POLLIN){
			// read red led ch2 brightness
			ret = read(fd_r2, &brightness_r2, sizeof(brightness_r2));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				CLOSE_ALL_FD();
				return 1;
			}
			//printf("rr\n");
		}
		if(fds[4].revents & POLLIN){
			// read green led ch2 brightness
			ret = read(fd_g2, &brightness_g2, sizeof(brightness_g2));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				CLOSE_ALL_FD();
				return 1;
			}
			//printf("rg\n");
		}
		if(fds[5].revents & POLLIN){
			// read blue led ch2 brightness
			ret = read(fd_b2, &brightness_b2, sizeof(brightness_b2));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				CLOSE_ALL_FD();
				return 1;
			}
			//printf("rb\n");
		}
		
		// write to arduino
		// ch1 values
		code[0] = '1';
		code[1] = brightness_r1;
		code[2] = brightness_g1;
		code[3] = brightness_b1;
		ret = write(arduino_fd, &code, sizeof(code));
		if (ret == -1) {
			perror("Couldn't write to Arduino");
			CLOSE_ALL_FD();
			return 1;
		}
		// ch2 values
		code[0] = '2';
		code[1] = brightness_r2;
		code[2] = brightness_g2;
		code[3] = brightness_b2;
		ret = write(arduino_fd, &code, sizeof(code));
		if (ret == -1) {
			perror("Couldn't write to Arduino");
			CLOSE_ALL_FD();
			return 1;
		}
		
	}
	
	// close all file descriptors
	CLOSE_ALL_FD();
	return 0;
}
