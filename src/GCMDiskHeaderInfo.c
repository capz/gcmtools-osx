/*
**  GCMDiskHeaderInfo.c
**  written by spike <spike666@mac.com>
**  www.sadistech.com
**  gcmtool.sourceforge.net
**  
**  part of the gcmtool project
**  Functions for handling diskheaderinfo from Gamecube DVD Images
*/

#include "GCMDiskHeaderInfo.h"
#include "GCMutils.h"
#include <string.h>
#include <stdlib.h>

void GCMDiskHeaderInfoStructToRaw(GCMDiskHeaderInfoStruct *d, char *buf) {
	/*
	**  sets buf to a DiskHeaderInfoStruct as raw data
	**  suitable for writing to a file or dumping back to a GCM
	**  
	**  when allocating memory for buf, you should use GCM_DISK_HEADER_INFO_LENGTH
	*/
	
	if (!d || !buf) return;
	
	char *start = buf;
	
	//first, let's zero out the buffer
	bzero(buf, GCM_DISK_HEADER_INFO_LENGTH);
	
	u32 *debugMonitorSize = (u32*)malloc(sizeof(u32));
	*debugMonitorSize = htonl(d->debugMonitorSize);
	memcpy(buf, debugMonitorSize, sizeof(u32));
	free(debugMonitorSize);
	buf += sizeof(u32);
	
	u32 *simulatedMemorySize = (u32*)malloc(sizeof(u32));
	*simulatedMemorySize = htonl(d->simulatedMemorySize);
	memcpy(buf, simulatedMemorySize, sizeof(u32));
	free(simulatedMemorySize);
	buf += sizeof(u32);
	
	u32 *argumentOffset = (u32*)malloc(sizeof(u32));
	*argumentOffset = htonl(d->argumentOffset);
	memcpy(buf, argumentOffset, sizeof(u32));
	free(argumentOffset);
	buf += sizeof(u32);
	
	u32 *debugFlag = (u32*)malloc(sizeof(u32));
	*debugFlag = htonl(d->debugFlag);
	memcpy(buf, debugFlag, sizeof(u32));
	free(debugFlag);
	buf += sizeof(u32);
	
	u32 *trackLocation = (u32*)malloc(sizeof(u32));
	*trackLocation = htonl(d->trackLocation);
	memcpy(buf, trackLocation, sizeof(u32));
	free(trackLocation);
	buf += sizeof(u32);
	
	u32 *trackSize = (u32*)malloc(sizeof(u32));
	*trackSize = htonl(d->trackSize);
	memcpy(buf, trackSize, sizeof(u32));
	free(trackSize);
	buf += sizeof(u32);
	
	u32 *countryCode = (u32*)malloc(sizeof(u32));
	*countryCode = htonl(d->countryCode);
	memcpy(buf, countryCode, sizeof(u32));
	free(countryCode);
	buf += sizeof(u32);
	
	u32 *unknown1 = (u32*)malloc(sizeof(u32));
	*unknown1 = htonl(d->unknown1);
	memcpy(buf, unknown1, sizeof(u32));
	free(unknown1);
	buf += sizeof(u32);
	
	u32 *unknown2 = (u32*)malloc(sizeof(u32));
	*unknown2 = htonl(d->unknown2);
	memcpy(buf, unknown2, sizeof(u32));
	free(unknown2);
	buf += sizeof(u32);
	
	buf = start;
}

GCMDiskHeaderInfoStruct *GCMRawDiskHeaderInfoToStruct(char *rawInfo) {
	/*
	**  experimental function for creating a struct out of the diskheaderinfo
	**  
	*/

	GCMDiskHeaderInfoStruct *d = (GCMDiskHeaderInfoStruct*)malloc(sizeof(GCMDiskHeaderInfoStruct));
	u32* rawfo = (u32*)rawInfo;
	d->debugMonitorSize	= *rawfo++;
	d->debugMonitorSize	= ntohl(d->debugMonitorSize);
	
	d->simulatedMemorySize  = *rawfo++;
	d->simulatedMemorySize	= ntohl(d->simulatedMemorySize); 
	
	d->argumentOffset		= *rawfo++;
	d->argumentOffset		= ntohl(d->argumentOffset);
	
	d->debugFlag			= *rawfo++;
	d->debugFlag			= ntohl(d->argumentOffset);
	
	d->trackLocation		= *rawfo++;
	d->trackLocation		= ntohl(d->trackLocation);
	
	d->trackSize			= *rawfo++;
	d->trackSize			= ntohl(d->trackSize);
	
	d->countryCode			= *rawfo++;
	d->countryCode			= ntohl(d->countryCode);
	
	d->unknown1				= *rawfo++;
	d->unknown1				= ntohl(d->unknown1);
	
	d->unknown2				= *rawfo++;
	d->unknown2				= ntohl(d->unknown2);
	
	return d;
}

void GCMFreeDiskHeaderInfoStruct(GCMDiskHeaderInfoStruct *dhi) {
	/*
	**  convenience method for freeing a DiskHeaderInfoStruct
	*/

	if (!dhi) return;
	
	free(dhi);
}

