/*
	nymphcast_client.h - Header file for the NymphCast client library.
	
	Revision 0
	
	Notes:
			-
			
	2019/10/26, Maya Posch
*/


#ifndef NYMPHCAST_CLIENT_H
#define NYMPHCAST_CLIENT_H


#include <string>
#include <fstream>

#include <nymph/nymph.h>

//#include "mdns.h"


class NymphCastClient {
	std::string clientId = "NymphClient_21xb";
	std::ifstream source;
	
	void MediaReadCallback(uint32_t session, NymphMessage* msg, void* data);
	void MediaStopCallback(uint32_t session, NymphMessage* msg, void* data);
	void MediaSeekCallback(uint32_t session, NymphMessage* msg, void* data);
	
public:
	NymphCastClient();
	~NymphCastClient();

	void findServers();
	bool connectServer(std::string ip, uint32_t &handle);
	bool disconnectServer(uint32_t handle);
	
	bool castFile(uint32_t handle, std::string filename);
	bool castUrl(uint32_t handle, std::string url);
	
	uint8_t volumeSet(uint32_t handle, uint8_t volume);
	uint8_t volumeUp(uint32_t handle);
	uint8_t volumeDown(uint32_t handle);
	
	uint8_t playbackStart(uint32_t handle);
	uint8_t playbackStop(uint32_t handle);
	uint8_t playbackPause(uint32_t handle);
	uint8_t playbackRewind(uint32_t handle);
	uint8_t playbackForward(uint32_t handle);
	uint8_t playbackSeek(uint32_t handle, uint64_t location);
};


#endif