/*
 * Peer manager
 *
 * The peer manager keeps track of neighbor nodes in a peer-to-peer
 * network.  This module might be used as part of a BitTorrent, BitCoin,
 * or Tor client.
 *
 * Every time there is activity from a peer, the peer manager is told about it.
 * The peer manager remembers the n most recently active unique peers.
 *
 * When we wish to communicate, the peer manager can select a random
 * peer.
 *
 * Example usage:
 *
 *   PeerManager mgr;
 *   peermgr_init(&mgr, 8);
 *
 *   peermgr_saw_peer(&mgr, 1234, time(NULL));
 *   peermgr_saw_peer(&mgr, 5432, time(NULL));
 *
 *   PeerId random_peer;
 *   if (peermgr_pick_random_peer(&mgr, &random_peer)) {
 *       printf("chosen peer = %" PRIu64 "\n", random_peer);
 *   }
 *
 *   peermgr_cleanup(&mgr);
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

/* TODO You may include additional C standard library headers and define
 * additional structs.  You cannot change the function prototypes, the API is
 * fixed.
 */

/** A unique identifier for a peer */
typedef uint64_t PeerId;

typedef struct {
	PeerId        _id;
	unsigned int  _maxpeers;
	time_t        _timestamp;
	PeerId        _tabla_peers[TAM];
	uint16_t      _num_peers;
} PeerManager;

/**
 * Initialize @mgr so that it can track up to @maxpeers peers.
 */
void peermgr_init(PeerManager *mgr, unsigned int maxpeers)
{
	if (maxpeers > TAM){
		printf("ERROR - The maximum number of peers is %d", TAM);
		return;
	}

	mgr = (PeerManager *)malloc(sizeof(PeerManager));
	mgr->_maxpeers = maxpeers;
	mgr->_num_peers = 0;
}
"
/**
 * Free any resources allocated by @mgr.
 */
void peermgr_cleanup(PeerManager *mgr)
{
	free(mgr);
}

/**
 * Update peer information with new activity from @peer at time @timestamp.
 * The peer manager retains a fixed number of unique peers with the most recent
 * timestamps.  The maximum number of peers to remember was set in
 * peermgr_init().
 *
 * If the maximum number of peers to remember has been reached, it may be
 * necessary to forget about the peer with the oldest timestamp so that there
 * is space for the newer peer.
 */
void peermgr_saw_peer(PeerManager *mgr, PeerId peer, time_t timestamp)
{
	
	if (mgr->_num_peers < mgr->_maxpeers) {
		mgr->_tabla_peers[_num_peers +1] = peer;
		mgr->_timestamp = timestamp;
		mgr->_num_peers++;
	} else {
		printf("ERROR - The maximum number of peers is %d",
                       mgr->_num_peers);
	}

}

/**
 * Select a peer at random and store its identifier in @peer.
 *
 * Returns: true on success
 */
bool peermgr_pick_random_peer(PeerManager *mgr, PeerId *peer)
{
    /* TODO use random(3) and assume a seed has already been set */
	long int num = random(3);
	
	if (num < _num_peers) {
		*peer = mgr->_tabla_peers[num];
		return true;
	} else
		return false;

}
