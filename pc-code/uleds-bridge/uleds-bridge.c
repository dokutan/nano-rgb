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
 * Usage: TODO
 * 
 */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <poll.h>
#include <linux/uleds.h>

int main(int argc, char const *argv[])
{
	//open arduino
	int arduino_fd;
	arduino_fd = open("/dev/ttyUSB0", O_RDWR);
	if (arduino_fd == -1) {
		perror("Failed to open Arduino");
		return 1;
	}
	
	// wait 5 seconds for the arduino to initialize
	sleep(5);
	
	// uleds stuff
	struct uleds_user_dev dev_led_r;
	struct uleds_user_dev dev_led_g;
	struct uleds_user_dev dev_led_b;
	int fd_r, fd_g, fd_b;
	int brightness_r, brightness_g, brightness_b;
	int ret;
	
	// configure leds
	strncpy(dev_led_r.name, "nano-rgb:red:ch1", LED_MAX_NAME_SIZE);
	strncpy(dev_led_g.name, "nano-rgb:green:ch1", LED_MAX_NAME_SIZE);
	strncpy(dev_led_b.name, "nano-rgb:blue:ch1", LED_MAX_NAME_SIZE);
	dev_led_r.max_brightness = 255;
	dev_led_g.max_brightness = 255;
	dev_led_b.max_brightness = 255;
	
	fd_r = open("/dev/uleds", O_RDWR);
	if (fd_r == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	fd_g = open("/dev/uleds", O_RDWR);
	if (fd_g == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	fd_b = open("/dev/uleds", O_RDWR);
	if (fd_b == -1) {
		perror("Couldn't open /dev/uleds");
		return 1;
	}
	
	// create leds in /sys/class/leds
	ret = write(fd_r, &dev_led_r, sizeof(dev_led_r));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		close(fd_r);
		close(fd_g);
		close(fd_b);
		close(arduino_fd);
		return 1;
	}
	ret = write(fd_g, &dev_led_g, sizeof(dev_led_g));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		close(fd_r);
		close(fd_g);
		close(fd_b);
		close(arduino_fd);
		return 1;
	}
	ret = write(fd_b, &dev_led_b, sizeof(dev_led_b));
	if (ret == -1) {
		perror("Couldn't write to /dev/uleds");
		close(fd_r);
		close(fd_g);
		close(fd_b);
		close(arduino_fd);
		return 1;
	}
	
	// poll stuff (monitors file descriptors)
	struct pollfd fds[3];
	fds[0].fd = fd_r;
	fds[1].fd = fd_g;
	fds[2].fd = fd_b;
	fds[0].events = POLLIN;
	fds[1].events = POLLIN;
	fds[2].events = POLLIN;
	
	// bytes to send to the arduino
	char code[4];
	
	while(1){
		
		// monitor file descriptor
		poll(fds,3,-1);
		//printf("poll returned\n");
		
		if(fds[0].revents & POLLIN){
			// read red led brightness
			ret = read(fd_r, &brightness_r, sizeof(brightness_r));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				close(fd_r);
				close(fd_g);
				close(fd_b);
				close(arduino_fd);
				return 1;
			}
			//printf("rr\n");
		}
		
		if(fds[1].revents & POLLIN){
			// read green led brightness
			ret = read(fd_g, &brightness_g, sizeof(brightness_g));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				close(fd_r);
				close(fd_g);
				close(fd_b);
				close(arduino_fd);
				return 1;
			}
			//printf("rg\n");
		}
		
		if(fds[2].revents & POLLIN){
			// read blue led brightness
			ret = read(fd_b, &brightness_b, sizeof(brightness_b));
			if (ret == -1) {
				perror("Couldn't read from /dev/uleds");
				close(fd_r);
				close(fd_g);
				close(fd_b);
				close(arduino_fd);
				return 1;
			}
			//printf("rb\n");
		}
		
		// write to arduino
		code[0] = 0;
		code[1] = brightness_r;
		code[2] = brightness_g;
		code[3] = brightness_b;
		ret = write(arduino_fd, &code, sizeof(code));
		if (ret == -1) {
			perror("Couldn't write to Arduino");
			close(arduino_fd);
			return 1;
		}
		
	}
	
	// close all file descriptors
	close(arduino_fd);
	close(fd_r);
	close(fd_g);
	close(fd_b);
	return 0;
}
