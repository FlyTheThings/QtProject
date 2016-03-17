#ifndef DATASTRUCTUREDEFINE_H
#define DATASTRUCTUREDEFINE_H

#include "messageIDDefine.h"

/* --[Protocol data structure define]-- */
typedef struct __datalink_message {
    quint8  magic1,                              ///< protocol magic marker1
            magic2;                              ///< protocol magic marker2
    quint8  len;                                 ///< Length of payload
    quint8  seq;                                 ///< Sequence of packet
    quint8  sysid;                               ///< ID of message sender system/aircraft
    quint8  compid;                              ///< ID of the message sender component
    quint8  msgid;                               ///< ID of message in payload
    quint8  payload[DATALINK_MAX_PAYLOAD_LEN];
    quint8  ck_a,                                ///< sent at end of packet
            ck_b;
} datalink_message_t;

typedef enum {
    DATALINK_PARSE_STATE_UNINIT=0,
    DATALINK_PARSE_STATE_IDLE,
    DATALINK_PARSE_STATE_GOT_STX1,
    DATALINK_PARSE_STATE_GOT_STX2,
    DATALINK_PARSE_STATE_GOT_LENGTH,
    DATALINK_PARSE_STATE_GOT_SEQ,
    DATALINK_PARSE_STATE_GOT_SYSID,
    DATALINK_PARSE_STATE_GOT_COMPID,
    DATALINK_PARSE_STATE_GOT_MSGID,
    DATALINK_PARSE_STATE_GOT_PAYLOAD,
    DATALINK_PARSE_STATE_GOT_CRC1
} datalink_parse_state_t;                    ///< The state machine for the comm parser

typedef struct __mavlink_status {
    quint8  msg_received;                    ///< flag of received messages
    quint8  parse_error;                     ///< Number of parse errors
    quint8  packet_idx;                      ///< Index in current packet
    quint8  current_rx_seq;                  ///< Sequence number of last packet received
    quint8  current_tx_seq;                  ///< Sequence number of last packet sent
    quint16 packet_rx_success_count;         ///< Received packets
    quint16 packet_rx_drop_count;            ///< Number of packet drops
    datalink_parse_state_t parse_state;      ///< Parsing state machine
} datalink_status_t;



typedef struct __heartbeat {
    quint8     uasInfo,  uasState;
    quint8     ctrlMode, plMode, vtMode, guidMode;
    double     lon, lat;
    float      vd, alt, Hdot, psi, track;
    quint16    flyTime;
    quint8     gpsState;
    float      oilEng, voltCell, cpuRatio,tempEng;
} heartbeat_Struc_t;

#endif // DATASTRUCTUREDEFINE_H
