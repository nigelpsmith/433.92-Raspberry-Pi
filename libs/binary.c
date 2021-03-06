/*
	Copyright 2013 CurlyMo

	This file is part of the Raspberry Pi 433.92Mhz transceiver.

    Raspberry Pi 433.92Mhz transceiver is free software: you can redistribute
	it and/or modify it under the terms of the GNU General Public License as
	published by the Free Software Foundation, either version 3 of the License,
	or (at your option) any later version.

    Raspberry Pi 433.92Mhz transceiver is distributed in the hope that it will
	be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Raspberry Pi 433.92Mhz transceiver. If not, see
	<http://www.gnu.org/licenses/>
*/

#include <stdio.h>
#include <stdlib.h>

#include "binary.h"

int binToDecRev(int *binary, int s, int e) {
	int dec = 0, i = 0;
	unsigned int x = 1;
	for(i=s;i<=e;i++) {
		x*=2;
	}
	for(i=s;i<=e;i++) {
		x/=2;
		if(binary[i] == 1)
			dec += (int)x;
	}
	return dec;
}

int binToDec(int *binary, int s, int e) {
	int dec = 0, i = 0;
	unsigned int x = 1;
	for(i=s;i<=e;i++) {
		if(binary[i] == 1)
			dec += (int)x;
		x*=2;
	}
	return dec;
}

int decToBin(int n, int binary[]) {
	unsigned int i=1;
	unsigned int x=0;
	int y=0;
	while(i<=n) {
		i*=2;
		x++;
	}
	i/=2;
	x--;
	for(y=(int)x;y>=0;y--) {
		if((n-(int)i)>=0) {
			n-=(int)i;
			binary[(int)x-y]=1;
		} else {
			binary[(int)x-y]=0;
		}
		i/=2;
	}
	return (int)x;
}

int decToBinRev(int n, int binary[]) {
	unsigned int i=1;
	unsigned int x=0;
	int y=0;
	while(i<=n) {
		i*=2;
		x++;
	}
	i/=2;
	x--;
	for(y=(int)x;y>=0;y--) {
		if((n-(int)i)>=0) {
			n-=(int)i;
			binary[y]=1;
		} else {
			binary[y]=0;
		}
		i/=2;
	}
	return (int)x;
}
