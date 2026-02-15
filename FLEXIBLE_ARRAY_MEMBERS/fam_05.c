struct Message {
    uint32_t type;
    uint32_t length;
    unsigned char payload[];
};
